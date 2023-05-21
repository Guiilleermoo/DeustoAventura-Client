#include "Persona.h"

#include <iostream>
using namespace std;

Persona::Persona()
{
	this->dni = NULL;
	this->nombre = NULL;
	this->apellido = NULL;
	this->telefono = 0;
	this->correo = NULL;
	this->contrasena = NULL;
}

Persona::Persona(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena)
{
	this->dni = new char[strlen(dni)] + 1;
	this->dni = dni;
	this->dni = new char[strlen(nombre)] + 1;
	this->nombre = nombre;
	this->dni = new char[strlen(apellido)] + 1;
	this->apellido = apellido;
	this->telefono = telefono;
	this->dni = new char[strlen(correo)] + 1;
	this->correo = correo;
	this->dni = new char[strlen(contrasena)] + 1;
	this->contrasena = contrasena;
}

Persona::Persona(const Persona &p)
{
	this->dni = new char[strlen(p.dni)] + 1;
	this->dni = p.dni;
	this->dni = new char[strlen(p.nombre)] + 1;
	this->nombre = p.nombre;
	this->dni = new char[strlen(p.apellido)] + 1;
	this->apellido = p.apellido;
	this->telefono = p.telefono;
	this->dni = new char[strlen(p.correo)] + 1;
	this->correo = p.correo;
	this->dni = new char[strlen(p.contrasena)] + 1;
	this->contrasena = p.contrasena;
}
Persona::~Persona()
{
	delete [] dni, nombre, apellido, correo, contrasena;
}

void Persona::imprimir()
{

}
