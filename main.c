#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

char sendBuff[512], recvBuff[512];
SOCKET s;

void principal();
void inicioSesion();
void registrarse();
void menu();
void mostrarReservas(){
	strcpy(sendBuff, "VisualizarReservas");
			send(s, sendBuff, sizeof(sendBuff), 0);

			int num_linea = 1;

			recv(s, recvBuff, sizeof(recvBuff), 0);

			do {
				char fecha[30];
				int cantP, codA, codC;

				strcpy(fecha, (char*) recvBuff);
				recv(s, recvBuff, sizeof(recvBuff), 0);

				cantP = atoi(recvBuff);
				recv(s, recvBuff, sizeof(recvBuff), 0);
				codA = atoi(recvBuff);
				recv(s, recvBuff, sizeof(recvBuff), 0);
				codC = atoi(recvBuff);

				printf("Reseva %d -> Fecha: %s - Cantid Personas: %d - Cod Acitividad: %d - Cod Cliente: %d\n", num_linea, fecha, cantP, codA, codC);
				fflush(stdout);

				num_linea++;

				recv(s, recvBuff, sizeof(recvBuff), 0);

				if(strcmp(recvBuff, "FIN") == 0)
				{
					break;
				}

			} while(1);
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

		printf("Actividad %d -> Nombre: %s - dificultad: %s - MIN: %d - MAX: %d - EdadMin: %d\n", codigo, nombre, dificultad, limitePerMin, limitePerMax, edadMin);
		fflush(stdout);

		recv(s, recvBuff, sizeof(recvBuff), 0);

		if(strcmp(recvBuff, "FIN") == 0)
		{
			break;
		}

	} while(1);

	printf("\n");
}

void actividades()
{
	printf("ACTIVIDADES\n");
	printf("1. Visualizar todas\n");
	printf("2. Buscar por Ciudad\n");
	printf("3. Buscar por Nivel de dificultad\n");
	printf("0. Volver\n");
	printf("Elija su opcion:  ");
	fflush(stdout);
	int numero;
	scanf("%d", &numero);
	fflush(stdout);
	printf("\n");

	if(numero == 1)
	{
		mostrarActividades();
		actividades();
	} else if(numero == 2)
	{
		char ciudad[20];
	    printf("Introduzca la ciudad: ");
	    fflush(stdout);
	    scanf(" %s", ciudad);
		strcpy(sendBuff, "VisualizarActividadesPorCiudad");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, ciudad);
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

			printf("Actividad %d -> Nombre: %s - dificultad: %s - MIN: %d - MAX: %d - EdadMin: %d\n", codigo, nombre, dificultad, limitePerMin, limitePerMax, edadMin);
			fflush(stdout);


			recv(s, recvBuff, sizeof(recvBuff), 0);

			if(strcmp(recvBuff, "FIN") == 0)
			{
				break;
			}

		} while(1);

		printf("\n");
		actividades();
	} else if(numero == 3)
	{
		char dificultad[20];
	    printf("Introduzca la dificultad: ");
	    fflush(stdout);
	    scanf(" %s", dificultad);
		strcpy(sendBuff, "VisualizarActividadesPorDificultad");
		send(s, sendBuff, sizeof(sendBuff), 0);
		strcpy(sendBuff, dificultad);
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

			printf("Actividad %d -> Nombre: %s - dificultad: %s - MIN: %d - MAX: %d - EdadMin: %d\n", codigo, nombre, dificultad, limitePerMin, limitePerMax, edadMin);
			fflush(stdout);

			recv(s, recvBuff, sizeof(recvBuff), 0);

			if(strcmp(recvBuff, "FIN") == 0)
			{
				break;
			}

		} while(1);

		printf("\n");
		actividades();
	} else if(numero == 0)
	{
		principal();
	}
}
void reservas()
{
	printf("\nRESERVAS\n");
	printf("1. Visualizar mis reservas\n");
	printf("2. Hacer reservas\n");
	printf("3. Cancelar reservas\n");
	printf("0. Volver\n");
	printf("Elija su opcion:  ");
	fflush(stdout);
	int numero;
	scanf("%d", &numero);
	fflush(stdout);
	printf("\n");

	if(numero == 1)
	{

		mostrarReservas();
		printf("\n");
		reservas();
	} else if(numero == 2)
	{
		int codActividad;
		char fecha[30];
		int cantPersonas;

		mostrarActividades();
		printf("Introduce el codigo de actividad: ");
		fflush(stdout);
		scanf(" %d", &codActividad);
		fflush(stdout);
		printf("\n");
		printf("Introduce la fecha: ");
		fflush(stdout);
		scanf(" %s", fecha);
		fflush(stdout);
		printf("\n");
		printf("Introduce las cantidad de personas que asistirán: ");
		fflush(stdout);
		scanf(" %d", &cantPersonas);
		fflush(stdout);
		printf("\n");


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

		printf("Reserva realizada correctamente\n");
			fflush(stdout);
			reservas();


	} else if(numero == 3)
	{	mostrarReservas();
		int codActividad;
		char fecha[30];
		printf("BORRAR RESERVA\n");
		printf("Introduce el codigo de actividad: ");
		fflush(stdout);
		scanf(" %d", &codActividad);
		fflush(stdout);
		printf("\n");
		printf("Introduce la fecha: ");
		fflush(stdout);
		scanf(" %s", fecha);
		fflush(stdout);
		printf("\n");


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

		printf("Reserva borrada correctamente\n");
			fflush(stdout);
			reservas();

	} else if(numero == 0)
	{
		principal();
	}
}
void principal()
{
	printf("1. Ver Actividades\n");
	printf("2. Gestionar Reservas\n");
	printf("0. Volver\n");
	printf("Elija su opcion:  ");
	fflush(stdout);
	int numero;
	scanf("%d", &numero);
	fflush(stdout);

	if(numero == 1)
	{
		actividades();
	} else if(numero == 2)
	{
		reservas();
	} else if(numero == 0)
	{
		strcpy(sendBuff, "EXIT");
		send(s, sendBuff, sizeof(sendBuff), 0);
		exit(-1);
	}
}

void inicioSesion()
{
    char dni[10], contra[20];
    printf("\nINICIO DE SESION\n");
    printf("Introduzca el DNI: ");
    fflush(stdout);
    scanf(" %s", dni);
	printf("Introduzca la contraseña:  ");
	fflush(stdout);
	scanf(" %s", contra);

	strcpy(sendBuff, "ComprobarCliente");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, dni);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, contra);
	send(s, sendBuff, sizeof(sendBuff), 0);

	recv(s, recvBuff, sizeof(recvBuff), 0);

	if(strcmp(recvBuff, " Correcto") == 0)
	{
		printf("Inicio de sesion correcto!\n\n");
		fflush(stdout);
		principal();
	} else {
		printf("DNI/contrasena incorrecto\n\n");
		fflush(stdout);
		menu();
	}
}

void registrarse()
{
	char dni[10], nombre[20],apellido[20],correo[20],contra[20];
	int tlf, cod_ciu;


	printf("REGISTRO CLIENTE\n");
	printf("Introduce el DNI\n");
	fflush(stdout);
	scanf(" %s", dni);
	printf("Introduce el nombre: \n");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Introduce el apellido: \n");
	fflush(stdout);
	scanf(" %s", apellido);
	printf("Introduce el teléfono: \n");
	fflush(stdout);
	scanf(" %d", &tlf);
	printf("Introduce el correo: \n");
	fflush(stdout);
	scanf(" %s", correo);
	printf("Introduce la contrasena: \n");
	fflush(stdout);
	scanf(" %s", contra);

	//Mostrar las ciudades y que elija el usuario


	printf("Introduce la ciudad: \n");
	fflush(stdout);
	scanf(" %d", &cod_ciu);

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
	printf("Usuario creado correctamente!");
	menu();
}

void menu()
{
	printf("DEUTOAVENTURA\n");
	printf("1. Iniciar Sesion\n");
	printf("2, Registrarse\n");
	printf("0. Salir\n");
	printf("Elija su opcion:  ");
	fflush(stdout);
	int numero;
	scanf(" %d", &numero);
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
	}
}

int main()
{
	WSADATA wsaData;

	struct sockaddr_in server;


	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		fflush(stdout);
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		fflush(stdout);
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");
	fflush(stdout);

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Connection error: %d", WSAGetLastError());
		fflush(stdout);
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));
	fflush(stdout);

	//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)
	menu();

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
