#include "Gestor.hpp"

//Variable que indica si se puede resetear
bool resetear = false; 

Gestor::Gestor(){
	Pila pila;
    Cola GPU0, GPU1, GPU2, GPU3;
    Lista normal, Treal;
	Arbol ABB;
}

Gestor::~Gestor(){}

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

//Funciones de las opciones del main:
//Pilas
void Gestor::genera12Procesos(){
	try{
		if(!resetear){resetear = true;} //Se permite resetear porque existen procesos
		if(pila.getLongitud() < 48){
			for (int i = 0; i < 12; i++){
				Proceso* p = new Proceso();
				pila.insertar(p);
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
    Proceso* desplazado;
    while(pila.getLongitud() != 0){
        desplazado = pila.extraer();
		if(desplazado->getTipo()){desplazado->setPrioridad(desplazado->getPrioridad()+120);}
        if (desplazado->getTipo()){ //Proceso de tipo normal porque estos equivalen a true
            if (GPU0.getLongitud() <= GPU1.getLongitud()){ //Compara longitudes
                GPU0.encolarOrdenado(desplazado);
            } else {GPU1.encolarOrdenado(desplazado);}
        } else { //Proceso de tipo tiempo real
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
		while(GPU0.getLongitud()>0){
			normal.insertarInicio(GPU0.desencolar());
		}
		while(GPU1.getLongitud()>0){
			normal.insertarInicio(GPU1.desencolar());
		}
		while(GPU2.getLongitud()>0){
			Treal.insertarInicio(GPU2.desencolar());
		}
		while(GPU3.getLongitud()>0){
			Treal.insertarInicio(GPU3.desencolar());
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
			eliminado->mostrar_proceso_lista();
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
			 eliminado->mostrar_proceso_lista();
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
			 cambiar->mostrar_proceso_lista();
		} else { //Si no esta en la normal mira en la de Treal
			Proceso* cambiar = Treal.cambiarPrioridad(PID,prioridad);
			cout << left << setw(10) << "PID"
				 << setw(15) << "Usuario"
				 << setw(20) << "Tipo de Proceso"
				 << setw(20) << "Estado"
				 << setw(10) << "Prioridad"
				 << endl;
			 cambiar->mostrar_proceso_lista();
		}
		 
	} catch (const out_of_range& e) { //Error si el PID no existe en ninguna de las listas
		cout << e.what() << endl;
	}
}

//Reiniciar programa
void Gestor::reiniciar(){ 
	//Comprueba si existe algun proceso en alguna de las estructuras y lo vacia despues de resetear los procesos
	if(resetear){ //El resetear se activa cuando se generan procesos
		if(pila.getLongitud() > 0){
			pila.cima()->resetProcesos();
			pila.vaciar();
		}
		if(!GPU0.esVacia()){
			GPU0.desencolar()->resetProcesos();
			GPU0.vaciar();
		}
		if(!GPU1.esVacia()){
			GPU1.desencolar()->resetProcesos();
			GPU1.vaciar();
		}
		if(!GPU2.esVacia()){
			GPU2.desencolar()->resetProcesos();
			GPU2.vaciar();
		}
		if(!GPU3.esVacia()){
			GPU3.desencolar()->resetProcesos();
			GPU3.vaciar();
		}
		if(Treal.getLongitud() > 0){
			Treal.getPrimero()->resetProcesos();
			Treal.vaciar();
		}
		if(normal.getLongitud() > 0){
			normal.getPrimero()->resetProcesos();
			normal.vaciar();
		}
	resetear = false; //Una vez reseteado no se puede resetear hasta que se hayan vuelto a generar
	}
}

int Gestor::ProcesosEnArbol(){
	return 0;
	}
void Gestor::crearDibujarABB(){
		Proceso* raiz=new Proceso();
		raiz->setPrioridad(100);
		ABB.insertar(raiz);
		while(pila.getLongitud()!=0){
			Proceso* proceso=pila.extraer();
			if(proceso->getTipo()){proceso->setPrioridad(proceso->getPrioridad()+120);}
			ABB.insertar(proceso);
			}
			ABB.dibujar();
	}
	
	
	
	
	
