#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Proceso.hpp"

class NodoLista{
    public:
        NodoLista(Proceso* p);
        ~NodoLista();
        
    private:
        Proceso* proceso;
        NodoLista* siguiente;
        NodoLista* anterior; //Doblemente enlazada
        
        friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP
