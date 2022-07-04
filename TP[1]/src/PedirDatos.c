/*
 * PedirDatos.c
 *
 *  Created on: 13 abr. 2022
 *      Author: leand
 */


#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTP1.h"


int ingresarKms()
{
	int kms;
	printf("Ingrese los kilometros del vuelo a realizar: ");
	scanf("%d", &kms);
	while (kms<1)
	{
		printf("Error, ingrese numero de kilometros valido del vuelo a realizar: ");
		scanf("%d", &kms);
	}
	system("pause");
	return kms;
}


float ingresarPrecioVueloAerolineas()
{
	float precio;
	printf("Ingrese el precio del vuelo por Aerolineas: \n");
	scanf("%f", &precio);
	while(precio<1)
	{
		printf("Error, ingrese el precio del vuelo valido: \n");
		scanf("%f", &precio);
	}
	return precio;
}

float ingresarPrecioVueloLatam()
{
	float precio;
	printf("Ingrese el precio del vuelo por Latam: \n");
	scanf("%f", &precio);
	while(precio<1)
	{
		printf("Error, ingrese el precio del vuelo valido: \n");
		scanf("%f", &precio);
	}
	return precio;
}
