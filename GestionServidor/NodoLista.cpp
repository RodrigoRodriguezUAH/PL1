#include "NodoLista.hpp"

NodoLista::NodoLista(Proceso* p){
	proceso = p;
	siguiente = nullptr;
	anterior = nullptr;
}

NodoLista::~NodoLista(){
}

