#include "area_de_juego_3d.h"

//aux sacar despues
#include "vista_pantalla_juego.h"

AreaDeJuego3D::AreaDeJuego3D(ControladorPantallaJuego& controlador) 
	: controlador(controlador) {

	gdk_pixbuf_get_file_info (RUTA_TEXTURA_RECIBIDA, &ancho_original, &alto_original);

	alpha = ANGULO_INICIAL_ESFERA;
	dist = DISTANCIA_INICIAL_ESFERA;

	esfera = gluNewQuadric(); 
	ciudadQuad = gluNewQuadric();
	tapaQuad = gluNewQuadric();

	this->imagen_activa = false;

	event_box = gtk_event_box_new();
	vbox = gtk_vbox_new(FALSE, 0);
	hbox = gtk_hbox_new(FALSE, 0);

	boton_izquierda = gtk_button_new_with_label("<<");
	boton_acercar = gtk_button_new_with_label("+");
	boton_alejar = gtk_button_new_with_label("-");
	boton_derecha = gtk_button_new_with_label(">>");



	g_signal_connect(G_OBJECT(this->event_box), "button_press_event", G_CALLBACK(on_click), this);


	gtk_signal_connect(GTK_OBJECT(this->boton_izquierda), "clicked", GTK_SIGNAL_FUNC(on_izquierda_presionada), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_derecha), "clicked", GTK_SIGNAL_FUNC(on_derecha_presionada), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_acercar), "clicked", GTK_SIGNAL_FUNC(on_acercar_presionado), this);
	gtk_signal_connect(GTK_OBJECT(this->boton_alejar), "clicked", GTK_SIGNAL_FUNC(on_alejar_presionado), this);

	// crea el widget de opengl y lo muestra:
	this->crear_widget_opengl();


	
	gtk_widget_show(boton_izquierda);
	gtk_widget_show(boton_derecha);
	gtk_widget_show(boton_acercar);
	gtk_widget_show(boton_alejar);

	gtk_box_pack_start(GTK_BOX(hbox), boton_izquierda, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), boton_derecha, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), boton_acercar, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), boton_alejar, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(vbox), event_box, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

	// muestro el vbox
	gtk_widget_show(event_box);
	gtk_widget_show(hbox);
	gtk_widget_show(vbox);


}


AreaDeJuego3D::~AreaDeJuego3D(){
	gluDeleteQuadric(esfera);
	gluDeleteQuadric(ciudadQuad);
	gluDeleteQuadric(tapaQuad);

	foreach(IteradorCiudades, i, ciudades)
		delete *i;
}


GtkWidget* AreaDeJuego3D::get_widget(){
	return this->vbox;
}


void AreaDeJuego3D::actualizar(InfoJuego* info){
	//this->
	this->actualizar_ciudades(info);

	this->refrescar();
}


void AreaDeJuego3D::resaltar_territorios_adyacentes(Territorio* territorio){
	foreach(IteradorCiudades, iterador_ciudad, this->ciudades){
		Ciudad* ciudad = *iterador_ciudad;
		Tropa* tropa = ciudad->get_tropa();
		ColorImperio color_imperio = tropa->get_imperio()->get_color();
		VistaColorImperio vista_color_imperio(color_imperio);

		Color color_base = vista_color_imperio.get_color_rgb();
		if(territorio->es_adyacente_a(tropa->get_territorio())){
			float rojo = color_base.get_rojo() + 0.5;
			float verde = color_base.get_verde() + 0.5;
			float azul = color_base.get_azul() + 0.5;
			if(rojo>1)rojo = 1;
			if(verde>1)verde = 1;
			if(azul>1)azul = 1;
			ciudad->set_color(Color(rojo,verde,azul));
		}
		else{
			ciudad->set_color(color_base);
		}
	}

	this->refrescar();
}


void AreaDeJuego3D::quitar_resaltado_de_territorios(){
	foreach(IteradorCiudades, iterador_ciudad, this->ciudades){
		Ciudad* ciudad = *iterador_ciudad;
		Tropa* tropa = ciudad->get_tropa();
		ColorImperio color_imperio = tropa->get_imperio()->get_color();
		VistaColorImperio vista_color_imperio(color_imperio);
		ciudad->set_color(vista_color_imperio.get_color_rgb());
	}

	this->refrescar();
}


void AreaDeJuego3D::actualizar_ciudades(InfoJuego* info){
	foreach(IteradorCiudades, i, ciudades)
		delete *i;

	ciudades = ContenedorCiudades();

	foreach(IteradorImperios, iterador_imperio, info->get_imperios()){
		Imperio* imperio = *iterador_imperio;
		ColorImperio color_imperio = imperio->get_color();
		VistaColorImperio vista_color_imperio(color_imperio);
		Color color = vista_color_imperio.get_color_rgb();

		foreach(IteradorTropas, iterador_tropa, imperio->get_tropas()){
			Tropa* tropa = *iterador_tropa;
			Coordenada coordenada = tropa->get_territorio()->get_posicion();
			float longitud  = (coordenada.get_x() / float(ancho_original)) * 360 - 270;
			float latitud = (-coordenada.get_y() / float(alto_original)) * 180 + 90;
			float altura = 0.025F;
			Ciudad* ciudad = new Ciudad(latitud, longitud, altura, tropa, color);
			ciudades.push_back(ciudad);
		}
	}
}

void AreaDeJuego3D::crear_widget_opengl(){

	GdkGLConfig* glconfig;

	// intenta crear una configuracion de opengl
	glconfig = gdk_gl_config_new_by_mode(GdkGLConfigMode(GDK_GL_MODE_RGB | GDK_GL_MODE_DEPTH | GDK_GL_MODE_DOUBLE));
	
	// si no puede usar double-buffer intenta configurarlo sin esa opcion
	if(glconfig == NULL)
		glconfig = gdk_gl_config_new_by_mode(GdkGLConfigMode(GDK_GL_MODE_RGB | GDK_GL_MODE_DEPTH));

	// en el drawing area voy a chantar las cosas de opengl
	drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, ANCHO_AREA_3D, ALTO_AREA_3D);

	// no se sabe porque esta, que hace o a donde va, pero nadie se anima a sacarlo.
	// No te recuerda a nadie???
	gtk_widget_set_gl_capability(drawing_area, glconfig, NULL, TRUE, GDK_GL_RGBA_TYPE);

	g_signal_connect(G_OBJECT(drawing_area), "configure_event", G_CALLBACK(configure_event), this);
	g_signal_connect_after(G_OBJECT(drawing_area), "realize", G_CALLBACK(realize), this);
	g_signal_connect(G_OBJECT (drawing_area), "expose_event", G_CALLBACK (expose_event), this);

	// agrego el drawing area al vbox
	gtk_container_add(GTK_CONTAINER(event_box), drawing_area);
	gtk_widget_show(drawing_area);

}

AUX_RGBImageRec* AreaDeJuego3D::leer_textura(char *filename)
{
	FILE* file=fopen(filename,"r");		
	if (file)								//Si pudo abrir la imagen la cierra y retorna un puntero a la misma
	{
		fclose(file);						
		return auxDIBImageLoad(filename);	
	}
 	return NULL;							//En caso de falla retorna NULL
}

#pragma warning(la textura no esta bueno que la saque de una constante)
void AreaDeJuego3D::cargar_textura()							
{
	AUX_RGBImageRec *image=NULL; //Puntero a la imagen
	
	image = leer_textura(RUTA_TEXTURA_RECIBIDA);
	if(image){
		glGenTextures(1,&texture);											//Asks for one texture
		glBindTexture(GL_TEXTURE_2D,texture);								//Constructs texture (GL_TEXTURE_2D)
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);	//Defines filter used when texture is scaled
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);	//MAG_FILTER = when the texture is enlarged
		glTexImage2D(GL_TEXTURE_2D,0,3,image->sizeX,image->sizeY,0,			//MIN_FILTER = when the texture is shrinked 
		GL_RGB,GL_UNSIGNED_BYTE,image->data);					//Pastes image on texture
		if (image->data)			
			free(image->data);		
		free(image);
	}

	gluQuadricNormals(esfera, GLU_SMOOTH); //Parametros de la esfera		
	gluQuadricTexture(esfera, GL_TRUE); //Parametros de la esfera

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);


}

void AreaDeJuego3D::refrescar(){
	gdk_window_invalidate_rect (this->drawing_area->window, &this->drawing_area->allocation, FALSE);

	/* Update synchronously (fast). */
	gdk_window_process_updates (this->drawing_area->window, FALSE);
}

void AreaDeJuego3D::actualizar_posicion_vista(){

	
	float beta = 0;
	
	alpha = (alpha > 2 * PI) ? alpha - 2 * PI : alpha;
	alpha = (alpha < -2 * PI) ? alpha +  2 * PI : alpha;
	beta = (beta > 1.0) ? 1.0 : beta;
	beta = (beta < -1.0) ? -1.0 : beta;

	viewpoint.x = dist * cos(alpha) * cos(beta);
	viewpoint.y = dist * sin(alpha) * cos(beta);
	viewpoint.z = dist * sin(beta);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( viewpoint.x, viewpoint.y, viewpoint.z, 0.0, 0.0, 0.0, 0.0, 0.0, 1);
}

/* Definicion de callbacks. */

void AreaDeJuego3D::on_izquierda_presionada(GtkWidget* widget, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;
	
	instancia->alpha =  instancia->alpha - INCREMENTO_ANGULO;
	if(instancia->alpha < 0)
		instancia->alpha += 2 * PI;

	instancia->refrescar();
}

void AreaDeJuego3D::on_derecha_presionada(GtkWidget* widget, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	instancia->alpha =  instancia->alpha + INCREMENTO_ANGULO;
	if(instancia->alpha> 2 * PI)
		instancia->alpha -= 2 * PI;

	instancia->refrescar();
}

void AreaDeJuego3D::on_acercar_presionado(GtkWidget* widget, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	if(instancia->dist - INCREMENTO_DISTANCIA > DISTANCIA_MINIMA_ESFERA)
		instancia->dist -= INCREMENTO_DISTANCIA;
	else
		instancia->dist = DISTANCIA_MINIMA_ESFERA;

	instancia->refrescar();
}

void AreaDeJuego3D::on_alejar_presionado(GtkWidget* widget, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	if(instancia->dist + INCREMENTO_DISTANCIA < DISTANCIA_MAXIMA_ESFERA)
		instancia->dist += INCREMENTO_DISTANCIA;
	else
		instancia->dist = DISTANCIA_MAXIMA_ESFERA;


	instancia->refrescar();
}


void AreaDeJuego3D::on_click(GtkWidget* widget, GdkEventButton* evento, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	double mm[16], pm[16];
	int v[4];
	Point3 fp, np;
	Vector3 rayDir;

	double mouseX = evento->x;
	double mouseY = ALTO_AREA_3D - evento->y;

	glGetDoublev(GL_MODELVIEW_MATRIX, mm);
	glGetDoublev(GL_PROJECTION_MATRIX, pm);
	glGetIntegerv(GL_VIEWPORT, v);

	gluUnProject(mouseX, mouseY, 1.0, mm, pm, v, &fp.x, &fp.y, &fp.z);
	gluUnProject(mouseX, mouseY, 0.0, mm, pm, v, &np.x, &np.y, &np.z);
	rayDir.x = fp.x - np.x;
	rayDir.y = fp.y - np.y;
	rayDir.z = fp.z - np.z;


	Ciudad* ciudad_seleccionada = 0;
	foreach(IteradorCiudades, iterador_ciudad, instancia->ciudades){
		Ciudad* ciudad = *iterador_ciudad;
		if(ciudad->cityRayIntersection(instancia->viewpoint, rayDir)){
			ciudad_seleccionada = ciudad;
		}
	}

	if(ciudad_seleccionada)
		instancia->controlador.manejar_evento_territorio_seleccionado(ciudad_seleccionada->get_tropa()->get_territorio());
	else
		instancia->controlador.manejar_evento_territorio_deseleccionado();
}

// creo que es tipo el redraw
gboolean AreaDeJuego3D::expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	GdkGLContext *glcontext = gtk_widget_get_gl_context(instancia->drawing_area);
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable(instancia->drawing_area);

	if(!gdk_gl_drawable_gl_begin(gldrawable, glcontext))
		return FALSE;


	static GLfloat ambient2[4]  = {0.2f, 0.2f, 0.2f, 1.0f}; //{ 0.329412, 0.223529, 0.027451, 1.0 };
	static GLfloat diffuse2[4]  = {0.8f, 0.8f, 0.8f, 1.0f}; //{ 0.780392, 0.568627, 0.113725, 1.0 };
	static GLfloat specular[4] = {0, 0, 0, 1};//{ 0.992157, 0.941176, 0.807843, 1.0 };
	glMaterialfv (GL_FRONT, GL_AMBIENT, ambient2);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, diffuse2);



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	instancia->actualizar_posicion_vista();

	glPushMatrix();

	glEnable(GL_DEPTH_TEST);			//Activa el modo depth
	
	glEnable(GL_TEXTURE_2D);
	gluSphere(instancia->esfera, RADIO_MUNDO_3D, 1000, 1000);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();


	foreach(IteradorCiudades, iterador_ciudad, instancia->ciudades){


		Ciudad* ciudad = *iterador_ciudad;
		float longitud = ciudad->get_longitud();
		float latitud =  ciudad->get_latitud();
		float hache = ciudad->get_altura();
		Color color = ciudad->get_color();

		GLfloat ambient[4]  = {color.get_rojo(), color.get_verde(), color.get_azul(), 1};
		GLfloat diffuse[4]  = {color.get_rojo() * 0.5, color.get_verde() * 0.5, color.get_azul() * 0.5, 1};
		glMaterialfv (GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, diffuse);


		glPushMatrix();
		glRotated(longitud, 0.0, 0.0, 1.0);
		glRotated(90.0 - latitud, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, RADIO_MUNDO_3D);
		gluCylinder(instancia->ciudadQuad, ANCHO_CIUDAD, ANCHO_CIUDAD, hache, 16, 1);

		glPushMatrix();
		glTranslatef(0, 0, hache);
		gluDisk(instancia->tapaQuad, 0, ANCHO_CIUDAD, 16, 2);
		glPopMatrix();
		glPopMatrix();
		
	}

	if(gdk_gl_drawable_is_double_buffered(gldrawable))
		gdk_gl_drawable_swap_buffers(gldrawable);	else
		glFlush();

	gdk_gl_drawable_gl_end(gldrawable);

	/*** OpenGL END ***/

	return TRUE;
}


void AreaDeJuego3D::realize(GtkWidget *widget, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	GdkGLContext *glcontext = gtk_widget_get_gl_context(instancia->drawing_area);
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable(instancia->drawing_area);

	if(!gdk_gl_drawable_gl_begin(gldrawable, glcontext))
		return;

	static GLfloat ambient[]  = { 0.0F, 0.0F, 0.0F, 1.0F };
	glLightfv (GL_LIGHT0, GL_AMBIENT, ambient);

	static GLfloat diffuse[]  = { 1.0F, 1.0F, 1.0F, 1.0F };
	glLightfv (GL_LIGHT0, GL_DIFFUSE, diffuse);

	static GLfloat position[] = { -1.0F, 1.0F, 2.0F, 0.0F };
	glLightfv (GL_LIGHT0, GL_POSITION, position);

	static GLfloat lmodel_ambient[] = {0.2F, 0.2F, 0.2F, 1.0F};
	glLightModelfv (GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	static GLfloat local_view[] = {0.0};
	glLightModelfv (GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glEnable (GL_DEPTH_TEST);

	glClearColor (0, 0, 0, 0);
	instancia->cargar_textura();

	gdk_gl_drawable_gl_end (gldrawable);
}

gboolean AreaDeJuego3D::configure_event(GtkWidget *widget, GdkEventConfigure *event, gpointer data){
	AreaDeJuego3D* instancia = (AreaDeJuego3D*)data;

	GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

	GLfloat w = widget->allocation.width;
	GLfloat h = widget->allocation.height;
	GLfloat aspect;

	/*** OpenGL BEGIN ***/
	if(!gdk_gl_drawable_gl_begin(gldrawable, glcontext))
		return FALSE;

	glViewport(0, 0, w, h);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	if(w > h){
		aspect = w / h;
		glFrustum (-aspect, aspect, -1.0, 1.0, 5.0, 60.0);
	}
	else{
		aspect = h / w;
		glFrustum (-1.0, 1.0, -aspect, aspect, 5.0, 60.0);
	}

	glMatrixMode(GL_MODELVIEW);

	gdk_gl_drawable_gl_end(gldrawable);
	/*** OpenGL END ***/

	return TRUE;
}
