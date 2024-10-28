#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola{
    public:
        Cola();
		~Cola();
		void encolarOrdenado(Proceso *p);
        Proceso* desencolar();
        void mostrar();
        Proceso* verPrimero();
        int getLongitud();
		bool esVacia();
		void vaciar(); //Vaciar actua como destructor
		
    private:
        pnodoCola primero, ultimo;
        int longitud;
        
};

#endif
