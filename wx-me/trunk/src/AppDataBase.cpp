/****************************************************************************
* RetroMessenger - Serverless & Secure Instant Messenger
* build with wxWidgets gui toolkit based on libretroshare (c++)
*
* Copyright (c) 2008 Ryan Pusztai, Mahendra Panpalia and the RetroMessenger Team
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
* http://www.gnu.org/licenses/gpl-2.0.html
*
* Please report all praise, requests, bugs and problems to the project
* team & admins: http://sourceforge.net/projects/retromessenger
*
* For the libretroshare library see the updates here:
* http://sourceforge.net/projects/retroshare/
*
* You can find us listed at our projectpage. New team members are welcome.
* Please keep in touch, if you use this code for other projects.
*
* Website:
*	   http://sourceforge.net/projects/retromessenger/
*      http://retromessenger.sf.net
*****************************************************************************/

#include "AppDataBase.h"
#include "FileVersion.h"

#include <wx/string.h>

ApplicationDataBase::ApplicationDataBase()
:
 m_majorVersion( 0 ),
 m_minorVersion( 0 ),
 m_buildVersion( 0 )
{
	m_exePath = GetExecutablePath();

	SetSettingsPath( m_exePath );
	SetResourcePath( m_exePath + wxT("res") + wxFILE_SEP_PATH );
	SetImagePath( m_exePath + wxT("res") + wxFILE_SEP_PATH + wxT("images") + wxFILE_SEP_PATH );
	SetSettingsFileName( wxFileName( GetSettingsPath() + wxT("settings.xml") ) );

	// Initialize position.
	SetPositionX( -1 );
	SetPositionY( -1 );
	SetSizeWidth( -1 );
	SetSizeHeight( -1 );
	SetIsIconized( false );
	SetIsMaximized( false );

	// Set the file version only if the settings file doesn't exist.
	if ( !GetSettingsFileName().FileExists() )
	{
		SetFileVersion();
	}
}

wxString ApplicationDataBase::GetExecutablePath()
{
    static bool found = false;
    static wxString path;

    if ( found )
	{
        return path;
	}
    else
    {
#ifdef __WXMSW__
        wxChar buf[MAX_PATH];
        buf[0] = wxT('\0');
		::GetModuleFileName( NULL, buf, MAX_PATH - 1 );
		wxFileName filename( buf );
        path = filename.GetPath( wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR );

#elif defined(__WXMAC__)
        ProcessInfoRec processinfo;
        ProcessSerialNumber procno ;
        FSSpec fsSpec;

        procno.highLongOfPSN = NULL ;
        procno.lowLongOfPSN = kCurrentProcess ;
        processinfo.processInfoLength = sizeof( ProcessInfoRec );
        processinfo.processName = NULL;
        processinfo.processAppSpec = &fsSpec;

        GetProcessInformation( &procno , &processinfo ) ;
        path = wxMacFSSpec2MacFilename( &fsSpec );
#else
        wxString argv0 = wxTheApp->argv[0];

        if ( wxIsAbsolutePath( argv0 ) )
		{
            path = argv0;
		}
        else
        {
            wxPathList pathlist;
            pathlist.AddEnvList( wxT("PATH") );
            path = pathlist.FindAbsoluteValidPath( argv0 );
        }

        wxFileName filename(path);
        filename.Normalize();
        path = filename.GetPath( wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR );
#endif
        found = true;

        return path;
    }
}

bool ApplicationDataBase::SaveToFile( const wxString& fileFullPath /*= wxEmptyString*/ )
{
	// Set the default path for the settings.
	//wxString fileName( GetSettingsPath() + wxT("settings.xml") );

	// Check to see if the default location for the settings should be used.
	if ( fileFullPath != wxEmptyString )
	{
		SetSettingsFileName( wxFileName( fileFullPath ) );
		//fileName = fileFullPath;
	}

	// Create the xml file.
	m_rootNode = new wxXmlNode( wxXML_ELEMENT_NODE, wxTheApp->GetAppName() + wxT("Config"), wxEmptyString );

	// Add the locations to the settings.
	m_appNode = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("app"), wxEmptyString );

	wxXmlNode* ver = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("version"), wxEmptyString );
	ver->AddProperty( wxT("major"), wxString::Format( wxT("%i"), GetMajorVersion() ) );
	ver->AddProperty( wxT("minor"), wxString::Format( wxT("%i"), GetMinorVersion() ) );
	ver->AddProperty( wxT("build"), wxString::Format( wxT("%i"), GetBuildNumber() ) );
	m_appNode->AddChild( ver );

	// Create the locations tree.
	m_directoriesNode = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("directories"), wxEmptyString );

	//Settings
	wxXmlNode* settingsPath = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("settings"), wxEmptyString );
	settingsPath->AddProperty( wxT("path"), GetSettingsPath() );
	m_directoriesNode->AddChild( settingsPath );
	//Resource
	wxXmlNode* resourcePath = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("resource"), wxEmptyString );
	resourcePath->AddProperty( wxT("path"), GetResourcePath() );
	m_directoriesNode->AddChild( resourcePath );
	//Image
	wxXmlNode* imagePath = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("image"), wxEmptyString );
	imagePath->AddProperty( wxT("path"), GetImagePath() );
	m_directoriesNode->AddChild( imagePath );

	m_appNode->AddChild( m_directoriesNode );
	
	// Create the forms node.
	m_formsNode = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("forms"), wxEmptyString );
	SavePosition( wxT("main") );

	m_appNode->AddChild( m_formsNode );
	
	m_rootNode->AddChild( m_appNode );

	// Set the root of the document.
	m_settingsDoc.SetRoot( m_rootNode );

	// Add the additional settings to the file, but first check to see if the xml is OK.
	if( m_settingsDoc.IsOk() )
	{
		SaveAdditional();
	}
	else
	{
		return false;
	}

	// Check to see if everything was added to the settings correctly.
	if( m_settingsDoc.IsOk() )
	{
		// Save the created doc.
		m_settingsDoc.Save( GetSettingsFileName().GetFullPath() );
		return true;
	}

	return false;
}

void ApplicationDataBase::SavePosition( const wxString& formName )
{
	wxXmlNode* form = new wxXmlNode( wxXML_ELEMENT_NODE, formName, wxEmptyString );
	form->AddProperty( wxT("pos_x"), wxString::Format( wxT("%i"), GetPositionX() ) );
	form->AddProperty( wxT("pos_y"), wxString::Format( wxT("%i"), GetPositionY() ) );
	form->AddProperty( wxT("size_w"), wxString::Format( wxT("%i"), GetSizeWidth() ) );
	form->AddProperty( wxT("size_h"), wxString::Format( wxT("%i"), GetSizeHeight() ) );
	form->AddProperty( wxT("is_iconized"), GetIsIconized() ? wxT("1") : wxT("0") );
	form->AddProperty( wxT("is_maximized"), GetIsMaximized() ? wxT("1") : wxT("0") );
	m_formsNode->AddChild( form );
}

bool ApplicationDataBase::LoadFromFile( const wxString& fileFullPath /*= wxEmptyString*/ )
{
	// Set the default path for the settings.
	//wxString fileName( GetSettingsPath() + wxT("settings.xml") );

	// Check to see if the default location for the settings should be used.
	if ( fileFullPath != wxEmptyString )
	{
		SetSettingsFileName( wxFileName( fileFullPath ) );
		//fileName = fileFullPath;
	}

	// Check to see if the settings file exists before loading it.
	if ( GetSettingsFileName().FileExists() )
	{
		// Load the file.
		if ( !m_settingsDoc.Load( GetSettingsFileName().GetFullPath() ) )
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	// Find the root node.
	m_rootNode = m_settingsDoc.GetRoot();

	wxXmlNode* child = m_rootNode->GetChildren();
	while ( child )
	{
		wxString nodeName = child->GetName();
		if ( 0 == nodeName.CmpNoCase( wxT("app") ) )
		{
			m_appNode = child;
			ProcessAppNode( m_appNode );
		}

		// Let the specific class have a chance to process the data.
		if ( !LoadAdditional( child ) )
		{
			return false;
		}

		child = child->GetNext();
	}

	return true;
}

void ApplicationDataBase::ProcessAppNode( const wxXmlNode* appNode )
{
	wxXmlNode* child = appNode->GetChildren();
	while ( child )
	{
		wxString nodeName = child->GetName();
		if ( 0 == nodeName.CmpNoCase( wxT("version") ) )
		{
			// Process properties of <version>.
			wxString ver;
			ver = child->GetPropVal( wxT("major"), wxString::Format( wxT("%i"), GetMajorVersion() ) );
			SetMajorVersion( ver );

			ver = child->GetPropVal( wxT("minor"), wxString::Format( wxT("%i"), GetMinorVersion() ) );
			SetMinorVersion( ver );

			ver = child->GetPropVal( wxT("build"), wxString::Format( wxT("%i"), GetBuildNumber() ) );
			SetBuildNumber( ver );
		}
		else if ( 0 == nodeName.CmpNoCase( wxT("directories") ) )
		{
			m_directoriesNode = child;
			ProcessDirectoriesNode( m_directoriesNode );
		}
		else if ( 0 == nodeName.CmpNoCase( wxT("forms") ) )
		{
			m_formsNode = child;
			ProcessFormsNode( m_formsNode );
		}

		child = child->GetNext();
	}
}

void ApplicationDataBase::ProcessDirectoriesNode( const wxXmlNode* dirNode )
{
	wxXmlNode* child = dirNode->GetChildren();
	while ( child )
	{
		wxString nodeName = child->GetName();
		if ( 0 == nodeName.CmpNoCase( wxT("settings") ) )
		{
			// Process properties of <settings>
			SetSettingsPath( child->GetPropVal( wxT("path"), GetSettingsPath() ) );
		}
		else if ( 0 == nodeName.CmpNoCase( wxT("resource") ) )
		{
			// Process properties of <resource>
			SetResourcePath( child->GetPropVal( wxT("path"), GetResourcePath() ) );
		}
		else if ( 0 == nodeName.CmpNoCase( wxT("image") ) )
		{
			// Process properties of <image>
			SetImagePath( child->GetPropVal( wxT("path"), GetImagePath() ) );
		}

		child = child->GetNext();
	}
}

void ApplicationDataBase::ProcessFormsNode( const wxXmlNode* formsNode )
{
	wxXmlNode* child = formsNode->GetChildren();
	while ( child )
	{
		wxString nodeName = child->GetName();
		if ( 0 == nodeName.CmpNoCase( wxT("main") ) )
		{
			// Process properties of <main>
			long location;
			( child->GetPropVal( wxT("pos_x"), wxString::Format( wxT("%i"), GetPositionX() ) ) ).ToLong( &location );
			SetPositionX( location );
			( child->GetPropVal( wxT("pos_y"), wxString::Format( wxT("%i"), GetPositionY() ) ) ).ToLong( &location );
			SetPositionY( location );
			( child->GetPropVal( wxT("size_w"), wxString::Format( wxT("%i"), GetSizeWidth() ) ) ).ToLong( &location );
			SetSizeWidth( location );
			( child->GetPropVal( wxT("size_h"), wxString::Format( wxT("%i"), GetSizeHeight() ) ) ).ToLong( &location );
			SetSizeHeight( location );

			wxString tmp = child->GetPropVal( wxT("is_iconized"), wxT("0") );
			if ( wxT("0") == tmp )
			{
				SetIsIconized( false );
			}
			else
			{
				SetIsIconized( true );
			}

			tmp = child->GetPropVal( wxT("is_maximized"), wxT("0") );
			if ( wxT("0") == tmp )
			{
				SetIsMaximized( false );
			}
			else
			{
				SetIsMaximized( true );
			}
		}

		child = child->GetNext();
	}
}

wxString ApplicationDataBase::GetSettingsPath()
{
	return m_settingPath;
}

void ApplicationDataBase::SetSettingsPath( const wxString& settingsPath )
{
	m_settingPath = settingsPath;
}

wxFileName ApplicationDataBase::GetSettingsFileName()
{
	return m_settingsFileName;
}

void ApplicationDataBase::SetSettingsFileName( const wxFileName& fileName )
{
	m_settingsFileName = fileName;
}

wxString ApplicationDataBase::GetImagePath()
{
	return m_imagesPath;
}

void ApplicationDataBase::SetImagePath( const wxString& imagesPath )
{
	m_imagesPath = imagesPath;
}

wxString ApplicationDataBase::GetResourcePath()
{
	return m_resourcePath;
}

void ApplicationDataBase::SetResourcePath( const wxString& resourcePath )
{
	m_resourcePath = resourcePath;
}

wxString ApplicationDataBase::GetExePath()
{
	return m_exePath;
}

wxXmlNode* ApplicationDataBase::GetRootNode()
{
	return m_rootNode;
}

wxXmlNode* ApplicationDataBase::GetDirectoriesNode()
{
	return m_directoriesNode;
}

wxXmlNode* ApplicationDataBase::GetFormsNode()
{
	return m_formsNode;
}

wxXmlNode* ApplicationDataBase::GetAppNode()
{
	return m_appNode;
}

int ApplicationDataBase::GetMajorVersion()
{
	return m_majorVersion;
}

void ApplicationDataBase::SetMajorVersion( const wxString& majorVersion )
{
	long ver;
	majorVersion.ToLong( &ver );
	m_majorVersion = (int)ver;
}

int ApplicationDataBase::GetMinorVersion()
{
	return m_minorVersion;
}

void ApplicationDataBase::SetMinorVersion( const wxString& minorVersion )
{
	long ver;
	minorVersion.ToLong( &ver );
	m_minorVersion = (int)ver;
}

int ApplicationDataBase::GetBuildNumber()
{
	return m_buildVersion;
}

void ApplicationDataBase::SetBuildNumber( const wxString& buildNum )
{
	long num;
	buildNum.ToLong( &num );
	m_buildVersion = (int)num;
}

wxString ApplicationDataBase::AddPathSeparator( const wxString& path )
{
	if ( !path.empty() )
	{
		if ( path.Last() == wxFILE_SEP_PATH )
		{
			return path;
		}
		else
		{
			wxString tmp = path;
			return tmp << wxFILE_SEP_PATH;
		}
	}
	else
	{
		return wxEmptyString;
	}
}

wxString ApplicationDataBase::GetVersionString( bool separateBuildNum /*= false*/ )
{
	wxString retVal = wxEmptyString;

	if ( true == separateBuildNum )
	{
		retVal = wxString::Format( wxT("%i.%i build %i"), GetMajorVersion(),
			GetMinorVersion(), GetBuildNumber() );
	}
	else
	{
		retVal = wxString::Format( wxT("%i.%i.%i"), GetMajorVersion(),
			GetMinorVersion(), GetBuildNumber() );
	}

	return retVal;
}

void ApplicationDataBase::SetFileVersion()
{
#ifdef __WXMSW__
	wxFileVersion ver;
	
	// Open the current executable's version information.
	ver.Open();
	
	// Get the file version.
	wxString fileVersion = ver.GetFixedFileVersion( true );

	// Parse the minor version out of the string.
	size_t firstDot = fileVersion.find( '.' ) + 1;
	size_t secondDot = fileVersion.find( '.', firstDot );
	wxString minorVer = fileVersion.Mid( firstDot, fileVersion.length() - secondDot );

	SetMajorVersion( fileVersion.BeforeFirst( '.' ) );
	SetMinorVersion( minorVer );
	SetBuildNumber( fileVersion.AfterLast( '.' ) );
#else
	SetMajorVersion( wxT("0") );
	SetMinorVersion( wxT("10") );
	SetBuildNumber( wxT("02") );
#endif
}

void ApplicationDataBase::SetPositionX( int x )
{
	m_posX = x;
}

int ApplicationDataBase::GetPositionX()
{
	return m_posX;
}

void ApplicationDataBase::SetPositionY( int y )
{
	m_posY = y;
}

int ApplicationDataBase::GetPositionY()
{
	return m_posY;
}

void ApplicationDataBase::SetSizeWidth( int w )
{
	m_sizeW = w;
}

int ApplicationDataBase::GetSizeWidth()
{
	return m_sizeW;
}

void ApplicationDataBase::SetSizeHeight( int h )
{
	m_sizeH = h;
}

int ApplicationDataBase::GetSizeHeight()
{
	return m_sizeH;
}

void ApplicationDataBase::SetIsIconized( bool iconized )
{
	m_isIconized = iconized;
}

bool ApplicationDataBase::GetIsIconized()
{
	return m_isIconized;
}

void ApplicationDataBase::SetIsMaximized( bool maximized )
{
	m_isMaximized = maximized;
}

bool ApplicationDataBase::GetIsMaximized()
{
	return m_isMaximized;
}
