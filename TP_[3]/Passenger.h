/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[20];
	char apellido[20];
	int precio;
	char codigoVuelo[8];
	char tipoPasajero[20];
	char estadoVuelo[12];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_SetIdTxt(Passenger* this, char* id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,int precio);
int Passenger_getPrecio(Passenger* this,int* precio);
int Passenger_SetPrecioTxt(Passenger* this, char* precio);


int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

void mostrarPasajero(Passenger* pass);
int passenger_getNextId(LinkedList* pArrayListPassenger);

//int searchPassenger(LinkedList* pArrayListPassenger, int* id_Get, int* id_Index, char* msgMenu, char* msgGet, char* msgErrorID);
int passenger_findPassengerById(LinkedList* pArrayListPassenger, int id);


#endif /* PASSENGER_H_ */
