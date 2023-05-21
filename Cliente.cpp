#include "Cliente.h"

#include <iostream>
using namespace std;

Cliente::Cliente() :Persona()
{
	this->ciudad = new Ciudad();
}

Cliente::Cliente(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena, Ciudad* ciudad) :Persona(dni, nombre, apellido, telefono, correo, contrasena)
{
	this->ciudad = ciudad;
}

Cliente::Cliente(const Cliente &c) :Persona(c)
{
	this->ciudad = c.ciudad;
}

Cliente::~Cliente()
{
	delete [] ciudad;
}

void Cliente::imprimir()
{
}

