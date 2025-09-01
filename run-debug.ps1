$root_path=Split-Path -Parent $MyInvocation.MyCommand.Definition
cd "$root_path"
&"$root_path/build-debug.ps1"
&"$root_path/binary-debug.exe"
