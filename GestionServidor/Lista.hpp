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
		Proceso* eliminar(int PID);
		void mostrar();
		int get_longitud();
		void MayorPrioridad();
		void MenorPrioridad();
		void busquedaNombres(string nombre);
		Proceso* getPrimero();
		Proceso* getUltimo();
		Proceso* cambiarPrioridad(int PDI,int prioridad);
		bool contiene(int PID);
		void vaciar();
};

#endif
