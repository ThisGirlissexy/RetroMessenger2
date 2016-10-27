///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __noname__
#define __noname__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/imaglist.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class m_linkDialog
///////////////////////////////////////////////////////////////////////////////
class m_linkDialog : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText4;
		
		wxListbook* m_listbook3;
		wxSplitterWindow* m_splitter1;
	
	public:
		m_linkDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger v0.01"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 351,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~m_linkDialog();
		void m_splitter1OnIdle( wxIdleEvent& )
		{
		m_splitter1->SetSashPosition( 0 );
		m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( m_linkDialog::m_splitter1OnIdle ), NULL, this );
		}
		
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class m_mainFrameNew
///////////////////////////////////////////////////////////////////////////////
class m_mainFrameNew : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel88;
		wxStaticText* m_staticText10;
		
		wxStaticText* m_staticText11;
		wxListbook* m_listbook2;
		wxPanel* m_panel48;
		wxTextCtrl* m_textCtrl52;
		wxTextCtrl* m_textCtrl53;
		wxButton* m_button26;
		wxPanel* m_panel481;
		wxTextCtrl* m_textCtrl521;
		wxTextCtrl* m_textCtrl531;
		wxButton* m_button261;
		wxPanel* m_panel482;
		wxTextCtrl* m_textCtrl522;
		wxTextCtrl* m_textCtrl532;
		wxButton* m_button262;
		wxPanel* m_panel484;
		wxTextCtrl* m_textCtrl524;
		wxTextCtrl* m_textCtrl534;
		wxButton* m_button264;
		wxPanel* m_panel483;
		wxTextCtrl* m_textCtrl523;
		wxTextCtrl* m_textCtrl533;
		wxButton* m_button263;
	
	public:
		m_mainFrameNew( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger v0.01"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~m_mainFrameNew();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class m_certificateDialog
///////////////////////////////////////////////////////////////////////////////
class m_certificateDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl2;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl3;
		wxStaticLine* m_staticline1;
		wxButton* m_button1;
	
	public:
		m_certificateDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger Certificate"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~m_certificateDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class m_loginDialog
///////////////////////////////////////////////////////////////////////////////
class m_loginDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap2;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrl100;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCtrl101;
		wxStaticLine* m_staticline2;
		wxCheckBox* m_checkBox1;
		wxButton* m_button50;
	
	public:
		m_loginDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger Login"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~m_loginDialog();
	
};

#endif //__noname__
