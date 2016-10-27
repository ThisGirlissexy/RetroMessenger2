; Script generated with the Venis Install Wizard & Modified

; Define your application name
!define APPNAME "RetroMessenger"
!define VERSION "0.1.00"
!define APPNAMEANDVERSION "${APPNAME} ${VERSION}"

; Main Install settings
Name "${APPNAMEANDVERSION}"
InstallDir "$PROGRAMFILES\RetroMessenger"
InstallDirRegKey HKLM "Software\${APPNAME}" ""
OutFile "RetroMessenger_${VERSION}_setup.exe"
BrandingText "${APPNAMEANDVERSION}"
; Use compression
SetCompressor LZMA

; Modern interface settings
!include Sections.nsh
!include "MUI.nsh"

;Interface Settings
!define MUI_ABORTWARNING
;!define MUI_HEADERIMAGE
;!define MUI_HEADERIMAGE_BITMAP "starlogo.png" ; optional

# MUI defines
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\orange-install.ico"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_LICENSEPAGE_RADIOBUTTONS
!define MUI_COMPONENTSPAGE_SMALLDESC
!define MUI_FINISHPAGE_LINK "Visit the RetroMessenger forum for the latest news and support"
!define MUI_FINISHPAGE_LINK_LOCATION "http://sourceforge.net/forum/forum.php?forum_id=845664"
!define MUI_FINISHPAGE_RUN "$INSTDIR\RetroMessenger.exe"
!define MUI_FINISHPAGE_SHOWREADME $INSTDIR\changelog.txt
!define MUI_FINISHPAGE_SHOWREADME_TEXT changelog.txt
!define MUI_FINISHPAGE_SHOWREADME_NOTCHECKED
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall.ico"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE
!define MUI_LANGDLL_REGISTRY_ROOT HKLM
!define MUI_LANGDLL_REGISTRY_KEY ${REGKEY}
!define MUI_LANGDLL_REGISTRY_VALUENAME InstallerLanguage

; !define MUI_WELCOMEPAGE_TEXT "This wizard will guide you through the installation of RetroMessenger. \r\n\r\nIt is recommended that you close all other applications before starting Setup. This will make it possible to update relevant system files without havinf to reboot your computer. \r\n\r\nIMPORTANT: Ensure that RetroMessenger is NOT RUNNING before continuing (you can exit from the taskbar menu), otherwise the installer cannot update the executables, and the installation will fail. \r\n\r\nClick Next to continue. "

!define MUI_WELCOMEPAGE_TEXT "This wizard will guide you through the installation of RetroMessenger. \r\n\r\nIMPORTANT: Ensure that RetroMessenger is NOT RUNNING before continuing (you can exit from the taskbar menu), otherwise the installer cannot update the executables, and the installation will fail. \r\n\r\nClick Next to continue. "


; Defines the un-/installer logo of RetroMessenger
!insertmacro MUI_DEFAULT MUI_WELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange.bmp"
!insertmacro MUI_DEFAULT MUI_UNWELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange-uninstall.bmp"

; Set languages (first is default language)
!insertmacro MUI_RESERVEFILE_LANGDLL
ReserveFile "${NSISDIR}\Plugins\AdvSplash.dll"

;--------------------------------
;Configuration


  ;!insertmacro MUI_RESERVEFILE_SPECIALBITMAP
 
  LicenseLangString myLicenseData 1033 "license.txt"


  LicenseData $(myLicenseData)

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "$(myLicenseData)"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English


  ;Component-selection page
    ;Titles
    
    LangString sec_main ${LANG_ENGLISH} "Program Files"
    LangString sec_link ${LANG_ENGLISH} "File Association"
    LangString sec_autostart ${LANG_ENGLISH} "Auto Startup"
    LangString DESC_sec_main ${LANG_ENGLISH} "Installs the RetroMessenger program files."
    LangString DESC_sec_link ${LANG_ENGLISH} "Associate RetroMessenger with .pqi file extension"
    LangString DESC_sec_autostart ${LANG_ENGLISH} "Auto-Run and Login at Startup"
    LangString LANGUAGEID ${LANG_ENGLISH} "1033"

 
    

!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

Section $(sec_main) sec_main

  ;Set Section required
  SectionIn RO

  ; Set Section properties
  SetOverwrite on

  ; Clears previous error logs
  Delete "$INSTDIR\*.log"
	
  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\"
  File /r "..\..\bin\RetroMessenger.exe"
  File /r "..\..\bin\mingwm10.dll"
  File /r "..\changelog.txt"

  

SectionEnd

Section  $(sec_data) sec_data

  ; Set Section properties
  SetOverwrite on

  ; Set Section Files and Shortcuts
  SetOutPath "$INSTDIR\RetroMessenger\"
  ;File /r "data\*"
  
  
	
SectionEnd



Section $(sec_link) sec_link
  ; Delete any existing keys


  ; Write the file association
  WriteRegStr HKCR .pqi "" retroshare
  WriteRegStr HKCR retroshare "" "PQI File"
  WriteRegBin HKCR retroshare EditFlags 00000100
  WriteRegStr HKCR "retroshare\shell" "" open
  WriteRegStr HKCR "retroshare\shell\open\command" "" `"$INSTDIR\RetroMessenger.exe" "%1"`

SectionEnd



Section  Desktop SEC0002
  

  CreateShortCut "$DESKTOP\${APPNAME}.lnk" "$INSTDIR\RetroMessenger.exe" "" "$INSTDIR\RetroShare.exe" 0
  
SectionEnd

Section  Quicklaunchbar SEC0003
  

  CreateShortCut "$QUICKLAUNCH\${APPNAME}.lnk" "$INSTDIR\RetroMessenger.exe" "" "$INSTDIR\RetroShare.exe" 0
  
SectionEnd
SectionGroupEnd        

Section $(sec_autostart) sec_autostart

  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Run" "RetroRun"   "$INSTDIR\${APPNAME}.exe -a"
  
SectionEnd

Section -FinishSection

  WriteRegStr HKLM "Software\${APPNAME}" "" "$INSTDIR"
  WriteRegStr HKLM "Software\${APPNAME}" "Version" "${VERSION}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "DisplayName" "${APPNAME}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}" "UninstallString" "$INSTDIR\uninstall.exe"
  WriteUninstaller "$INSTDIR\uninstall.exe"

SectionEnd



;--------------------------------
;Descriptions

!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${sec_main} $(DESC_sec_main)
    !insertmacro MUI_DESCRIPTION_TEXT ${sec_data} $(DESC_sec_data)
    !insertmacro MUI_DESCRIPTION_TEXT ${sec_shortcuts} $(DESC_sec_shortcuts)
    !insertmacro MUI_DESCRIPTION_TEXT ${sec_link} $(DESC_sec_link)
	!insertmacro MUI_DESCRIPTION_TEXT ${sec_autostart} $(DESC_sec_autostart)
!insertmacro MUI_FUNCTION_DESCRIPTION_END

;Uninstall section
Section "Uninstall"
  
  ; Remove file association registry keys
  DeleteRegKey HKCR .pqi
  DeleteRegKey HKCR retromessenger
	
  ; Remove program/uninstall registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APPNAME}"
  DeleteRegKey HKLM SOFTWARE\${APPNAME}

  DeleteRegValue HKCU "Software\Microsoft\Windows\CurrentVersion\Run" "RetroRun"

  ; Remove files and uninstaller
  Delete $INSTDIR\RetroMessenger.exe
  Delete $INSTDIR\*.dll
  Delete $INSTDIR\*.dat
  Delete $INSTDIR\*.txt
  Delete $INSTDIR\*.ini
  Delete $INSTDIR\*.log

  Delete $INSTDIR\uninstall.exe

  ; Remove the kadc.ini file.
  ; Don't remove the directory, otherwise
  ; we lose the XPGP keys.
  ; Should make this an option though...
  Delete $INSTDIR\RetroMessenger\kadc.ini

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\${APPNAME}\*.*"

  ; Remove desktop shortcut
  Delete "$DESKTOP\${APPNAME}.lnk"
  
  ; Remove Quicklaunch shortcut
  Delete "$QUICKLAUNCH\${APPNAME}.lnk"

  ; Remove directories used
  RMDir "$SMPROGRAMS\${APPNAME}"
  RMDir "$INSTDIR"

SectionEnd

Function .onInit

    InitPluginsDir
    Push $R1
    File /oname=$PLUGINSDIR\spltmp.bmp "splash.bmp"
    advsplash::show 1200 1000 1000 -1 $PLUGINSDIR\spltmp
    Pop $R1
    Pop $R1
    !insertmacro MUI_LANGDLL_DISPLAY



FunctionEnd


# Installer Language Strings


LangString ^UninstallLink ${LANG_ENGLISH} "Uninstall"





; eof
