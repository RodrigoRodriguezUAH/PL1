#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
	private:
		NodoLista* primero;
		NodoLista* ultimo;
		int longitud;
		
	public:
		Lista();
		~Lista();
		void insertarInicio(Proceso* p);
		void insertarFinal(Proceso* p);
		void eliminar(Proceso* p);
		void mostrar();
		int get_longitud();
		void MayorPrioridad();
		void MenorPrioridad();
		void busquedaNombres(string nombre);
};

#endif
