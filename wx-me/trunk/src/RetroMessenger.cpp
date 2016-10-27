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

#include "RetroMessenger.h"
#include "RetroMessengerMainFrame.h"
#include "AppData.h"

// RetroShare
#include <rsiface/rsinit.h>

#include <openssl/ssl.h>

// wxWidgets
#include <wx/clipbrd.h>

IMPLEMENT_APP( MyApp );

bool MyApp::OnInit()
{
	// Initialize all image handlers.
	wxInitAllImageHandlers();
	
	// Initialize application data.
	m_globalData = std::auto_ptr< ApplicationDataBase >(AppData);

	// Load the saved settings.
	AppData->LoadFromFile();
	
	// Initialize OpenSSL libraries.
	SSL_load_error_strings();
	SSL_library_init();

	int rsArgc = wxTheApp->argc;
	std::vector< std::vector< char > > buffer;
	std::vector< char* > ptrs = wxCharPtrPtrToCharPtrPtr( wxTheApp->argv, rsArgc,  buffer );
	char** rsArgv = &ptrs[0];
	
	RsInit::SetBasedir(".");	

	// Initialize RsConfig
	RsInit::InitRsConfig();
	
	// Initialize RetroShare
	RsInit::InitRetroShare( rsArgc, rsArgv );
	
	// Make a main frame so we can add the friends.
	RetroMessengerMainFrame* frame = new RetroMessengerMainFrame();
	AppData->SetMainFrame( frame );
	SetTopWindow( frame );
	frame->Show();

	return true;
}

int MyApp::OnExit()
{
	AppData->SaveToFile();
	
	if( !wxTheClipboard->IsOpened() )
	{
        if ( !wxTheClipboard->Open() )
        {
            return wxApp::OnExit();
        }
	}

    // Allow clipboard data to persist after close
    wxTheClipboard->Flush();
    wxTheClipboard->Close();
	
	return wxApp::OnExit();
}

std::vector< char* > MyApp::wxCharPtrPtrToCharPtrPtr( wxChar** wxCharArray, int size, std::vector< std::vector< char > >& buffer )
{
	std::vector< char* > ptrs;

	// Clear the buffer.
	buffer.clear();

	for ( int i = 0; i < size; ++i )
	{
		// Create a wxString for the conversion to ASCII.
		wxString wxTmp( wxCharArray[i] );
		// Put the ASCII characters into a string to hold them long enough to push them into the buffer.
		std::string cTmp( wxTmp.ToAscii() );
		// Use a vector to make sure the memory will be contigious. Like the char** expects.
		std::vector< char > arg( cTmp.begin(), cTmp.end() );
		// Add the NULL char.
		arg.push_back( '\0' );
		// Push it into the vector passed into the function so that they are not destroyed after the function exits.
		buffer.push_back( arg );
		// Add it to the vector of pointers to the locations in the buffer vector.
		ptrs.push_back( &( buffer[i] )[0] );
	}

	return ptrs;
}
