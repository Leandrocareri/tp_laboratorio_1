/*
 * MostrarDatos.c
 *
 *  Created on: 13 abr. 2022
 *      Author: leand
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTP1.h"


void mostrarCalculosAerolineas (int z, float a, float b, float c, float d, float e)
{
	system("cls");
	printf("Kms Ingresados: %d kms\n\n",z);
	printf("Precio Aerolineas: $ %.2f\n",a);
	printf("a) Precio con tarjeta de debito: $ %.2f\n",b);
	printf("b) Precio con tarjeta de credito: $ %.2f\n",c);
	printf("c) Precio pagando con bitcoin: %.2f\n",d);
	printf("d) Mostrar precio unitario: $ %.2f\n\n", e);
}


void mostrarCalculosLatam (float a, float b, float c, float d, float e, float f)
{
	printf("Precio Latam: $ %.2f\n",a);
	printf("a) Precio con tarjeta de debito: $ %.2f\n",b);
	printf("b) Precio con tarjeta de credito: $ %.2f\n",c);
	printf("c) Precio pagando con bitcoin: %.2f\n",d);
	printf("d) Mostrar precio unitario: $ %.2f\n\n", e);
	printf("La diferencia de precio es: $ %.2f\n\n",f);
}
