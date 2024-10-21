#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola{
    public:
        Cola();
        ~Cola();
        void encolar(Proceso* p);
		void encolarOrdenado(Proceso *p);
        Proceso* desencolar();
		void vaciar();
        void mostrar();
        Proceso* verPrimero();
        int getLongitud();
		bool esVacia();
        
    private:
        pnodoCola primero, ultimo;
        int longitud;
        
};

#endif
