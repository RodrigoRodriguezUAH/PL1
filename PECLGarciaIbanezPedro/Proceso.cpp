#include "Proceso.hpp"

using namespace std;

//Lista de los nombres de usuario que tendran los procesos
string nombres[10] = {"Ana","Luis","Maria","Pedro","Sofia","Javier","Lucia","Carlos","Marta","Andres"};

//Metodos
Proceso::Proceso(){
    this->tipo = generar_bool();
    this->PID = 0; //PID ficticio
    this->nombre = generar_nombre();
    this->prioridad = 200; //Una prioridad ficticia que nos indicara que aun no ha salido de la pila
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

//Metodos que muestran datos
//En la pila
void Proceso::mostrar_proceso(){
	//Poner el nombre del tipo segun su booleano
	string tipoString;
	if (this->tipo == true) {tipoString = "normal";}
	else {tipoString = "en tiempo real";}
	//Si esta en la pila tendra PID de 200
	if(this->prioridad == 200){
		//Mostrar datos
		cout << "El proceso cuyo PID es " << PID << " es de tipo " << tipoString << endl;
	} else { //Si no esta en la pila
		//Asignar segun el estado (Esto diferencia si estan en la cola/arbol o en la lista)
		string estadoString;
		if(this->estado == true){ //Para Lista
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
}

//Gets y sets
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
string Proceso::getNombre(){
	return nombre;
}
void Proceso::setPID(int PID){
	this->PID = PID;
}
void Proceso::setEstado(bool estado){
	this->estado = estado;
}
void Proceso::setPrioridad(int prioridad){
	this->prioridad = prioridad;
}
