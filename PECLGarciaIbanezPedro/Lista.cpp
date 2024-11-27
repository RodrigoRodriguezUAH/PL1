#include "Lista.hpp"

Lista::Lista(){
	primero = NULL;
	ultimo = NULL;
	longitud = 0;
}

Lista::~Lista(){}


void Lista::insertarInicio(Proceso* p) {
    pnodoLista nuevo = new NodoLista(p);
    nuevo->siguiente = primero;
    primero = nuevo;
	longitud++;
}

//Metodo para mostrar contenido de una lista
void Lista::mostrar(){
	//Columnas para los datos
	cout << left << setw(10) << "PID"
         << setw(15) << "Usuario"
         << setw(20) << "Tipo de Proceso"
         << setw(20) << "Estado"
         << setw(10) << "Prioridad"
         << endl;
	//Auxiliar que recorre la lista
	pnodoLista aux = primero;
	//Bucle que recorre la lista
	while(aux){
		aux->proceso->mostrar_proceso(true);
		aux = aux->siguiente;
    }
}

//Metodo para cambiar la prioridad de un proceso seleccionado segun su PID, por otra prioridad seleccionada
Proceso* Lista::cambiarPrioridad(int PDI, int prioridad){
		pnodoLista aux = primero;
		if(primero->proceso->getPID() == PDI){
			primero->proceso->mostrar_proceso(true);
			primero->proceso->setPrioridad(prioridad);
			return primero->proceso;
		}
		
		while(aux){
			if(aux->proceso->getPID() == PDI){
				aux->proceso->mostrar_proceso(true);
				aux->proceso->setPrioridad(prioridad);
				return aux->proceso;
			}
			aux = aux->siguiente;
		}
		throw out_of_range("El proceso por ese PID no existe en la lista, intentelo con otro PID.");
}

//Metodo para eliminar un proceso que tiene un PID seleccionado
Proceso* Lista::eliminar(int PID) {
	pnodoLista aux = primero;
	pnodoLista temp = nullptr;
	pnodoLista anterior;
	
	if(primero->proceso->getPID() == PID){
		primero = aux->siguiente;
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
	pnodoLista aux = primero;
	while(aux){
		if(aux->proceso->getPID() == PID){return true;}
		aux = aux->siguiente;
	}
	return false;
}

//Metodos para buscar el elemento con mayor y menor prioridades
void Lista::MenorPrioridad(){
	int minimo = primero->proceso->getPrioridad();
	pnodoLista aux = primero;
	pnodoLista temp = primero;
	while(aux){
		if(aux->proceso->getPrioridad() < minimo){
			minimo = aux->proceso->getPrioridad();
			temp = aux;
		}
		aux = aux->siguiente;
	}
	temp->proceso->mostrar_proceso(true);
}

void Lista::MayorPrioridad(){
	int maximo = primero->proceso->getPrioridad();
	pnodoLista aux = primero;
	pnodoLista temp = primero;
	while(aux){
		if(aux->proceso->getPrioridad() > maximo){
			maximo = aux->proceso->getPrioridad();
			temp = aux;
		}
		aux = aux->siguiente;
	}
	temp->proceso->mostrar_proceso(true);
}

//Metodo para buscar en funcion de los nombres de usuario
void Lista::busquedaNombres(string nombre){
	pnodoLista aux = primero;
	while(aux){
		if(aux->proceso->getNombre() == nombre){aux->proceso->mostrar_proceso(true);}
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
    NodoLista* actual =new NodoLista(); 
	actual = primero;
    while (actual != nullptr) {
        pnodoLista temp = actual;
        actual = actual->siguiente;
		longitud --;
        delete temp;
    }
}
