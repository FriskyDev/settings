@REM copies the _template_ project to a new project name
@ECHO OFF
SET PROJ=%1
SHIFT

@ECHO Creating new C++ project %PROJ%...
XCOPY /S/I/V/Q _template_ %PROJ%

