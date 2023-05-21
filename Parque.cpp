#include "Parque.h"

#include <iostream>
using namespace std;

Parque::Parque()
{
	this->nombre = NULL;
	this->horaInicio = 0;
	this->horaFin = 0;
	this->capacidad = 0;
	this->ciudad = new Ciudad();
	this->encargado = new Empleado();
	this->actividades = NULL;
}

Parque::Parque(char* nombre, int horaInicio, int horaFin, int capacidad, Ciudad* ciudad, Empleado* encargado, Actividad* actividades)
{
	this->nombre = nombre;
	this->horaInicio = horaInicio;
	this->horaFin = horaFin;
	this->capacidad = capacidad;
	this->ciudad = ciudad;
	this->encargado = encargado;
	this->actividades = actividades;
}

Parque::Parque(const Parque &p)
{
	this->nombre = p.nombre;
	this->horaInicio = p.horaInicio;
	this->horaFin = p.horaFin;
	this->capacidad = p.capacidad;
	this->ciudad = p.ciudad;
	this->encargado = p.encargado;
	this->actividades = p.actividades;
}

Parque::~Parque()
{
	delete [] nombre;
	delete [] ciudad;
	delete [] encargado;
}
