; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Eternal Deck Builder"
#define MyAppVersion "Eternal Deck Builder - beta 1.0 "
#define MyAppPublisher "Zugzwangs"
#define MyAppURL "https://github.com/Zugzwangs/Eternal-Deck-Builder"
#define MyAppExeName "Eternal.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{0E3BB79C-D3EA-403D-9C3B-473D2F90C403}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
LicenseFile=D:\Eternal-Deck-Builder\docs\License.txt
OutputDir=D:\Eternal-Deck-Builder\Installer
OutputBaseFilename=Eternal_deck_builder_setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Dirs]
Name: "{app}\bin"
Name: "{app}\bin\platforms"
Name: "{app}\bin\sqldrivers"
Name: "{app}\bin\printsupport"
Name: "{app}\bin\imageformats"
Name: "{app}\Cartes"
Name: "{app}\Decks"
Name: "{app}\docs"


[Files]
Source: "D:\Eternal-Deck-Builder\bin\Eternal.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\docs\*"; DestDir: "{app}\docs"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\Eternal-Deck-Builder\bin\cfg.ini"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\eternal.log"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Eternal_resource.rc"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\icudt51.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\icuin51.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\icuuc51.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\libgcc_s_dw2-1.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\libstdc++-6.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\libwinpthread-1.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Qt5Core.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Qt5Gui.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Qt5Network.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Qt5PrintSupport.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Qt5Sql.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\Qt5Widgets.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\VtesCardsListDB"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\platforms\qwindows.dll"; DestDir: "{app}\bin\platforms"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\sqldrivers\qsqlite.dll"; DestDir: "{app}\bin\sqldrivers"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\printsupport\windowsprintersupport.dll"; DestDir: "{app}\bin\printsupport"; Flags: ignoreversion
Source: "D:\Eternal-Deck-Builder\bin\imageformats\*"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\bin\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\bin\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\bin\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

