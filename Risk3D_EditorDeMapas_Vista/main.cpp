#include "ventana_principal.h"

static Log log("main");

int main(int argc, char* argv[]){
	
	try {
		gtk_init(&argc, &argv);
		
		VentanaPrincipal ventanaPrincipal(&ContextoEditor::CrearContexto());
		ventanaPrincipal.crear();
		ventanaPrincipal.mostrar();
		
		gtk_main();
	}
	catch(ExcepcionRisk3D& ex){
		log.excepcion(ex);
	}
	catch(...){
		log.excepcion(exception("Excepcion desconocida."));
	}
	return 0;
}
