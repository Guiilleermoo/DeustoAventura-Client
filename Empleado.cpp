#include "Empleado.h"
#include "Persona.h"
#include "Parque.h"

#include <iostream>
using namespace std;

Empleado::Empleado() :Persona()
{
	this->estatus = NULL;
	this->parque = new Parque();
}

Empleado::Empleado(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena, char* estatus, Parque* parque) :Persona(dni, nombre, apellido, telefono, correo, contrasena)
{
	this->estatus = new char[strlen(dni) + 1];
	this->estatus = estatus;
	this->parque = parque;
}

Empleado::Empleado(const Empleado &e) :Persona(e)
{
	this->estatus = new char[strlen(e.dni) + 1];
	this->estatus = e.estatus;
	this->parque = e.parque;
}
Empleado::~Empleado()
{

}

void Empleado::imprimir()
{

}
