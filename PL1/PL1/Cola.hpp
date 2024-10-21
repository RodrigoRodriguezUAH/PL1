#include "NodoCola.hpp"
class Cola{
public:
	Cola();
	~Cola();
	void insertar_orden(Proceso* p);
	Proceso* eliminar();
	void mostrar();
	Proceso* verPrimero();
	bool esta_vacia();
	int get_long();
	void vaciar();
private:
	pnodoCola primero, ultimo;
	int longitud;
	string nombre;
	};