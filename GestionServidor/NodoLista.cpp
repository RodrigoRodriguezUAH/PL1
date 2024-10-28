#include "NodoLista.hpp"
NodoLista::NodoLista(Proceso* p, NodoLista* sig){
	proceso = p;
	siguiente = sig;
}
NodoLista::NodoLista(){
	proceso = nullptr;
	siguiente = nullptr;
}
NodoLista::~NodoLista(){

}
