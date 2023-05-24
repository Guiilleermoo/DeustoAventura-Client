#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000
#include "Reserva.h"
#include "Actividad.h"
#include "Ciudad.h"
char sendBuff[512], recvBuff[512];
SOCKET s;
#include <iostream>
using namespace std;
void principal();
void inicioSesion();
void registrarse();
void menu();
void reservas();

void mostrarReservas()
{
	strcpy(sendBuff, "VisualizarReservas");
	send(s, sendBuff, sizeof(sendBuff), 0);

	int num_linea = 1;

	recv(s, recvBuff, sizeof(recvBuff), 0);

	while(1)
	{
		char fecha[30];
		int cantP, codA, codC;

		strcpy(fecha, (char*) recvBuff);
		if(strcmp(recvBuff, "TAM0") == 0)
		{
			cout<<"No hay reservas"<<endl;

			reservas();
			break;
		}
		recv(s, recvBuff, sizeof(recvBuff), 0);

		cantP = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		codA = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		codC = atoi(recvBuff);
		Reserva r(codC, codA, fecha, cantP);
		r.imprimir();

		fflush(stdout);

		num_linea++;

		recv(s, recvBuff, sizeof(recvBuff), 0);

		if(strcmp(recvBuff, "FIN") == 0)
		{
			break;
		}
	}
}

void mostrarCiudades()
{
	strcpy(sendBuff, "VisualizarCiudades");
	send(s, sendBuff, sizeof(sendBuff), 0);


	recv(s, recvBuff, sizeof(recvBuff), 0);

	do {
		char nombre[30];
		int codigo;

		codigo = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		strcpy(nombre, recvBuff);

		Ciudad c(codigo, nombre);
		c.imprimir();


		fflush(stdout);

		recv(s, recvBuff, sizeof(recvBuff), 0);
		if(strcmp(recvBuff, "TAM0") == 0){
			cout<<"No hay reservas.";

				break;
				}
		if(strcmp(recvBuff, "FIN") == 0)
		{
			break;
		}

	} while(1);

	cout<<endl;
}

void mostrarActividades()
{
	strcpy(sendBuff, "VisualizarActividades");
	send(s, sendBuff, sizeof(sendBuff), 0);


	recv(s, recvBuff, sizeof(recvBuff), 0);

	do {
		char nombre[30], dificultad[10];
		int codigo, limitePerMin, limitePerMax, edadMin;

		codigo = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		strcpy(nombre, (char*) recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		strcpy(dificultad, (char*) recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		limitePerMin = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		limitePerMax = atoi(recvBuff);
		recv(s, recvBuff, sizeof(recvBuff), 0);
		edadMin = atoi(recvBuff);

		Actividad a(nombre,dificultad,limitePerMin,limitePerMax,edadMin);
		a.imprimir();


		fflush(stdout);

		recv(s, recvBuff, sizeof(recvBuff), 0);
		if(strcmp(recvBuff, "TAM0") == 0){
			cout<<"No hay reservas.";

				break;
				}
		if(strcmp(recvBuff, "FIN") == 0)
		{
			break;
		}

	} while(1);

	cout<<endl;
}

void actividades()
{
	cout<<endl<<"ACTIVIDADES"<<endl;
	cout<<"1. Visualizar todas"<<endl;
	cout<<"2. Buscar por Ciudad"<<endl;
	cout<<"3. Buscar por Nivel de dificultad"<<endl;
	cout<<"0. Volver"<<endl;
	cout<<"Elija su opcion:  ";

	fflush(stdout);
	int numero;
	cin>>numero;

	fflush(stdout);
	cout<<endl;

	if(numero == 1)
	{
		mostrarActividades();
		actividades();
	} else if(numero == 2)
	{
		char ciudad[20];
		cout<<"Introduzca la ciudad: ";

	    fflush(stdout);
	    scanf(" %s", ciudad);
		strcpy(sendBuff, "VisualizarActividadesPorCiudad");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, ciudad);
		send(s, sendBuff, sizeof(sendBuff), 0);

		recv(s, recvBuff, sizeof(recvBuff), 0);

		while(1) {
			char nombre[30], dificultad[10];
			int codigo, limitePerMin, limitePerMax, edadMin;
			if(strcmp(recvBuff, "TAM0") == 0){
				cout<<endl<<"No hay actividades en esta ciudad.";
					fflush(stdout);
					break;
				}
			codigo = atoi(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);



			strcpy(nombre, (char*) recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			strcpy(dificultad, (char*) recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			limitePerMin = atoi(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			limitePerMax = atoi(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			edadMin = atoi(recvBuff);
			Actividad a(nombre,dificultad,limitePerMin,limitePerMax,edadMin);
			a.imprimir();
			fflush(stdout);


			recv(s, recvBuff, sizeof(recvBuff), 0);

			if(strcmp(recvBuff, "FIN") == 0)
			{
				break;
			}
		}
		cout<<endl;

		actividades();
	} else if(numero == 3)
	{
		char dificultad[20];
		cout<<"Introduzca la dificultad: ";

	    fflush(stdout);
	    cin>>dificultad;

		strcpy(sendBuff, "VisualizarActividadesPorDificultad");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, dificultad);
		send(s, sendBuff, sizeof(sendBuff), 0);

		recv(s, recvBuff, sizeof(recvBuff), 0);

		do {
			char nombre[30], dificultad[10];
			int codigo, limitePerMin, limitePerMax, edadMin;
			if(strcmp(recvBuff, "TAM0") == 0){
				cout<<"No hay actividades con esta dificultad.";
						break;
									}
			codigo = atoi(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);


			strcpy(nombre, (char*) recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			strcpy(dificultad, (char*) recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			limitePerMin = atoi(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			limitePerMax = atoi(recvBuff);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			edadMin = atoi(recvBuff);
			Actividad a(nombre,dificultad,limitePerMin,limitePerMax,edadMin);
			a.imprimir();

			fflush(stdout);

			recv(s, recvBuff, sizeof(recvBuff), 0);

			if(strcmp(recvBuff, "FIN") == 0)
			{
				break;
			}

		} while(1);
		cout<<endl;

		actividades();
	} else if(numero == 0)
	{
		principal();
	}else{
		actividades();
	}
}
void reservas()
{
	cout<<endl<<"RESERVAS"<<endl;
	cout<<"1. Visualizar mis reserva"<<endl;
	cout<<"2. Hacer reservas"<<endl;
	cout<<"3. Cancelar reservas"<<endl;
	cout<<"0. Volver";
	cout<<"Elija su opcion: ";

	fflush(stdout);
	int numero;
	cin>>numero;
	fflush(stdout);
	cout<<endl;

	if(numero == 1)
	{

		mostrarReservas();
		cout<<endl;
		reservas();
	} else if(numero == 2)
	{
		int codActividad;
		char fecha[30];
		int cantPersonas;

		mostrarActividades();
		cout<<"Introduce el codigo de actividad: ";

		fflush(stdout);
		cin>>codActividad;
		fflush(stdout);
		cout<<endl;
		cout<<"Introduce la fecha:";

		fflush(stdout);
		cin>>fecha;
		fflush(stdout);
		cout<<endl;
		cout<<"Introduce las cantidad de personas que asistirán: ";

		fflush(stdout);
		cin>>cantPersonas;
		fflush(stdout);
		cout<<endl;


		strcpy(sendBuff, "R8");
		send(s, sendBuff, sizeof(sendBuff), 0);
		sprintf(sendBuff, "%d", codActividad);
		fflush(stdout);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, fecha);
		send(s, sendBuff, sizeof(sendBuff), 0);
		sprintf(sendBuff, "%d", cantPersonas);
		send(s, sendBuff, sizeof(sendBuff), 0);

		recv(s, recvBuff, sizeof(recvBuff), 0);
		do{
		if(strcmp(recvBuff, " R")){
			break;
		}
		}while(1);
		cout<<"Reserva realizada correctamente"<<endl;

			fflush(stdout);
			reservas();


	} else if(numero == 3)
	{	mostrarReservas();
		int codActividad;
		char fecha[30];
		cout<<endl<<"BORRAR RESERVA"<<endl;
		cout<<"Introduce el codigo de actividad: ";

		fflush(stdout);
		cin>>codActividad;

		fflush(stdout);
		cout<<endl;
		cout<<"Introduce la fecha: ";

		fflush(stdout);
		cin>>fecha;

		fflush(stdout);
		cout<<endl;


		strcpy(sendBuff, "RD");
		send(s, sendBuff, sizeof(sendBuff), 0);
		sprintf(sendBuff, "%d", codActividad);
		fflush(stdout);
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, fecha);
		send(s, sendBuff, sizeof(sendBuff), 0);


		recv(s, recvBuff, sizeof(recvBuff), 0);
		do{
		if(strcmp(recvBuff, " RF")){
			break;
		}
		}while(1);
		cout<< "Reserva borrada correctamente"<<endl;

			fflush(stdout);
			reservas();

	} else if(numero == 0)
	{
		principal();
	}else{
		reservas();
	}
}
void principal()
{
	cout<<endl<<"MENU CLIENTE"<<endl;
	cout<<"1. Ver Actividades"<<endl;
	cout<<"2. Gestionar Reservas"<<endl;
	cout<<"0. Volver"<<endl;
	cout<<"Elija su opcion: ";


	fflush(stdout);
	int numero;
	cin>>numero;

	fflush(stdout);

	if(numero == 1)
	{
		actividades();
	} else if(numero == 2)
	{
		reservas();
	} else if(numero == 0)
	{
		menu();
	}else{
		principal();
	}
}

void inicioSesion()
{
    char dni[10], contra[20];
    cout<<endl<<"INICIO DE SESION"<<endl;
    cout<<"Introduzca el DNI: ";

    fflush(stdout);
    cin>>dni;
    cout<<"Introduzca la contraseña: ";

	fflush(stdout);
	cin>>contra;

	strcpy(sendBuff, "ComprobarCliente");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dni);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contra);
	send(s, sendBuff, sizeof(sendBuff), 0);

	recv(s, recvBuff, sizeof(recvBuff), 0);

	if(strcmp(recvBuff, " Correcto") == 0)
	{
		cout<<"Inicio de sesion correcto!"<<endl<<endl;

		fflush(stdout);
		principal();
	} else {
		cout<<"DNI/contrasena incorrecto"<<endl<<endl;

		fflush(stdout);
		menu();
	}
}

void registrarse()
{
	char dni[10], nombre[20],apellido[20],correo[20],contra[20];
	int tlf, cod_ciu;

	cout << endl;
	cout<<"REGISTRO CLIENTE"<<endl;
	cout<<"Introduce el DNI: "<<endl;

	fflush(stdout);
	cin>>dni;
	cout<<"Introduce el nombre: "<<endl;

	fflush(stdout);
	cin>>nombre;
	cout<<"Introduce el apellido: "<<endl;

	fflush(stdout);
	cin>>apellido;
	cout<<"Introduce el teléfono: "<<endl;

	fflush(stdout);
	cin>>tlf;
	cout<<"Introduce el correo: "<<endl;

	fflush(stdout);
	cin>>correo;
	cout<<"Introduce la contrasena: "<<endl;

	fflush(stdout);
	cin>>contra;


	//Mostrar las ciudades y que elija el usuario
	mostrarCiudades();

	cout << "Introduce el codigo de tu ciudad: " << endl;

	fflush(stdout);
	cin>>cod_ciu;

	strcpy(sendBuff, "REG");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dni);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, nombre);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, apellido);
	send(s, sendBuff, sizeof(sendBuff), 0);
	sprintf(sendBuff, "%d", tlf);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, correo);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contra);
	send(s, sendBuff, sizeof(sendBuff), 0);
	sprintf(sendBuff, "%d", cod_ciu);
	send(s, sendBuff, sizeof(sendBuff), 0);



	recv(s, recvBuff, sizeof(recvBuff), 0);
			do{
			if(strcmp(recvBuff, " REGE")){
				break;
			}
			}while(1);
	cout<<"Usuario creado correctamente!";

	menu();
}

void menu()
{
	cout<<endl<<"DEUSTOAVENTURA"<<endl;
	cout<<"1. Iniciar Sesion"<<endl;
	cout<<"2. Registrarse"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Elija su opcion:  ";

	fflush(stdout);

	int numero;
	cin>>numero;
	fflush(stdout);

	if(numero == 1)
	{
		inicioSesion();
	} else if(numero == 2)
	{
		registrarse();
	} else if(numero == 0)
	{
		strcpy(sendBuff, "EXIT");
		send(s, sendBuff, sizeof(sendBuff), 0);
		exit(-1);

	}else{

		menu();
	}
}

int main()
{
	WSADATA wsaData;

	struct sockaddr_in server;

	cout<<endl<<"Initialising Winsock..."<<endl;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout<<"Failed. Error Code :"<<WSAGetLastError();

		fflush(stdout);
		return -1;
	}
	cout<<"Initialised."<<endl;


	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		cout<<"Could not create socket :"<<WSAGetLastError();

		fflush(stdout);
		WSACleanup();
		return -1;
	}
	cout<<"Socket created."<<endl;

	fflush(stdout);

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		cout<<"Connection error: "<<WSAGetLastError();

		fflush(stdout);
		closesocket(s);
		WSACleanup();
		return -1;
	}
	cout<<"Connection stablished with: "<<inet_ntoa(server.sin_addr)<<" "<<ntohs(server.sin_port)<<endl;

	fflush(stdout);

	//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)
	menu();

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
