#ifndef INTERFAZ_PARQUE_H_
#define INTERFAZ_PARQUE_H_

#include "Ciudad.h"
#include "Empleado.h"
#include "Actividad.h"

class Parque
{
	private:
		char* nombre;
		int horaInicio;
		int horaFin;
		int capacidad;
		Ciudad* ciudad;
		Empleado* encargado;
		Actividad* actividades;

	public:
		Parque();
		Parque(char* nombre, int horaInicio, int horaFin, int capacidad, Ciudad* ciudad, Empleado* encargado, Actividad* actividades);
		Parque(const Parque &p);
		~Parque();

		void imprimir();
};

#endif
