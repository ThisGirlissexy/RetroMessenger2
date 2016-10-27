///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 21 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "RetroMessenger_GUI.h"

#include "images/logo.xpm"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_fileMenu = new wxMenu();
	fileLogin = new wxMenuItem( m_fileMenu, ID_FILE_LOGIN, wxString( _("Lo&gin") ) + wxT('\t') + wxT("Ctrl+G"), _("Logs in user."), wxITEM_NORMAL );
	m_fileMenu->Append( fileLogin );
	
	m_fileMenu->AppendSeparator();
	
	wxMenuItem* fileDisplayOwnCert;
	fileDisplayOwnCert = new wxMenuItem( m_fileMenu, ID_FILE_DISPLAY_OWN_CERT, wxString( _("&Display Certificate") ) + wxT('\t') + wxT("Ctrl+D"), _("Display your own certificate"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	fileDisplayOwnCert->SetBitmaps( wxBitmap( wxT("icons/saveowncert_pqi.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	fileDisplayOwnCert->SetBitmap( wxBitmap( wxT("icons/saveowncert_pqi.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_fileMenu->Append( fileDisplayOwnCert );
	
	wxMenuItem* fileCopyOwnCert;
	fileCopyOwnCert = new wxMenuItem( m_fileMenu, ID_FILE_COPY_OWN_CERT, wxString( _("&Copy Certificate") ) + wxT('\t') + wxT("Ctrl+Shift+S"), _("Copy your own certificate to the Clipboard"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	fileCopyOwnCert->SetBitmaps( wxBitmap( wxT("icons/copyowncert_txt.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	fileCopyOwnCert->SetBitmap( wxBitmap( wxT("icons/copyowncert_txt.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_fileMenu->Append( fileCopyOwnCert );
	
	m_fileMenu->AppendSeparator();
	
	wxMenuItem* fileExit;
	fileExit = new wxMenuItem( m_fileMenu, ID_FILE_EXIT, wxString( _("&Exit") ) + wxT('\t') + wxT("Alt+F4"), _("Exit the application"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	fileExit->SetBitmaps( wxBitmap( wxT("icons/exit.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	fileExit->SetBitmap( wxBitmap( wxT("icons/exit.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_fileMenu->Append( fileExit );
	
	m_menubar->Append( m_fileMenu, _("&File") );
	
	m_editMenu = new wxMenu();
	wxMenuItem* editCut;
	editCut = new wxMenuItem( m_editMenu, ID_EDIT_CUT, wxString( _("&Cut") ) + wxT('\t') + wxT("Ctrl+X"), _("Cuts the selected text from the current chat."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	editCut->SetBitmaps( wxBitmap( wxT("icons/cut.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	editCut->SetBitmap( wxBitmap( wxT("icons/cut.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_editMenu->Append( editCut );
	
	wxMenuItem* editCopy;
	editCopy = new wxMenuItem( m_editMenu, ID_EDIT_COPY, wxString( _("Co&py") ) + wxT('\t') + wxT("Ctrl+C"), _("Copies the selected text from the current chat."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	editCopy->SetBitmaps( wxBitmap( wxT("icons/copy.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	editCopy->SetBitmap( wxBitmap( wxT("icons/copy.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_editMenu->Append( editCopy );
	
	wxMenuItem* editPaste;
	editPaste = new wxMenuItem( m_editMenu, ID_EDIT_PASTE, wxString( _("&Paste") ) + wxT('\t') + wxT("Ctrl+V"), _("Pastes the previous text that was copied/cut to the current text box."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	editPaste->SetBitmaps( wxBitmap( wxT("icons/paste.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	editPaste->SetBitmap( wxBitmap( wxT("icons/paste.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_editMenu->Append( editPaste );
	
	m_menubar->Append( m_editMenu, _("&Edit") );
	
	m_friendsMenu = new wxMenu();
	wxMenuItem* friendsAddCertTxt;
	friendsAddCertTxt = new wxMenuItem( m_friendsMenu, ID_FRIEND_ADD_CERT_TEXT, wxString( _("&Add Friend with Cert (txt)") ) + wxT('\t') + wxT("F4"), _("Add a friend with Txt-Cert"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	friendsAddCertTxt->SetBitmaps( wxBitmap( wxT("icons/addcert_txt.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	friendsAddCertTxt->SetBitmap( wxBitmap( wxT("icons/addcert_txt.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_friendsMenu->Append( friendsAddCertTxt );
	
	wxMenuItem* friendsAddCertFile;
	friendsAddCertFile = new wxMenuItem( m_friendsMenu, ID_FRIENDS_ADD_CERT_FILE, wxString( _("&Add Friend with Cert (PQI-File)") ) + wxT('\t') + wxT("F5"), _("Add a friend with PQI-File-Cert"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	friendsAddCertFile->SetBitmaps( wxBitmap( wxT("icons/addcert_pqi.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	friendsAddCertFile->SetBitmap( wxBitmap( wxT("icons/addcert_pqi.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_friendsMenu->Append( friendsAddCertFile );
	
	m_menubar->Append( m_friendsMenu, _("&Friends") );
	
	m_toolsMenu = new wxMenu();
	wxMenuItem* toolsLinkCloud;
	toolsLinkCloud = new wxMenuItem( m_toolsMenu, ID_TOOLS_LINK_CLOUD, wxString( _("&Link Cloud") ) + wxT('\t') + wxT("Ctrl+L"), _("Show Link Cloud Dialog"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	toolsLinkCloud->SetBitmaps( wxBitmap( wxT("icons/showlinkcloud.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	toolsLinkCloud->SetBitmap( wxBitmap( wxT("icons/showlinkcloud.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_toolsMenu->Append( toolsLinkCloud );
	
	wxMenuItem* toolsWebSearch;
	toolsWebSearch = new wxMenuItem( m_toolsMenu, ID_TOOLS_WEB_SEARCH, wxString( _("&Find On The Web") ) + wxT('\t') + wxT("Ctrl+F"), _("Open your default browser with the entered keywords"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	toolsWebSearch->SetBitmaps( wxBitmap( wxT("icons/search.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	toolsWebSearch->SetBitmap( wxBitmap( wxT("icons/search.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_toolsMenu->Append( toolsWebSearch );
	
	m_toolsMenu->AppendSeparator();
	
	wxMenuItem* toolsNetworkStatus;
	toolsNetworkStatus = new wxMenuItem( m_toolsMenu, ID_TOOLS_NETWORK_STATUS, wxString( _("&Network Status") ) + wxT('\t') + wxT("Ctrl+N"), _("Show network status"), wxITEM_NORMAL );
	m_toolsMenu->Append( toolsNetworkStatus );
	
	m_toolsMenu->AppendSeparator();
	
	wxMenuItem* m_toolsPreferences;
	m_toolsPreferences = new wxMenuItem( m_toolsMenu, ID_TOOLS_PREFERENCES, wxString( _("Preferences") ) + wxT('\t') + wxT("Ctrl+P"), _("Change the applications settings."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_toolsPreferences->SetBitmaps( wxBitmap( wxT("icons/preferences.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_toolsPreferences->SetBitmap( wxBitmap( wxT("icons/preferences.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_toolsMenu->Append( m_toolsPreferences );
	m_toolsPreferences->Enable( false );
	
	m_menubar->Append( m_toolsMenu, _("&Tools") );
	
	m_helpMenu = new wxMenu();
	wxMenuItem* helpAbout;
	helpAbout = new wxMenuItem( m_helpMenu, ID_HELP_ABOUT, wxString( _("&About") ) + wxT('\t') + wxT("F1"), _("Show info about this application"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	helpAbout->SetBitmaps( wxBitmap( wxT("icons/help.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	helpAbout->SetBitmap( wxBitmap( wxT("icons/help.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_helpMenu->Append( helpAbout );
	
	m_menubar->Append( m_helpMenu, _("&Help") );
	
	this->SetMenuBar( m_menubar );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_mainPanel->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_mainTreebook = new wxTreebook( m_mainPanel, ID_MAIN_TREEBOOK, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT );
	m_mainTreebook->SetMinSize( wxSize( 480,280 ) );
	
	bSizer2->Add( m_mainTreebook, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND, 5 );
	
	m_mainPanel->SetSizer( bSizer2 );
	m_mainPanel->Layout();
	bSizer2->Fit( m_mainPanel );
	bSizer1->Add( m_mainPanel, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	m_statusBar1 = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( fileLogin->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLogin ) );
	this->Connect( fileDisplayOwnCert->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDisplayOwnCert ) );
	this->Connect( fileCopyOwnCert->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnCopyOwnCert ) );
	this->Connect( fileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExit ) );
	this->Connect( editCut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEditCut ) );
	this->Connect( editCopy->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEditCopy ) );
	this->Connect( editPaste->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEditPaste ) );
	this->Connect( friendsAddCertTxt->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddFriendCertTxt ) );
	this->Connect( friendsAddCertFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddFriendCertFile ) );
	this->Connect( toolsLinkCloud->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLinkCloud ) );
	this->Connect( toolsWebSearch->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnWebSearch ) );
	this->Connect( toolsNetworkStatus->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnNetworkStatus ) );
	this->Connect( m_toolsPreferences->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPreferences ) );
	this->Connect( helpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAbout ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLogin ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnDisplayOwnCert ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnCopyOwnCert ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnExit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEditCut ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEditCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnEditPaste ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddFriendCertTxt ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAddFriendCertFile ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnLinkCloud ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnWebSearch ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnNetworkStatus ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnPreferences ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::OnAbout ) );
}

CertificateDlg::CertificateDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_logoBitmap = new wxStaticBitmap( this, ID_LOGO_BITMAP, wxBitmap( logo_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_logoBitmap, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextHelp1 = new wxStaticText( this, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHelp1->Wrap( -1 );
	bSizer2->Add( m_staticTextHelp1, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_hyperlinkHelp = new wxHyperlinkCtrl( this, wxID_ANY, _("help"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer2->Add( m_hyperlinkHelp, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_staticTextHelp2 = new wxStaticText( this, wxID_ANY, _("before continuing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHelp2->Wrap( -1 );
	bSizer2->Add( m_staticTextHelp2, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_staticTextPGPAccount = new wxStaticText( this, wxID_ANY, _("OpenPGP Account"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPGPAccount->Wrap( -1 );
	bSizer1->Add( m_staticTextPGPAccount, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_comboBox1 = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	m_comboBox1->SetToolTip( _("Choose an OpenPGP account") );
	
	bSizer1->Add( m_comboBox1, 0, wxALL|wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextID1 = new wxStaticText( this, wxID_ANY, _("For"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID1->Wrap( -1 );
	m_staticTextID1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	bSizer3->Add( m_staticTextID1, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_bitmapUP = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("images/viewmagfit.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_bitmapUP, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_staticTextID2 = new wxStaticText( this, wxID_ANY, _("the ID is :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID2->Wrap( -1 );
	bSizer3->Add( m_staticTextID2, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );
	
	m_textCtrlID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textCtrlID->SetToolTip( _("OpenPGP ID for selected account") );
	
	bSizer1->Add( m_textCtrlID, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	m_staticTextPGPPassword = new wxStaticText( this, wxID_ANY, _("OpenPGP Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPGPPassword->Wrap( -1 );
	bSizer1->Add( m_staticTextPGPPassword, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_passwordTextCtrl = new wxTextCtrl( this, ID_PASSWORD_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_passwordTextCtrl->SetToolTip( _("Provide the OpenPGP password which opens the selected OpenPGP account") );
	
	bSizer1->Add( m_passwordTextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	m_staticTextRMUser = new wxStaticText( this, wxID_ANY, _("RetroMessenger Username"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRMUser->Wrap( -1 );
	bSizer1->Add( m_staticTextRMUser, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_userNameTextCtrl = new wxTextCtrl( this, ID_USERNAME_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_userNameTextCtrl->SetToolTip( _("Choose any nickname as your Username") );
	
	bSizer1->Add( m_userNameTextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticTextRMPass = new wxStaticText( this, wxID_ANY, _("RetroMessenger Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRMPass->Wrap( -1 );
	bSizer1->Add( m_staticTextRMPass, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_textCtrlRMPass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_textCtrlRMPass->SetToolTip( _("Choose any password. It only protects the launch of the Messenger by third party and encrypts your certificates") );
	
	bSizer1->Add( m_textCtrlRMPass, 0, wxALL|wxEXPAND, 5 );
	
	m_staticTextRMPassRepeat = new wxStaticText( this, wxID_ANY, _("RetroMessenger Password repeat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRMPassRepeat->Wrap( -1 );
	bSizer1->Add( m_staticTextRMPassRepeat, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_textCtrlRMPassRepeat = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_textCtrlRMPassRepeat->SetToolTip( _("Repeat RetroMessenger password") );
	
	bSizer1->Add( m_textCtrlRMPassRepeat, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );
	
	m_generateCertificateButton = new wxButton( this, ID_GENERATE_CERTIFICATE_BUTTON, _("Generate Certificate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_generateCertificateButton->SetDefault(); 
	m_generateCertificateButton->SetToolTip( _("Press and create your Account with 2 Certificates (private and public key) stored on your hard disc. Back them up both later.") );
	
	bSizer1->Add( m_generateCertificateButton, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_hyperlinkHelp->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( CertificateDlg::OnHyperlinkHelpClicked ), NULL, this );
	m_comboBox1->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CertificateDlg::OnComboBoxSelected ), NULL, this );
	m_generateCertificateButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CertificateDlg::OnGenerateCertificateClicked ), NULL, this );
}

CertificateDlg::~CertificateDlg()
{
	// Disconnect Events
	m_hyperlinkHelp->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( CertificateDlg::OnHyperlinkHelpClicked ), NULL, this );
	m_comboBox1->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( CertificateDlg::OnComboBoxSelected ), NULL, this );
	m_generateCertificateButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CertificateDlg::OnGenerateCertificateClicked ), NULL, this );
}

CertDlg::CertDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_certificateTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_certificateTextCtrl->SetMinSize( wxSize( 520,280 ) );
	
	bSizer1->Add( m_certificateTextCtrl, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_saveToFileButton = new wxButton( this, wxID_ANY, _("Save To File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_saveToFileButton, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizer->Realize();
	bSizer2->Add( m_sdbSizer, 1, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_saveToFileButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CertDlg::OnSaveToFile ), NULL, this );
	m_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CertDlg::OnOK ), NULL, this );
}

CertDlg::~CertDlg()
{
	// Disconnect Events
	m_saveToFileButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CertDlg::OnSaveToFile ), NULL, this );
	m_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CertDlg::OnOK ), NULL, this );
}

LoginDlg::LoginDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_logoBitmap = new wxStaticBitmap( this, ID_LOGO_BITMAP, wxBitmap( logo_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_logoBitmap, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Username"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer1->Add( m_staticText1, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_userNameTextCtrl = new wxTextCtrl( this, ID_USERNAME_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_userNameTextCtrl->Enable( false );
	m_userNameTextCtrl->SetToolTip( _("Your Username") );
	
	bSizer1->Add( m_userNameTextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer1->Add( m_staticText2, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_passwordTextCtrl = new wxTextCtrl( this, ID_PASSWORD_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_passwordTextCtrl->SetToolTip( _("Enter your password to open this application") );
	
	bSizer1->Add( m_passwordTextCtrl, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticline7 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );
	
	m_staticTextPGPAccount = new wxStaticText( this, wxID_ANY, _("OpenPGP Account"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextPGPAccount->Wrap( -1 );
	bSizer1->Add( m_staticTextPGPAccount, 0, wxALL, 5 );
	
	m_comboBoxAccounts = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	m_comboBoxAccounts->SetToolTip( _("Choose your PGP account") );
	
	bSizer1->Add( m_comboBoxAccounts, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("OpenPGP Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer1->Add( m_staticText3, 0, wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_textCtrlPGPPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	m_textCtrlPGPPassword->SetToolTip( _("Enter the PGP password which unlocks the selected PGP account") );
	
	bSizer1->Add( m_textCtrlPGPPassword, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_staticline = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_autoLoginCheckBox = new wxCheckBox( this, ID_AUTO_LOGIN_CHECK_BOX, _("Auto-Login"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_autoLoginCheckBox->SetValue(true);
	
	m_autoLoginCheckBox->SetToolTip( _("Check-Box to Login automatically on startup.") );
	
	bSizer2->Add( m_autoLoginCheckBox, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_loginButton = new wxButton( this, ID_LOGIN_BUTTON, _("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	m_loginButton->SetDefault(); 
	m_loginButton->SetToolTip( _("Press Login to start RetroMessenger.") );
	
	bSizer2->Add( m_loginButton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_autoLoginCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LoginDlg::OnAutoLoginChecked ), NULL, this );
	m_loginButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginDlg::OnLoginClicked ), NULL, this );
}

LoginDlg::~LoginDlg()
{
	// Disconnect Events
	m_autoLoginCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LoginDlg::OnAutoLoginChecked ), NULL, this );
	m_loginButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginDlg::OnLoginClicked ), NULL, this );
}

AddFriendDlg::AddFriendDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_friendCertTextCtrl = new wxTextCtrl( this, ID_FRIEND_CERT_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_friendCertTextCtrl->SetMinSize( wxSize( 520,280 ) );
	
	bSizer1->Add( m_friendCertTextCtrl, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_loadFromFileButton = new wxButton( this, ID_LOAD_FROM_FILE_BUTTON, _("Load From File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_loadFromFileButton, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	bSizer2->Add( m_sdbSizer, 1, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_loadFromFileButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFriendDlg::OnLoadFromFile ), NULL, this );
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFriendDlg::OnCancel ), NULL, this );
	m_sdbSizerOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFriendDlg::OnOK ), NULL, this );
}

AddFriendDlg::~AddFriendDlg()
{
	// Disconnect Events
	m_loadFromFileButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFriendDlg::OnLoadFromFile ), NULL, this );
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFriendDlg::OnCancel ), NULL, this );
	m_sdbSizerOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AddFriendDlg::OnOK ), NULL, this );
}

AboutDlg::AboutDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetToolTip( _("Click OK to close this Information window.\nBut wait !! before you do that, think about, how you can contribute to the project and community for the RetroMessenger.\nGive and Take: at least, bring one new friend into your friendslist or feed them with one new URLs daily! :-)") );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	mainSizer->SetMinSize( wxSize( 350,-1 ) ); 
	wxBoxSizer* textSizer;
	textSizer = new wxBoxSizer( wxVERTICAL );
	
	m_logoPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_logoPanel->SetBackgroundColour( wxColour( 55, 55, 55 ) );
	
	wxBoxSizer* logoSizer;
	logoSizer = new wxBoxSizer( wxVERTICAL );
	
	m_icon = new wxStaticBitmap( m_logoPanel, ID_ABOUT_ICON, wxBitmap( logo_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
	logoSizer->Add( m_icon, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_logoPanel->SetSizer( logoSizer );
	m_logoPanel->Layout();
	logoSizer->Fit( m_logoPanel );
	textSizer->Add( m_logoPanel, 0, wxTOP|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticVersion = new wxStaticText( this, ID_ABOUT_VERSION, _("Version 0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticVersion->Wrap( -1 );
	textSizer->Add( m_staticVersion, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* infoSizer;
	infoSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_staticCopyright = new wxStaticText( this, ID_ABOUT_COPYRIGHT, _("Serverless and Secure Instant Messenger\n\nCopyright (c) RetroMessenger Team  2008-2009\n\nGNU Library General Public License V2\nFree Software Foundation"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticCopyright->Wrap( -1 );
	infoSizer->Add( m_staticCopyright, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALL, 5 );
	
	textSizer->Add( infoSizer, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_retroMessengerHyperlink = new wxHyperlinkCtrl( this, wxID_ANY, _("http://retromessenger.sf.net"), wxT("http://retromessenger.sf.net/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	textSizer->Add( m_retroMessengerHyperlink, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	mainSizer->Add( textSizer, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_aboutDialogButtonSizer = new wxStdDialogButtonSizer();
	m_aboutDialogButtonSizerOK = new wxButton( this, wxID_OK );
	m_aboutDialogButtonSizer->AddButton( m_aboutDialogButtonSizerOK );
	m_aboutDialogButtonSizer->Realize();
	mainSizer->Add( m_aboutDialogButtonSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	mainSizer->Fit( this );
}

AboutDlg::~AboutDlg()
{
}

LinkCloudDlg::LinkCloudDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Link Cloud") ), wxVERTICAL );
	
	m_linksListBox = new wxListBox( this, ID_LINKS_LIST_BOX, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	m_linksListBox->SetToolTip( _("List of links sent to you by your Friends.") );
	m_linksListBox->SetMinSize( wxSize( 250,100 ) );
	
	sbSizer1->Add( m_linksListBox, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Rate Link") ), wxHORIZONTAL );
	
	wxString m_ratingChoiceChoices[] = { _("+2 Great!"), _("+1 Good"), _("=0 Okay"), _("-1 Sux"), _("-2 Bad Url") };
	int m_ratingChoiceNChoices = sizeof( m_ratingChoiceChoices ) / sizeof( wxString );
	m_ratingChoice = new wxChoice( this, ID_RATING_CHOICE, wxDefaultPosition, wxSize( -1,-1 ), m_ratingChoiceNChoices, m_ratingChoiceChoices, 0 );
	m_ratingChoice->SetSelection( 0 );
	m_ratingChoice->SetToolTip( _("Rate the currently selcted link and press the 'Rate' button to accept the rating.") );
	
	sbSizer2->Add( m_ratingChoice, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_rateButton = new wxButton( this, ID_RATE_BUTTON, _("Rate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rateButton->SetToolTip( _("Set the selected rating on the currently select link. Only after this will it be visible to your friends.") );
	
	sbSizer2->Add( m_rateButton, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sendFriendsButton = new wxButton( this, ID_SEND_FRIENDS_BUTTON, _("Send Friends"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sendFriendsButton->SetToolTip( _("Send the currently selected link to your friends.") );
	
	sbSizer2->Add( m_sendFriendsButton, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 2 );
	
	bSizer1->Add( sbSizer2, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Link Details") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Title:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );
	
	m_linkTitleTextCtrl = new wxTextCtrl( this, ID_LINK_TITLE_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_linkTitleTextCtrl->SetToolTip( _("Title of the link.") );
	
	fgSizer1->Add( m_linkTitleTextCtrl, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("URL:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_urlTextCtrl = new wxTextCtrl( this, ID_URL_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_urlTextCtrl->SetToolTip( _("The URL of the link.") );
	
	fgSizer1->Add( m_urlTextCtrl, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Your Comment:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetToolTip( _("You can delete the comment and enter your own. Then press the Rate-Button.") );
	
	fgSizer1->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_commentTextCtrl = new wxTextCtrl( this, ID_COMMENT_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_commentTextCtrl->SetToolTip( _("More description about the link.\nFor links forwarded from your Friends, you can delete the Comment and enter your own Comment.\nMake sure to rate the link again to keep the comment changes.") );
	
	fgSizer1->Add( m_commentTextCtrl, 0, wxEXPAND|wxALL, 5 );
	
	m_submitAnonymousCheckBox = new wxCheckBox( this, ID_SUBMIT_ANONYMOUS_CHECK_BOX, _("Anonymous"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	
	m_submitAnonymousCheckBox->SetToolTip( _("Check this to insert any link without your Nickname, the link is delivered to your friends slower and without a comment.") );
	
	fgSizer1->Add( m_submitAnonymousCheckBox, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_copyLinkButton = new wxButton( this, ID_COPY_LINK_BUTTON, _("Copy Link"), wxDefaultPosition, wxDefaultSize, 0 );
	m_copyLinkButton->Enable( false );
	m_copyLinkButton->SetToolTip( _("Copy the current URL to the Clipboard.") );
	
	bSizer12->Add( m_copyLinkButton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_addLinkButton = new wxButton( this, ID_ADD_LINK_BUTTON, _("Add Link"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addLinkButton->SetToolTip( _("Adds the link to your Link Cloud.") );
	
	bSizer12->Add( m_addLinkButton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizer1->Add( bSizer12, 1, wxEXPAND, 5 );
	
	sbSizer3->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer3, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_linksListBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( LinkCloudDlg::OnLinksClicked ), NULL, this );
	m_linksListBox->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LinkCloudDlg::OnLinksDoubleClicked ), NULL, this );
	m_ratingChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( LinkCloudDlg::OnRatingSelected ), NULL, this );
	m_rateButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnRateClicked ), NULL, this );
	m_sendFriendsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnSendToFriendsClicked ), NULL, this );
	m_submitAnonymousCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnAnonymousClicked ), NULL, this );
	m_copyLinkButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnCopyLinkClicked ), NULL, this );
	m_addLinkButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnAddLinkClicked ), NULL, this );
}

LinkCloudDlg::~LinkCloudDlg()
{
	// Disconnect Events
	m_linksListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( LinkCloudDlg::OnLinksClicked ), NULL, this );
	m_linksListBox->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( LinkCloudDlg::OnLinksDoubleClicked ), NULL, this );
	m_ratingChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( LinkCloudDlg::OnRatingSelected ), NULL, this );
	m_rateButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnRateClicked ), NULL, this );
	m_sendFriendsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnSendToFriendsClicked ), NULL, this );
	m_submitAnonymousCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnAnonymousClicked ), NULL, this );
	m_copyLinkButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnCopyLinkClicked ), NULL, this );
	m_addLinkButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LinkCloudDlg::OnAddLinkClicked ), NULL, this );
}

MessageSentDlg::MessageSentDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("LINK SENT TO ..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer15->Add( m_staticText12, 0, wxALL, 5 );
	
	m_LinkSentButtonSizer = new wxStdDialogButtonSizer();
	m_LinkSentButtonSizerOK = new wxButton( this, wxID_OK );
	m_LinkSentButtonSizer->AddButton( m_LinkSentButtonSizerOK );
	m_LinkSentButtonSizer->Realize();
	bSizer15->Add( m_LinkSentButtonSizer, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer15 );
	this->Layout();
}

MessageSentDlg::~MessageSentDlg()
{
}

ChatPage::ChatPage( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_chatLogTextCtrl = new wxHtmlWindow( this, ID_CHAT_LOG_TEXT_CTRL, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER );
	m_chatLogTextCtrl->SetMinSize( wxSize( 200,100 ) );
	
	sbSizer1->Add( m_chatLogTextCtrl, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_messageTextCtrl = new wxTextCtrl( this, ID_MESSAGE_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer2->Add( m_messageTextCtrl, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sendButton = new wxButton( this, wxID_ANY, _("Send"), wxDefaultPosition, wxSize( -1,-1 ), wxBU_EXACTFIT );
	bSizer2->Add( m_sendButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	sbSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND|wxLEFT, 10 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	m_chatLogTextCtrl->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( ChatPage::OnUrlClicked ), NULL, this );
	m_messageTextCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ChatPage::OnMessageUpdated ), NULL, this );
	m_messageTextCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( ChatPage::OnSendClicked ), NULL, this );
	m_sendButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChatPage::OnSendClicked ), NULL, this );
}

ChatPage::~ChatPage()
{
	// Disconnect Events
	m_chatLogTextCtrl->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( ChatPage::OnUrlClicked ), NULL, this );
	m_messageTextCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ChatPage::OnMessageUpdated ), NULL, this );
	m_messageTextCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( ChatPage::OnSendClicked ), NULL, this );
	m_sendButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChatPage::OnSendClicked ), NULL, this );
}

PopUpPersonalChat::PopUpPersonalChat( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("Hooked-up Personal Chat with ...:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetToolTip( _("Just close this window to retrun to the main chat Frame and integrate this chat.") );
	
	bSizer1->Add( m_staticText12, 0, wxALL, 5 );
	
	m_chatLogTextCtrl = new wxTextCtrl( this, ID_CHAT_LOG_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_chatLogTextCtrl->SetMinSize( wxSize( 250,200 ) );
	
	bSizer1->Add( m_chatLogTextCtrl, 1, wxEXPAND|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sendButton = new wxButton( this, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_sendButton, 0, wxTOP|wxLEFT, 5 );
	
	m_messageTextCtrl = new wxTextCtrl( this, ID_MESSAGE_TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_messageTextCtrl, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_sendButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PopUpPersonalChat::OnSendClicked ), NULL, this );
	m_messageTextCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PopUpPersonalChat::OnMessageUpdated ), NULL, this );
	m_messageTextCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PopUpPersonalChat::OnSendClicked ), NULL, this );
}

PopUpPersonalChat::~PopUpPersonalChat()
{
	// Disconnect Events
	m_sendButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PopUpPersonalChat::OnSendClicked ), NULL, this );
	m_messageTextCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( PopUpPersonalChat::OnMessageUpdated ), NULL, this );
	m_messageTextCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PopUpPersonalChat::OnSendClicked ), NULL, this );
}

ProgressDlg::ProgressDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxVERTICAL );
	
	m_statusStaticText = new wxStaticText( this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_statusStaticText->Wrap( -1 );
	bSizer->Add( m_statusStaticText, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_progressGauge = new wxGauge( this, ID_PROGRESS_GAUGE, 100, wxDefaultPosition, wxSize( -1,-1 ), wxGA_HORIZONTAL );
	m_progressGauge->SetMinSize( wxSize( 300,-1 ) );
	
	bSizer->Add( m_progressGauge, 1, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();
	bSizer->Add( m_sdbSizer, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer );
	this->Layout();
	bSizer->Fit( this );
	
	// Connect Events
	m_sdbSizerCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ProgressDlg::OnCancel ), NULL, this );
}

ProgressDlg::~ProgressDlg()
{
	// Disconnect Events
	m_sdbSizerCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ProgressDlg::OnCancel ), NULL, this );
}
