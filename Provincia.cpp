#include "Provincia.h"
#include "string.h"

Provincia::Provincia()
{
	this->nombre = NULL;
}

Provincia::Provincia(char* nombre)
{
	this->nombre = new char[strlen(nombre) + 1];
	this->nombre = nombre;
}

Provincia::Provincia(const Provincia &p)
{
	this->nombre = new char[strlen(p.nombre) + 1];
	this->nombre = p.nombre;
}

Provincia::~Provincia()
{
	delete [] nombre;
}
