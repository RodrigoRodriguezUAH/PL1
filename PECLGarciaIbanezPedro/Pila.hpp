#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila{
    public:
        Pila();
		~Pila();
        void insertar(Proceso* p);
        Proceso* extraer();
        Proceso* cima();
        void mostrar();
        int getLongitud();
        void vaciar(); //Vaciar actua como destructor
        
    private:
        pnodoPila ultimo;
        int longitud;
};

#endif