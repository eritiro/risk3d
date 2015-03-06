# Microsoft Developer Studio Project File - Name="Risk3D_Cliente_Controlador" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Risk3D_Cliente_Controlador - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Cliente_Controlador.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Cliente_Controlador.mak" CFG="Risk3D_Cliente_Controlador - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Risk3D_Cliente_Controlador - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Risk3D_Cliente_Controlador - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Risk3D_Cliente_Controlador - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Risk3D_Cliente_Controlador - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\Risk3D_MVC" /I "..\Risk3D_Modelo" /I "..\Risk3D_Cliente_Modelo" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
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

# Name "Risk3D_Cliente_Controlador - Win32 Release"
# Name "Risk3D_Cliente_Controlador - Win32 Debug"
# Begin Group "General"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\contexto_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\contexto_juego.h
# End Source File
# Begin Source File

SOURCE=.\controlador_contexto.h
# End Source File
# Begin Source File

SOURCE=.\vista_contexto.h
# End Source File
# End Group
# Begin Group "Pantalla Principal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_pantalla_principal.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_pantalla_principal.h
# End Source File
# Begin Source File

SOURCE=.\vista_pantalla_principal.h
# End Source File
# End Group
# Begin Group "Pantalla Creacion De Juego"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_pantalla_creacion_de_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_pantalla_creacion_de_juego.h
# End Source File
# Begin Source File

SOURCE=.\vista_pantalla_creacion_de_juego.h
# End Source File
# End Group
# Begin Group "Pantalla Seleccion De Servidor"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_pantalla_seleccion_de_servidor.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_pantalla_seleccion_de_servidor.h
# End Source File
# Begin Source File

SOURCE=.\vista_pantalla_seleccion_de_servidor.h
# End Source File
# End Group
# Begin Group "Pantalla Juego"

# PROP Default_Filter ""
# Begin Group "Manejador De Mensajes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\manejador_de_mensajes.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_actualizacion.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_batalla_producida.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_de_chat.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_de_error.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_de_sistema.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_defensa_requerida.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_juego_cancelado.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_juego_terminado.h
# End Source File
# Begin Source File

SOURCE=.\manejador_mensaje_objetivo_secreto.h
# End Source File
# End Group
# Begin Group "Estrategia Juego"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\estrategia_ataque.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_ataque.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_de_juego.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_reagrupacion.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_reagrupacion.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_refuerzo.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_refuerzo.h
# End Source File
# Begin Source File

SOURCE=.\estrategia_sin_seleccion.cpp
# End Source File
# Begin Source File

SOURCE=.\estrategia_sin_seleccion.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\controlador_pantalla_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_pantalla_juego.h
# End Source File
# Begin Source File

SOURCE=.\vista_pantalla_juego.h
# End Source File
# End Group
# Begin Group "Pantalla Previa"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_pantalla_previa.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_pantalla_previa.h
# End Source File
# Begin Source File

SOURCE=.\vista_pantalla_previa.h
# End Source File
# End Group
# Begin Group "Pantala Seleccion De Imperio"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\controlador_pantalla_seleccion_de_imperio.cpp
# End Source File
# Begin Source File

SOURCE=.\controlador_pantalla_seleccion_de_imperio.h
# End Source File
# Begin Source File

SOURCE=.\vista_pantalla_seleccion_de_imperio.h
# End Source File
# End Group
# End Target
# End Project
