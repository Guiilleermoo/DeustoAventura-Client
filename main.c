#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

void inicioSesion()
{
    char dni[10], contra[20];
    printf("INICIO DE SESION\n");
    printf("Introduzca el DNI: \n");
    fflush(stdout);
    scanf(" %s", dni);
	printf("Introduzca la contraseña:  \n");
	fflush(stdout);
	scanf(" %s", contra);
}

void registrarse()
{
	char dni[10], nombre[20],apellido[20],correo[20],contra[20];
	int tlf, cod_ciu;

	printf("Registrarse\n");
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

	printf("Usuario creado correctamente!");
}

void principal()
{
	printf("1. Ver Acitivdades");
	printf("2. Gestioanr Reservar");
	printf("0. Volver");
	printf("Elija su opcion:  ");
	fflush(stdout);
	printf("\n");
	int numero;
	scanf("%d", &numero);
	fflush(stdout);
}

void actividades()
{
	printf("1. Visualizar todas");
	printf("2. Buscar por Ciudad");
	printf("3. Buscar por Nivel de dificultad");
	printf("0. Volver");
	printf("Elija su opcion:  ");
	fflush(stdout);
	printf("\n");
	int numero;
	scanf("%d", &numero);
	fflush(stdout);
}

void menu()
{
	printf("DEUTOAVENTURA");
	printf("1. Iniciar Sesion");
	printf("2, Registrarse");
	printf("0. Salir");
	printf("Elija su opcion:  ");
	fflush(stdout);
	printf("\n");
	int numero;
	scanf("%d", &numero);
	fflush(stdout);

	if(numero == 1)
	{
		inicioSesion();
	} else if(numero == 2)
	{
		registrarse();
	} else if(numero == 0)
	{
		exit(-1);
	}
}

int main()
{
	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)
	menu();

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
