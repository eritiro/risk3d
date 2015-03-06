# Microsoft Developer Studio Project File - Name="Risk3D_EditorDeMapas_Controlador" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Risk3D_EditorDeMapas_Controlador - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_EditorDeMapas_Controlador.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_EditorDeMapas_Controlador.mak" CFG="Risk3D_EditorDeMapas_Controlador - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Risk3D_EditorDeMapas_Controlador - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Risk3D_EditorDeMapas_Controlador - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Risk3D_EditorDeMapas_Controlador - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x2c0a /d "NDEBUG"
# ADD RSC /l 0x2c0a /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Risk3D_EditorDeMapas_Controlador - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Risk3D_MVC" /I "..\Risk3D_Modelo" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x2c0a /d "_DEBUG"
# ADD RSC /l 0x2c0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Risk3D_EditorDeMapas_Controlador - Win32 Release"
# Name "Risk3D_EditorDeMapas_Controlador - Win32 Debug"
# Begin Group "Editor De Mapa"

# PROP Default_Filter ""
# Begin Group "Estrategia Edicion"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\estrategia_de_edicion.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_edicion_adyacencia.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_edicion_adyacencia.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_edicion_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_edicion_territorio.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_eliminar_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_eliminar_territorio.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_sin_seleccion.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_sin_seleccion.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\controlador_editor_de_mapa.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_editor_de_mapa.h
# End Source File
# Begin Source File

SOURCE=.\vista_editor_de_mapa.h
# End Source File
# End Group
# Begin Group "Crear Continente"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_crear_continente.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_crear_continente.h
# End Source File
# Begin Source File

SOURCE=.\vista_crear_continente.h
# End Source File
# End Group
# Begin Group "Modificar Continente"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_modificar_continente.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_modificar_continente.h
# End Source File
# Begin Source File

SOURCE=.\vista_modificar_continente.h
# End Source File
# End Group
# Begin Group "General"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\contexto_editor.cpp
# End Source File
# Begin Source File

SOURCE=.\contexto_editor.h
# End Source File
# Begin Source File

SOURCE=.\controlador_contexto.h
# End Source File
# Begin Source File

SOURCE=.\vista_contexto.h
# End Source File
# End Group
# Begin Group "Edicion Territorio"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_edicion_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_edicion_territorio.h
# End Source File
# Begin Source File

SOURCE=.\vista_edicion_territorio.h
# End Source File
# End Group
# Begin Group "Eliminar Continente"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_eliminar_continente.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_eliminar_continente.h
# End Source File
# Begin Source File

SOURCE=.\vista_eliminar_continente.h
# End Source File
# End Group
# Begin Group "Objetivos"

# PROP Default_Filter ""
# Begin Group "Administrar Objetivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_administrar_objetivos.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_administrar_objetivos.h
# End Source File
# Begin Source File

SOURCE=.\vista_administrar_objetivos.h
# End Source File
# End Group
# Begin Group "Editar Objetivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_editar_objetivo.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_editar_objetivo.h
# End Source File
# Begin Source File

SOURCE=.\vista_editar_objetivo.h
# End Source File
# End Group
# End Group
# End Target
# End Project
