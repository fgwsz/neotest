$root_path=Split-Path -Parent $MyInvocation.MyCommand.Definition
$build_path=Join-Path $root_path "build/windows/release"
$binary_release_path=Join-Path $root_path "binary-release.exe"

if(Test-Path -Path $build_path){
    Remove-Item $build_path -Recurse -Force
}
if(Test-Path -Path $binary_release_path){
    Remove-Item $binary_release_path -Recurse -Force
}
