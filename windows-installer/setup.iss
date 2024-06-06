[Setup]
AppName=YouTube Downloader
AppVersion=1.0
DefaultDirName={commonpf}\YouTube Downloader
DisableDirPage=yes
DefaultGroupName=YouTube Downloader
DisableProgramGroupPage=yes
ChangesEnvironment=yes
SetupIconFile=YouTube Downloader\icon.ico
OutputDir=Output
OutputBaseFilename=YouTube Downloader Setup

SolidCompression=yes
Compression=lzma2/ultra64
LZMAUseSeparateProcess=yes
LZMADictionarySize=1048576
LZMANumFastBytes=273

[Files]
Source: "YouTube Downloader\*"; DestDir: "{app}"; Flags: recursesubdirs
Source: "yt-dlp\yt-dlp.exe"; DestDir: "{commonpf}\yt-dlp"
Source: "ffmpeg\bin\ffmpeg.exe"; DestDir: "{commonpf}\ffmpeg"
Source: "ffmpeg\bin\ffplay.exe"; DestDir: "{commonpf}\ffmpeg"
Source: "ffmpeg\bin\ffprobe.exe"; DestDir: "{commonpf}\ffmpeg"

[Icons]
Name: "{group}\YouTube Downloader"; Filename: "{app}\YouTube Downloader.exe"; IconFilename: "{app}\icon.ico"

[Run]
Filename: {app}\{cm:AppName}.exe; Description: {cm:LaunchProgram,{cm:AppName}}; Flags: nowait postinstall skipifsilent

[CustomMessages]
AppName=YouTube Downloader
LaunchProgram=Open after finishing installation

[Registry]
; set PATH
Root: HKCU; Subkey: "Environment"; ValueType:string; ValueName:"PATH"; ValueData:"{olddata};{commonpf}\yt-dlp;{commonpf}\ffmpeg\bin;"; Flags: preservestringtype
