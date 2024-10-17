#include "Proceso.hpp"
#include <cstdlib>
#include <string> 
#include <iostream>
using namespace std;

int numbers[49];
int currentIndex;	
Proceso::Proceso(){
		this->tipo=generar_bool();
		this->PID=generar_PID();
		this->nombre=generar_nombre();
		this->prioridad=generar_prioridad();
		this->estado=false;
		
	}

bool Proceso::generar_bool() {
	return rand() % 2 == 0;
}


string Proceso::generar_nombre(){
	string nombres[10] = {
        "Ana",
        "Luis",
        "Maria",
        "Pedro",
        "Sofia",
        "Javier",
        "Lucia",
        "Carlos",
        "Marta",
        "Andres"
    };
	int i=rand()%10;
	return nombres[i];
	}
	
	
int Proceso::generar_PID(){
	for (int i = 0; i < 49; ++i) {
			numbers[i] = 300 + i;
			
        }
		if (currentIndex < 49) {
            return numbers[currentIndex++];  
        } else {
            throw out_of_range("Fuera de Rango.");
        }
	}
int Proceso::generar_prioridad(){
	bool tipo = generar_bool();
	if(tipo){
		return rand()% 39 - 19;
		}
	else{
		return rand()%100;	
		}
		
	}
	
	
void Proceso::mostrar_proceso(){
		string tipoString;
		if(tipo==true){
			tipoString="normal";
			}
		else{
			tipoString="en tiempo real";
		}
		cout<<"El proceso cuyo PID es "<<PID<<" es de tipo "<<tipoString<<endl;
		}
void Proceso::mostrar_proceso_cola(){
	string tipoString;
		if(tipo==true){
			tipoString="normal";
			}
		else{
			tipoString="en tiempo real";
		}
	string estadoString;
	if(estado==true){
			estadoString="ejecución";
			}
		else{
			estadoString="parado";
		}
		cout<<"El proceso cuyo PID es: "<<PID<<" es de tipo "<<tipoString<<" ,su estado es "<<estadoString<<" y su prioridad es: "<<prioridad;
	} 
	Proceso::~Proceso(){
		}