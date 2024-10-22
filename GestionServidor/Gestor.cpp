#include "Gestor.hpp"
#include <iostream>
using namespace std;
Gestor::Gestor(){
	Pila pila;
    Cola GPU0, GPU1, GPU2, GPU3;
    Lista normal, Treal;
}

Gestor::~Gestor(){
}

//Funciones de la pantalla de interfaz
int Gestor::ProcesosEnPila(){
	return pila.getLongitud();
}

int Gestor::ProcesosEnGPU0(){
    return GPU0.getLongitud();
}

int Gestor::ProcesosEnGPU1(){
    return GPU1.getLongitud();
}

int Gestor::ProcesosEnGPU2(){
    return GPU2.getLongitud();
}

int Gestor::ProcesosEnGPU3(){
    return GPU3.getLongitud();
}

//Funciones de las opciones del main:
//Pilas
void Gestor::genera12Procesos(){
	try{
		if(pila.getLongitud() < 48){
			for (int i=0; i<12; i++){
				Proceso* p = new Proceso();
				pila.insertar(p);
			}
		}
	} catch(const out_of_range& e) {
		cout << e.what() << endl; //Muestra el mensaje de la excepcion
	}
}

void Gestor::muestraProcesos(){
	pila.mostrar();
}

void Gestor::borraProcesosPila(){
	pila.vaciar();
	cout << "Pila vaciada";
}

//Colas
void Gestor::encolarProcesos(){
    Proceso* desplazado;
    while(pila.getLongitud() != 0){
        desplazado = pila.extraer();
        if (desplazado->getTipo()){ //Proceso de tipo normal porque estos equivalen a true
            if (GPU0.getLongitud() <= GPU1.getLongitud()){ //Compara longitudes
                GPU0.encolarOrdenado(desplazado);
            } else {GPU1.encolarOrdenado(desplazado);}
        } else { //Proceso de tipo tiempo real
            if (GPU2.getLongitud() <= GPU3.getLongitud()){
                GPU2.encolarOrdenado(desplazado);
            } else {GPU3.encolarOrdenado(desplazado);}
        }
    }
}

void Gestor::muestraProcesosGPUs0y1(){
    cout << "GPU 0:" << endl;
    GPU0.mostrar();
    cout << endl << "GPU 1:" << endl;
    GPU1.mostrar();
}

void Gestor::muestraProcesosGPUs2y3(){
    cout << "GPU 2:" << endl;
    GPU2.mostrar();
    cout << endl << "GPU 3:" << endl;
    GPU3.mostrar();
}
 
void Gestor::borraProcesosColas(){
    GPU0.vaciar();
    GPU1.vaciar();
    GPU2.vaciar();
    GPU3.vaciar();
	cout << "Colas vaciadas" << endl;
}

//Listas
int Gestor::ProcesosEnListaNormal(){
	return normal.get_longitud();
}
int Gestor::ProcesosEnListaTiempoReal(){
		return Treal.get_longitud();
}
void Gestor::enlistarProcesos(){
		while(GPU0.getLongitud()>0){
			normal.insertarFinal(GPU0.desencolar());
		}
		while(GPU1.getLongitud()>0){
			normal.insertarFinal(GPU1.desencolar());
		}
		while(GPU2.getLongitud()>0){
			Treal.insertarFinal(GPU2.desencolar());
		}
		while(GPU3.getLongitud()>0){
			Treal.insertarFinal(GPU3.desencolar());
		}
}

void Gestor::muestraProcesosNormal(){
	cout << "Lista de procesos Normales" << endl;
	normal.mostrar();
}

void Gestor::muestraProcesosTiempoReal(){
	cout << "Lista de procesos en Tiempo Real" << endl;
	Treal.mostrar();
}