#ifndef PROCESO_HPP
#define PROCESO_HPP

#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

class Proceso{
    public:
        Proceso();
		~Proceso();
		//Metodos para generar sus datos
		string generar_nombre();
        bool generar_bool();
		//Metodos que muestran datos
        void mostrar_proceso();	
		//Metodos get y set
		int getPID();
        int getPrioridad();
		bool getEstado();
		bool getTipo();
		string getNombre();
		void setPID(int PID);
		void setPrioridad(int prioridad);
		void setEstado(bool estado);

	private:
		//Atributos
        int PID;
        string nombre;
        bool estado;
        bool tipo;
        int prioridad;
        
};

#endif
