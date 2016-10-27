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

#include "RetroMessengerLoginDlg.h"
#include "RetroMessengerMainFrame.h"
#include "AppData.h"
#include "RetroMessenger.h"
#include "NotifyTxt.h"

// RetroShare
#include <rsiface/rsiface.h>
#include <rsiface/rsinit.h>
#include <rsserver/p3face.h>
#include <rsiface/rspeers.h>
#include <rsserver/p3peers.h>
#include <pqi/p3connmgr.h>

// wxWidgets
#include <wx/filename.h>
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/list.h>
#include <wx/app.h>
#include <wx/tokenzr.h>

RetroMessengerLoginDlg::RetroMessengerLoginDlg( wxWindow* parent, int id ) : LoginDlg( parent, id )
{
#ifdef __WXMSW__
	SetIcon( wxICON( amain ) );
#else
#include "images/starlogo.xpm"
	SetIcon( wxICON( starlogo ) );
#endif

#ifdef RS_USE_PGPSSL

		std::cerr << "Finding PGPUsers" << std::endl;

        std::list<std::string> pgpIds;
        std::list<std::string>::iterator it;
        if (RsInit::GetPGPLogins(pgpIds))
        {
                for(it = pgpIds.begin(); it != pgpIds.end(); it++)
                {
                        std::string name, email;
                        RsInit::GetPGPLoginDetails(*it, name, email);
						std::cerr << "Adding PGPUser: " << name << " id: " << *it << std::endl;
						std::string tmp = name+":"+(*it);
						wxString temp(tmp.c_str(), wxConvUTF8);
						m_comboBoxAccounts->Append(temp);
                }
        }
#endif

	m_userNameTextCtrl->SetValue( AppData->GetUserName() );

	// Make this the control that has focus when it opens.
	m_passwordTextCtrl->SetFocus();
}

void RetroMessengerLoginDlg::OnAutoLoginChecked( wxCommandEvent& /*event*/ )
{
	/*if ( !RsTryAutoLogin( AppData->GetRsConfig() ) )
	{
		AppData->GetRsConfig()->autoLogin = RsStoreAutoLogin( AppData->GetRsConfig() );
		AppData->SetShouldAutoLoggIn( true );
	}
	else
	{
		AppData->GetRsConfig()->autoLogin = RsClearAutoLogin( AppData->GetRsConfig()->basedir );
		AppData->SetShouldAutoLoggIn( false );
	}*/
	
	//Todo : FIX if different in any way to the above version
	if ( !RsInit::RsTryAutoLogin() )
	{
		RsInit::SetAutoLogin(RsInit::RsStoreAutoLogin());
		AppData->SetShouldAutoLogIn( true );
	}
	else
	{
		RsInit::SetAutoLogin( RsInit::RsClearAutoLogin() );
		AppData->SetShouldAutoLogIn( false );
	}
}


void RetroMessengerLoginDlg::InitializeRetroShare( const std::string& passwd, const std::string& gpgPasswd )
{
	wxStringTokenizer tkz(m_comboBoxAccounts->GetValue(), wxT(":"));

	wxString token1 = tkz.GetNextToken();
	wxString token2 = tkz.GetNextToken();
		
	if((token1 == _T("")) or (token2 == _T("")))
	{
		wxMessageBox( wxT("No valid OpenPGP account"), wxT("Missing account") );
		return;	
	}

#ifdef RS_USE_PGPSSL
	std::string accountId(token2.ToAscii());
	
	RsInit::SelectGPGAccount(accountId);
	RsInit::LoadGPGPassword(gpgPasswd);
#endif

	std::string preferedId;
	RsInit::getPreferedAccountId(preferedId);

	RsInit::LoadPassword(preferedId, passwd);
	
	// Load up your certificate. RetroShare will not work without a valid certificate.
	if(RsInit::LoadCertificates( RsInit::IsAutoLogin() ) == false)
	{
		wxMessageBox( wxT("Login Failed"), wxT("Wrong Password") );
		return;
	}
		
	// Create the RetroShare interface objects.
	NotifyTxt *notify = new NotifyTxt();
	RsIface *iface = createRsIface( *notify );
	RsControl *rsServer = createRsControl( *iface, *notify );
	notify->setRsIface( iface );

	// Startup RetroShare.
	rsServer->StartupRetroShare( );
}

void RetroMessengerLoginDlg::OnLoginClicked( wxCommandEvent& /*event*/ )
{
	// Get username string from text control.
	std::string userName( m_userNameTextCtrl->GetValue().ToAscii() );

	// Get pasword string from text control.
	std::string password( m_passwordTextCtrl->GetValue().ToAscii() );
	
	// Get GPG pasword string from text control.
	std::string gpgPassword( m_textCtrlPGPPassword->GetValue().ToAscii() );

	// Init RetroShare
	InitializeRetroShare( password, gpgPassword );

	// Load RetroShare with the required password and Certificate.
	if ( RsInit::LoadPassword( userName, password ) )
	{
		AppData->SetIsUserLoggedIn(true);
			
		// Close the Login dialog.
		EndModal( wxID_OK );			

		// Check the peers list and get peer details
		RsPeerDetails  detail;
		std::list<std::string> peers;
		std::list<std::string>::iterator it;

		if ( rsPeers )
		{
			rsPeers->getFriendList( peers );

			// TODO: Add peer detail to application data

			// Loop through all friends and add them to the main frame.
			for ( it = peers.begin(); it != peers.end(); it++ )
			{
				if ( !rsPeers->getPeerDetails( *it, detail ) )
				{
					continue;
				}
					
				//Add friend to Main frame
				AppData->GetMainFrame()->AddFriend( detail.name, detail.id, detail.state );
			}
		}
	}
}

RetroMessengerLoginDlg::~RetroMessengerLoginDlg()
{
}
