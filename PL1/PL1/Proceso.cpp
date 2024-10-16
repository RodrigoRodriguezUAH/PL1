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
        "María",
        "Pedro",
        "Sofía",
        "Javier",
        "Lucía",
        "Carlos",
        "Marta",
        "Andrés"
    };
	int i=rand()%10;
	return nombres[i];
	}
	
	
int Proceso::generar_PID(){
	for (int i = 0; i < 49; ++i) {
			numbers[i] = 300 + i;
			
        }
		if (currentIndex < 49) {
            return numbers[currentIndex++];  // Devolvemos el número y aumentamos el índice
        } else {
            throw out_of_range("No more unique numbers left");
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
		cout<<"Proceso numero: "<<PID<<" lanzado por "<<nombre<<" de tipo "<<tipo<<" con prioridad "<<prioridad<<" se encuentra en estado: "<<estado<<endl;
		}
	Proceso::~Proceso(){
		}