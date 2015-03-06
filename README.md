# risk3d

Risk 3D a multiplayer 2D / 3D Risk game (T.E.G.)
http://en.wikipedia.org/wiki/Risk_(game)

It is a student project made in 2007 for "Taller de Programación", a course of Computer engineering in Facultad de Ingenieria de la Universidad de Buenos Aires (FIUBA)
It is a C++ client/server system. 
It uses GTK graphical interface and OpenGL for 3D graphics.

The system consists of three different components:
* The client which connects to the server using sockets. It works in two different threads (one for GUI, and one for communication)
* The server which processes the game logic and handles client connections. It has a main thread for processing rules and multiple threads, one for each connection.
* The map editor which generates new map files.

The connection between client and server is made by TCP sockets.
All the rules are ensured by the server.

### Notes 
- All code and documentation (Except for this) is in spanish
- The naming convention of this project is very particular.
- Because it is a student project, we haven't put enough effort to the GUI design.
