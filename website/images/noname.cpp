///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

m_linkDialog::m_linkDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _("OFFSystem URLs:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer12->Add( m_staticText4, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer12->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer3->Add( bSizer12, 0, wxEXPAND, 5 );
	
	m_listbook3 = new wxListbook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT );
	#ifndef __WXGTK__ // Small icon style not supported in GTK
	wxListView* m_listbook3ListView = m_listbook3->GetListView();
	long m_listbook3Flags = m_listbook3ListView->GetWindowStyleFlag();
	m_listbook3Flags = ( m_listbook3Flags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
	m_listbook3ListView->SetWindowStyleFlag( m_listbook3Flags );
	#endif
	
	bSizer3->Add( m_listbook3, 1, wxEXPAND | wxALL, 5 );
	
	m_splitter1 = new wxSplitterWindow( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( m_linkDialog::m_splitter1OnIdle ), NULL, this );
	bSizer3->Add( m_splitter1, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	bSizer2->Add( m_panel1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
}

m_linkDialog::~m_linkDialog()
{
}

m_mainFrameNew::m_mainFrameNew( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer97;
	bSizer97 = new wxBoxSizer( wxVERTICAL );
	
	m_panel88 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( m_panel88, wxID_ANY, _("Friends:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer56->Add( m_staticText10, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer56->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText11 = new wxStaticText( m_panel88, wxID_ANY, _("Chat:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer56->Add( m_staticText11, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizer55->Add( bSizer56, 0, wxEXPAND, 5 );
	
	m_listbook2 = new wxListbook( m_panel88, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT );
	wxSize m_listbook2ImageSize = wxSize( 16,16 );
	int m_listbook2Index = 0;
	wxImageList* m_listbook2Images = new wxImageList( m_listbook2ImageSize.GetWidth(), m_listbook2ImageSize.GetHeight() );
	m_listbook2->AssignImageList( m_listbook2Images );
	wxBitmap m_listbook2Bitmap;
	wxImage m_listbook2Image;
	m_listbook2->SetMinSize( wxSize( 350,200 ) );
	
	m_panel48 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl52 = new wxTextCtrl( m_panel48, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( m_textCtrl52, 1, wxEXPAND|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl53 = new wxTextCtrl( m_panel48, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_textCtrl53, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_button26 = new wxButton( m_panel48, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_button26, 0, wxTOP|wxLEFT, 5 );
	
	bSizer57->Add( bSizer58, 0, wxEXPAND, 5 );
	
	m_panel48->SetSizer( bSizer57 );
	m_panel48->Layout();
	bSizer57->Fit( m_panel48 );
	m_listbook2->AddPage( m_panel48, _("Bob"), true );
	m_listbook2Bitmap = wxBitmap( wxT("\\\\Znas2\\electrical\\User\\Tester\\rpusztai\\Code\\Icons\\famfamfam\\asterisk_yellow.png"), wxBITMAP_TYPE_ANY );
	if ( m_listbook2Bitmap.Ok() )
	{
	m_listbook2Image = m_listbook2Bitmap.ConvertToImage();
	m_listbook2Images->Add( m_listbook2Image.Scale( m_listbook2ImageSize.GetWidth(), m_listbook2ImageSize.GetHeight() ) );
	m_listbook2->SetPageImage( m_listbook2Index, m_listbook2Index );
	m_listbook2Index++;
	}
	m_panel481 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer571;
	bSizer571 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl521 = new wxTextCtrl( m_panel481, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer571->Add( m_textCtrl521, 1, wxEXPAND|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer581;
	bSizer581 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl531 = new wxTextCtrl( m_panel481, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer581->Add( m_textCtrl531, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_button261 = new wxButton( m_panel481, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button261->Enable( false );
	
	bSizer581->Add( m_button261, 0, wxTOP|wxLEFT, 5 );
	
	bSizer571->Add( bSizer581, 0, wxEXPAND, 5 );
	
	m_panel481->SetSizer( bSizer571 );
	m_panel481->Layout();
	bSizer571->Fit( m_panel481 );
	m_listbook2->AddPage( m_panel481, _("Alice"), false );
	m_listbook2Bitmap = wxBitmap( wxT("\\\\Znas2\\electrical\\User\\Tester\\rpusztai\\Code\\Icons\\famfamfam\\asterisk_orange.png"), wxBITMAP_TYPE_ANY );
	if ( m_listbook2Bitmap.Ok() )
	{
	m_listbook2Image = m_listbook2Bitmap.ConvertToImage();
	m_listbook2Images->Add( m_listbook2Image.Scale( m_listbook2ImageSize.GetWidth(), m_listbook2ImageSize.GetHeight() ) );
	m_listbook2->SetPageImage( m_listbook2Index, m_listbook2Index );
	m_listbook2Index++;
	}
	m_panel482 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer572;
	bSizer572 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl522 = new wxTextCtrl( m_panel482, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer572->Add( m_textCtrl522, 1, wxEXPAND|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer582;
	bSizer582 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl532 = new wxTextCtrl( m_panel482, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer582->Add( m_textCtrl532, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_button262 = new wxButton( m_panel482, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer582->Add( m_button262, 0, wxTOP|wxLEFT, 5 );
	
	bSizer572->Add( bSizer582, 0, wxEXPAND, 5 );
	
	m_panel482->SetSizer( bSizer572 );
	m_panel482->Layout();
	bSizer572->Fit( m_panel482 );
	m_listbook2->AddPage( m_panel482, _("A Really Long Username"), false );
	m_panel484 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer574;
	bSizer574 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl524 = new wxTextCtrl( m_panel484, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer574->Add( m_textCtrl524, 1, wxEXPAND|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer584;
	bSizer584 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl534 = new wxTextCtrl( m_panel484, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer584->Add( m_textCtrl534, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_button264 = new wxButton( m_panel484, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer584->Add( m_button264, 0, wxTOP|wxLEFT, 5 );
	
	bSizer574->Add( bSizer584, 0, wxEXPAND, 5 );
	
	m_panel484->SetSizer( bSizer574 );
	m_panel484->Layout();
	bSizer574->Fit( m_panel484 );
	m_listbook2->AddPage( m_panel484, _("a page"), false );
	m_panel483 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer573;
	bSizer573 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl523 = new wxTextCtrl( m_panel483, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer573->Add( m_textCtrl523, 1, wxEXPAND|wxBOTTOM|wxLEFT, 5 );
	
	wxBoxSizer* bSizer583;
	bSizer583 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl533 = new wxTextCtrl( m_panel483, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer583->Add( m_textCtrl533, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_button263 = new wxButton( m_panel483, wxID_ANY, _("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer583->Add( m_button263, 0, wxTOP|wxLEFT, 5 );
	
	bSizer573->Add( bSizer583, 0, wxEXPAND, 5 );
	
	m_panel483->SetSizer( bSizer573 );
	m_panel483->Layout();
	bSizer573->Fit( m_panel483 );
	m_listbook2->AddPage( m_panel483, _("a page"), false );
	
	bSizer55->Add( m_listbook2, 1, wxEXPAND | wxALL, 5 );
	
	m_panel88->SetSizer( bSizer55 );
	m_panel88->Layout();
	bSizer55->Fit( m_panel88 );
	bSizer97->Add( m_panel88, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer97 );
	this->Layout();
}

m_mainFrameNew::~m_mainFrameNew()
{
}

m_certificateDialog::m_certificateDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("logo4.gif"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_bitmap1, 0, wxALL, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Username:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer1->Add( m_staticText1, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, _("<user_name>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_textCtrl1, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer1->Add( m_staticText2, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer1->Add( m_textCtrl2, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Password Repeat:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer1->Add( m_staticText3, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer1->Add( m_textCtrl3, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_button1 = new wxButton( this, wxID_ANY, _("Generate Certificate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_button1, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
}

m_certificateDialog::~m_certificateDialog()
{
}

m_loginDialog::m_loginDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("logo4.gif"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer107->Add( m_bitmap2, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("Username"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer107->Add( m_staticText12, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrl100 = new wxTextCtrl( this, wxID_ANY, _("<UserName>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer107->Add( m_textCtrl100, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer107->Add( m_staticText13, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_textCtrl101 = new wxTextCtrl( this, wxID_ANY, _("password"), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer107->Add( m_textCtrl101, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer107->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer108;
	bSizer108 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkBox1 = new wxCheckBox( this, wxID_ANY, _("Auto-Login"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_checkBox1->SetValue(true);
	
	bSizer108->Add( m_checkBox1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button50 = new wxButton( this, wxID_ANY, _("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button50->SetDefault(); 
	bSizer108->Add( m_button50, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer107->Add( bSizer108, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer107 );
	this->Layout();
	bSizer107->Fit( this );
}

m_loginDialog::~m_loginDialog()
{
}
