/*
 * Persona.h
 *
 *  Created on: 20 may 2023
 *      Author: Usuario
 */

#ifndef INTERFAZ_PERSONA_H_
#define INTERFAZ_PERSONA_H_

class Persona
{
	protected:
		char* dni;
		char* nombre;
		char* apellido;
		int telefono;
		char* correo;
		char* contrasena;

	public:
		Persona();
		Persona(char* dni, char* nombre, char* apellido, int telefono, char* correo, char* contrasena);
		Persona(const Persona &p);
		virtual ~Persona();

		virtual void imprimir();
};

#endif /* INTERFAZ_PERSONA_H_ */
