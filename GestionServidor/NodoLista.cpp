#include "NodoLista.hpp"
NodoLista::NodoLista(Proceso* p, NodoLista* sig)
{
	proceso=p;
	siguiente=sig;
	}
NodoLista::~NodoLista(){
	}