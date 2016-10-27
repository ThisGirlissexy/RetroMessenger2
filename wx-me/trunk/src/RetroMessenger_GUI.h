///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 21 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __RetroMessenger_GUI__
#define __RetroMessenger_GUI__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/treebook.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/hyperlink.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/choice.h>
#include <wx/html/htmlwin.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			ID_DEFAULT = wxID_ANY, // Default
			ID_FILE_LOGIN = 1000,
			ID_FILE_DISPLAY_OWN_CERT,
			ID_FILE_COPY_OWN_CERT,
			ID_FILE_EXIT,
			ID_EDIT_CUT,
			ID_EDIT_COPY,
			ID_EDIT_PASTE,
			ID_FRIEND_ADD_CERT_TEXT,
			ID_FRIENDS_ADD_CERT_FILE,
			ID_TOOLS_LINK_CLOUD,
			ID_TOOLS_WEB_SEARCH,
			ID_TOOLS_NETWORK_STATUS,
			ID_TOOLS_PREFERENCES,
			ID_HELP_ABOUT,
			ID_MAIN_TREEBOOK,
		};
		
		wxMenuBar* m_menubar;
		wxMenu* m_fileMenu;
		wxMenuItem* fileLogin;
		wxMenu* m_editMenu;
		wxMenu* m_friendsMenu;
		wxMenu* m_toolsMenu;
		wxMenu* m_helpMenu;
		wxPanel* m_mainPanel;
		wxTreebook* m_mainTreebook;
		wxStatusBar* m_statusBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLogin( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDisplayOwnCert( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCopyOwnCert( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnEditCut( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnEditCopy( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnEditPaste( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddFriendCertTxt( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddFriendCertFile( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLinkCloud( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnWebSearch( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnNetworkStatus( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPreferences( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger v0.5"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();
};

///////////////////////////////////////////////////////////////////////////////
/// Class CertificateDlg
///////////////////////////////////////////////////////////////////////////////
class CertificateDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_LOGO_BITMAP = 1000,
			ID_USERNAME_TEXT_CTRL,
			ID_PASSWORD_TEXT_CTRL,
			ID_PASSWORD_REPEAT_TEXT_CTRL,
			ID_GENERATE_CERTIFICATE_BUTTON,
		};
		
		wxStaticBitmap* m_logoBitmap;
		wxStaticText* m_staticTextHelp1;
		wxHyperlinkCtrl* m_hyperlinkHelp;
		wxStaticText* m_staticTextHelp2;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticTextPGPAccount;
		wxComboBox* m_comboBox1;
		wxStaticText* m_staticTextID1;
		wxStaticBitmap* m_bitmapUP;
		wxStaticText* m_staticTextID2;
		wxTextCtrl* m_textCtrlID;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticTextPGPPassword;
		wxTextCtrl* m_passwordTextCtrl;
		wxStaticLine* m_staticline3;
		wxStaticText* m_staticTextRMUser;
		wxTextCtrl* m_userNameTextCtrl;
		wxStaticText* m_staticTextRMPass;
		wxTextCtrl* m_textCtrlRMPass;
		wxStaticText* m_staticTextRMPassRepeat;
		wxTextCtrl* m_textCtrlRMPassRepeat;
		wxStaticLine* m_staticline4;
		wxButton* m_generateCertificateButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnHyperlinkHelpClicked( wxHyperlinkEvent& event ){ event.Skip(); }
		virtual void OnComboBoxSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnGenerateCertificateClicked( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		CertificateDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger Certificate"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CertificateDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CertDlg
///////////////////////////////////////////////////////////////////////////////
class CertDlg : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* m_certificateTextCtrl;
		wxButton* m_saveToFileButton;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSaveToFile( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		CertDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger Certificate"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~CertDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LoginDlg
///////////////////////////////////////////////////////////////////////////////
class LoginDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_LOGO_BITMAP = 1000,
			ID_USERNAME_TEXT_CTRL,
			ID_PASSWORD_TEXT_CTRL,
			ID_AUTO_LOGIN_CHECK_BOX,
			ID_LOGIN_BUTTON,
		};
		
		wxStaticBitmap* m_logoBitmap;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_userNameTextCtrl;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_passwordTextCtrl;
		wxStaticLine* m_staticline7;
		wxStaticText* m_staticTextPGPAccount;
		wxComboBox* m_comboBoxAccounts;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrlPGPPassword;
		wxStaticLine* m_staticline;
		wxCheckBox* m_autoLoginCheckBox;
		wxButton* m_loginButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAutoLoginChecked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLoginClicked( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		LoginDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger Login"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~LoginDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddFriendDlg
///////////////////////////////////////////////////////////////////////////////
class AddFriendDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_FRIEND_CERT_TEXT_CTRL = 1000,
			ID_LOAD_FROM_FILE_BUTTON,
		};
		
		wxTextCtrl* m_friendCertTextCtrl;
		wxButton* m_loadFromFileButton;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoadFromFile( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		AddFriendDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Add Friend"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~AddFriendDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDlg
///////////////////////////////////////////////////////////////////////////////
class AboutDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_DEFAULT = wxID_ANY, // Default
			ID_ABOUT_ICON = 1000,
			ID_ABOUT_VERSION,
			ID_ABOUT_COPYRIGHT,
		};
		
		wxPanel* m_logoPanel;
		wxStaticBitmap* m_icon;
		wxStaticText* m_staticVersion;
		wxStaticText* m_staticCopyright;
		wxHyperlinkCtrl* m_retroMessengerHyperlink;
		wxStdDialogButtonSizer* m_aboutDialogButtonSizer;
		wxButton* m_aboutDialogButtonSizerOK;
	
	public:
		AboutDlg( wxWindow* parent, wxWindowID id = ID_DEFAULT, const wxString& title = _("About RetroMessenger..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~AboutDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LinkCloudDlg
///////////////////////////////////////////////////////////////////////////////
class LinkCloudDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_LINKS_LIST_BOX = 1000,
			ID_RATING_CHOICE,
			ID_RATE_BUTTON,
			ID_SEND_FRIENDS_BUTTON,
			ID_LINK_TITLE_TEXT_CTRL,
			ID_URL_TEXT_CTRL,
			ID_COMMENT_TEXT_CTRL,
			ID_SUBMIT_ANONYMOUS_CHECK_BOX,
			ID_COPY_LINK_BUTTON,
			ID_ADD_LINK_BUTTON,
		};
		
		wxListBox* m_linksListBox;
		wxChoice* m_ratingChoice;
		wxButton* m_rateButton;
		wxButton* m_sendFriendsButton;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_linkTitleTextCtrl;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_urlTextCtrl;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_commentTextCtrl;
		wxCheckBox* m_submitAnonymousCheckBox;
		wxButton* m_copyLinkButton;
		wxButton* m_addLinkButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLinksClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLinksDoubleClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRatingSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRateClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSendToFriendsClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAnonymousClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCopyLinkClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddLinkClicked( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		LinkCloudDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger - Link Cloud"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~LinkCloudDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MessageSentDlg
///////////////////////////////////////////////////////////////////////////////
class MessageSentDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText12;
		wxStdDialogButtonSizer* m_LinkSentButtonSizer;
		wxButton* m_LinkSentButtonSizerOK;
	
	public:
		MessageSentDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger - Message Sent"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 312,117 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MessageSentDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ChatPage
///////////////////////////////////////////////////////////////////////////////
class ChatPage : public wxPanel 
{
	private:
	
	protected:
		enum
		{
			ID_CHAT_LOG_TEXT_CTRL = 1000,
			ID_MESSAGE_TEXT_CTRL,
		};
		
		wxHtmlWindow* m_chatLogTextCtrl;
		wxTextCtrl* m_messageTextCtrl;
		wxButton* m_sendButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnUrlClicked( wxHtmlLinkEvent& event ){ event.Skip(); }
		virtual void OnMessageUpdated( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSendClicked( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		ChatPage( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL );
		~ChatPage();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PopUpPersonalChat
///////////////////////////////////////////////////////////////////////////////
class PopUpPersonalChat : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_CHAT_LOG_TEXT_CTRL = 1000,
			ID_MESSAGE_TEXT_CTRL,
		};
		
		wxStaticText* m_staticText12;
		wxTextCtrl* m_chatLogTextCtrl;
		wxButton* m_sendButton;
		wxTextCtrl* m_messageTextCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSendClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMessageUpdated( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		PopUpPersonalChat( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger - Personal Chat"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~PopUpPersonalChat();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ProgressDlg
///////////////////////////////////////////////////////////////////////////////
class ProgressDlg : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_PROGRESS_GAUGE = 1000,
		};
		
		wxStaticText* m_statusStaticText;
		wxGauge* m_progressGauge;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		ProgressDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("RetroMessenger Progress"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~ProgressDlg();
	
};

#endif //__RetroMessenger_GUI__
