#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"

#include <vector>
using namespace std;

class Arbol{
	public:
		Arbol();
		~Arbol();
		void insertar(Proceso* p);
		void pintar();
		void dibujar();
		int getNumeroNodos();
		

	private:
		pnodoAbb raiz;
		pnodoAbb insertar(pnodoAbb, Proceso*);
		void pintar(pnodoAbb);
		int altura(pnodoAbb);
		void dibujarNodo(vector<string>& output, vector<string>& linkAbove, 
						pnodoAbb nodo, int nivel, int minPos, char linkChar);
		int numeroNodos;
};

#endif // ARBOL_HPP
