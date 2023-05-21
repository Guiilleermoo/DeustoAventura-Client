#ifndef INTERFAZ_CLIENTE_H_
#define INTERFAZ_CLIENTE_H_

#include "Persona.h"
#include "Ciudad.h"

class Cliente :public Persona
{
	private:
		Ciudad* ciudad;

	public:
		Cliente();
		Cliente(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena, Ciudad* ciudad);
		Cliente(const Cliente &c);
		virtual ~Cliente();

		virtual void imprimir();
};

#endif
