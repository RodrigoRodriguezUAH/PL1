#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Proceso.hpp"

class NodoLista {
public:
		NodoLista();
		NodoLista(Proceso* p, NodoLista* sig=NULL);
		~NodoLista();
		
	private:
		Proceso* proceso;
		NodoLista* siguiente;
		friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif
