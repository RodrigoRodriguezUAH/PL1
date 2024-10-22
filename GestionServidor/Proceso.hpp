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
        int generar_prioridad();
		//Metodos que muestran datos
        void mostrar_proceso();
        void mostrar_proceso_cola();
		void mostrar_proceso_lista();	
		//Metodos get y set
        void setPrioridad(int prioridad);
        int getPrioridad();
		bool getTipo();
		void setEstado(bool estado);
		//Funcion Reset
		void resetProcesos();
};

#endif
