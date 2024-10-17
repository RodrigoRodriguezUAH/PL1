#include "NodoCola.hpp"
NodoCola::NodoCola(Proceso* p, NodoCola* sig)
{
	proceso=p;
	siguiente=sig;
	}
NodoCola::~NodoCola(){
	}