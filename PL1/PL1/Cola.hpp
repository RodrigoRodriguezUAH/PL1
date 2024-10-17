#include "NodoCola.hpp"
class Cola{
public:
	Cola(string nombre);
	~Cola();
	void insertar_orden(Proceso* p);
	Proceso* eliminar();
	void mostrar();
	Proceso* verPrimero();
private:
	pnodoCola primero, ultimo;
	int longitud;
	string nombre;
	};
