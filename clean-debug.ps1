$root_path=Split-Path -Parent $MyInvocation.MyCommand.Definition
$build_path=Join-Path $root_path "build/windows/debug"
$binary_debug_path=Join-Path $root_path "binary-debug.exe"

if(Test-Path -Path $build_path){
    Remove-Item $build_path -Recurse -Force
}
if(Test-Path -Path $binary_debug_path){
    Remove-Item $binary_debug_path -Recurse -Force
}
