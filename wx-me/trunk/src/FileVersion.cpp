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

#include "FileVersion.h"

#ifdef __WXMSW__

wxFileVersion::wxFileVersion()
{
	m_lpVersionData = NULL;
	m_dwLangCharset = 0;
}

wxFileVersion::~wxFileVersion()
{
	Close();
}

void wxFileVersion::Close()
{
	delete[] m_lpVersionData;
	m_lpVersionData = NULL;
	m_dwLangCharset = 0;
}

bool wxFileVersion::Open( wxString strModuleName )
{
	if ( strModuleName.IsEmpty() )
	{
		wxChar szExeName[MAX_PATH];
		::GetModuleFileName( NULL, szExeName, sizeof( szExeName ) );
		strModuleName = szExeName;
	}

	wxASSERT( !strModuleName.IsEmpty() );
	wxASSERT( m_lpVersionData == NULL );

	unsigned long dwHandle;
	unsigned long dwDataSize = ::GetFileVersionInfoSize( (WCHAR*)strModuleName.c_str(), &dwHandle );
	if ( dwDataSize == 0 )
	{
		return false;
	}

	m_lpVersionData = new unsigned char[dwDataSize];
	if ( !::GetFileVersionInfo( (WCHAR*)strModuleName.c_str(), dwHandle, dwDataSize,
		(void**)m_lpVersionData ) )
	{
		Close();
		return false;
	}

	unsigned int nQuerySize;
	unsigned long* pTransTable;
	if ( !::VerQueryValue(m_lpVersionData, wxT("\\VarFileInfo\\Translation"),
		(void **)&pTransTable, &nQuerySize ) )
	{
		Close();
		return false;
	}

	m_dwLangCharset = MAKELONG( HIWORD( pTransTable[0] ), LOWORD( pTransTable[0] ) );

	return true;
}

wxString wxFileVersion::QueryValue( wxString strValueName, unsigned long dwLangCharset /* = 0*/ )
{
	wxASSERT( m_lpVersionData != NULL );
	if ( m_lpVersionData == NULL )
	{
		return wxEmptyString;
	}

	if ( dwLangCharset == 0 )
	{
		dwLangCharset = m_dwLangCharset;
	}

	unsigned int nQuerySize;
	void* lpData;
	wxString strValue, strBlockName;
	strBlockName = wxString::Format( wxT("\\StringFileInfo\\%08lx\\%s"), dwLangCharset, strValueName.c_str() );

	if ( ::VerQueryValue( (void **)m_lpVersionData, (wxChar*)strBlockName.c_str(),
		&lpData, &nQuerySize ) )
	{
		strValue = wxString::FromAscii( (char*)lpData );
	}

	return strValue;
}

bool wxFileVersion::GetFixedInfo( VS_FIXEDFILEINFO& vsffi )
{
	wxASSERT( m_lpVersionData != NULL );
	if ( m_lpVersionData == NULL )
	{
		return false;
	}

	unsigned int nQuerySize;
	VS_FIXEDFILEINFO* pVsffi;
	if ( ::VerQueryValue( (void **)m_lpVersionData, wxT("\\"),
		(void**)&pVsffi, &nQuerySize ) )
	{
		vsffi = *pVsffi;
		return true;
	}

	return false;
}

wxString wxFileVersion::GetFixedFileVersion( bool HumanlyReadable /*= false */ )
{
	wxString strVersion;
	VS_FIXEDFILEINFO vsffi;

	if ( GetFixedInfo( vsffi ) )
	{
		if ( HumanlyReadable )
		{
			strVersion = wxString::Format ( wxT("%u.%u%u.%u"), HIWORD( vsffi.dwFileVersionMS ),
				LOWORD( vsffi.dwFileVersionMS ),
				HIWORD( vsffi.dwFileVersionLS ),
				LOWORD( vsffi.dwFileVersionLS ) );
		}
		else
		{
			strVersion = wxString::Format ( wxT("%u,%u,%u,%u"), HIWORD( vsffi.dwFileVersionMS ),
				LOWORD( vsffi.dwFileVersionMS ),
				HIWORD( vsffi.dwFileVersionLS ),
				LOWORD( vsffi.dwFileVersionLS ) );
		}
	}

	return strVersion;
}

wxString wxFileVersion::GetFixedProductVersion( bool HumanlyReadable /*= false */ )
{
	wxString strVersion;
	VS_FIXEDFILEINFO vsffi;

	if ( GetFixedInfo(vsffi) )
	{
		if ( HumanlyReadable )
		{
			strVersion = wxString::Format ( wxT("%u.%u%u.%u"), HIWORD( vsffi.dwProductVersionMS ),
				LOWORD( vsffi.dwProductVersionMS ),
				HIWORD( vsffi.dwProductVersionLS ),
				LOWORD( vsffi.dwProductVersionLS ) );
		}
		else
		{
			strVersion = wxString::Format ( wxT("%u,%u,%u,%u"), HIWORD( vsffi.dwProductVersionMS ),
				LOWORD( vsffi.dwProductVersionMS ),
				HIWORD( vsffi.dwProductVersionLS ),
				LOWORD( vsffi.dwProductVersionLS ) );
		}
	}

	return strVersion;
}

#endif //__WXMSW__
