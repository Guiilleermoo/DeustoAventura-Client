#ifndef INTERFAZ_CIUDAD_H_
#define INTERFAZ_CIUDAD_H_

#include "Provincia.h"

class Ciudad
{
	private:
		char* nombre;
		Provincia* provincia;

	public:
		Ciudad();
		Ciudad(char* nombre, Provincia* provincia);
		Ciudad(const Ciudad &c);
		~Ciudad();
};

#endif
