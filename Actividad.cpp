#include "Actividad.h"

#include <iostream>
using namespace std;
#include "string.h"
Actividad::Actividad()
{
	this->codigo = codigo;
	this->nombre = NULL;
	this->dificultad = NULL;
	this->limitePerMin = 0;
	this->limitePerMax = 0;
	this->edadMin = 0;
}

Actividad::Actividad(int codigo, char* nombre, char* dificultad, int limitePerMin, int limitePerMax, int edadMin)
{
	this->codigo = codigo;
	this->nombre = new char[strlen(nombre) + 1];
	this->nombre = nombre;
	this->dificultad = new char[strlen(dificultad) + 1];
	this->dificultad = dificultad;
	this->limitePerMin = limitePerMin;
	this->limitePerMax = limitePerMax;
	this->edadMin = edadMin;
}

Actividad::Actividad(const Actividad &a)
{
	this->codigo = a.codigo;
	this->nombre = new char[strlen(a.nombre) + 1];
	this->nombre = a.nombre;
	this->dificultad = new char[strlen(a.dificultad) + 1];
	this->dificultad = a.dificultad;
	this->limitePerMin = a.limitePerMin;
	this->limitePerMax = a.limitePerMax;
	this->edadMin = a.edadMin;
}

Actividad::~Actividad()
{
	delete [] nombre;
	delete [] dificultad;
}

void Actividad::imprimir()
{
	cout << codigo <<" Nombre de actividad: " << nombre << endl;
	cout << "Dificultad: " << dificultad << endl;
	cout << "Minimo de personas: " << limitePerMin << "		" << " Maximo de personas: " << limitePerMax << "	" << " Edad minima: " << edadMin << endl;
}
