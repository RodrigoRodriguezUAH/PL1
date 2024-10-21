
#include "Cola.hpp"
#include "Pila.hpp"
using namespace std;
class Gestor{
public:
	Gestor();
	int ProcesosEnPila();
	void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	void insertar_colas();
	int ProcesosEnGPU1();
	int ProcesosEnGPU2();
	int ProcesosEnGPU3();
	int ProcesosEnGPU4();
	void muestraProcesosGPUs1y2();
	void muestraProcesosGPUs3y4();
	void mostrar_colas();
	void borraProcesosColas();
	~Gestor();
private:
	Pila pila;
	Cola GPU1;
	Cola GPU2;
	Cola GPU3;
	Cola GPU4;
	
	};
