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
		pnodoAbb getRaiz();
		void mostrarProcesosNormales();
		void mostrarProcesosReales();
		void mostrarProcesosArbol();
		void mostrarExtremos(); //Nos da el proceso con menor prioridad de los normales y con mayor prioridad de los reales
		void mostrarHojas();

	private:
		pnodoAbb raiz;
		int numeroNodos;
		pnodoAbb insertar(pnodoAbb, Proceso*);
		void pintar(pnodoAbb);
		int altura(pnodoAbb);
		void dibujarNodo(vector<string>& output, vector<string>& linkAbove, 
						pnodoAbb nodo, int nivel, int minPos, char linkChar);
		void recorrerMostrando(pnodoAbb nodo); //Recorre en inorden
		void buscarMostrandoHojas(pnodoAbb nodo);
};

#endif // ARBOL_HPP
