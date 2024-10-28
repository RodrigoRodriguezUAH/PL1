#include "Lista.hpp"

Lista::Lista(){
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

Lista::~Lista(){}

//Metodos para insertar elementos en la lista
void Lista::insertarInicio(Proceso* p) {
    pnodoLista nuevo = new NodoLista(p);
    primero->siguiente = nuevo;
    primero = nuevo;
	nuevo->siguiente = nullptr;
	p->setEstado(true);
	longitud++;
}

void Lista::insertarFinal(Proceso* p){
	pnodoLista nuevo = new NodoLista(p);
	nuevo->siguiente = ultimo;
	ultimo = nuevo;
	p->setEstado(true);
	longitud++;
}

//Metodo para mostrar contenido de una lista
void Lista::mostrar(){
	pnodoLista aux = ultimo;
	cout << left << setw(10) << "PID"
         << setw(15) << "Usuario"
         << setw(20) << "Tipo de Proceso"
         << setw(20) << "Estado"
         << setw(10) << "Prioridad"
         << endl;
	
	while(aux){
		aux->proceso->mostrar_proceso_lista();
		aux = aux->siguiente;
    }
}

//Metodo para cambiar la prioridad de un proceso seleccionado segun su PID, por otra prioridad seleccionada
Proceso* Lista::cambiarPrioridad(int PDI, int prioridad){
		pnodoLista aux = ultimo;
		if(ultimo->proceso->getPID() == PDI){
			ultimo->proceso->mostrar_proceso_lista();
			ultimo->proceso->setPrioridad(prioridad);
			return ultimo->proceso;
		}
		
		while(aux){
			if(aux->proceso->getPID() == PDI){
				aux->proceso->mostrar_proceso_lista();
				aux->proceso->setPrioridad(prioridad);
				return aux->proceso;
			}
			aux = aux->siguiente;
		}
		throw out_of_range("El proceso por ese PID no existe en la lista, intentelo con otro PID.");
}

//Metodo para eliminar un proceso que tiene un PID seleccionado
Proceso* Lista::eliminar(int PID) {
	pnodoLista aux = ultimo;
	pnodoLista temp = nullptr;
	pnodoLista anterior;
	
	if(ultimo->proceso->getPID() == PID){
		ultimo = aux->siguiente;
		temp = aux;
		delete aux;
		return temp->proceso;
	}
	while(aux){
		if(aux->proceso->getPID() == PID){
			temp = aux;
			anterior->siguiente = aux->siguiente;
			delete aux;
			longitud--;
			return temp->proceso;
		}
		anterior = aux;
		aux = aux->siguiente;
	}
	throw out_of_range("El proceso por ese PID no existe, intentelo con otro PID."); 
}

//Metodo que busca si existe un elemento con el PID seleccionado
bool Lista::contiene(int PID){
	pnodoLista aux = ultimo;
	while(aux){
		if(aux->proceso->getPID() == PID){return true;}
		aux = aux->siguiente;
	}
	return false;
}

//Metodos para buscar el elemento con mayor y menor prioridades
void Lista::MenorPrioridad(){
	int minimo = ultimo->proceso->getPrioridad();
	pnodoLista aux = ultimo;
	pnodoLista temp = ultimo;
	while(aux){
		if(aux->proceso->getPrioridad() < minimo){
			minimo = aux->proceso->getPrioridad();
			temp = aux;
		}
		aux = aux->siguiente;
	}
	temp->proceso->mostrar_proceso_cola();
}

void Lista::MayorPrioridad(){
	int maximo = ultimo->proceso->getPrioridad();
	pnodoLista aux = ultimo;
	pnodoLista temp = ultimo;
	while(aux){
		if(aux->proceso->getPrioridad() > maximo){
			maximo = aux->proceso->getPrioridad();
			temp = aux;
		}
		aux = aux->siguiente;
	}
	temp->proceso->mostrar_proceso_cola();
}

//Metodo para buscar en funcion de los nombres de usuario
void Lista::busquedaNombres(string nombre){
	pnodoLista aux = ultimo;
	while(aux){
		if(aux->proceso->getNombre() == nombre){aux->proceso->mostrar_proceso_lista();}
		aux = aux->siguiente;
	}
}

//Metodos Get
Proceso* Lista::getPrimero(){
	return primero->proceso;
}

Proceso* Lista::getUltimo(){
	return ultimo->proceso;
}

int Lista::getLongitud(){
	return this->longitud;
}

//Los metodos vaciar actuan como destructores
void Lista::vaciar(){
    pnodoLista actual = primero;
    while (actual != nullptr) {
        pnodoLista temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}