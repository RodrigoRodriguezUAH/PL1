#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Gestor{
    public:
        Gestor();
        ~Gestor();
        //Metodos Interfaz
        int ProcesosEnPila();
        int ProcesosEnGPU0();
        int ProcesosEnGPU1();
        int ProcesosEnGPU2();
        int ProcesosEnGPU3();
		int ProcesosEnListaNormal();
		int ProcesosEnListaTiempoReal();
        //Metodos ejercicios
        //Pilas
        void genera12Procesos();
        void muestraProcesos();
        void borraProcesosPila();
        //Colas
        void encolarProcesos();
        void muestraProcesosGPUs0y1();
        void muestraProcesosGPUs2y3();
        void borraProcesosColas();
        //Listas
        void enlistarProcesos();
		void muestraProcesosNormal();
		void muestraProcesosTiempoReal();
		void buscarProcesos();
		void buscarProcesoPorNombreUsuario();
		void eliminarProcesoPorPID();
		void mostrarPrimeroUltimo();
		void cambiarPrioridadProcesoPorPID();
		//Reiniciar
		void reiniciar();
		
    private:
        Pila pila;
        Cola GPU0, GPU1, GPU2, GPU3;
        Lista normal, Treal;
};
