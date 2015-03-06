#ifndef MANEJADOR_MENSAJE_DEFENSA_REQUERIDA_H_
#define MANEJADOR_MENSAJE_DEFENSA_REQUERIDA_H_

#include "manejador_de_mensajes.h"
#include "defensa_requerida.h"

class ManejadorMensajeDefensaRequerida : public ManejadorDeMensajes {	
	public:
		void manejar_mensaje(Mensaje& mensaje, ControladorPantallaJuego& controlador){

			DefensaRequerida mensaje_defensa = dynamic_cast<DefensaRequerida&>(mensaje);
			Tropa* tropa_agredida = controlador.get_contexto()->get_servidor()->get_info()->get_tropa(mensaje_defensa.get_territorio_agredido());
			string pregunta = "Esta siendo atacado desde ";
			pregunta += mensaje_defensa.get_territorio_agresor()->get_nombre();
			pregunta += " con ";
			pregunta += UtilidadesString::int_a_string(mensaje_defensa.get_ejercitos_ataque());
			pregunta += " ejercitos\na ";
			pregunta += mensaje_defensa.get_territorio_agredido()->get_nombre();
			pregunta += " donde posee ";
			pregunta += UtilidadesString::int_a_string(tropa_agredida->get_ejercitos());
			pregunta += " ejercitos.\n";
			
			pregunta += "Elija con cuantos ejercitos defenderse:";

			string respuesta;
			do{
				respuesta = controlador.get_vista().preguntar(pregunta);	

			}while(!UtilidadesString::es_entero(respuesta));
			
			int ejercitos_elegidos = UtilidadesString::string_a_int(respuesta);
			controlador.get_contexto()->get_servidor()->enviar(FabricaDeOrdenes::crear_orden_defender(ejercitos_elegidos));
		}
};

#endif /* MANEJADOR_MENSAJE_DEFENSA_REQUERIDA_H_ */
