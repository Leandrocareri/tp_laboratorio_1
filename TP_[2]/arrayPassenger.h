#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty; // 1 vacio, 0 cargado
}ePassenger;

#endif // ARRAYPASSENGER_H_INCLUDED

int initPassengers(ePassenger lista[], int tam);
int buscarLibre(ePassenger lista[], int tam, int* pIndice);
int cargarPasajero(ePassenger lista[], int tam, int* pId);
int addPassenger(ePassenger* lista, int tam, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);
void mostrarPasajero(ePassenger p);
int mostrarPasajeros(ePassenger lista[], int tam);
int findPassengerById(ePassenger lista[], int len,int id);
int removePassenger(ePassenger lista[], int tam);
int modificarPasajero (ePassenger lista[], int tam);
int informarPromedio(ePassenger lista[], int tam);
int sortPassengers(ePassenger lista[], int tam);
int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pId);
int sortPassengersByCode(ePassenger lista[], int tam);


