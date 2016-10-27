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

#include "RetroMessengerChatPage.h"
#include "AppData.h"

//#include <cstdlib>


// wxWidgets
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/help.h>
#include <wx/html/htmlpars.h>
//retroshare
#include <rsiface/rsmsgs.h>
#include <rsserver/p3msgs.h>
#include <rsiface/rspeers.h>

RetroMessengerChatPage::RetroMessengerChatPage( wxWindow* parent )
	:
ChatPage( parent )
{
}

void RetroMessengerChatPage::OnUrlClicked( wxTextUrlEvent& event )
{
	// Get URL from control.
	wxString url = m_chatLogTextCtrl->ToText().substr( event.GetURLStart(), event.GetURLEnd() );
	// Debug a bit
	wxMessageBox( wxT( "URL: " ) + url );
	// Launch the default browser
	wxLaunchDefaultBrowser( url );
}

void RetroMessengerChatPage::OnMessageUpdated( wxCommandEvent& /*event*/ )
{
	// TODO: Implement OnMessageUpdatedRsMsgs *personalchat;

	if ( !rsMsgs->chatAvailable() )
	{
		//wxMessageBox( wxT("Error: Chat is not availbale"));
		return;
	}

	std::list<ChatInfo> newchat;
	if ( !rsMsgs->getNewChat( newchat ) )
	{
		//wxMessageBox( wxT("Error: Incorrect chatinfo, can not get new sent"));
		return;
	}

	std::list<ChatInfo>::iterator it;
	for ( it = newchat.begin(); it != newchat.end(); it++ )
	{
		std::string msg( it->msg.begin(), it->msg.end() );

		// are they private
		if ( it->chatflags )
		{
		//get the chat for current selected friend
		if ( it->rsid == AppData->GetMainFrame()->GetRsId() )
		  {
			//newchat.pop_back();
			wxString recievemessage((it->msg).c_str(), wxConvUTF8);
			recievemessage = recievemessage + wxT( '\n' );
                        
			//write on chat log window
		 	m_chatLogTextCtrl->AppendToPage(recievemessage);
			m_chatLogTextCtrl->Scroll(-1, 50);
		  }
			continue;
		}

	}


}

void RetroMessengerChatPage::OnSendClicked( wxCommandEvent& )
{
	//Get the message contents
	wxString wx_msg = m_messageTextCtrl->GetValue() + wxT( '\n' );

	//sending chat to friend
	RsPeerDetails  detail;
	ChatInfo ci;

	ci.rsid = AppData->GetMainFrame()->GetRsId();
	ci.chatflags = 0x0002;
	ci.name = rsPeers->getPeerName( ci.rsid );
	ci.msg = std::wstring( wx_msg.c_str() );
	std::string msg( ci.msg.begin(), ci.msg.end() );

	if ( rsMsgs->ChatSend( ci ) )
	{
		//write on chat log window
		m_chatLogTextCtrl->AppendToPage(wx_msg);
		m_chatLogTextCtrl->Scroll(-1, 50);
		m_messageTextCtrl->Clear();
	}
	else
	{
		//error message on chat log (i.e.User is offline);
		wxMessageBox( wxT( "Error: Incorrect chatinfo, Chat can not be sent" ) );
	}
}
