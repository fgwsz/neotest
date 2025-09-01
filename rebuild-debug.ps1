$root_path=Split-Path -Parent $MyInvocation.MyCommand.Definition
&"$root_path/clean-debug.ps1"
&"$root_path/build-debug.ps1"
