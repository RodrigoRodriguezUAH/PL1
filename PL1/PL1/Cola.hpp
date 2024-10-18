#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola{
    public:
        Cola();
        ~Cola();
        void encolar(Proceso* p);
        Proceso* vaciar();
        void mostrar();
        Proceso* verPrimero();
        int getLongitud();
        
    private:
        pnodoCola primero, ultimo;
        int longitud;
        
};

#endif
