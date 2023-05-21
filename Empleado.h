#ifndef INTERFAZ_EMPLEADO_H_
#define INTERFAZ_EMPLEADO_H_

#include "Persona.h"
#include "Parque.h"


class Empleado : public Persona
{
	private:
		char* estatus;
		Parque* parque;

	public:
		Empleado();
		Empleado(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena, char* estatus, Parque* parque);
		Empleado(const Empleado &e);
		virtual ~Empleado();

		virtual void imprimir();
};

#endif
