#include "Gestor.hpp"
using namespace std;

Gestor::Gestor(){
	Pila pila;
    Cola cola;
}

Gestor::~Gestor(){
}

//Funciones de la pantalla principal

int Gestor::ProcesosEnPila(){
	return pila.getLongitud();
}

//Funciones de las opciones del main:

//Pilas
void Gestor::genera12Procesos(){
	if(pila.getLongitud()<48){
        for (int i=0; i<12; i++){
            Proceso* p = new Proceso();
            pila.insertar(p);
        }
    }
}

void Gestor::muestraProcesos(){
	pila.mostrar();
}

void Gestor::borraProcesosPila(){
	pila.vaciar();
}

//Colas
void Gestor::encolarProcesos(){
    
}

void Gestor::muestraProcesosGPUs0y1(){
    
}

void Gestor::muestraProcesosGPUs2y3(){
    
}
 
void Gestor::borraProcesosColas(){
    
}




