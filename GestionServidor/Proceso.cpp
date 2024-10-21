#include "Proceso.hpp"
#include <cstdlib>

using namespace std;

//Variables globales
int numbers[49]; //Lista de PIDs creados
int currentIndex; //Variable que contabiliza el nº de PIDs creados
//Lista de los nombres de usuario ficticios que tendran los procesos
string nombres[10] = {"Ana","Luis","Maria","Pedro","Sofia","Javier","Lucia","Carlos","Marta","Andres"};

//Metodos
Proceso::Proceso(){
    this->tipo = generar_bool();
    this->PID = generar_PID();
    this->nombre = generar_nombre();
    this->prioridad = generar_prioridad();
    this->estado = false;
}

Proceso::~Proceso(){
	
}

//Metodos generadores de datos
bool Proceso::generar_bool() {
	return rand() % 2 == 0;
}

string Proceso::generar_nombre(){
	int i = rand()%10;
	return nombres[i];
}

int Proceso::generar_PID(){
	for (int i = 0; i < 49; ++i) {
        numbers[i] = 300 + i;
    }
	if (currentIndex < 49) { //Surge un problema y es que si despues de generar procesos y enviarlos o borrarlos queremos volver a generar, la lista ya se ha llenado
        return numbers[currentIndex++];  
    }
	else throw out_of_range("Limite de procesos generados alcanzado.");
	/*Este texto no se seberia ver durante la implementacion del programa por la restriccion en generar procesos dentro de Gestor*/
} //Si queremos hacer un throw, hace falta incluir un try-catch, este puede estar en el constructor on en la funcion del gestor que genera los procesos

int Proceso::generar_prioridad(){
	bool tipo = generar_bool();
	if(tipo){
		return rand()% 39 - 19;
    } else return rand()%100;
}

//Metodos que muestran datos
void Proceso::mostrar_proceso(){
    string tipoString;
    if (tipo == true) {tipoString = "normal";} 
	else {tipoString = "en tiempo real";}
	
    cout << "El proceso cuyo PID es " << PID << " es de tipo " << tipoString << endl;
}

void Proceso::mostrar_proceso_cola(){
    string tipoString;
    if(tipo == true){ tipoString = "normal";}
    else {tipoString = "en tiempo real";}
    
    string estadoString;
    if(estado == true){ estadoString = "ejecución";}
    else {estadoString = "parado";}
    
    cout << "El proceso cuyo PID es: " << PID << " es de tipo " << tipoString << ", su estado es " 
		<< estadoString << " y su prioridad es: " << prioridad << endl;
}

//Gets y sets
void Proceso::setPrioridad(int prioridad){
	this->prioridad = prioridad;
}

int Proceso::getPrioridad(){
	return prioridad;
}

bool Proceso::getTipo(){
	return tipo;
}
