#include "Proceso.hpp"

using namespace std;

//Variables globales
//Lista de PIDs
int PIDs[] = {300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 
			  316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
              332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348};
int contador; //Variable que contabiliza el nº de PIDs creados
int prioridadesNormales[40]; //Contiene las prioridades de procesos normales
int prioridadesReales[100]; //Contienen las prioridades de procesos en tiempo real
//Lista de los nombres de usuario ficticios que tendran los procesos
string nombres[10] = {"Ana","Luis","Maria","Pedro","Sofia","Javier","Lucia","Carlos","Marta","Andres"};

//Metodos
Proceso::Proceso(){
    this->tipo = generar_bool();
    this->PID = generar_PID();
    this->nombre = generar_nombre();
    this->prioridad = generar_prioridad(tipo);
    this->estado = false;
}

Proceso::~Proceso(){}

//Metodos generadores de datos
bool Proceso::generar_bool() {
	return rand() % 2 == 0;
}

string Proceso::generar_nombre(){
	int i = rand()%10;
	return nombres[i];
}

int Proceso::generar_PID(){
	//Si el contador no ha llegado al limite no hay problema
	if (contador < 49) {return PIDs[contador++];}
	else throw out_of_range("Limite de procesos alcanzado, resetea el programa para poder generar mas.");
}

int Proceso::generar_prioridad(bool tipo){
	int prioridad;
	//Si tipo, rango de -19 a 19, sino de 0 a 99
	if (tipo){
		//Generar numero random del -19 al 19
		prioridad = rand()%39 - 19;
		//Comprobar si esta en el array, si esta descartarlo y generar uno nuevo
		while(prioridadesNormales[prioridad]){
			prioridad = rand()%39 - 19;
		}
		//Al salir significa que esa prioridad no existe, asi que se agrega
		prioridadesNormales[prioridad] = prioridad;
	} else {
		//Generar numero random del 0 al 99
		prioridad = rand()%100;
		//Comprobar si esta en el array, si esta descartarlo y generar uno nuevo
		while(prioridadesReales[prioridad]){
			prioridad = rand()%100;
		}
		//Al salir significa que esa prioridad no existe, asi que se agrega
		prioridadesReales[prioridad] = prioridad;
	}
    return prioridad;
}


//Metodos que muestran datos
//En la pila
void Proceso::mostrar_proceso(){
	//Poner el nombre del tipo segun su booleano
    string tipoString;
    if (tipo == true) {tipoString = "normal";} 
	else {tipoString = "en tiempo real";}
	//Mostrar datos
    cout << "El proceso cuyo PID es " << PID << " es de tipo " << tipoString << endl;
}
//En las demas estructuras
void Proceso::mostrar_proceso(bool estado){
	//Igualamos el estado que entre con el estado del proceso
	estado = this->estado;
    //Poner el nombre del tipo segun su booleano
	string tipoString;
    if (tipo == true) {tipoString = "normal";}
    else {tipoString = "en tiempo real";}
    //Asignar segun el estado (Esto diferenciara si estan en la cola/arbol o en la lista)
    string estadoString;
    if(estado == true){ //Para Lista
		estadoString = "ejecucion";
		//Mostrar datos
		cout << left << setw(10) << PID
			 << setw(15) << nombre
			 << setw(20) << tipoString
			 << setw(20) << estadoString
			 << setw(10) << prioridad
			 << endl;
	} else { //Para cola o arbol
		estadoString = "parado";
		//Mostrar datos
		cout << "El proceso cuyo PID es: " << PID << " es de tipo " << tipoString << ", su estado es " 
			<< estadoString << " y su prioridad es: " << prioridad << endl;
	}
}

//Gets y sets
void Proceso::setPrioridad(int prioridad){
	this->prioridad = prioridad;
}
int Proceso::getPID(){
	return PID;
}
int Proceso::getPrioridad(){
	return prioridad;
}

bool Proceso::getTipo(){
	return tipo;
}
bool Proceso::getEstado(){
	return estado;
}
void Proceso::setEstado(bool estado){
	this->estado = estado;
}
string Proceso::getNombre(){
	return nombre;
}

//Funcion reset para reiniciar la lista de procesos
void Proceso::resetProcesos(){
	//Vaciar los arrays
	for(int i = -19; prioridadesNormales[i]; i++){
		prioridadesNormales[i] = 0;
	}
	for(int i = 0; prioridadesReales[i]; i++){
		prioridadesNormales[i] = 0;
	}
	contador = 0; //Reinicia el indice
}

