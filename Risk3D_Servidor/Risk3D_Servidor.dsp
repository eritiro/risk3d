# Microsoft Developer Studio Project File - Name="Risk3D_Servidor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Risk3D_Servidor - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Servidor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Servidor.mak" CFG="Risk3D_Servidor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Risk3D_Servidor - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Risk3D_Servidor - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Risk3D_Servidor - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x2c0a /d "NDEBUG"
# ADD RSC /l 0x2c0a /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Risk3D_Servidor - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Risk3D_Modelo" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x2c0a /d "_DEBUG"
# ADD RSC /l 0x2c0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Risk3D_Servidor - Win32 Release"
# Name "Risk3D_Servidor - Win32 Debug"
# Begin Group "Proveedores"

# PROP Default_Filter ""
# Begin Group "Ordenes Remotas"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\hilo_envio.cpp
# End Source File
# Begin Source File

SOURCE=.\hilo_envio.h
# End Source File
# Begin Source File

SOURCE=.\hilo_recepcion.cpp
# End Source File
# Begin Source File

SOURCE=.\hilo_recepcion.h
# End Source File
# Begin Source File

SOURCE=.\jugador_remoto.cpp
# End Source File
# Begin Source File

SOURCE=.\jugador_remoto.h
# End Source File
# Begin Source File

SOURCE=.\oyente_de_peticiones.cpp
# End Source File
# Begin Source File

SOURCE=.\oyente_de_peticiones.h
# End Source File
# Begin Source File

SOURCE=.\proveedor_de_ordenes_remotas.cpp
# End Source File
# Begin Source File

SOURCE=.\proveedor_de_ordenes_remotas.h
# End Source File
# End Group
# Begin Group "Ordenes Desde Archivo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\proveedor_de_ordenes_desde_archivo.cpp
# End Source File
# Begin Source File

SOURCE=.\proveedor_de_ordenes_desde_archivo.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\proveedor_de_ordenes.h
# End Source File
# End Group
# Begin Group "Ambientes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ambiente_desde_archivo.cpp
# End Source File
# Begin Source File

SOURCE=.\ambiente_desde_archivo.h
# End Source File
# End Group
# Begin Group "Ordenes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\orden_extendida.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_extendida.h
# End Source File
# End Group
# Begin Group "Parser"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\excepcion_parseando_parametros.h
# End Source File
# Begin Source File

SOURCE=.\parser_de_parametros.cpp
# End Source File
# Begin Source File

SOURCE=.\parser_de_parametros.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Target
# End Project
