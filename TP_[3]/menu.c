#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "inputs.h"
#include <string.h>

/*
 * menu.c
 *
 *  Created on: 26 jun. 2022
 *      Author: leand
 */



int menu()
{
	int opcion;
    system("cls");
    printf("     *** AEROLINEAS  - Sistema de pasajeros ***\n\n");
    printf("1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
    printf("2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
    printf("3- Alta de  Pasajero\n");
    printf("4- Modificar datos de pasajero\n");
    printf("5- Baja de pasajero\n");
    printf("6- Listar pasajeros\n");
    printf("7- Ordenar pasajeros\n");
    printf("8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
    printf("9- Guardar los datos de los pasajeros en el archivo data.bin (modo binario)\n");
    printf("10- Salir\n\n");
    utn_getNumero(&opcion,"Ingrese opcion: ","Error en la opcion ingresada. \n",1,10,3);
	return opcion;
}



int menuOrdenar(){
    int opcion;
    system("cls");
    printf("* * *  MENU ORDENAR LISTADO * * *\n\n");
    printf("1. Ordenar por Id [Menor a Mayor]\n");
    printf("2. Ordenar por Id [Mayor a Menor]\n");
    printf("3. Ordenar por Nombre [A-Z]\n");
    printf("4. Ordenar por Nombre [Z-A]\n");
	printf("5. Ordenar por Apellido [A-Z]\n");
    printf("6. Ordenar por Apellido [Z-A]\n");
    printf("7. Ordenar por Precio [Menor a Mayor]\n");
    printf("8. Ordenar por Precio [Mayor a Menor]\n");
	printf("9. Ordenar por Tipo de pasajero [A-Z]\n");
    printf("10. Ordenar por Tipo de pasajero [Z-A]\n");
	printf("11. Ordenar por Codigo de vuelo [A-Z]\n");
    printf("12. Ordenar por Codigo de vuelo [Z-A]\n");
    printf("13. Ordenar por Estado de vuelo [A-Z]\n");
    printf("14. Ordenar por Estado de vuelo [Z-A]\n");
    printf("15. Salir\n");
    utn_getNumero(&opcion,"Ingrese opcion: ","Error en la opcion ingresada. \n",1,15,3);
    return opcion;
}



int menuModificar()
{
	int opcion;
	system("cls");
	printf("* * * MENU MODIFICAR PASAJERO * * *\n\n");
	printf("1- Modificar nombre\n");
	printf("2- Modificar apellido\n");
	printf("3- Modificar precio\n");
	printf("4- Modificar tipo de pasajero\n");
	printf("5- Modificar codigo de vuelo\n");
	printf("6- Modificar estado de vuelo\n");
	printf("7- Salir\n");
	fflush(stdin);
	utn_getNumero(&opcion,"Ingrese opcion: ","Error en la opcion ingresada. \n",1,7,3);
	return opcion;
}
