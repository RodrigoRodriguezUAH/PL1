#include "Proceso.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

//Variables globales
//Lista de PIDs
int PIDs[] = {300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 
			  316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331,
              332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348};
int contador; //Variable que contabiliza el nº de PIDs creados
set<int> prioridades_generadas;
int arrayPrioridades[49]; //Contiene las prioridades que se han creado
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
	//Si tipo, el minimo es -19, en caso contrario es 0.
	int min = tipo ? -19 : 0;
	int max = tipo ? 19 : 99;
	// Generar número único dentro del rango correspondiente
    do {
        prioridad = min + rand() % (max - min + 1);
    } while (prioridades_generadas.find(prioridad) != prioridades_generadas.end());

    // Añadir el número generado al conjunto
    prioridades_generadas.insert(prioridad);
    return prioridad;
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
	prioridades_generadas.clear();//Se vacia el set de prioridades
	contador = 0; //Reinicia el indice
}
