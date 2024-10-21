#include "Gestor.hpp"

Gestor::Gestor(){
	Pila pila;
    Cola GPU0, GPU1, GPU2, GPU3;
    Lista Normal, TR;
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
	if(pila.getLongitud() < 48){
        for (int i=0; i<12; i++){
            Proceso* p = new Proceso();
            pila.insertar(p);
        }
    }
    /*Aqui se podria poner o un try catch si queremos dejar el throw en generar proceso o sino:
    else{ cout << "La pila esta llena, vaciala antes de introducir nuevos procesos." << endl;}*/
}

void Gestor::muestraProcesos(){
	pila.mostrar();
}

void Gestor::borraProcesosPila(){
	pila.vaciar();
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
}

