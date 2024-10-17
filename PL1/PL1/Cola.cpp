#include "Cola.hpp"
Cola::Cola(string nombre){
	primero=NULL;
	ultimo=NULL;
	longitud=0;
	this->nombre=nombre;
	}
void Cola::mostrar(){
	pnodoCola aux=primero;
	cout<<nombre;
	
	while(aux){
		aux->proceso->mostrar_proceso_cola();
		aux=aux->siguiente;
		}
	}
Proceso* Cola::eliminar(){
	pnodoCola nodo;
	Proceso* p;
	nodo=primero;
	if(!nodo)
		return 0;
	primero=nodo->siguiente;
	p=nodo->proceso;
	delete nodo;
	if(!primero)
		ultimo=NULL;
	longitud--;
	return p;
	}
Proceso* Cola::verPrimero(){
	return primero->proceso;
	}
Cola::~Cola(){
	while(primero)
		eliminar();
		
	}