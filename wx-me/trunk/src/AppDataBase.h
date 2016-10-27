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

#ifndef APPDATABASE_H
#define APPDATABASE_H

#include <wx/xml/xml.h>
#include <wx/filename.h>

// Macros
/**
	Use to simplify declaring and creating getters and setters for variables.
	@warning This macro changes the scopping to @ppublic for your class so put it last in your
	class definition.
*/
#define DECLARE_VAR( TYPE, VAR )																			\
private:																									\
	TYPE m_##VAR;																							\
public:																										\
	TYPE Get##VAR()	const																					\
	{																										\
		return m_##VAR;																						\
	}																										\
	void Set##VAR( const TYPE set )																				\
	{																										\
		m_##VAR = set;																						\
	}

/** Static class that contains your applications settings. */
class ApplicationDataBase
{
public:
	/** Constructor. This sets the executable path automatically for the application. */
	ApplicationDataBase();

	/** Destructor. */
	virtual ~ApplicationDataBase(){}

	/**
		Saves the settings to an xml file.
		It defaults to output in the executables path with a name of 'settings.xml'
		@returns True if the document is saved, else false for a failure.
	*/
	bool SaveToFile( const wxString& fileFullPath = wxEmptyString );

	/**
		Saves the current windows position to an element under <forms>.
		@param formName Name of the form you are saving the data for.
	*/
	void SavePosition( const wxString& formName );

	/**
		Impliment this to save the additional settings to an xml file.
		It defaults to output in the executables path with a name of 'settings.xml'
		@returns True if the document is saved, else false for a failure.
	*/
	virtual void SaveAdditional(){}

	/**
		Loads the settings from an xml file.
		It defaults to take it's input from a file name of 'settings.xml'
		located in the executables directory.
		@returns True if the document is loaded, else false for a failure.
	*/
	bool LoadFromFile( const wxString& fileFullPath = wxEmptyString );

	/**
		Impliment this to load the additional settings from an xml file.
		This is the way you can add more settings to your own derived ApplicationDataBase
		It defaults to take it's input from a file name of 'settings.xml'
		located in the executables directory.
		@param node Current node that the LoadFromFile() function is processing.
		            Ignore this if you only need to get to the built-in data nodes.
		@returns True if the specific data is loaded, else false for a failure.
	*/
	virtual bool LoadAdditional( const wxXmlNode* /*node*/ ){ return true; }

	/**
		Processes the @p app xml node.
		@param appNode The @p app node in the xml file.
	*/
	void ProcessAppNode( const wxXmlNode* appNode );

	/**
		Processes the @p directories xml node.
		@param dirNode The @p directories node in the xml file.
	*/
	void ProcessDirectoriesNode( const wxXmlNode* dirNode );

	/**
		Processes the @p forms xml node.
		@param formsNode The @p forms node in the xml file.
	*/
	void ProcessFormsNode( const wxXmlNode* formsNode );

	/**
		Gets the applications settings path.
		@returns Applications settings path.
		@see SetSettingsPath().
	*/
	wxString GetSettingsPath();

	/**
		Sets the settings path for the application.
		@param settingsPath Path to set.
		@see GetSettingsPath().
	*/
	void SetSettingsPath( const wxString& settingsPath );

	/**
		Gets the path where images for the application are located.
		@returns Path to the applications BakeFile directory.
		@see SetImagePath().
	*/
	wxString GetImagePath();

	/**
		Sets the image path for the application.
		@param imagePath Path to set.
		@see GetImagePath().
	*/
	void SetImagePath( const wxString& imagesPath );

	/**
		Gets the path where images for the application are located.
		@returns Path to the applications BakeFile directory.
		@see SetResourcePath().
	*/
	wxString GetResourcePath();

	/**
		Sets the image path for the application.
		@param imagePath Path to set.
		@see GetResourcePath().
	*/
	void SetResourcePath( const wxString& resourcePath );

	/**
		Gets the executables path.
		@returns Path to the executable.
	*/
	wxString GetExePath();

	/**
		Gets the root node from the file with the application data.
		@returns Root xml node from the application data saved file.
	*/
	wxXmlNode* GetRootNode();

	/**
		Gets the directories node from the file with the application data.
		@returns Directories xml node from the application data saved file.
	*/
	wxXmlNode* GetDirectoriesNode();

	/**
		Gets the forms node from the file with the application data.
		@returns Forms xml node from the application data saved file.
	*/
	wxXmlNode* GetFormsNode();

	/**
		Gets the app node from the file with the application data.
		@returns App xml node from the application data saved file.
	*/
	wxXmlNode* GetAppNode();

	/**
		Gets the applications major version.
		@returns Major version of the application.
	*/
	int GetMajorVersion();

	/**
		Gets the applications minor version.
		@returns Minor version of the application.
	*/
	int GetMinorVersion();

	/**
		Gets the applications build number.
		@returns Build number of the application.
	*/
	int GetBuildNumber();

	/**
		Gets the applications version information as a humanly readable format.
		The format is MAJOR.MINOR.BUILD or MAJOR.MINOR build BUILD.
		@param separateBuildNum [DEF] If true the string returned will be in MAJOR.MINOR build BUILD
		                        format, else MAJOR.MINOR.BUILD format.
		@returns Applications version informating is a humanly readable format.
	*/
	wxString GetVersionString( bool separateBuildNum = false );

	/**
		Sets the forms X  position.
		@ x Position to set.
	*/
	void SetPositionX( int x );
	
	/**
		Get the forms X position.
		@returns X position of the form.
	*/
	int GetPositionX();
	
	/**
		Sets the forms Y position.
		@ y Position to set.
	*/
	void SetPositionY( int y );

	/**
		Get the forms X position.
		@returns Y position of the form.	
	*/
	int GetPositionY();
	
	/**
		Sets the forms width.
		@param w Width to set.
	*/
	void SetSizeWidth( int w );
	
	/**
		Gets the forms width.
		@returns Width of the form.
	*/
	int GetSizeWidth();

	/**
		Sets the forms height.
		@param h Height to set.
	*/
	void SetSizeHeight( int h );
	
	/**
		Gets the forms height.
		@returns Height of the form.
	*/
	int GetSizeHeight();

	/**
		Sets the applications data iconized state.
	*/
	void SetIsIconized( bool iconized );

	/**
		Gets if the application was minimized before settings save.
		@returns true is the application was minimized, else false.
	*/
	bool GetIsIconized();

	/**
		Sets the applications data maximized state.
	*/
	void SetIsMaximized( bool iconized );

	/**
		Gets if the application was maximized before settings save.
		@returns true is the application was maximized, else false.
	*/
	bool GetIsMaximized();

protected:
	/**
		Gets the full path including the path, file name, and extension.
		@returns Full settings file path and name with extention.
	*/
	wxFileName GetSettingsFileName();

	/**
		Sets the full path, with the file name and extension, to the settings file.
		@param fileName Full settings file path and name with extention.
	*/
	void SetSettingsFileName( const wxFileName& fileName );

	/**
		Sets the applications major version.
		@param majorVersion Major version of the application.
	*/
	void SetMajorVersion( const wxString& majorVersion );

	/**
		Sets the applications minor version.
		@param minorVersion Minor version of the application.
	*/
	void SetMinorVersion( const wxString& minorVersion );

	/**
		Sets the applications build number.
		@param buildNum Build number of the application.
	*/
	void SetBuildNumber( const wxString& buildNum );

	/**
		Add a path separator to the end of a path if it doesn't already exist.
		@param path Path to add a path separator to the end of.
		@returns Path with a path separator appended to the end if it didn't already have one.
	*/
	wxString AddPathSeparator( const wxString& path );

private:
	int				m_majorVersion;			//**< Application major version. */
	int				m_minorVersion;			//**< Application minor version. */
	int				m_buildVersion;			//**< Application build number. */
	int				m_posX;					//**< Applications X position. */
	int				m_posY;					//**< Applications Y position. */
	int				m_sizeW;				//**< Applications width. */
	int				m_sizeH;				//**< Applications height. */
	bool			m_isIconized;			//**< Applications iconized state. */
	bool			m_isMaximized;			//**< Applications maximized state. */
	wxString		m_exePath;				//**< Executables path. */
	wxString		m_resourcePath;			//**< Directory where the programs reources are kept. (ie. license)
	wxString		m_imagesPath;			//**< Directory where the programs images are kept. (ie. Banner and pictures) */
	wxString		m_settingPath;			//**< Program settings path. */
	wxFileName		m_settingsFileName;		//**< Full path with file name and extension. */

	wxXmlDocument	m_settingsDoc;			//**< Settings xml file. */
	wxXmlNode*		m_rootNode;				//**< Root XML node element. */
	wxXmlNode*		m_appNode;				//**< XML node for the applications configuration. */
	wxXmlNode*		m_directoriesNode;		//**< XML node for the directories relavent to the application. */
	wxXmlNode*		m_formsNode;			//**< XML node for the forms settings.

	/** Gets the executable path in a cross-platform way. */
	wxString GetExecutablePath();

	/**
		Sets the version information in the application data.
	*/
	void SetFileVersion();
};

#endif // APPDATABASE_H
