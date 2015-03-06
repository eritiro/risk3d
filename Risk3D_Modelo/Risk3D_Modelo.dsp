# Microsoft Developer Studio Project File - Name="Risk3D_Modelo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Risk3D_Modelo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Modelo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Risk3D_Modelo.mak" CFG="Risk3D_Modelo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Risk3D_Modelo - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Risk3D_Modelo - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Risk3D_Modelo - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Risk3D_Modelo - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /GZ /c
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

# Name "Risk3D_Modelo - Win32 Release"
# Name "Risk3D_Modelo - Win32 Debug"
# Begin Group "Entidades"

# PROP Default_Filter ""
# Begin Group "Terreno"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\configuracion_mapa.cpp
# End Source File
# Begin Source File

SOURCE=.\configuracion_mapa.h
# End Source File
# Begin Source File

SOURCE=.\constructor_de_mapa.cpp
# End Source File
# Begin Source File

SOURCE=.\constructor_de_mapa.h
# End Source File
# Begin Source File

SOURCE=.\continente.cpp
# End Source File
# Begin Source File

SOURCE=.\continente.h
# End Source File
# Begin Source File

SOURCE=.\mapa.cpp
# End Source File
# Begin Source File

SOURCE=.\mapa.h
# End Source File
# Begin Source File

SOURCE=.\territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\territorio.h
# End Source File
# End Group
# Begin Group "Contrincantes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\color_imperio.h
# End Source File
# Begin Source File

SOURCE=.\imperio.cpp
# End Source File
# Begin Source File

SOURCE=.\imperio.h
# End Source File
# Begin Source File

SOURCE=.\tropa.cpp
# End Source File
# Begin Source File

SOURCE=.\tropa.h
# End Source File
# End Group
# Begin Group "Juego"

# PROP Default_Filter ""
# Begin Group "Estados"

# PROP Default_Filter ""
# Begin Group "Turnos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\atacando.cpp
# End Source File
# Begin Source File

SOURCE=.\atacando.h
# End Source File
# Begin Source File

SOURCE=.\esperando_defensa.cpp
# End Source File
# Begin Source File

SOURCE=.\esperando_defensa.h
# End Source File
# Begin Source File

SOURCE=.\estado_belico.cpp
# End Source File
# Begin Source File

SOURCE=.\estado_belico.h
# End Source File
# Begin Source File

SOURCE=.\reforzando_territorios.cpp
# End Source File
# Begin Source File

SOURCE=.\reforzando_territorios.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\asignando_inicialmente_tropas.cpp
# End Source File
# Begin Source File

SOURCE=.\asignando_inicialmente_tropas.h
# End Source File
# Begin Source File

SOURCE=.\creando_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\creando_juego.h
# End Source File
# Begin Source File

SOURCE=.\estado_del_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\estado_del_juego.h
# End Source File
# Begin Source File

SOURCE=.\fin_del_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\fin_del_juego.h
# End Source File
# End Group
# Begin Group "Ambientes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ambiente_de_juego.h
# End Source File
# Begin Source File

SOURCE=.\ambiente_normal.cpp
# End Source File
# Begin Source File

SOURCE=.\ambiente_normal.h
# End Source File
# End Group
# Begin Group "Rondas"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ronda.h
# End Source File
# Begin Source File

SOURCE=.\ronda_normal.cpp
# End Source File
# Begin Source File

SOURCE=.\ronda_normal.h
# End Source File
# End Group
# Begin Group "Combate"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\batalla.cpp
# End Source File
# Begin Source File

SOURCE=.\batalla.h
# End Source File
# End Group
# Begin Group "Inicializacion"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\repartidor_de_objetivos.cpp
# End Source File
# Begin Source File

SOURCE=.\repartidor_de_objetivos.h
# End Source File
# Begin Source File

SOURCE=.\repartidor_de_territorios.cpp
# End Source File
# Begin Source File

SOURCE=.\repartidor_de_territorios.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\excepcion_orden_invalida.h
# End Source File
# Begin Source File

SOURCE=.\info_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\info_juego.h
# End Source File
# Begin Source File

SOURCE=.\juego.cpp
# End Source File
# Begin Source File

SOURCE=.\juego.h
# End Source File
# End Group
# Begin Group "Jugadores"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\jugador.cpp
# End Source File
# Begin Source File

SOURCE=.\jugador.h
# End Source File
# Begin Source File

SOURCE=.\jugador_bot.h
# End Source File
# Begin Source File

SOURCE=.\jugador_bot_simple.cpp
# End Source File
# Begin Source File

SOURCE=.\jugador_bot_simple.h
# End Source File
# Begin Source File

SOURCE=.\jugador_de_prueba.cpp
# End Source File
# Begin Source File

SOURCE=.\jugador_de_prueba.h
# End Source File
# End Group
# Begin Group "Comunicacion"

# PROP Default_Filter ""
# Begin Group "Ordenes"

# PROP Default_Filter ""
# Begin Group "Movimientos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\orden_atacar.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_atacar.h
# End Source File
# Begin Source File

SOURCE=.\orden_defender.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_defender.h
# End Source File
# Begin Source File

SOURCE=.\orden_reagrupar_ejercitos.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_reagrupar_ejercitos.h
# End Source File
# Begin Source File

SOURCE=.\orden_reforzar_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_reforzar_territorio.h
# End Source File
# Begin Source File

SOURCE=.\orden_terminar_turno.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_terminar_turno.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\orden_agregar_jugador.cpp
# End Source File
# Begin Source File

SOURCE=.\orden_agregar_jugador.h
# End Source File
# Begin Source File

SOURCE=.\orden_cancelar_juego.h
# End Source File
# Begin Source File

SOURCE=.\orden_chatear.h
# End Source File
# Begin Source File

SOURCE=.\orden_comenzar_juego.h
# End Source File
# Begin Source File

SOURCE=.\orden_quitar_jugador.h
# End Source File
# End Group
# Begin Group "Mensajes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\actualizacion.h
# End Source File
# Begin Source File

SOURCE=.\defensa_requerida.h
# End Source File
# Begin Source File

SOURCE=.\evento_batalla_producida.h
# End Source File
# Begin Source File

SOURCE=.\evento_comienzo_turno.h
# End Source File
# Begin Source File

SOURCE=.\evento_juego_cancelado.h
# End Source File
# Begin Source File

SOURCE=.\evento_juego_iniciado.h
# End Source File
# Begin Source File

SOURCE=.\evento_juego_terminado.h
# End Source File
# Begin Source File

SOURCE=.\evento_jugador_agregado.h
# End Source File
# Begin Source File

SOURCE=.\mensaje_de_chat.h
# End Source File
# Begin Source File

SOURCE=.\mensaje_de_error.h
# End Source File
# Begin Source File

SOURCE=.\mensaje_de_sistema.h
# End Source File
# Begin Source File

SOURCE=.\mensaje_objetivo_secreto.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\fabrica_de_mensajes.cpp
# End Source File
# Begin Source File

SOURCE=.\fabrica_de_mensajes.h
# End Source File
# Begin Source File

SOURCE=.\fabrica_de_ordenes.cpp
# End Source File
# Begin Source File

SOURCE=.\fabrica_de_ordenes.h
# End Source File
# Begin Source File

SOURCE=.\mensaje.cpp
# End Source File
# Begin Source File

SOURCE=.\mensaje.h
# End Source File
# Begin Source File

SOURCE=.\orden.cpp
# End Source File
# Begin Source File

SOURCE=.\orden.h
# End Source File
# Begin Source File

SOURCE=.\tipo_de_mensaje.cpp
# End Source File
# Begin Source File

SOURCE=.\tipo_de_mensaje.h
# End Source File
# Begin Source File

SOURCE=.\tipo_de_orden.cpp
# End Source File
# Begin Source File

SOURCE=.\tipo_de_orden.h
# End Source File
# End Group
# Begin Group "Objetivos"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\objetivo.cpp
# End Source File
# Begin Source File

SOURCE=.\objetivo.h
# End Source File
# Begin Source File

SOURCE=.\objetivo_de_destruccion.cpp
# End Source File
# Begin Source File

SOURCE=.\objetivo_de_destruccion.h
# End Source File
# Begin Source File

SOURCE=.\objetivo_de_ocupacion.cpp
# End Source File
# Begin Source File

SOURCE=.\objetivo_de_ocupacion.h
# End Source File
# Begin Source File

SOURCE=.\requisito_de_ocupacion.cpp
# End Source File
# Begin Source File

SOURCE=.\requisito_de_ocupacion.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\identificable.h
# End Source File
# End Group
# Begin Group "Utilidades"

# PROP Default_Filter ""
# Begin Group "Manejo De Memoria"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ciclo_de_vida.cpp
# End Source File
# Begin Source File

SOURCE=.\ciclo_de_vida.h
# End Source File
# Begin Source File

SOURCE=.\tranferible.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\coordenada.cpp
# End Source File
# Begin Source File

SOURCE=.\coordenada.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_de_parseo.h
# End Source File
# Begin Source File

SOURCE=.\macros.h
# End Source File
# Begin Source File

SOURCE=.\utilidades_archivo.cpp
# End Source File
# Begin Source File

SOURCE=.\utilidades_archivo.h
# End Source File
# Begin Source File

SOURCE=.\utilidades_string.cpp
# End Source File
# Begin Source File

SOURCE=.\utilidades_string.h
# End Source File
# End Group
# Begin Group "Logueo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\log.cpp
# End Source File
# Begin Source File

SOURCE=.\log.h
# End Source File
# End Group
# Begin Group "Excepciones"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\excepcion_de_negocio.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_de_usuario.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_risk3d.cpp
# End Source File
# Begin Source File

SOURCE=.\excepcion_risk3d.h
# End Source File
# End Group
# Begin Group "Configuracion"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\constantes.h
# End Source File
# End Group
# Begin Group "Serializacion"

# PROP Default_Filter ""
# Begin Group "Serializacion De Ordenes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\serializador_orden_agregar_jugador.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_agregar_jugador.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_atacar.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_atacar.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_chatear.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_chatear.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_defender.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_defender.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_especifica.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_estandar.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_reagrupar_ejercitos.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_reagrupar_ejercitos.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_reforzar_territorio.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden_reforzar_territorio.h
# End Source File
# End Group
# Begin Group "Serializacion De Mensajes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\serializador_actualizacion.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_actualizacion.h
# End Source File
# Begin Source File

SOURCE=.\serializador_defensa_requerida.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_defensa_requerida.h
# End Source File
# Begin Source File

SOURCE=.\serializador_evento_batalla_producida.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_evento_batalla_producida.h
# End Source File
# Begin Source File

SOURCE=.\serializador_evento_juego_terminado.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_evento_juego_terminado.h
# End Source File
# Begin Source File

SOURCE=.\serializador_evento_jugador_agregado.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_evento_jugador_agregado.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_de_chat.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_de_chat.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_de_error.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_de_error.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_de_sistema.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_de_sistema.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_especifico.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_estandar.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_objetivo_secreto.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje_objetivo_secreto.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\excepcion_de_serializacion.h
# End Source File
# Begin Source File

SOURCE=.\serializador_info_juego.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_info_juego.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mapa.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_mapa.h
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_mensaje.h
# End Source File
# Begin Source File

SOURCE=.\serializador_orden.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_orden.h
# End Source File
# Begin Source File

SOURCE=.\serializador_requisito_de_ocupacion.cpp
# End Source File
# Begin Source File

SOURCE=.\serializador_requisito_de_ocupacion.h
# End Source File
# End Group
# Begin Group "Servicios"

# PROP Default_Filter ""
# Begin Group "Serializado"

# PROP Default_Filter ""
# Begin Group "Msxml"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\documento_de_xml.cpp
# End Source File
# Begin Source File

SOURCE=.\documento_de_xml.h
# End Source File
# Begin Source File

SOURCE=.\escritor_de_xml.cpp
# End Source File
# Begin Source File

SOURCE=.\escritor_de_xml.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_de_xml.h
# End Source File
# Begin Source File

SOURCE=.\lector_de_xml.cpp
# End Source File
# Begin Source File

SOURCE=.\lector_de_xml.h
# End Source File
# Begin Source File

SOURCE=.\nodo_xml.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\escritor.h
# End Source File
# Begin Source File

SOURCE=.\lector.h
# End Source File
# End Group
# Begin Group "Sockets"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\excepcion_de_socket.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_socket_cerrado.h
# End Source File
# Begin Source File

SOURCE=.\excepcion_socket_invalido.h
# End Source File
# Begin Source File

SOURCE=.\socket.cpp
# End Source File
# Begin Source File

SOURCE=.\socket.h
# End Source File
# End Group
# Begin Group "Concurrencia"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\excepcion_de_concurrencia.h
# End Source File
# Begin Source File

SOURCE=.\lock.cpp
# End Source File
# Begin Source File

SOURCE=.\lock.h
# End Source File
# Begin Source File

SOURCE=.\mutex.cpp
# End Source File
# Begin Source File

SOURCE=.\mutex.h
# End Source File
# Begin Source File

SOURCE=.\thread.cpp
# End Source File
# Begin Source File

SOURCE=.\thread.h
# End Source File
# End Group
# End Group
# End Target
# End Project
