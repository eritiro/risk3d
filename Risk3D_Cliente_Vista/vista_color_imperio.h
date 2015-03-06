#ifndef VISTA_COLOR_IMPERIO_H_
#define VISTA_COLOR_IMPERIO_H_

#include "color.h"
#include "color_imperio.h"
#include "excepcion_color_invalido.h"

class VistaColorImperio {
	private:
		ColorImperio color_imperio;
	public:
		VistaColorImperio(ColorImperio color_imperio);
		VistaColorImperio(string color);
		ColorImperio get_color_imperio();
		Color get_color_rgb();
		string get_string_color();

		static VistaColorImperio get_rojo() { return VistaColorImperio(ROJO); }
		static VistaColorImperio get_verde() { return VistaColorImperio(VERDE); }
		static VistaColorImperio get_azul() { return VistaColorImperio(AZUL); }
		static VistaColorImperio get_naranja() { return VistaColorImperio(NARANJA); }
		static VistaColorImperio get_rosa() { return VistaColorImperio(ROSA); }
		static VistaColorImperio get_turquesa() { return VistaColorImperio(TURQUESA); }
};

#endif /* VISTA_COLOR_IMPERIO_H_ */
