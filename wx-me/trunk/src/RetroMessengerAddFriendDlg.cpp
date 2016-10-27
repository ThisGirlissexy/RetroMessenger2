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

#include "RetroMessengerAddFriendDlg.h"
#include "RetroMessenger_GUI.h"
#include "RetroMessengerChatPage.h"
#include "RetroMessengerMainFrame.h"
#include "AppData.h"

// RetroShare
#include <rsserver/p3peers.h>
#include <rsiface/rsiface.h>
#include <rsiface/rspeers.h>
//#include <rsserver/p3face-startup.cc>
// wxWidgets
#include <wx/msgdlg.h>
#include <wx/filedlg.h>

RetroMessengerAddFriendDlg::RetroMessengerAddFriendDlg( wxWindow* parent )
	:
AddFriendDlg( parent )
{
}

void RetroMessengerAddFriendDlg::OnOK( wxCommandEvent& /*event*/ )
{
	//Get the Certificate in string
	const wxString wxCertString = m_friendCertTextCtrl->GetValue();
	std::string Certstring( wxCertString.ToAscii() );

	// get the peer id and username
	std::string id;// = rsPeers->getOwnId();
	std::string code;

	//add friend to retroshare
	if ( rsPeers->LoadCertificateFromString( Certstring, id ) )// && rsPeers->addFriend(id))
	{
		if ( rsPeers->AuthCertificate( id, code ) )
		{
			//add friend to Frame friend list
			std::string username = rsPeers->getPeerName( id );
			AppData->GetMainFrame()->AddFriend( username, id, 0x1 );
			AppData->GetMainFrame()->Show();
			EndModal( wxID_OK );
		}
		else
		{
			//error messege
			wxString wxid( id.c_str(), wxConvUTF8 );
			wxMessageBox( wxT( "Error occured while adding friend.because of invalid id = " ) + wxid ); //wxT("Error occured while adding friend.") );
			EndModal( wxID_CANCEL );
		}
	}
	else
	{
		//error messege
		wxMessageBox( wxT( "Error occured while loading certificate" ) );
		EndModal( wxID_CANCEL );
	}

}

void RetroMessengerAddFriendDlg::OnCancel( wxCommandEvent& /*event*/ )
{
	EndModal( wxID_CANCEL );
}

void RetroMessengerAddFriendDlg::OnLoadFromFile( wxCommandEvent& /*event*/ )
{
	wxString fileName = wxFileSelector( wxT( "Choose a friends certificate to open" ), wxEmptyString, wxEmptyString, wxT( "Certificates (*.pem,*.pqi)|*.pem;*.pqi|Text files(*.txt)|*.txt|All files (*.*)|*.*" )  );
	if ( !fileName.empty() )
	{
		// Load the file.
		m_friendCertTextCtrl->LoadFile( fileName );
	}
}
