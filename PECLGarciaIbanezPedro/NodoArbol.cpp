#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Proceso* p){
    this->proceso = p;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}
