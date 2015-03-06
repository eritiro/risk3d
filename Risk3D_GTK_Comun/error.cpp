#include "error.h"

/* *
 * Constructor.
 * */
 
Error::Error(string error){
	GtkWidget* ventana;
   
	ventana = gtk_message_dialog_new(NULL, GtkDialogFlags(0), GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, error.c_str());
	gtk_window_set_title(GTK_WINDOW(ventana), "Alerta.");
	gtk_window_set_position(GTK_WINDOW(ventana), GTK_WIN_POS_CENTER);
	gtk_dialog_run(GTK_DIALOG(ventana));
	gtk_widget_destroy(ventana);
}


/* *
 * Destructor.
 * */

Error::~Error(){}
