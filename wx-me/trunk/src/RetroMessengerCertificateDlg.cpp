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

#include "RetroMessengerCertificateDlg.h"
#include "RetroMessengerLoginDlg.h"
#include "RetroMessengerCertDlg.h"
#include "RetroMessenger_GUI.h"
#include "AppData.h"
#include "NotifyTxt.h"

// RetroShare
#include <rsiface/rsiface.h>
#include <rsiface/rsinit.h>
#include <rsserver/p3face.h>

// wxWidgets
#include <wx/msgdlg.h>
#include <wx/file.h>
#include <wx/filefn.h>

RetroMessengerCertificateDlg::RetroMessengerCertificateDlg ( wxWindow* parent, int id )
	:
CertificateDlg ( parent, id )
{
#ifdef __WXMSW__
	SetIcon( wxICON( amain ) );
#else
	#include "images/starlogo.xpm"
	SetIcon( wxICON( starlogo ) );
#endif

//get all available pgp private certificates 
//and mark last one as default
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
						wxString temp(name.c_str(), wxConvUTF8);
						m_comboBox1->Append(temp);
                }
        }
#endif

	// Make this the control that has focus when it opens.
	m_comboBox1->SetFocus();
}

void RetroMessengerCertificateDlg::OnGenerateCertificateClicked ( wxCommandEvent& /*event*/ )
{
	// Make sure that the directory 'keys' exists.
	if ( !wxDirExists( wxT("keys") ) )
	{
		wxMkdir( wxT("keys"), 0777);
	}
	
	//std::string pgpName( m_comboBox1->GetValue().ToAscii() );
	std::string pgpId( m_textCtrlID->GetValue().ToAscii() );	
	std::string pgpPasswd( m_passwordTextCtrl->GetValue().ToAscii() );
	std::string genName( m_userNameTextCtrl->GetValue().ToAscii() );	
	std::string genOrg("");
	std::string genLoc("");
	std::string genCountry("");
	std::string err("");
	std::string sslPasswd(m_textCtrlRMPass->GetValue().ToAscii());
	std::string sslId("");
		
	if (m_comboBox1->GetValue() == wxEmptyString)
	{
		wxMessageBox( wxT("Please select (or create if list is empty) an OpenPGP account first"), wxT("PGP certificate missing") );
		return;	
	}
	
	if (genName.length() < 3)
	{
		wxMessageBox( wxT("Your name is too short (3+ characters required)"), wxT("Short username") );
		return;	
	}
	
	if (m_textCtrlRMPass->GetValue().Length() == 0)
	{
		wxMessageBox( wxT("RetroMessenger password missing"), wxT("Password missing") );
		return;
	}
	
	if (m_textCtrlRMPass->GetValue().Length() < 4)
	{
		wxMessageBox( wxT("RetroMessenger password must be 4+ characters"), wxT("Wrong password length") );
		return;
	}
	
	if (m_textCtrlRMPass->GetValue() != m_textCtrlRMPassRepeat->GetValue())
	{
		wxMessageBox( wxT("RetroMessenger passwords (initial and repeated) do not match"), wxT("Passwords mismatch") );
		return;
	}
	
	// Initialise the PGP user first 
	RsInit::SelectGPGAccount(pgpId);
	RsInit::LoadGPGPassword(pgpPasswd);
	
	bool okGen = RsInit::GenerateSSLCertificate(genName, genOrg, genLoc, genCountry, sslPasswd, sslId, err);

	if (okGen)
	{
		// complete the process 
		RsInit::LoadPassword(sslId, sslPasswd);
		
		if(RsInit::LoadCertificates(AppData->GetShouldAutoLogIn()))
		{
			// Save that the certificate has been saved.
			AppData->SetIsCertificateGenerated( true );
					
			// Save the user name.
			AppData->SetUserName( m_userNameTextCtrl->GetValue() );
			
			// Certificate generated so close the dialog.
			EndModal( wxID_OK );		
		}
		else
		{
			wxMessageBox( wxT("Failed to Load your new Certificate!" ), wxT("Generate ID failure") );
			return;			
		}
	}
	else
	{
		wxMessageBox( wxT("Failed to Generate your new Certificate, maybe PGP password is wrong !" ), wxT("Certificate generation failure") );
		return;
	}
}

void RetroMessengerCertificateDlg::OnHyperlinkHelpClicked( wxHyperlinkEvent& event )
{ 
	wxMessageBox( wxT(
	"You must create a GPG key before creating a RetroMessenger Profile.\n"
	"1. On Linux must install GPA :\n"
	"sudo apt-get install gpa\n\n"
	"2. On Windows must install gpg4win package:\n"
	"http://ftp.gpg4win.org/ \n"
	),	wxT("Help") );
}

void RetroMessengerCertificateDlg::OnComboBoxSelected( wxCommandEvent& event )
{
#ifdef RS_USE_PGPSSL

        std::list<std::string> pgpIds;
        std::list<std::string>::iterator it;
        if (RsInit::GetPGPLogins(pgpIds))
        {
                for(it = pgpIds.begin(); it != pgpIds.end(); it++)
                {
						std::string userData(*it);
                        std::string name, email;
                        RsInit::GetPGPLoginDetails(*it, name, email);
						
						std::string combo(m_comboBox1->GetValue().ToAscii());
					
						if (combo == name)
						{
							wxString temp(userData.c_str(), wxConvUTF8);
							m_textCtrlID->SetValue(temp);							
						}	
                }
        }
#endif	
}

RetroMessengerCertificateDlg::~RetroMessengerCertificateDlg()
{
}
