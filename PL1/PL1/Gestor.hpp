#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
using namespace std;

class Gestor{
    public:
        Gestor();
        ~Gestor();
        //Metodos Interfaz
        int ProcesosEnPila();
        
        //Metodos ejercicios
        //Pilas
        void genera12Procesos();
        void muestraProcesos();
        void borraProcesosPila();
        //Colas
        void encolarProcesos():
        void muestraProcesosGPUs0y1();
        void muestraProcesosGPUs2y3();
        void borraProcesosColas();
        //Listas
        
    private:
        Pila pila;
}