#include "Cola.hpp"

Cola::Cola(){
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

int Cola::getLongitud(){
    return this->longitud;
}
/*
void Cola::encolar(Proceso* p){
	pnodoCola siguiente = NULL;
    pnodoCola nodo = new NodoCola(p, siguiente); 
	if (!primero){
		primero = ultimo = nodo;
		longitud++;
	} else {
		ultimo->siguiente = nodo;
		ultimo = nodo;
		longitud++;
	}
}
*/
void Cola::encolarOrdenado(Proceso* p){
	pnodoCola nuevo = new NodoCola(p);
	pnodoCola actual = primero;
	//Antes de encolar hay que aumentar la prioridad de los procesos normales
	if(p->getTipo()){p->setPrioridad(p->getPrioridad()+120);}
	//Cola vacia
	if(esVacia()){
		primero = ultimo = nuevo;
		longitud++;
		return;
	}
	//Elemento tiene menos prioridad que el primero de la cola
	if(nuevo->proceso->getPrioridad() < primero->proceso->getPrioridad()){
		nuevo->siguiente = primero;
		primero = nuevo;
		longitud++;
		return;
	}
	//Recorrer la cola hasta encontrar la posicion por prioridad
	while(actual->siguiente != NULL and 
		actual->siguiente->proceso->getPrioridad() <= nuevo->proceso->getPrioridad()){
			actual = actual->siguiente;
	}
	//Colocar el nuevo nodo en la cola
	nuevo->siguiente = actual->siguiente;
	actual->siguiente = nuevo;
	//Si se llega al final de la cola ultimo apunta al nuevo nodo
	if(nuevo->siguiente == NULL){ultimo = nuevo;}
	
	longitud++;
}

Proceso* Cola::verPrimero(){
	return primero->proceso;
}

void Cola::mostrar(){
	pnodoCola aux = primero;
	while(aux){
		aux->proceso->mostrar_proceso_cola();
		aux = aux->siguiente;
    }
}

bool Cola::esVacia(){
	if(!primero){return true;} 
	else {return false;}
}

Proceso* Cola::desencolar(){
	pnodoCola nodo;
	Proceso* p;
	nodo = primero;
	//Si la cola esta vacia dejar la funcion
	if(!nodo){ 
		cout<<"La cola esta vacía"; 
		return 0;
	}
	//Si no esta vacia se desencola el primer nodo
	primero = nodo->siguiente;
	p = nodo->proceso;
	delete nodo;
	//Si era el ultimo nodo de la cola, ultimo queda null
	if(!primero)
		ultimo = NULL;
	longitud--;
	return p;
}

void Cola::vaciar(){
	while(primero) desencolar();
}

Cola::~Cola(){
	while(primero) vaciar();
	delete primero;
	delete ultimo;	
}

