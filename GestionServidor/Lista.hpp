#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
	public:
		Lista();
		~Lista();
		void insertarInicio(Proceso* p);
		void insertarFinal(Proceso* p);
		Proceso* eliminar(int PID);
		void mostrar();
		int getLongitud();
		void MayorPrioridad();
		void MenorPrioridad();
		void busquedaNombres(string nombre);
		Proceso* getPrimero();
		Proceso* getUltimo();
		Proceso* cambiarPrioridad(int PDI,int prioridad);
		bool contiene(int PID);
		void vaciar(); //Vaciar actua como destructor
		
	private:
		NodoLista* primero;
		NodoLista* ultimo;
		int longitud;
};

#endif
