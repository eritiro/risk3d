#ifndef AMBIENTE_DE_JUEGO_H_
#define AMBIENTE_DE_JUEGO_H_

class AmbienteDeJuego {
	public:
		virtual int generar_valor_aleatorio(int minimo, int maximo) = 0;

		virtual ~AmbienteDeJuego(){
		}
};


#endif /* AMBIENTE_DE_JUEGO_H_ */
