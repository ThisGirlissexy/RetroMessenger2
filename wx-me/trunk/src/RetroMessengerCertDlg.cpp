#include "RetroMessengerCertDlg.h"

RetroMessengerCertDlg::RetroMessengerCertDlg( wxWindow* parent )
	:
CertDlg( parent )
{	
}

void RetroMessengerCertDlg::OnOk( wxCommandEvent& /*event*/ )
{
	EndModal( wxID_OK );
}

void RetroMessengerCertDlg::OnCancel( wxCommandEvent& /*event*/ )
{
	EndModal( wxID_CANCEL );
}

void RetroMessengerCertDlg::OnSave( wxCommandEvent& event )
{
	// TODO: Implement OnSave
}

void RetroMessengerCertDlg::DisplayCertificate( const std::string& path )
{
	m_certificateTextCtrl->LoadFile( wxString::FromAscii( path.c_str() ) );
}

void RetroMessengerCertDlg::DisplayErrorMessage( const std::string& errorMessage )
{
	m_certificateTextCtrl->AppendText( wxString::FromAscii( errorMessage.c_str() ) );
}
