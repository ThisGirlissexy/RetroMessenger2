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

#include "RetroMessengerPopUpPersonalChat.h"

#include <wx/string.h>
#include <wx/help.h>


RetroMessengerPopUpPersonalChat::RetroMessengerPopUpPersonalChat( wxWindow* parent )
:
PopUpPersonalChat( parent )
{

}

void RetroMessengerPopUpPersonalChat::OnMessageUpdated( wxCommandEvent& event )
{
	// TODO: Implement OnMessageUpdated
}

void RetroMessengerPopUpPersonalChat::OnSendClicked( wxCommandEvent& event )
{

	      //Get the message contents
			 wxString message= m_messageTextCtrl->GetValue();
		     message=message + wxT('\n');
		  //write on chat log window  
			m_chatLogTextCtrl->WriteText((const wxString &)message); 
		    m_messageTextCtrl->Clear();

}
