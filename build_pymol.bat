@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
set "PATH=C:\Program Files\CMake\bin;%PATH%"
set "PREFIX_PATH=C:\vcpkg\installed\x64-windows-static;C:\vcpkg\installed\x64-windows-static\include\mmtf-cpp;C:\vcpkg\installed\x64-windows-static\include\msgpack-cxx"
cd /d "D:\Users\26416\projects\pymol-open-source"
.venv\Scripts\pip.exe install --no-build-isolation --no-deps --config-settings testing=False --config-settings libxml=True --config-settings vmd-plugins=True --config-settings use-msgpackc=c++11 --config-settings use-openmp=yes -e .
