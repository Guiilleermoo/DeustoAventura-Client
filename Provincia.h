#ifndef INTERFAZ_PROVINCIA_H_
#define INTERFAZ_PROVINCIA_H_

class Provincia
{
	private:
		char * nombre;

	public:
		Provincia();
		Provincia(char* nombre);
		Provincia(const Provincia &p);
		~Provincia();
};

#endif
