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
#include "RetroMessengerLinkCloudDlg.h"

//#include "RetroMessenger_GUI.h"

#include "RetroMessengerMessageSentDlg.h"


// wxWidgets
#include <wx/msgdlg.h>
#include <wx/clipbrd.h>
#include <wx/dataobj.h>

#ifdef WINDOWS_SYS
	#include <winsock2.h>
#else
	#include <wx/socket.h>
#endif

#include <wx/string.h>

//Retroshare
#include <services/p3ranking.h>
#include <serialiser/rsrankitems.h>
RetroMessengerLinkCloudDlg::RetroMessengerLinkCloudDlg( wxWindow* parent )
		:
		LinkCloudDlg( parent )
{
	// Add some dummy links to show to test operations.

}

void RetroMessengerLinkCloudDlg::OnLinksClicked( wxCommandEvent&  )
{
	// Clear the details.
	m_linkTitleTextCtrl->Clear();
	m_urlTextCtrl->Clear();
	m_commentTextCtrl->Clear();

	// Disable the 'Copy Link' button.
	m_copyLinkButton->Disable();
}

void RetroMessengerLinkCloudDlg::OnLinksDoubleClicked( wxCommandEvent& )
{
	wxString selection = m_linksListBox->GetStringSelection();

	// Fill in the details using the selection.
	//
	// Parse the string into the parts.
	wxString user = selection.BeforeFirst( wxT( '|' ) );
	wxString rest = selection.AfterFirst( wxT( '|' ) );
	wxString title = rest.BeforeFirst( wxT( '|' ) );
	rest = rest.AfterFirst( wxT( '|' ) );
	wxString url = rest.BeforeFirst( wxT( '|' ) );
	wxString comment = rest.AfterFirst( wxT( '|' ) );

	if ( user == wxT( "anon" ) )
	{
		m_submitAnonymousCheckBox->SetValue( true );
	}

	m_linkTitleTextCtrl->SetValue( title );
	m_urlTextCtrl->SetValue( url );
	m_commentTextCtrl->SetValue( comment );

	// Enable 'Copy Link' button.
	m_copyLinkButton->Enable();
}

void RetroMessengerLinkCloudDlg::OnRatingSelected( wxCommandEvent& )
{
	// TODO: I am not sure if we will need this event.
}

void RetroMessengerLinkCloudDlg::OnRateClicked( wxCommandEvent& /*event*/ )
{

	if ( !( m_linksListBox->IsEmpty() ) ) // && !(event.IsSelection()))
	{
		//link selection
		wxString selection = m_linksListBox->GetStringSelection();
		int index_item = m_linksListBox->GetSelection();
		//choice selection
		size_t choice = m_ratingChoice->GetCurrentSelection();
		wxString label = m_ratingChoice->GetString( choice );

		wxString old_label = selection.BeforeFirst( wxT( '|' ) );//old rated label string
		size_t old_label_length = old_label.Len();//length of old label string

		wxString mystring( wxT( "Fred" ), wxConvUTF8 );

		//  if(old_label==mystring)
		//{
		//remove old label
		selection.Remove ( 0, old_label_length + 1 );
		//}
		selection = label + wxT( "|" ) + selection;

		//rate the link
		m_linksListBox->Delete( index_item );
		m_linksListBox->Insert( selection, index_item );
	}
}

void RetroMessengerLinkCloudDlg::OnRecieveLinkCloud(wxCommandEvent&)
{
       
}

void RetroMessengerLinkCloudDlg::OnSendToFriendsClicked( wxCommandEvent& /*event*/ )
{
	// TODO: Implement OnSendToFriendsClicked

	wxString title = m_linkTitleTextCtrl->GetValue();
	wxString link = m_urlTextCtrl->GetValue();
	wxString comment = m_commentTextCtrl->GetValue();

	p3Ranking *addlink;
	RsRankLinkMsg *msg;

	//here we need a for loop for sending link-cloud to all the friends in list
	{
	//msg->PeerId(mOwnId);
	//msg->pid = mOwnId;
	//msg->rid = "0001";

    msg->title = title;
	msg->link = link;
	msg->comment = comment;
	msg->score = 1;
	}
	addlink->addRankMsg( msg );

	RetroMessengerMessageSentDlg* msgDlg = new RetroMessengerMessageSentDlg( this );
	msgDlg->ShowModal();
	
	//  void p3Ranking::addRankMsg(RsRankLinkMsg *msg)
}

void RetroMessengerLinkCloudDlg::OnCopyLinkClicked( wxCommandEvent& )
{
	// Check if there is any text.
	if ( !m_urlTextCtrl->IsEmpty() )
	{
		// Get the value in the URL textbox.
		wxString url = m_urlTextCtrl->GetValue();

		// Copy it to the clipboard.
		if ( wxTheClipboard->Open() )
		{
			// This data objects are held by the clipboard,
			// so do not delete them in the app.
			wxTheClipboard->SetData( new wxTextDataObject( url ) );
			wxTheClipboard->Close();
		}
	}
}

void RetroMessengerLinkCloudDlg::OnAddLinkClicked( wxCommandEvent& )
{
	// Get the deatils and append them to a single string.
	wxString link;
	if ( m_submitAnonymousCheckBox->GetValue() )
	{
		link += wxT( "anon|" );
	}
	else
	{
		// TODO: get the currently logged in username.
		link += wxT( "Fred|" );
	}

	link += m_linkTitleTextCtrl->GetValue() + wxT( "|" );
	link += m_urlTextCtrl->GetValue() + wxT( "|" );
	link += m_commentTextCtrl->GetValue();

	// Add the link to the links list.
	m_linksListBox->AppendAndEnsureVisible( link );
}
