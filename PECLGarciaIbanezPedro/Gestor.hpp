#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"
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
		int ProcesosEnArbol();
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
		//ABB
		void crearDibujarABB();
		void mostrarNormalesABB();
		void mostrarRealesABB();
		void mostrarProcesosArbol();
		void mostrarProcesoMinNormalMaxReal();
		void mostrarProcesosHoja();
		void eliminarPorPrioridad();
		//Reiniciar
		void reiniciar();
		
	private:
        //Atributos
		Pila pila;
        Cola GPU0, GPU1, GPU2, GPU3;
        Lista normal, Treal;
		Arbol ABB;
		//Métodos privados
		void llenar_listas_prioridades(); //Genera los rangos de prioridades de los procesos
		void asignarPID(Proceso *p); //Asigna los PIDs a los procesos
		void asignarPrioridad(Proceso *p); //Asigna la prioridad al proceso
		void activarProceso(Proceso *p); //Activa el estado del proceso
};
