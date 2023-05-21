#include "Empleado.h"
#include "Persona.h"
#include "Parque.h"

#include <iostream>
using namespace std;
#include "string.h"
Empleado::Empleado() :Persona()
{
	this->estatus = NULL;
	this->cod_parque = 0;
}

Empleado::Empleado(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena, char* estatus, int cod_parque) :Persona(dni, nombre, apellido, telefono, correo, contrasena)
{
	this->estatus = new char[strlen(dni) + 1];
	this->estatus = estatus;
	this->cod_parque = cod_parque;
}

Empleado::Empleado(const Empleado &e) :Persona(e)
{
	this->estatus = new char[strlen(e.dni) + 1];
	this->estatus = e.estatus;
	this->cod_parque = e.cod_parque;
}
Empleado::~Empleado()
{

}

void Empleado::imprimir()
{

}
