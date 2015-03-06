#pragma warning(disable:4786)


#include <gtk/gtk.h>
#include <gtk/gtkgl.h>
#include "contexto_juego.h"
#include "pantalla_principal.h"
#include "log.h"

static Log log("main");


// SOLO PANTALLA GRAFICA
/*
#include "pantalla_juego.h"
#include "servidor_de_prueba.h"

int main(int argc, char* argv[]){
	gtk_init(&argc, &argv);
	gtk_gl_init (&argc, &argv);

	ContextoJuego* c = &ContextoJuego::CrearContexto();
	c->set_servidor(new ServidorDePrueba("..\\mundo.xml"));
	c->set_id_imperio(1);
	PantallaJuego pantalla_juego(c);

	gtk_main();
	return 0;
}
*/

// DEBUG:
/*
int main(int argc, char* argv[]){
	gtk_init(&argc, &argv);
	gtk_gl_init (&argc, &argv);

	PantallaPrincipal pantalla_principal(&ContextoJuego::CrearContexto());
	gtk_main();
	return 0;
}
*/

// DEFINITIVO:

int main(int argc, char* argv[]){
	
	try{ 
		Log::set_logueo_por_consola(false);
		
		gtk_init(&argc, &argv);
		gtk_gl_init (&argc, &argv);

		PantallaPrincipal pantalla_principal(&ContextoJuego::CrearContexto());
		gtk_main();
	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida"));
	}
	
	return 0;
}
