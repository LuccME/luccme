; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{1F80FBB1-2C18-4FC0-85FB-E82346A23938}
AppName=LuccME
AppVersion=3.0.2.0
;AppVerName=LuccME 1.0.2.1
AppPublisher=CCST - INPE
AppPublisherURL=http://luccme.ccst.inpe.br/
AppSupportURL=http://luccme.ccst.inpe.br/
AppUpdatesURL=http://luccme.ccst.inpe.br/
DefaultDirName=C:\LuccME
DisableDirPage=yes
DefaultGroupName=LuccME
DisableProgramGroupPage=yes
LicenseFile=D:\_SVN\LuccME\branches\Project2\Project1\Resources\comment.txt
OutputDir=D:\Diego Melo\Desktop
OutputBaseFilename=LuccME_3.0.2.0
SetupIconFile=D:\_SVN\LuccME\branches\Project2\Project1\Resources\icon.ico
Compression=lzma
SolidCompression=yes
UninstallFilesDir=C:\LuccME
;ChangesEnvironment=yes
UninstallDisplayIcon={app}\icon.ico

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}";

[Files]
Source: "D:\_SVN\LuccME\branches\Project2\Release\LuccME 3.0.exe"; DestDir: "C:\LuccME"; Flags: ignoreversion;
Source: "D:\_SVN\LuccME\branches\Project2\Release\*"; DestDir: "C:\LuccME"; Flags: ignoreversion recursesubdirs createallsubdirs;
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\LuccME"; Filename: "C:\LuccME\LuccME 3.0.exe"
Name: "{group}\{cm:UninstallProgram,LuccME}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\LuccME 3.0"; Filename: "C:\LuccME\LuccME 3.0.exe"; Tasks: desktopicon


;[Registry]
;Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; ValueType: string; ValueName: "TME_PATH_1_3_1"; ValueData: "C:\LuccME\TerraME"; Flags: uninsdeletevalue
;Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; ValueType: expandsz; ValueName: "Path"; ValueData: "{olddata};C:\LuccME\TerraME";
