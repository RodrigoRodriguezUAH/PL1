#include <iostream>
#include "Proceso.hpp"
using namespace std;

class NodoCola{
public:
	NodoCola(Proceso* p, NodoCola* sig=NULL);
	~NodoCola();
private:
	Proceso* proceso;
	NodoCola* siguiente;
	friend class Cola;
	};
typedef NodoCola* pnodoCola;
