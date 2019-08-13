; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{6D5D196C-1793-4C0B-843F-7009F6F330FD}
AppName=FillCell
AppVersion=2.2.1
AppPublisher=CCST - INPE
AppPublisherURL=http://luccme.ccst.inpe.br/
AppSupportURL=http://luccme.ccst.inpe.br/
AppUpdatesURL=http://luccme.ccst.inpe.br/
DefaultDirName=C:\FillCell
DisableDirPage=yes
DefaultGroupName=FillCell
DisableProgramGroupPage=yes
LicenseFile=D:\_SVN\LuccME\branches\InterfaceCellFill\Project1\Resources\comment.txt
OutputDir=D:\Diego\Desktop
OutputBaseFilename=FillCell_2.2.1
SetupIconFile=D:\_SVN\LuccME\branches\InterfaceCellFill\Project1\Resources\icon.ico
Compression=lzma
SolidCompression=yes
UninstallFilesDir=C:\FillCell
;ChangesEnvironment=yes
UninstallDisplayIcon={app}\icon.ico

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}";

[Files]
Source: "D:\_SVN\LuccME\branches\InterfaceCellFill\x64\Release\FillCell 2.2.exe"; DestDir: "C:\FillCell"; Flags: ignoreversion;
Source: "D:\_SVN\LuccME\branches\InterfaceCellFill\x64\Release\*"; DestDir: "C:\FillCell"; Flags: ignoreversion recursesubdirs createallsubdirs;
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\FillCell"; Filename: "C:\FillCell\FillCell 2.2.exe"
Name: "{group}\{cm:UninstallProgram,FillCell}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\FillCell 2.2"; Filename: "C:\FillCell\FillCell 2.2.exe"; Tasks: desktopicon
