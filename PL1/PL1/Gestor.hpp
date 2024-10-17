

#include "Pila.hpp"
using namespace std;
class Gestor{
public:
	Gestor();
	int ProcesosEnPila();
	void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	~Gestor();
private:
	Pila pila;
	};