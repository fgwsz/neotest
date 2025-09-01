$root_path=Split-Path -Parent $MyInvocation.MyCommand.Definition
&"$root_path/clean-release.ps1"
&"$root_path/build-release.ps1"
