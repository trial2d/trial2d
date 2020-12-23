@echo off
set BUILD_DIR=%~dp0%\..\build
mkdir %BUILD_DIR%\msvc2017_win || goto :error
pushd %BUILD_DIR%\msvc2017_win || goto :error
cmake -G "Visual Studio 15 2017" ..\.. || goto :error
start trial2d.sln || goto :error
popd || goto :error

goto :EOF

:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%
