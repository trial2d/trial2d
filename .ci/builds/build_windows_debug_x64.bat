@echo off
set DIR=%~dp0

set ROOT_DIR=%DIR%..\..\
set BUILD_DIR=%ROOT_DIR%build\windows_debug_x64\

if not exist %BUILD_DIR% mkdir %BUILD_DIR% || goto :error
cmake -S %ROOT_DIR% -B %BUILD_DIR% -A x64 || goto :error
cmake --build %BUILD_DIR% --config Debug || goto :error

pushd %BUILD_DIR%
ctest --verbose
popd

goto :EOF

:error
echo Failed with error #%errorlevel%.
exit /b %errorlevel%
