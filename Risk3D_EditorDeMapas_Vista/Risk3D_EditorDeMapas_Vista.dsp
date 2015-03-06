# Microsoft Developer Studio Project File - Name="Risk3D_EditorDeMapas_Vista" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Risk3D_EditorDeMapas_Vista - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_EditorDeMapas_Vista.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_EditorDeMapas_Vista.mak" CFG="Risk3D_EditorDeMapas_Vista - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Risk3D_EditorDeMapas_Vista - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Risk3D_EditorDeMapas_Vista - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Risk3D_EditorDeMapas_Vista - Win32 Release"

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
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Risk3D_EditorDeMapas_Vista - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Risk3D_EditorDeMapas_Controlador" /I "..\Risk3D_MVC" /I "..\Risk3D_Modelo" /I "..\Risk3D_GTK_Comun" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x2c0a /d "_DEBUG"
# ADD RSC /l 0x2c0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glib-2.0.lib gobject-2.0.lib gthread-2.0.lib gdk-win32-2.0.lib gdk_pixbuf-2.0.lib gtk-win32-2.0.lib atk-1.0.lib pango-1.0.lib /nologo /entry:"mainCRTStartup" /subsystem:console /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Risk3D_EditorDeMapas_Vista - Win32 Release"
# Name "Risk3D_EditorDeMapas_Vista - Win32 Debug"
# Begin Group "Ventana Principal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\area_de_edicion.cpp
# End Source File
# Begin Source File

SOURCE=.\area_de_edicion.h
# End Source File
# Begin Source File

SOURCE=.\barra_de_estado.cpp
# End Source File
# Begin Source File

SOURCE=.\barra_de_estado.h
# End Source File
# Begin Source File

SOURCE=.\menu_ventana_principal.cpp
# End Source File
# Begin Source File

SOURCE=.\menu_ventana_principal.h
# End Source File
# Begin Source File

SOURCE=.\ventana_principal.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_principal.h
# End Source File
# End Group
# Begin Group "Carteles"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_pregunta_si_no.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_pregunta_si_no.h
# End Source File
# End Group
# Begin Group "Archivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_exploracion_archivos.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_exploracion_archivos.h
# End Source File
# End Group
# Begin Group "Edicion"

# PROP Default_Filter ""
# Begin Group "Objetivos"

# PROP Default_Filter ""
# Begin Group "Administracion Objetivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_administracion_objetivos.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_administracion_objetivos.h
# End Source File
# End Group
# Begin Group "Edicion Objetivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ventana_edicion_objetivo.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_edicion_objetivo.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\ventana_crear_continente.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_crear_continente.h
# End Source File
# Begin Source File

SOURCE=.\ventana_edicion_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_edicion_territorio.h
# End Source File
# Begin Source File

SOURCE=.\ventana_eliminar_continente.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_eliminar_continente.h
# End Source File
# Begin Source File

SOURCE=.\ventana_modificar_continente.cpp
# End Source File
# Begin Source File

SOURCE=.\ventana_modificar_continente.h
# End Source File
# End Group
# Begin Group "Varios"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\textura.cpp
# End Source File
# Begin Source File

SOURCE=.\textura.h
# End Source File
# End Group
# Begin Group "Iconos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\icono_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\icono_territorio.h
# End Source File
# Begin Source File

SOURCE=.\icono_territorio_activo.cpp
# End Source File
# Begin Source File

SOURCE=.\icono_territorio_activo.h
# End Source File
# Begin Source File

SOURCE=.\icono_territorio_adyacente.cpp
# End Source File
# Begin Source File

SOURCE=.\icono_territorio_adyacente.h
# End Source File
# Begin Source File

SOURCE=.\icono_territorio_comun.cpp
# End Source File
# Begin Source File

SOURCE=.\icono_territorio_comun.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Target
# End Project
