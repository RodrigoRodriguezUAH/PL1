#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Proceso.hpp"

class NodoCola{
    public:
        NodoCola(Proceso* p, NodoCola* sig=NULL);
        ~NodoCola();
        
    private:
        Proceso* proceso;
        NodoCola* siguiente;
        
        friend class Cola;
};

typedef NodoCola* pnodoCola;


#endif
