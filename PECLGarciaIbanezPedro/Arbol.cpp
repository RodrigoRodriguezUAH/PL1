#include "Arbol.hpp"

Arbol::Arbol() {
	raiz = nullptr; 
	numeroNodos = 0;
}

//Métodos para insertar
void Arbol::insertar(Proceso* p) {
	raiz = insertar(raiz, p); //Lllama al insertar privado
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Proceso* p){
    //Entra en una hoja/nodo vacia
	if(!nodo){
		numeroNodos = numeroNodos + 1;
		return new NodoArbol(p);
	}
	//Si existe un nodo, compara con la prioridad para determinar si va al aubarbol derecho o izquierdo
    if(p->getPrioridad() <= nodo->proceso->getPrioridad()){
		nodo->izq = insertar(nodo->izq, p);
	} else {
		nodo->der = insertar(nodo->der, p);
	}
    return nodo;
}

//Métodos para dibujar el arbol
void Arbol::pintar(){
    pintar(raiz); //Llama al metodo privado para pintar
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo){
    //Si esta vacio el nodo sale
	if(!nodo)
        return;
	//Sino recursividad a la izquierda
    pintar(nodo->izq);
	//Muestra la prioridad del nodo
    cout << nodo->proceso->getPrioridad() << " ";
	//Y hace recursividad a la derecha
    pintar(nodo->der);
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, 
						pnodoAbb nodo, int nivel, int p, char linkChar) {
	//Si esta vacio sale
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol =
            nodo->izq->proceso->getPrioridad(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol =
        nodo->proceso->getPrioridad(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar(){
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}
bool Arbol::esta(pnodoAbb nodo, int prioridad){
		//Si el árbol esta vacío o alcanza una hoja el elemento no esta
		
		//Si esta vacio el nodo sale
	if(!nodo) return false;
	if (nodo->proceso->getPrioridad()==prioridad){
		return true;
		}
	else if(nodo->proceso->getPrioridad()>prioridad){
	//Sino recursividad a la izquierda
    return buscarPorPrioridad(prioridad,nodo->izq);
		}
	else if(nodo->proceso->getPrioridad()<prioridad){
	//Y hace recursividad a la derecha
	return buscarPorPrioridad(prioridad,nodo->der);
		}
	else{return false;}
	}
//Metodo que obtiene la altura
int Arbol::altura(pnodoAbb nodo){
	//Si esta vacio sale
    if(!nodo)
        return 0;
	//Sino hace llamada recursiva y suma 1
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

//Metodos mostrar
void Arbol::mostrarProcesosNormales(){
	recorrerMostrando(this->raiz->der);
}

void Arbol::mostrarProcesosReales(){
	recorrerMostrando(this->raiz->izq);
}

void Arbol::mostrarProcesosArbol(){
	//Nota: no mostramos el nodo ficticio
	recorrerMostrando(this->raiz->izq);
	recorrerMostrando(this->raiz->der);
}

void Arbol::recorrerMostrando(pnodoAbb nodo){
	//Si esta vacio el nodo sale
	if(!nodo) return;
	//Sino recursividad a la izquierda
    recorrerMostrando(nodo->izq);
	//Muestra el proceso del nodo
    nodo->proceso->mostrar_proceso();
	//Y hace recursividad a la derecha
    recorrerMostrando(nodo->der);
}

void Arbol::mostrarExtremos(){
	//Creamos un puntero auxiliar que apunte a la raiz
	pnodoAbb aux = raiz; 
	//Mientras exista un nodo derecho seguimos recorriendo el arbol derecho
	while(aux->der){ aux = aux->der; }
	//Al salir apuntamos al proceso con menor prioridad de los normales
	cout << "- El proceso con menor prioridad de los normales es:\n\t";
	aux->proceso->mostrar_proceso();
	//Volvemos a la raiz
	aux = raiz;
	//Mientras exista un nodo izquierdo seguimos recorriendo el arbol izquierdo
	while(aux->izq){ aux = aux->izq; }
	//Al salir apuntamos al proceso con mayor prioridad de los reales
	cout << "- El proceso con mayor prioridad de los de tiempo real es:\n\t";
	aux->proceso->mostrar_proceso();
}

void Arbol::mostrarHojas(){
	cout << "Procesos almacenados en nodos hojas:\n";
	buscarMostrandoHojas(this->raiz);
}

void Arbol::buscarMostrandoHojas(pnodoAbb nodo){
	//Si es un nodo hoja mostrarlo
	if(nodo->izq == nullptr && nodo->der == nullptr){
		nodo->proceso->mostrar_proceso();
		return; //Salir de la funcion
	}
	//Sino, si una rama esta vacia buscar en la otra
	if(nodo->der == nullptr){ //Si solo hay rama izquierda
		//Busca en ella
		buscarMostrandoHojas(nodo->izq);
	} else { //Existe la rama der
		if(nodo->izq != nullptr){ //Si las dos ramas existen buscar en las 2
			//Busca en la izq
			buscarMostrandoHojas(nodo->izq);
		}
		//Busca en la der
		buscarMostrandoHojas(nodo->der);
	}
}

// Función para encontrar el valor máximo en un árbol binario
Proceso* Arbol::maximo(pnodoAbb abb) {
    while (abb->der != nullptr) {
        abb = abb->der;
    }
    return abb->proceso;
}
//Declaración adelantada para evitar errores
//pnodoAbb Arbol::borrarElemento(Proceso* proceso, pnodoAbb abb);

// Función para borrar un nodo del árbol
pnodoAbb Arbol::borrarNodo(pnodoAbb abb) {
    pnodoAbb nuevo;
    if (abb->izq == nullptr && abb->der == nullptr) {
        delete abb;
        return nullptr;
    } 
	else if (abb->izq == nullptr) {
        nuevo = abb->der;
        delete abb;
        return nuevo;
    } 
	else if (abb->der == nullptr) {
        nuevo = abb->izq;
        delete abb;
        return nuevo;
    } 
	else {
        abb->proceso = maximo(abb->izq);
        abb->izq = borrarElemento(abb->proceso, abb->izq);
        return abb;
    }
}
// Función para borrar un elemento del árbol
pnodoAbb Arbol::borrarElemento(Proceso* proceso, pnodoAbb abb) {
    int p=proceso->getPrioridad();
	if (abb == nullptr) {
        return nullptr;
    } 
	else if (p < abb->proceso->getPrioridad()) {
        abb->izq = borrarElemento(proceso, abb->izq);
    } 
	else if (p > abb->proceso->getPrioridad()) {
        abb->der = borrarElemento(proceso, abb->der);
    } 
	else {
        abb = borrarNodo(abb);
    }
    return abb;
}

//Metodos get
int Arbol::getNumeroNodos(){
	return this->numeroNodos;
}

pnodoAbb Arbol::getRaiz(){
	return this->raiz;
}


Proceso* Arbol::buscarPorPrioridad(int prioridad,pnodoAbb nodo){
		
	//Si esta vacio el nodo sale
	if(!nodo) return 0;
	if (nodo->proceso->getPrioridad()==prioridad){
		return nodo->proceso;
		}
	else if(nodo->proceso->getPrioridad()>prioridad){
	//Sino recursividad a la izquierda
    return buscarPorPrioridad(prioridad,nodo->izq);
		}
	else if(nodo->proceso->getPrioridad()<prioridad){
	//Y hace recursividad a la derecha
	return buscarPorPrioridad(prioridad,nodo->der);
		}
	
}






Arbol::~Arbol() {}

