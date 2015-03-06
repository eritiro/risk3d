#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#pragma warning(disable:4786)

class ControladorBase {
	private:
		void* vista;
		void* contexto;
	public:
		void* get_referencia_vista() const {
			return vista;
		}

		void set_vista(void* instancia){
			vista = instancia;
		}

		void* get_referencia_contexto() const {
			return contexto;
		}

		void set_contexto(void* valor){
			contexto = valor;
		}
};


template<class T> class Controlador : public ControladorBase {
	public:

		T& get_vista() const{
			return *(T*)get_referencia_vista();
		}

};

#endif /* CONTROLADOR_H_ */
