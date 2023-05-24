#ifndef INTERFAZ_ACTIVIDAD_H_
#define INTERFAZ_ACTIVIDAD_H_

class Actividad
{
	private:
		int codigo;
		char* nombre;
		char* dificultad;
		int limitePerMin;
		int limitePerMax;
		int edadMin;

	public:
		Actividad();
		Actividad(int codigo, char* nombre, char* dificultad, int limitePerMin, int limitePerMax, int edadMin);
		Actividad(const Actividad &a);
		~Actividad();

		void imprimir();
};

#endif
