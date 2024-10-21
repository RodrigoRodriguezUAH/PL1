#include "Cola.hpp"
using namespace std;
Cola::Cola(){
	primero=NULL;
	ultimo=NULL;
	longitud=0;
	}
bool Cola::esta_vacia(){
	return primero==nullptr;
	}
void Cola::vaciar(){
	while(primero)
		eliminar();
	
}
void Cola::mostrar(){
	pnodoCola aux=primero;
	while(aux){
		aux->proceso->mostrar_proceso_cola();
		aux=aux->siguiente;
		}
	}
int Cola::get_long(){
	return longitud;
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
	longitud--;	
	}
void Cola::insertar_orden(Proceso* p){
	pnodoCola nuevo=new NodoCola(p);
	pnodoCola actual=primero;
	
	if(esta_vacia()){
		primero=ultimo=nuevo;
			longitud++;
			return;
		}
	
		if(nuevo->proceso->get_prioridad() < primero->proceso->get_prioridad()){
			nuevo->siguiente=primero;
			primero=nuevo;
			longitud++;
			return;
			}
		
		while(actual->siguiente != NULL and actual->siguiente->proceso->get_prioridad()<=nuevo->proceso->get_prioridad()){
				actual=actual->siguiente;
				}
		nuevo->siguiente=actual->siguiente;
		actual->siguiente=nuevo;
		
		if(nuevo->siguiente==NULL){
			ultimo=nuevo;
			
			}
		longitud++;
		
	}