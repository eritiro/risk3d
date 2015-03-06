#ifndef BARRA_DE_ESTADO_H_
#define BARRA_DE_ESTADO_H_


#include <gtk/gtk.h>
#include <string>

typedef int id_mensaje;
typedef int id_contexto;

using namespace std;



class BarraDeEstado {
	private:
		GtkWidget* barra_de_estado;

	public:
		BarraDeEstado();
		~BarraDeEstado();
		void crear();
		void mostrar();
		id_contexto get_id_contexto(string descripcion);
		id_mensaje mostrar_mensaje(id_contexto id, string mensaje);
		void quitar_mensaje(id_contexto id);
		void eliminar_mensaje(id_contexto id_con, id_mensaje id_msg);
		GtkWidget* get_widget();
};

#endif /* BARRA_DE_ESTADO_H_ */
