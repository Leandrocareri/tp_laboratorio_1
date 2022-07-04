/*
 ============================================================================
 Name        : Tp1.c
 Author      : Careri, Leandro
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico n 1, Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTP1.h"

int main(void) {
	setbuf(stdout,NULL);

	char respuestaSalida='n';
	int x=0; //Cantidad de km de vuelo
	float y=0; //Precio de vuelo Aerolineas
	float z=0; //Precio de vuelo Latam;
	float costoDebitoAerolineas;
	float costoDebitoLatam;
	float costoCreditoAerolineas;
	float costoCreditoLatam;
	float costoBTCAerolineas;
	float costoBTCLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaPrecio;
	int flagVueloIngresado=0;
	int flagKmsIngresado=0;
	int flagCalculos=0;


	do {
		switch (menu(x,y,z))
		{
		case 1:
			x=ingresarKms();
			flagKmsIngresado=1;
			break;
		case 2:
			y=ingresarPrecioVueloAerolineas();
			z=ingresarPrecioVueloLatam();
			flagVueloIngresado=1;
			system("pause");
			break;
		case 3:
			if(flagVueloIngresado==0 || flagKmsIngresado==0)
			{
				printf("Error, debe ingresar antes el precio del vuelo y los kms del mismo antes de hacer los calculos\n");
				system("pause");
			}
			else
			{
			//Aerolineas
			costoDebitoAerolineas= calcularDebito(y);
			costoCreditoAerolineas= calcularCredito(y);
			costoBTCAerolineas= calcularBTC(y);
			precioUnitarioAerolineas=calcularUnitario(y,x);
			//Latam
			costoDebitoLatam= calcularDebito(z);
			costoCreditoLatam= calcularCredito(z);
			costoBTCLatam= calcularBTC(z);
			precioUnitarioLatam=calcularUnitario(z,x);
			diferenciaPrecio=calcularDiferenciaPrecio(z,y);
			printf("Costos ya calculados\n");
			flagCalculos=1;
			system("pause");
			}
			break;
		case 4:
			if(flagCalculos==0)
			{
				printf("No se han realizados los calculos para mostrar los resultados\n");
				system("pause");
			}
			else
			{
			//Aerolineas
			mostrarCalculosAerolineas(x,y,costoDebitoAerolineas,costoCreditoAerolineas,costoBTCAerolineas,precioUnitarioAerolineas);
			//Latam
			mostrarCalculosLatam(z,costoDebitoLatam,costoCreditoLatam,costoBTCLatam,precioUnitarioLatam,diferenciaPrecio);
			system("pause");
			}
			break;

		case 5:
			x=7090;
			y=162965;
			z=159339;
			system("cls");
			//Aerolineas
			costoDebitoAerolineas= calcularDebito(y);
			costoCreditoAerolineas= calcularCredito(y);
			costoBTCAerolineas= calcularBTC(y);
			precioUnitarioAerolineas=calcularUnitario(y,x);
			//Latam
			costoDebitoLatam= calcularDebito(z);
			costoCreditoLatam= calcularCredito(z);
			costoBTCLatam= calcularBTC(z);
			precioUnitarioLatam=calcularUnitario(z,x);
			diferenciaPrecio=calcularDiferenciaPrecio(z,y);
			//Aerolineas
			mostrarCalculosAerolineas(x,y,costoDebitoAerolineas,costoCreditoAerolineas,costoBTCAerolineas,precioUnitarioAerolineas);
			//Latam
			mostrarCalculosLatam(z,costoDebitoLatam,costoCreditoLatam,costoBTCLatam,precioUnitarioLatam,diferenciaPrecio);
			system("pause");
			x=0;// Elimino datos de carga forzada
			y=0;
			z=0;
			break;
		case 6:
			respuestaSalida=confirmarSalida();
			break;}
		}
	while (respuestaSalida !='s');


	return EXIT_SUCCESS;
}


