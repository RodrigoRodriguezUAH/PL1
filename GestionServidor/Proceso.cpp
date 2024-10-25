#include "Proceso.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
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
	//Se llena la lista con los PIDs
	for (int i = 0; i < 49; ++i) {numbers[i] = 300 + i;}
	//Si el contador no ha llegado al limite no hay problema
	if (currentIndex < 49) {return numbers[currentIndex++];}
	else throw out_of_range("Limite de procesos alcanzado, resetea el programa para poder generar mas.");
}

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
    if(estado == true){ estadoString = "ejecucion";}
    else {estadoString = "parado";}
    
    cout << "El proceso cuyo PID es: " << PID << " es de tipo " << tipoString << ", su estado es " 
		<< estadoString << " y su prioridad es: " << prioridad << endl;
}

void Proceso::mostrar_proceso_lista(){
	string tipoString;
	if(tipo == true){ tipoString = "Normal";}
    else {tipoString = "TiempoReal";}
	
	string estadoString;
	if(estado == true){ estadoString = "En Ejecucion";}
    else {estadoString = "Parado";}
	
	cout << left << setw(10) << PID
         << setw(15) << nombre
         << setw(20) << tipoString
         << setw(20) << estadoString
         << setw(10) << prioridad
         << endl;
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
void Proceso::setEstado(bool estado){
	this->estado = estado;
}
string Proceso::getNombre(){
	return nombre;
}

//Funcion reset para reiniciar la lista de procesos
void Proceso::resetProcesos(){
	for(int i = 0; i < 49; i++){numbers[i] = 0;} //Llena la lista de 0
	currentIndex = 0; //Reinicia el indice
}
