#include "Lista.hpp"
#include <iostream>
Lista::Lista(){
	primero = NULL;
	ultimo = NULL;
	longitud=0;
}

Lista::~Lista() {
    pnodoLista actual = primero;
    while (actual != nullptr) {
        pnodoLista temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

int Lista::get_longitud(){return longitud;}

void Lista::insertarInicio(Proceso* p) {
    pnodoLista nuevo = new NodoLista(p);
    nuevo->siguiente = primero;
    primero = nuevo;
	p->setEstado(true);
	longitud++;
}

void Lista::insertarFinal(Proceso* p){
	pnodoLista nuevo = new NodoLista(p);
	nuevo->siguiente = ultimo;
	ultimo = nuevo;
	p->setEstado(true);
	longitud++;
}

void Lista::mostrar(){
	pnodoLista aux = ultimo;
	cout << left << setw(10) << "PID"
         << setw(15) << "Usuario"
         << setw(20) << "Tipo de Proceso"
         << setw(20) << "Estado"
         << setw(10) << "Prioridad"
         << endl;
	while(aux){
		aux->proceso->mostrar_proceso_lista();
		aux = aux->siguiente;
    }
}

void Lista::eliminar(Proceso* p) {
    if (primero == nullptr) return;

    if (primero->proceso == p) {
        NodoLista* temp = primero;
        primero = primero->siguiente;
        delete temp;
    } else {
        NodoLista* actual = ultimo;
        while (actual->siguiente != nullptr && actual->proceso != p) {
            actual = actual->siguiente;
        }
        if (actual->siguiente != nullptr) {
            NodoLista* temp = actual->siguiente;
            actual->siguiente=(temp->siguiente);
            delete temp;
        }
    }
}
