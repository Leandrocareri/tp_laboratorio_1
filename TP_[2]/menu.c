#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "arrayPassenger.h"
#include "inputs.h"


int menu(){
	int opcion;
    system("cls");
    printf("     *** AEROLINEAS  - Sistema de pasajeros ***\n\n");
    printf("1- Alta Pasajero\n");
    printf("2- Modificar Pasajero\n");
    printf("3- Baja Pasajero\n");
    printf("4- Informar\n");
    printf("5- Alta forzada de pasajeros\n");
    printf("6- Salir\n\n");
    utn_getNumero(&opcion,"Ingrese opcion: ","Error en la opcion ingresada. \n",1,6,3);
    return opcion;
}


char confirmarSalida(){
	char confirma;
	printf("Desea confirmar la salida? s / n : ");
	fflush(stdin);
	scanf("%c", &confirma);
	while (confirma != 's' && confirma != 'n')
	{
		printf("Error, ingrese respuesta valida, desea confirmar la salida? s / n : ");
		fflush(stdin);
		scanf("%c", &confirma);
	}
	return confirma;
}


int menuModificarPasajero()
{
    int opcion;
    printf("\n\n *  Campos a modificar  * \n\n");
    printf("1_ Nombre\n");
    printf("2_ Apellido\n");
    printf("3_ Precio\n");
    printf("4_ Tipo de pasajero\n");
    printf("5_ Codigo de vuelo\n\n");
    printf("6_ Salir\n\n");
    utn_getNumero(&opcion,"Elija la opcion a modificar: ","Error en la opcion ingresada. \n",1,6,3);
    return opcion;
}



int menuInformar()
{
    int opcion;
    printf("Opciones a informar: \n");
    printf("1_ Listado de pasajeros por apellido y tipo\n");
    printf("2_ Total y promedio de los precios, y cuantos lo superan\n");
    printf("3_ Listado de pasajeros por codigo de vuelo y estados activo\n");
    printf("4_ Salir\n");
    utn_getNumero(&opcion,"Elija la opcion a informar: ","Error en la opcion ingresada. \n",1,4,3);
    return opcion;
}
