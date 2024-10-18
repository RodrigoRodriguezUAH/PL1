#include "NodoCola.hpp"

class Cola{
    public:
        Cola(string nombre);
        ~Cola();
        void encolar(Proceso* p);
        Proceso* vaciar();
        void mostrar();
        Proceso* verPrimero();
        int getLongitud();
        
    private:
        pnodoCola primero, ultimo;
        int longitud;
        string nombre;
}
