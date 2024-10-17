
#include "Gestor.hpp"
using namespace std;

Gestor::Gestor(){
	Pila pila;
	}
Gestor::~Gestor(){
	
	}
int Gestor::ProcesosEnPila(){
	return pila.getLongitud();
	}
void Gestor::genera12Procesos(){
	if(pila.getLongitud()<48){
	for (int i=0;i<12;i++){
		Proceso* p=new Proceso();
		pila.insertar(p);
			}
		}
	}
void Gestor::muestraProcesos(){
	pila.mostrar();
	}
	
