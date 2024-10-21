#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista{
    public:
        Lista();
        ~Lista();
		void insertar();
		void extraer();
		void mostrar();

    private:
        pnodoLista Primero;
		pnodoLista Ultimo;
};

#endif // LISTA_HPP
