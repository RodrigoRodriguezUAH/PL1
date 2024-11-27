#ifndef PROCESO_HPP
#define PROCESO_HPP

#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

class Proceso{
    private:
        int PID;
        string nombre;
        bool estado;
        bool tipo;
        int prioridad;
        
    public:
        Proceso();
		~Proceso();
		//Metodos para generar sus datos
		string generar_nombre();
		int generar_PID();
        bool generar_bool();
        int generar_prioridad(bool tipo);
		//Metodos que muestran datos
        void mostrar_proceso();
        void mostrar_proceso(bool estado);	
		//Metodos get y set
		int getPID();
        int getPrioridad();
		bool getEstado();
		bool getTipo();
		string getNombre();
		void setPrioridad(int prioridad);
		void setEstado(bool estado);
		//Funcion Reset
		void resetProcesos();
};

#endif
