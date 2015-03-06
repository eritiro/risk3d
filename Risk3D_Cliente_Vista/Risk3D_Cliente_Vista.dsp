# Microsoft Developer Studio Project File - Name="Risk3D_Cliente_Vista" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Risk3D_Cliente_Vista - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Cliente_Vista.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Cliente_Vista.mak" CFG="Risk3D_Cliente_Vista - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Risk3D_Cliente_Vista - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Risk3D_Cliente_Vista - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Risk3D_Cliente_Vista - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Risk3D_Cliente_Vista - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Risk3D_MVC" /I "..\Risk3D_Modelo" /I "..\Risk3D_Cliente_Controlador" /I "..\Risk3D_Cliente_Modelo" /I "..\Risk3D_GTK_Comun" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x2c0a /d "_DEBUG"
# ADD RSC /l 0x2c0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib opengl32.lib glu32.lib ws2_32.lib glaux.lib glib-2.0.lib gobject-2.0.lib gthread-2.0.lib gdk-win32-2.0.lib gdk_pixbuf-2.0.lib gtk-win32-2.0.lib atk-1.0.lib pango-1.0.lib gtkglext-win32-1.0.lib gdkglext-win32-1.0.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Risk3D_Cliente_Vista - Win32 Release"
# Name "Risk3D_Cliente_Vista - Win32 Debug"
# Begin Group "Pantalla Principal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pantalla_principal.cpp
# End Source File
# Begin Source File

SOURCE=.\pantalla_principal.h
# End Source File
# End Group
# Begin Group "Pantalla Creacion De Juego"

# PROP Default_Filter ""
# Begin Group "Archivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_exploracion_archivos.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_exploracion_archivos.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\pantalla_creacion_de_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\pantalla_creacion_de_juego.h
# End Source File
# End Group
# Begin Group "Pantalla Seleccion De Servidor"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pantalla_seleccion_de_servidor.cpp
# End Source File
# Begin Source File

SOURCE=.\pantalla_seleccion_de_servidor.h
# End Source File
# End Group
# Begin Group "Pantalla Juego"

# PROP Default_Filter ""
# Begin Group "Barra De Estado"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\barra_de_estado.cpp
# End Source File
# Begin Source File

SOURCE=.\barra_de_estado.h
# End Source File
# End Group
# Begin Group "Areas de Juego"

# PROP Default_Filter ""
# Begin Group "Area 2D"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\area_de_juego_2d.cpp
# End Source File
# Begin Source File

SOURCE=.\area_de_juego_2d.h
# End Source File
# Begin Source File

SOURCE=.\icono_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\icono_territorio.h
# End Source File
# End Group
# Begin Group "Area 3D"

# PROP Default_Filter ""
# Begin Group "Soporte Picking"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ciudad.cpp
# End Source File
# Begin Source File

SOURCE=.\ciudad.h
# End Source File
# Begin Source File

SOURCE=.\math3d.cpp
# End Source File
# Begin Source File

SOURCE=.\math3d.h
# End Source File
# Begin Source File

SOURCE=.\ray_cyl.cpp
# End Source File
# Begin Source File

SOURCE=.\ray_cyl.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\area_de_juego_3d.cpp
# End Source File
# Begin Source File

SOURCE=.\area_de_juego_3d.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\area_de_juego.h
# End Source File
# End Group
# Begin Group "Iconos"

# PROP Default_Filter ""
# End Group
# Begin Group "Ventana De Informacion"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_de_informacion.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_de_informacion.h
# End Source File
# End Group
# Begin Group "Ventana Mostrar Objetivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_mostrar_objetivo.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_mostrar_objetivo.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\pantalla_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\pantalla_juego.h
# End Source File
# End Group
# Begin Group "Manejo De Graficos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\color.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_color_invalido.h
# End Source File
# Begin Source File

SOURCE=.\vista_color_imperio.cpp
# End Source File
# Begin Source File

SOURCE=.\vista_color_imperio.h
# End Source File
# End Group
# Begin Group "Pantalla Seleccion De Imperio"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pantalla_seleccion_de_imperio.cpp
# End Source File
# Begin Source File

SOURCE=.\pantalla_seleccion_de_imperio.h
# End Source File
# End Group
# Begin Group "Pantalla Previa Al Juego"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\pantalla_previa.cpp
# End Source File
# Begin Source File

SOURCE=.\pantalla_previa.h
# End Source File
# End Group
# Begin Group "General"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\constantes_vista.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Target
# End Project
