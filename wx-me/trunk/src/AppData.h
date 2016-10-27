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

#ifndef APPDATA_H
#define APPDATA_H

#include "AppDataBase.h"
#include "RetroMessengerMainFrame.h"

// STL
#include <string>
#include <vector>

// RetroShare
#include <rsiface/rsiface.h>
#include <rsserver/p3face.h>
#include <rsiface/rspeers.h>

/**
	Simplifies the syntax needed to use the ApplicationData class.
	@returns ApplicationData pointer that you can use to get at the methods and
	public data contained in ApplicationData.
*/
#define AppData ApplicationData::Get()

/** Static class that contains your specific applications settings. */
class ApplicationData : public ApplicationDataBase
{
public:
	/**
		Returns the single instance of the ApplicationDataBase class.
		@note This class is setup to use a standard auto_ptr.
		      If you decide to use that method there is no reason to
			  call Destroy() unless you need to reset the ApplicationDataBase
			  class.

		Example cpp (app.cpp)
		@code
		#include "myapp.h"
		#include "appdata.h"

		bool MyApp::OnInit()
		{
			// Initialize application.

			m_globalData = std::auto_ptr< ApplicationDataBase >(AppData);
		}
		@endcode

		Example h (myapp.h)
		@code
		#ifndef MY_APP_H
		#define MY_APP_H

		#include <memory>

		class ApplicationDataBase;

		class MyApp : public wxApp
		{
		private:
			std::auto_ptr< ApplicationDataBase > m_globalData;
		public:
			virtual bool OnInit();
		};

		#endif // MY_APP_H
		@endcode
	*/
	static ApplicationData* Get();

	/**	Destructor. Clean up any resources that are needed here. */
	~ApplicationData();
	
	/**
		Saves the specific data for the application to the nodes already setup
		in the SaveToFile() function.
	*/
	virtual void SaveAdditional();

	/**
		Loads the specific data from the application data file.
		@param node Current node that the LoadFromFile() function is processing.
		            Ignore this if you only need to get to the built-in data nodes.
		@returns True if the specific data is loaded, else false for a failure.
	*/
	virtual bool LoadAdditional( const wxXmlNode* node );

	void ProcessSupportApps( wxXmlNode* supportAppsNode );

	inline RsPeerDetails GetRsPeerDetail()
	{
		return m_rsDetails;
	}
	
	inline RetroMessengerMainFrame* GetMainFrame()
	{
		return m_mainFrame;
	}
	
	inline void SetMainFrame( RetroMessengerMainFrame* mainFrame )
	{
		m_mainFrame = mainFrame;
	}
	
	/**
		Reset / Cleans up ApplicationDataBase.
		@note Use a standard auto_ptr to avoid having to worry about explicitly calling Destroy().
		@warning Use this with care. It is an advanced feature and only included for completeness.
	*/
	static void Destroy();
	
private:
	/** Singleton constructor. Use Get() to return an instance of the class.*/
	ApplicationData();
	
	// Application specific data.
	RsPeerDetails  m_rsDetails;
	RetroMessengerMainFrame* m_mainFrame;
	
	DECLARE_VAR( wxString, UserName )
	DECLARE_VAR( bool, ShouldAutoLogIn )
	DECLARE_VAR( bool, IsCertificateGenerated )
	DECLARE_VAR( bool, IsUserLoggedIn )
	DECLARE_VAR( std::string, PreferedId )
};

#endif	// APPDATA_H
