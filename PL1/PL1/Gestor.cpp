
#include "Gestor.hpp"
using namespace std;

Gestor::Gestor(){
	Pila pila;
	Cola GPU1;
	Cola GPU2;
	Cola GPU3;
	Cola GPU4;
	
	}
void Gestor::mostrar_colas(){
	GPU1.mostrar();
	cout<<endl;
	GPU2.mostrar();
	cout<<endl;
	GPU3.mostrar();
	cout<<endl;
	GPU4.mostrar();
	}
int Gestor::ProcesosEnGPU1(){
	return GPU1.get_long();
	}
int Gestor::ProcesosEnGPU2(){
	return GPU2.get_long();
	}
int Gestor::ProcesosEnGPU3(){
	return GPU3.get_long();
	}
int Gestor::ProcesosEnGPU4(){
	return GPU4.get_long();
	}	
Gestor::~Gestor(){
	
	}
int Gestor::ProcesosEnPila(){
	return pila.getLongitud();
	}
void Gestor::genera12Procesos(){
	if(pila.getLongitud()<48){
	for (int i=0;i<12;i++){
		Proceso* p=new Proceso();
		pila.insertar(p);
			}
		}
	}
void Gestor::muestraProcesos(){
	pila.mostrar();
	}
	void Gestor::borraProcesosPila(){
		pila.vaciar();
		}
void Gestor::muestraProcesosGPUs1y2(){
	cout<<"GPU1:"<<endl;
	GPU1.mostrar();
	cout<<endl;
	cout<<"GPU2:"<<endl;
	GPU2.mostrar();
	cout<<endl;
	}
void Gestor::muestraProcesosGPUs3y4(){
	cout<<"GPU3:"<<endl;
	GPU3.mostrar();
	cout<<endl;
	cout<<"GPU4:"<<endl;
	GPU4.mostrar();
	cout<<endl;
	}
void Gestor::borraProcesosColas(){
		GPU1.vaciar();
		GPU2.vaciar();
		GPU3.vaciar();
		GPU4.vaciar();
	}
void Gestor::insertar_colas(){
		while(!pila.es_vacia()){
				if(pila.cima()->get_tipo()){
					if(GPU1.get_long()<=GPU2.get_long()){
						GPU1.insertar_orden(pila.extraer());
						}
					else{
						GPU2.insertar_orden(pila.extraer());
						}	
					}
				else{
					if(GPU3.get_long()<=GPU4.get_long()){
						GPU3.insertar_orden(pila.extraer());
						}
					else{
						GPU4.insertar_orden(pila.extraer());
						}
					}	
			}
	}
