#include "Cola.hpp"

Cola::Cola(){
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

int Cola::getLongitud(){
    return this->longitud;
}

void Cola::encolar(Proceso* p){
	pnodoCola siguiente = NULL;
    pnodoCola nodo = new NodoCola(p, siguiente); 
	if (!primero){
		primero = nodo;
		ultimo = primero;
		longitud++;
	} else {
		nodo->siguiente = ultimo;
		ultimo = nodo;
		longitud++;
	}
}

void Cola::mostrar(){
	pnodoCola aux = primero;
	while(aux){
		aux->proceso->mostrar_proceso_cola();
		aux = aux->siguiente;
    }
}

Proceso* Cola::vaciar(){
	pnodoCola nodo;
	Proceso* p;
	nodo = primero;
	//Si la cola esta vacia termina el metodo
    if(!nodo)
        cout << "La cola esta vacia";
		return 0;
    //Eliminar elemento de la cola
	primero = nodo->siguiente;
	p = nodo->proceso;
	delete nodo;
	//Si termina la cola
    if(!primero)
		ultimo = NULL;
	longitud--;
	return p;
}

Proceso* Cola::verPrimero(){
	return primero->proceso;
}

Cola::~Cola(){
	while(primero)
		vaciar();		
}

