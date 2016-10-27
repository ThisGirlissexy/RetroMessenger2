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

#include "RetroMessengerMainFrame.h"
#include "RetroMessengerLinkCloudDlg.h"
#include "RetroMessengerCertificateDlg.h"
#include "RetroMessengerCertDlg.h"
#include "RetroMessengerChatPage.h"
#include "RetroMessengerAbout.h"
#include "RetroMessengerAddFriendDlg.h"
#include "RetroMessengerLoginDlg.h"
#include "AppData.h"

// wxWidgets
#include <wx/treebook.h>
#include <wx/treectrl.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>

// RetroShare
#include <rsiface/rsiface.h>
#include <rsiface/rspeers.h>
#include <rsiface/rsinit.h>

#include <cstdlib>
#include <sstream>
#include <iomanip>

BEGIN_EVENT_TABLE(RetroMessengerMainFrame,MainFrame)
  EVT_TIMER(-1,RetroMessengerMainFrame::OnTimerEvent)
END_EVENT_TABLE()

class RmItemData : public wxTreeItemData
{
public:
	RmItemData( const std::string& id, const std::string& username )
		:
	m_rsId( id )
	{
	}
	
	inline void SetRsId( const std::string& id )
	{
		m_rsId = id;
	}
	
	inline std::string GetRsId()
	{
		return m_rsId;
	}
	
	inline void SetUserName( const std::string& username )
	{
		m_username = username;
	}
	
	inline std::string GetUserName()
	{
		return m_username;
	}
	
private:
	std::string m_rsId;
	std::string m_username;
};

RetroMessengerMainFrame::RetroMessengerMainFrame( wxWindow *parent, int id )
	: MainFrame( parent, id ), m_timer(this)
{
#ifdef __WXMSW__
	SetIcon( wxICON( amain ) );
#else
	#include "images/starlogo.xpm"
	SetIcon( wxICON( starlogo ) );
#endif

	std::string preferedId;
	RsInit::getPreferedAccountId(preferedId);	
	AppData->SetPreferedId(preferedId);
	
	// Add dummy friends.
	AddFriend( "DummyBob", "", 0x1 );
	AddFriend( "DummyEve", "", 0x1 );
	
	AppData->SetIsUserLoggedIn(false);
	
	// Restore the previous state.
	RestorePosition();
	if ( AppData->GetIsCertificateGenerated() )
	{
		RetroMessengerLoginDlg login;
		if ( login.ShowModal() == wxID_OK )
		{
			AppData->SetIsUserLoggedIn(true);
			fileLogin->Enable( false );
		}
		else
		{
			AppData->SetIsUserLoggedIn(false);
			fileLogin->Enable( true );
		}
	}
	else 
	{
		RetroMessengerCertificateDlg certificate;
		if(certificate.ShowModal() == wxID_OK)
		{
			AppData->SaveToFile();
			
			RetroMessengerLoginDlg login;
			if ( login.ShowModal() == wxID_OK )
			{
				AppData->SetIsUserLoggedIn(true);
				fileLogin->Enable( false );
			}
			else
				this->Destroy();
		}
	}
	
	if(AppData->GetIsUserLoggedIn() == true)
		m_statusBar1->SetStatusText(wxT("Logged in as : ")+AppData->GetUserName(),0);		
	else
		m_statusBar1->SetStatusText(wxT("No user logged in!"),0);	
		
	m_timer.Start(1000);
}

void RetroMessengerMainFrame::OnTimerEvent(wxTimerEvent &event)
{
	if(m_statusBar1)
	{
		this->GetPeerStatus();
	}
}

void RetroMessengerMainFrame::GetPeerStatus()
{
	/* set users/friends/network */

    std::list<std::string> ids;
    rsPeers->getOnlineList(ids);
    int online = ids.size();

    ids.clear();
    rsPeers->getFriendList(ids);
    int friends = ids.size();

    ids.clear();
    rsPeers->getOthersList(ids);
    int others = 1 + ids.size();

    std::ostringstream out2;
    out2 << 
	"Online:" <<
	online << " | " 
	<< "Friends:"
	<< friends << " | " << "Network:"
	 << others << " ";
	
	std::string s(out2.str());
	wxString xs(s.c_str(),wxConvUTF8);
	
	m_statusBar1->SetStatusText(xs,1);	
}


void RetroMessengerMainFrame::RestorePosition()
{
	Maximize( AppData->GetIsMaximized() );
	SetSize( AppData->GetPositionX(), AppData->GetPositionY(),
	AppData->GetSizeWidth(), AppData->GetSizeHeight() );
	Iconize( AppData->GetIsIconized() );
}

void RetroMessengerMainFrame::SavePosition()
{
	if ( !( IsMaximized() || IsIconized() ) )
	{
		AppData->SetPositionX( GetPosition().x );
		AppData->SetPositionY( GetPosition().y );
		AppData->SetSizeWidth( GetSize().GetWidth() );
		AppData->SetSizeHeight( GetSize().GetHeight() );
	}

	AppData->SetIsIconized( IsIconized() );
	AppData->SetIsMaximized( IsMaximized() );
}

void RetroMessengerMainFrame::AddFriend( const std::string& userName, std::string rsid, uint32_t userState /*= 0*/ )
{
	// Add a friend page to the treebook.
	RetroMessengerChatPage* newFriend = new RetroMessengerChatPage( this );
	m_mainTreebook->AddPage( newFriend, wxString::FromAscii( userName.c_str() ), true );
	
	// Get the tree control so I can add the tree item data to it.
	wxTreeCtrl* tree = m_mainTreebook->GetTreeCtrl();
	
	// Get the current selection.
	wxTreeItemId currentSelection = tree->GetSelection();
	if ( currentSelection != wxNOT_FOUND )
	{
		// Pack the id into a RmItemData class.
		tree->SetItemData( currentSelection, new RmItemData( rsid, userName ) );
	}
}

std::string RetroMessengerMainFrame::GetRsId()
{
	// Get the tree control so I can add the tree item data to it.
	wxTreeCtrl* tree = m_mainTreebook->GetTreeCtrl();
	
	// Get the current selection.
	wxTreeItemId currentSelection = tree->GetSelection();
	if ( currentSelection != wxNOT_FOUND )
	{
		// Pack the id into a RmItemData class.
		RmItemData* rmItemData = ( RmItemData* )tree->GetItemData( currentSelection );
		return rmItemData->GetRsId();
	}
	
	return std::string();
}

void RetroMessengerMainFrame::OnDisplayOwnCert( wxCommandEvent& /*event*/ )
{
	//const std::string loadCert = RsInit::GetLoadCert();
	
	std::string loadCert = RsInit::GetBasedir()+RsInit::GetDirSeparator() \
			+AppData->GetPreferedId()+RsInit::GetDirSeparator()+"keys"+RsInit::GetDirSeparator()+"user_cert.pem";

	// No errors so then display the certificate.
	RetroMessengerCertDlg* rxCert = new RetroMessengerCertDlg( this );
	rxCert->DisplayCertificate( loadCert );
	rxCert->Show();
}

void RetroMessengerMainFrame::OnCopyOwnCert( wxCommandEvent& event )
{
	// TODO: Implement OnCopyOwnCertTxt()
}

void RetroMessengerMainFrame::OnExit( wxCommandEvent& /*event*/ )
{
	Close();
}

void RetroMessengerMainFrame::OnLogin( wxCommandEvent& /*event*/ )
{
	RetroMessengerLoginDlg LoginDlg( this );
	if(LoginDlg.ShowModal() == wxID_OK)	
		fileLogin->Enable( !fileLogin->IsEnabled() );
	
	if(AppData->GetIsUserLoggedIn() == true)
		m_statusBar1->SetStatusText(wxT("Logged in as : ")+AppData->GetUserName(),0);		
	else
		m_statusBar1->SetStatusText(wxT("No user logged in!"),0);
}

void RetroMessengerMainFrame::OnEditCut( wxCommandEvent& event )
{
	// TODO: Implement OnEditCut
}

void RetroMessengerMainFrame::OnEditCopy( wxCommandEvent& event )
{
	// TODO: Implement OnEditCopy
}

void RetroMessengerMainFrame::OnEditPaste( wxCommandEvent& event )
{
	// TODO: Implement OnEditPaste
}

void RetroMessengerMainFrame::OnAddFriendCertTxt( wxCommandEvent& /*event*/ )
{
	RetroMessengerAddFriendDlg addFriend( this );
	addFriend.ShowModal();
}

void RetroMessengerMainFrame::OnAddFriendCertFile( wxCommandEvent& /*event*/ )
{
	RetroMessengerAddFriendDlg addFriend( this );
	addFriend.ShowModal();
}

void RetroMessengerMainFrame::OnLinkCloud( wxCommandEvent& /*event*/ )
{
	RetroMessengerLinkCloudDlg linkCloudDlg( this );
	linkCloudDlg.ShowModal();
}

void RetroMessengerMainFrame::OnWebSearch( wxCommandEvent& /*event*/ )
{
	// Display the ask for input dialog.
	wxString keyword = wxGetTextFromUser( _("Enter your yacy search term and press <Enter>") );
	
	if(keyword != _T(""))
	{		
		wxString url = wxT("http://141.52.175.50:8080/yacysearch.html?display=2&search=");
		url += keyword;
		
		// Launch the default browser
		if ( !wxLaunchDefaultBrowser( url ) )
		{
			wxMessageBox( wxT("Couldn't launch the default browser.\nMake sure your system is setup properly."), wxT("Error Occured") );
		}
	}
}

void RetroMessengerMainFrame::OnNetworkStatus( wxCommandEvent& /*event*/ )
{
	std::ostringstream out2;	
	
	//DHT Status
	
	rsiface->lockData(); /* Lock Interface */

    /* now the extra bit .... switch on check boxes */
    const RsConfig &config = rsiface->getConfig();

    if (config.netDhtOk)
    {
    out2<<"DHT OK\n\n";		
		}
		else
		{
   out2<<"DHT DOWN\n\n";		
		}
		
	rsiface->unlockData(); /* UnLock Interface */
	
	
	//NAT Status
	
	rsiface->lockData(); /* Lock Interface */

	if(config.netUpnpOk)
    {
      out2<<"NAT : UPNP IS ACTIVE\n\n";
    }
    else
    {    
      out2<<"NAT : UPNP NOT FOUND\n\n";
    }   
    
    if(config.netExtOk)
    {
      out2<<"NAT : Stable External IP Address\n\n";
    }
    else
    {
     out2<<"NAT : Not Found External Address\n\n";
    }
    
    if(config.netUdpOk)
    {
      out2<<"NAT : UDP Port is reachable\n\n";
    }
    else
    {
      out2<<"NAT : UDP Port is unreachable\n\n";
    }
    
    if(config.netTcpOk)
    {
      out2<<"NAT : TCP Port is reachable\n\n";
    }
    else
    {
      out2<<"NAT : TCP Port is unreachable\n\n";
    }

    if (config.netExtOk)
    {
      if (config.netUpnpOk || config.netTcpOk)
      {
        out2<<"OK | Retro-Server\n\n";
      }
      else
      {
        out2<<"OK | UDP Server\n\n";
      }
    }
    else if (config.netOk)
    {
     out2<<"Net Limited\n\n";
    }
    else
    {
     out2<<"No Conectivity\n\n";
    }
		
    rsiface->unlockData(); /* UnLock Interface */	
	
	//IPs
	
	const std::string LOCAL_IP = "LOCAL IP : ";
	const std::string EXT_IP = "EXTERNAL IP : ";
	
	std::string invite;

    //add the ip local and external address after the signature
    RsPeerDetails ownDetail;
    rsPeers->getPeerDetails(rsPeers->getOwnId(), ownDetail);
    invite += LOCAL_IP;
    invite += ownDetail.localAddr + ":";
    std::ostringstream out;
    out << ownDetail.localPort;
    invite += out.str();
    invite += "\n\n";
    invite += EXT_IP;
    invite += ownDetail.extAddr + ":";
    std::ostringstream out3;
    out3 << ownDetail.extPort;
    invite += out3.str();
	
	out2<<invite;
	
	std::string s(out2.str());
	wxString xs(s.c_str(),wxConvUTF8);
	
        wxMessageDialog *dial = new wxMessageDialog(this, xs, wxT("RetroMessenger Social-Network Status"), wxOK);
	dial->ShowModal(); 	
}

void RetroMessengerMainFrame::OnPreferences( wxCommandEvent& event )
{
	// TODO: Implement OnPreferences
}

void RetroMessengerMainFrame::OnAbout( wxCommandEvent& /*event*/ )
{
	RetroMessengerAbout about( this );
	about.ShowModal();
}

RetroMessengerMainFrame::~RetroMessengerMainFrame()
{
	SavePosition();
}
