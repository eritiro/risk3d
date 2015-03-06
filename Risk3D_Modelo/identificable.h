#ifndef IDENTIFICABLE_H_
#define IDENTIFICABLE_H_

//Macro para generar el siguiente id
#define generar_id(coleccion) \
	((coleccion).size() > 0) ? (coleccion).back()->get_id() + 1 : 1

class Identificable {
	private:
		int id;
	public:
		Identificable(int id) : id(id){
		}
		int get_id(){ return id; }
};

#endif /* IDENTIFICABLE_H_ */
