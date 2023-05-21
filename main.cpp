#include <iostream>
using namespace std;

void inicioSesion()
{
    char dni[10], contra[20];
    cout << "INICIO DE SESION" << endl;
    cout << "Introduzca el DNI: " << endl;
	cin >> dni;
	cout <<"Introduzca la contraseña:  " << endl;
	cin >> contra;
}

void registrarse()
{
	char dni[10], nombre[20],apellido[20],tlf[20],correo[20],contra[20];
	int cod_ciu;

	cout << "Registrarse" << endl;
	cout << "Introduce el DNI: " << endl;
	cin >> dni;
	cout <<"Introduce el nombre: " << endl;
	cin >> nombre;
	cout << "Introduce el apellido: " << endl;
	cin >> apellido;
	cout << "Introduce el teléfono: " << endl;
	cin >> tlf;
	cout << "Introduce el correo: " << endl;
	cin >> contra;
	cout << "Introduce la contrasena: " << endl;
	cin >> contra;

	//Mostrar las ciudades y que elija el usuario

	cout << "Usuario creado correctamente!";
}

void principal()
{
	int numero;
	cout << "1. Ver Acitivdades" << endl;
	cout << "2. Gestioanr Reservar" << endl;
	cout << "0. Volver" << endl;
	cin >> numero;
}

void actividades()
{
	int numero;
	cout << "1. Visualizar todas" << endl;
	cout << "2. Buscar por Ciudad" << endl;
	cout << "3. Buscar por Nivel de dificultad" << endl;
	cout << "0. Volver"<<endl;
	cin >> numero;
}

int main()
{
	int numero;
	cout << "DEUTOAVENTURA" << endl;
	cout << "1. Iniciar Sesion" << endl;
	cout << "2, Registrarse" << endl;
	cout << "0. Salir" << endl;
	cin >> numero;

	if(numero == 1)
	{
		inicioSesion();
	} else if(numero == 2)
	{
		registrarse();
	} else if(numero == 0)
	{
		return 0;
	}

	return 0;
}
