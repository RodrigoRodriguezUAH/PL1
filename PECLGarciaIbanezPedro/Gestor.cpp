#include "Gestor.hpp"
#include <algorithm> //Para usar random_shuffle
//Variable que indica si se puede resetear
bool resetear = false;
//Lista de PIDs
int PIDs[] = {300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 
			  316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
              332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348};
int contador; //Variable que contabiliza el nº de PIDs creados
//Arrays de prioridades y sus contadores
int prioridadesNormales[40]; //Contiene las prioridades de procesos normales
int prioridadesReales[100]; //Contienen las prioridades de procesos en tiempo real
int contadorNormal; //Indica cuantos procesos normales existen
int contadorReal; //Indica cuantos procesos de tiempo real existen

Gestor::Gestor(){
	Pila pila;
    Cola GPU0, GPU1, GPU2, GPU3;
    Lista normal, Treal;
	Arbol ABB;
	//Generamos los elementos de los arrays de prioridades
	llenar_listas_prioridades();
	//Iniciamos los contadores a 0
	contador = 0;
	contadorNormal = 0;
	contadorReal = 0; 
}

Gestor::~Gestor(){}

//Funciones privadas
void Gestor::asignarPID(Proceso *p){
	//Si el contador no ha llegado al limite
	if(contador < 49){
		p->setPID(PIDs[contador]); //Asigna el PID
		contador++; //Aumenta el contador de PIDs
	} else throw out_of_range("Limite de procesos alcanzado, resetea el programa para poder generar mas.");
}

void Gestor::asignarPrioridad(Proceso *p){
	bool tipo = p->getTipo();
	if(tipo){ //Proceso Normal
		p->setPrioridad(prioridadesNormales[contadorNormal]); //Asigna la prioridad de la posicion del contador
		contadorNormal++; //Aumenta el contador
		//Si la prioridad del proceso normal aun no se ha aumentado, aumentarla
		if (p->getPrioridad() < 20){
			p->setPrioridad(p->getPrioridad() + 120);
		}
	} else { //Proceso en tiempo real
		p->setPrioridad(prioridadesReales[contadorReal]); //Asigna la prioridad de la posicion del contador
		contadorReal++; //Aumenta el contador
	}
}

void Gestor::activarProceso(Proceso *p){
	p->setEstado(true);
}

//Funcion de datos de control
//Método constructor de las listas de prioridades
void Gestor::llenar_listas_prioridades(){
	//Generar los numeros del -19 al 19
	for(int i = 0; i <= 39; i++){prioridadesNormales[i] = i - 19;}
	//Desordenar el array
	random_shuffle(prioridadesNormales, prioridadesNormales + 39);

	//Generar numero random del 0 al 99
	for(int i = 0; i <= 99; i++){prioridadesReales[i] = i;}
	//Desordenar el array
	random_shuffle(prioridadesReales, prioridadesReales + 39);
}

//Funciones de la pantalla de interfaz
int Gestor::ProcesosEnPila(){
	return pila.getLongitud();
}

int Gestor::ProcesosEnGPU0(){
    return GPU0.getLongitud();
}

int Gestor::ProcesosEnGPU1(){
    return GPU1.getLongitud();
}

int Gestor::ProcesosEnGPU2(){
    return GPU2.getLongitud();
}

int Gestor::ProcesosEnGPU3(){
    return GPU3.getLongitud();
}

int Gestor::ProcesosEnArbol(){
	return ABB.getNumeroNodos();
}

//Funciones de las opciones del main:
//Pilas
void Gestor::genera12Procesos(){
	try{
		if(!resetear){resetear = true;} //Se permite resetear porque existen procesos
		if(pila.getLongitud() < 48){
			for (int i = 0; i < 12; i++){ //Repetimos el bucle 12 veces
				Proceso* p = new Proceso(); //Creamos el proceso
				asignarPID(p); //Le asignamos el PID
				pila.insertar(p); //Lo introducioms en la pila
			}
		}
	} catch(const out_of_range& e) {
		cout << e.what() << endl; //Muestra el mensaje de la excepcion
	}
}

void Gestor::muestraProcesos(){
	pila.mostrar();
}

void Gestor::borraProcesosPila(){
	pila.vaciar();
	cout << "Pila vaciada";
}

//Colas
void Gestor::encolarProcesos(){
    Proceso* desplazado; //Puntero que apuntara a los procesos a entre estructuras
    while(pila.getLongitud() != 0){ //Mientras la pila no este vacia
        desplazado = pila.extraer(); //Apuntamos al proceso que sacamos de la pila
		asignarPrioridad(desplazado); //Le asignamos una prioridad
        if (desplazado->getTipo()){ //Si el proceso es de tipo normal
			//Compara longitudes de las colas e introduce el proceso en la que corresponde
            if (GPU0.getLongitud() <= GPU1.getLongitud()){ 
                GPU0.encolarOrdenado(desplazado);
            } else {GPU1.encolarOrdenado(desplazado);}
        } else { //Igual en los procesos de tipo tiempo real
            if (GPU2.getLongitud() <= GPU3.getLongitud()){
                GPU2.encolarOrdenado(desplazado);
            } else {GPU3.encolarOrdenado(desplazado);}
        }
    }
}

void Gestor::muestraProcesosGPUs0y1(){
    cout << "GPU 0:" << endl;
    GPU0.mostrar();
    cout << endl << "GPU 1:" << endl;
    GPU1.mostrar();
}

void Gestor::muestraProcesosGPUs2y3(){
    cout << "GPU 2:" << endl;
    GPU2.mostrar();
    cout << endl << "GPU 3:" << endl;
    GPU3.mostrar();
}
 
void Gestor::borraProcesosColas(){
    GPU0.vaciar();
    GPU1.vaciar();
    GPU2.vaciar();
    GPU3.vaciar();
	cout << "Colas vaciadas" << endl;
}

//Listas
int Gestor::ProcesosEnListaNormal(){
	return normal.getLongitud();
}

int Gestor::ProcesosEnListaTiempoReal(){
		return Treal.getLongitud();
}


void Gestor::enlistarProcesos(){
	//Desencola el proceso, lo activa y lo inserta en las lista que corresponden
	while(GPU0.getLongitud()>0){
		Proceso *p = GPU0.desencolar();
		activarProceso(p);
		normal.insertarInicio(p);
	}
	while(GPU1.getLongitud()>0){
		Proceso *p = GPU1.desencolar();
		activarProceso(p);
		normal.insertarInicio(p);
	}
	while(GPU2.getLongitud()>0){
		Proceso *p = GPU2.desencolar();
		activarProceso(p);
		Treal.insertarInicio(p);
	}
	while(GPU3.getLongitud()>0){
		Proceso *p = GPU3.desencolar();
		activarProceso(p);
		Treal.insertarInicio(p);
	}
}

void Gestor::muestraProcesosNormal(){
	cout << "Lista de procesos Normales" << endl;
	normal.mostrar();
}

void Gestor::muestraProcesosTiempoReal(){
	cout << "Lista de procesos en Tiempo Real" << endl;
	Treal.mostrar();
}

void Gestor::buscarProcesos(){
	cout<<"Normal menor prioridad-> "; 
	normal.MenorPrioridad();
	cout<<endl;
	cout<<"Tiempo real mayor prioridad-> ";
	Treal.MayorPrioridad();
	cout<<endl;
}

void Gestor::buscarProcesoPorNombreUsuario(){
	string nombre;
	cout << "Introduce el nombre de usuario: ";
	cin >> nombre;
	cout << "Procesos en lista normal: " << endl;
	//Formato de las columnas como se van a mostrar los proceso
	cout << left << setw(10) << "PID"
         << setw(15) << "Usuario"
         << setw(20) << "Tipo de Proceso"
         << setw(20) << "Estado"
         << setw(10) << "Prioridad"
         << endl;
	
	normal.busquedaNombres(nombre);
	cout << endl;
	cout << "Procesos en lista Tiempo Real: " << endl;
	Treal.busquedaNombres(nombre);
	cout << endl;
}

void Gestor::eliminarProcesoPorPID(){
	int PID;
	cout << "Introduce PID: ";
	cin >> PID;
	try { //Intenta ejecutar
		if(normal.contiene(PID)){ //Comprueba si el proceso esta en la lista Normal
			Proceso* eliminado = normal.eliminar(PID);
			eliminado->setEstado(false);
			pila.insertar(eliminado); //Se debe insertar el proceso sacado de lista en la pila
			//Mostrar elemento eliminado
			cout << left << setw(10) << "PID"
				 << setw(15) << "Usuario"
				 << setw(20) << "Tipo de Proceso"
				 << setw(20) << "Estado"
				 << setw(10) << "Prioridad"
				 << endl;
			eliminado->mostrar_proceso();
		} else { //Si no esta en la normal, revisa la de Tiempo Real
			Proceso* eliminado = Treal.eliminar(PID);
			eliminado->setEstado(false);
			pila.insertar(eliminado);
			cout << left << setw(10) << "PID"
				 << setw(15) << "Usuario"
				 << setw(20) << "Tipo de Proceso"
				 << setw(20) << "Estado"
				 << setw(10) << "Prioridad"
				 << endl;
			 eliminado->mostrar_proceso();
		}
	} catch (const out_of_range& e) { //Error por PID erroneo
		cout << e.what() << endl;
    }
}

void Gestor::cambiarPrioridadProcesoPorPID(){
	int prioridad;
	int PID;
	cout << "Introduce PID: ";
	cin >> PID;
	cout << "Introduce la nueva prioridad: ";
	cin >> prioridad;
	
	try{ //Comprobar si el PID es valido
		if(normal.contiene(PID)){ //Mira en la lista normal
			Proceso* cambiar = normal.cambiarPrioridad(PID,prioridad);
			cout << left << setw(10) << "PID"
				  << setw(15) << "Usuario"
				  << setw(20) << "Tipo de Proceso"
				  << setw(20) << "Estado"
				  << setw(10) << "Prioridad"
				  << endl;
			cambiar->mostrar_proceso();
		} else { //Si no esta en la normal mira en la de Treal
			Proceso* cambiar = Treal.cambiarPrioridad(PID,prioridad);
			cout << left << setw(10) << "PID"
				 << setw(15) << "Usuario"
				 << setw(20) << "Tipo de Proceso"
				 << setw(20) << "Estado"
				 << setw(10) << "Prioridad"
				 << endl;
			cambiar->mostrar_proceso();
		}
		 
	} catch (const out_of_range& e) { //Error si el PID no existe en ninguna de las listas
		cout << e.what() << endl;
	}
}

//Arbol
void Gestor::crearDibujarABB(){
	//Si la raiz no se ha creado generarla
	if(ABB.getRaiz() == nullptr){
		Proceso* raiz = new Proceso();
		raiz->setPrioridad(100);
		ABB.insertar(raiz);
	}
	//Desapila e insertar al arbol
	while(pila.getLongitud() != 0){ //Bucle mientras la pila no este vacia
		Proceso* proceso = pila.extraer(); //Creamos un puntero que apunte al proceso desapilado
		asignarPrioridad(proceso); //Le asignamos una prioridad
		ABB.insertar(proceso); //Lo introducimos en el arbol
	}
	//Muestra el arbol por pantalla
	ABB.dibujar();
}

void Gestor::mostrarNormalesABB(){
	ABB.mostrarProcesosNormales();
}

void Gestor::mostrarRealesABB(){
	ABB.mostrarProcesosReales();
}

void Gestor::mostrarProcesosArbol(){
	ABB.mostrarProcesosArbol();
}

void Gestor::mostrarProcesoMinNormalMaxReal(){
	ABB.mostrarExtremos();
}

void Gestor::mostrarProcesosHoja(){
	ABB.mostrarHojas();
}
void Gestor::eliminarPorPrioridad(){
		int Prioridad;
		cout<<"Indica la prioridad del proceso a eliminar: ";
		cin>>Prioridad;
		cout<<"Arbol antes de eliminar-> "<<endl;
		ABB.dibujar();
		Proceso* eliminar = ABB.buscarPorPrioridad(Prioridad,ABB.getRaiz());
		eliminar->mostrar_proceso();
		ABB.borrarElemento( eliminar,ABB.getRaiz());
		cout<<"Arbol tras eliminar-> "<<endl;
		ABB.dibujar();
}
//Reiniciar programa
void Gestor::reiniciar(){ 
	//Comprueba si existe algun proceso en alguna de las estructuras y lo vacia despues de resetear los procesos
	if(resetear){ //El resetear se activa cuando se han generado procesos
		//Vaciado de las estructuras
		//Si hay algun proceso en la pila se resetea
		if(pila.getLongitud() > 0){pila.vaciar();}
		//Se revisa si hay algun proceso en las colas
		if(!GPU0.esVacia()){GPU0.vaciar();}
		if(!GPU1.esVacia()){GPU1.vaciar();}
		if(!GPU2.esVacia()){GPU2.vaciar();}
		if(!GPU3.esVacia()){GPU3.vaciar();}
		//Se revisa si las Listas estan vacias
		if(Treal.getLongitud() > 0){Treal.vaciar();}
		if(normal.getLongitud() > 0){normal.vaciar();}
		//Se revisa si hay nodos en alguno de los subarboles de la raiz ya que el raiz es uno inventado
		if(ABB.getNumeroNodos() > 0){
			//Pendiente de vaciar
		}
		
		//Contadores reiniciados
		contador = 0;
		contadorNormal = 0;
		contadorReal = 0;
		//Una vez reseteado no se puede resetear hasta que se hayan vuelto a generar
		resetear = false;
	}
}
	
	
