#include <iostream>
#include <iomanip>
#include <string> 
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
	~Proceso();
	
};