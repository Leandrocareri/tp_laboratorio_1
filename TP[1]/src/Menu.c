/*
 * Menus.c
 *
 *  Created on: 13 abr. 2022
 *      Author: leand
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTP1.h"


int menu(int k,float a, float l)
{
	int opcion;


	system("cls");
	printf("/////  Menu de opciones  /////\n\n");
	printf("1_ Ingresar kilometros (km ingresado: %d)\n",k);
	printf("2_ Ingresar precio de vuelos (Aerolineas $ %.2f, Latam $ %.2f)\n",a,l);
	printf("3_ Calcular todos los costos\n");
	printf("4_ Informar resultados\n");
	printf("5_ Carga forzada de datos\n");
	printf("6_ Salir\n\n");
	printf("Opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

