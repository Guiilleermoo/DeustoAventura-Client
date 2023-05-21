#include "Ciudad.h"
#include "string.h"

Ciudad::Ciudad()
{
	this->nombre = NULL;
	this->provincia = new Provincia();
}

Ciudad::Ciudad(char* nombre, Provincia* provincia)
{
	this->nombre = new char[strlen(nombre) + 1];
	this->nombre = nombre;
	this->provincia = provincia;
}

Ciudad::Ciudad(const Ciudad &c)
{
	this->nombre = new char[strlen(c.nombre) + 1];
	this->nombre = c.nombre;
	this->provincia = c.provincia;
}

Ciudad::~Ciudad()
{
	delete [] nombre, provincia;
}

