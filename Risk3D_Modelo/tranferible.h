#ifndef TRANFERIBLE_H_
#define TRANFERIBLE_H_

class Tranferible {
	public:
		virtual ~Tranferible(){
		}
		template<class T> asociar_al_ciclo_de_vida_de(T& ciclo_de_vida){
			ciclo_de_vida.agregar_objeto_tranferible(this);
		}
};


#endif /* TRANFERIBLE_H_ */
