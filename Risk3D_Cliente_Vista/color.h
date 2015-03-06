#ifndef COLOR_H_
#define COLOR_H_

class Color {
	private:
		float rojo;
		float verde;
		float azul;

	public:			
		Color(float rojo, float verde, float azul)
			: rojo(rojo), verde(verde), azul(azul){
		}

		float get_rojo(){
			return rojo;
		}
		float get_verde(){
			return verde;
		}
		float get_azul(){
			return azul;
		}

		static Color blanco(){
			return Color(1, 1, 1);
		}
};

#endif /* COLOR_H_ */
