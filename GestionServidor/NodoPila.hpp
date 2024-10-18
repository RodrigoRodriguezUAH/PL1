#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Proceso.hpp"

class NodoPila{
    public:
        NodoPila(Proceso* p,NodoPila* sig=NULL);
        ~NodoPila();
    
    private:
        Proceso* proceso;
        NodoPila* siguiente;
        friend class Pila;
};

typedef NodoPila* pnodoPila;

#endif
