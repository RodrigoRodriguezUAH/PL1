

#include "Pila.hpp"
using namespace std;
class Gestor{
public:
	Gestor();
	int ProcesosEnPila();
	void genera12Procesos();
	void muestraProcesos();
	~Gestor();
private:
	Pila pila;
	};