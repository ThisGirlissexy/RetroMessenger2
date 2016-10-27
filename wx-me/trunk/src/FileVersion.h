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

#ifndef __FILEVERSION_H_
#define __FILEVERSION_H_

#include <wx/wx.h>

#ifdef __WXMSW__

class wxFileVersion
{
public:
	wxFileVersion();
	~wxFileVersion();

	bool    Open( wxString strModuleName = wxEmptyString );
	void    Close();

	wxString QueryValue( wxString strValueName, unsigned long dwLangCharset = 0 );

	wxString GetFileDescription()  { return QueryValue( wxT("FileDescription") );  };
	wxString GetFileVersion()      { return QueryValue( wxT("FileVersion") );      };
	wxString GetInternalName()     { return QueryValue( wxT("InternalName") );     };
	wxString GetCompanyName()      { return QueryValue( wxT("CompanyName") );      };
	wxString GetLegalCopyright()   { return QueryValue( wxT("LegalCopyright") );   };
	wxString GetOriginalFilename() { return QueryValue( wxT("OriginalFilename") ); };
	wxString GetProductName()      { return QueryValue( wxT("ProductName") );      };
	wxString GetProductVersion()   { return QueryValue( wxT("ProductVersion") );   };

	bool     GetFixedInfo( VS_FIXEDFILEINFO& vsffi );
	wxString GetFixedFileVersion( bool HumanlyReadable = false );
	wxString GetFixedProductVersion( bool HumanlyReadable = false );

protected:
	unsigned char*  m_lpVersionData;
	unsigned long   m_dwLangCharset;
};

#endif //__WXMSW__
#endif  // __FILEVERSION_H_
