#include "NodoPila.hpp"

class Pila{
public:
	Pila();
	~Pila();
	void insertar(Proceso* p);
	Proceso* extraer();
	Proceso* cima();
	void mostrar();
	int getLongitud();
	
private:
	pnodoPila ultimo;
	int longitud;
};