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

#include <string>
#include "AppData.h"
#include <wx/app.h>

#include <rsiface/rsiface.h>
#include <rsiface/rsinit.h>

static ApplicationData* s_instance = 0;	//**< Main instance of this static class. */

ApplicationData* ApplicationData::Get()
{
    if ( !s_instance )
    {
        s_instance = new ApplicationData();
    }

    return s_instance;
}

ApplicationData::ApplicationData()
{
	// Set all preferences to the default values.
	SetUserName( wxEmptyString );
	SetShouldAutoLogIn( false );
	SetIsCertificateGenerated( false );
}

ApplicationData::~ApplicationData()
{
}

void ApplicationData::SaveAdditional()
{
	wxXmlNode* userConfig = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("UserConfig"), wxEmptyString );
	userConfig->AddProperty( wxT("UserName"), GetUserName() );
	userConfig->AddProperty( wxT("AutoLogin"), wxString::Format( wxT("%i"), GetShouldAutoLogIn() ? 1 : 0 ) );
	GetAppNode()->AddChild( userConfig );
	
	wxXmlNode* certificateConfig = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("CertificateConfig"), wxEmptyString );
	certificateConfig->AddProperty( wxT("IsGenerated"), wxString::Format( wxT("%i"), GetIsCertificateGenerated() ? 1 : 0 ) );
	GetAppNode()->AddChild( certificateConfig );
}

bool ApplicationData::LoadAdditional( const wxXmlNode* node )
{
	wxXmlNode* child = node->GetChildren();
	
	while ( child )
	{
		wxString nodeName = child->GetName();
		if ( 0 == nodeName.CmpNoCase( wxT("UserConfig") ) )
		{
			// Process properties of <UserConfig>.
			SetUserName( child->GetPropVal( wxT("UserName"), GetUserName() ) );
			
			wxString autoLoginConfig;
			autoLoginConfig = child->GetPropVal( wxT("AutoLogin"), wxString::Format( wxT("%i"), GetShouldAutoLogIn() ? 1 : 0 ) );
			long aLogin;
			autoLoginConfig.ToLong( &aLogin );
			SetShouldAutoLogIn( aLogin != 0 );
		}
		else if ( 0 == nodeName.CmpNoCase( wxT("CertificateConfig") ) )
		{
			// Process properties of <CertificateConfig>.
			wxString certConfig;
			certConfig = child->GetPropVal( wxT("IsGenerated"), wxString::Format( wxT("%i"), GetIsCertificateGenerated() ? 1 : 0 ) );
			long generated;
			certConfig.ToLong( &generated );
			SetIsCertificateGenerated( generated != 0 );
		}
		child = child->GetNext();
	}

	return true;
}

void ApplicationData::Destroy()
{
	if ( s_instance )
	{
		delete s_instance;
	}

	s_instance = NULL;
}
