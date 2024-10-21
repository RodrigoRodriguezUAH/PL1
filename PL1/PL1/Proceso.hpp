#include <iostream>
#include <iomanip>
#include <string> 
#ifndef PROCESO_HPP
#define PROCESO_HPP
using namespace std;
class Proceso{
private:
	int PID;
	string nombre;
	bool estado;
	bool tipo;
	int prioridad;
public:
	Proceso();
	string generar_nombre ();
	void set_prioridad(int prioridad);
	int get_prioridad();
	void mostrar_proceso();
	int generar_PID();
	bool generar_bool();
	int generar_prioridad();
	void mostrar_proceso_cola();
	bool get_tipo();
	~Proceso();
	
};
#endif