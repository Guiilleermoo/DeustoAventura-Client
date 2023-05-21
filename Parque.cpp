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
	this->cod_empleado = 0;
	this->actividades = NULL;
}

Parque::Parque(char* nombre, int horaInicio, int horaFin, int capacidad, Ciudad* ciudad, int cod_empleado, Actividad* actividades)
{
	this->nombre = nombre;
	this->horaInicio = horaInicio;
	this->horaFin = horaFin;
	this->capacidad = capacidad;
	this->ciudad = ciudad;
	this->cod_empleado = cod_empleado;
	this->actividades = actividades;
}

Parque::Parque(const Parque &p)
{
	this->nombre = p.nombre;
	this->horaInicio = p.horaInicio;
	this->horaFin = p.horaFin;
	this->capacidad = p.capacidad;
	this->ciudad = p.ciudad;
	this->cod_empleado = p.cod_empleado;
	this->actividades = p.actividades;
}

Parque::~Parque()
{
	delete [] nombre;
	delete [] ciudad;
}
