/*
 * FuncionesTP1.c
 *
 *  Created on: 10 abr. 2022
 *      Author: leand
 */


#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTP1.h"



float calcularDebito(float a)
{
	float multiplicadorDescuento=0.9;
	float resultado;
	resultado= a*multiplicadorDescuento;
	return resultado;
}

float calcularCredito(float a)
{
	float multiplicadorRecargo=1.25;
	float resultado;
	resultado= a*multiplicadorRecargo;
	return resultado;
}

float calcularBTC(float a)
{
	float precioBTC=4606954.55;
	float resultado;
	resultado= a/precioBTC;
	return resultado;
}

float calcularUnitario(float a, int b) // a precio, b km
{
	float resultado;
	resultado=(float) a/b;
	return resultado;
}

float calcularDiferenciaPrecio(float a, float b) // a Latam, b Aerolineas
{
	float resultado;
	resultado=a-b;
	return resultado;
}

char confirmarSalida()
{
	char confirma;
	printf("Desea confirmar la salida? s / n :");
	fflush(stdin);
	scanf("%c", &confirma);
	while (confirma != 's'&& confirma != 'n')
	{
		printf("Error, ingrese respuesta valida, desea confirmar la salida? s / n :");
		fflush(stdin);
		scanf("%c", &confirma);
	}
	return confirma;
}
