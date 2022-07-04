#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "parser.h"
#include "utn_inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int flagArchivo = 0;
	int flagGuardado = 0;
    char salir = 'N';
    char auxChar;
    int cantidadPasajeros;
    int proxId;
    controller_loadIdFromText("nextid.csv" ,&proxId);
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{

        switch(menu())
        {
           case 1:
			  if(flagArchivo==0)
			  {
				if(controller_loadFromText("data.csv",listaPasajeros)) //hecho
				{
                		printf("\n Se cargaron los datos de manera satisfactoria\n");
                		flagArchivo=1;
                		system("pause");
				}
				else
				{
						printf("\nNo se pudo cargar el archivo\n");
						system("pause");
				}
			  }
			  else
			  {
				  printf("No se puede cargar el archivo, ya se cargo antes\n");
				  system("pause");
			  }
			  break;
			case 2:
				 if (flagArchivo == 0)
				{
                	if(controller_loadFromBinary("data.bin",listaPasajeros))  //hecho
					{
                		printf("\n Se cargaron los datos de manera satisfactoria\n");
                		flagArchivo = 1;
                		system("pause");
					}
					else
					{
						printf("\nNo se pudo cargar el archivo\n");
						system("pause");
					}
				}
                else
                {
                	printf("No se puede cargar el archivo, ya se cargo antes\n");
                	system("pause");
                }
				break;
			case 3:
				if(controller_addPassenger(listaPasajeros,&proxId))
				{
					printf("Pasajero dado de alta con exito\n");
				}
				else
				{
					printf("No se pudo dar de alta al pasajero\n");
				}
				system("pause");
                break;
			case 4:
				cantidadPasajeros = ll_len(listaPasajeros);
				if(cantidadPasajeros == 0)
				{
					printf("No hay pasajeros cargados para dar de baja\n");
				}
				else
				{
					if(controller_editPassenger(listaPasajeros))
					{
						printf("\n Pasajero modificado con exito\n");
					}
					else
					{
						printf("\n Error al modificar pasajero, no se pudo realizar\n");
					}
				}
				system("pause");
                break;
			case 5:
				cantidadPasajeros = ll_len(listaPasajeros);
				if(cantidadPasajeros == 0)
				{
					printf("No hay pasajeros cargados para dar de baja\n");
				}
				else
				{
					if(controller_removePassenger(listaPasajeros))
					{
						printf("Pasajero dado de baja con exito\n");
					}
					else
					{
						printf("No se pudo realizar la baja del pasajero\n");
					}
				}
				system("pause");
				break;
			case 6:
				cantidadPasajeros = ll_len(listaPasajeros);
				if(cantidadPasajeros == 0)
					{
						printf("No hay pasajeros cargados para mostrar\n");
					}
					else
						{if(!controller_ListPassenger(listaPasajeros))
						{
							printf("No se pudo mostrar el listado de pasajeros\n");
						}
					}
				system("pause");
				break;
			case 7:
				cantidadPasajeros = ll_len(listaPasajeros);
				if(cantidadPasajeros == 0)
					{
						printf("No hay pasajeros cargados para mostrar\n");
					}
					else
					{
						if(!controller_sortPassenger(listaPasajeros))
						{
							printf("No se pudo realizar el ordenamiento de los pasajeros\n");
						}
					}
				system("pause");
                break;
			case 8: // guardar en data.csv modo texto
				if(controller_saveAsText("data.csv",listaPasajeros))
				{
					printf("Se guardo el archivo en modo texto correctamente\n");
					flagGuardado = 1;
					controller_saveIdAsText("nextid.csv" ,&proxId);
				}
				else
				{
					printf("Error al guardar el archivo en modo texto \n");
				}
				system("pause");
                break;
			case 9:  // guardar en data.bin modo binario
				if(controller_saveAsBinary("data.bin",listaPasajeros))
					{
						printf("Se guardo el archivo en modo binario correctamente\n");
						flagGuardado = 1;
						controller_saveIdAsText("nextid.csv" ,&proxId);
					}
					else
					{
						printf("Error al guardar el archivo en modo binario \n");
					}
				system("pause");
                break;
			case 10:
				if(flagGuardado == 0)
				{
					printf("\nNo se puede salir sin antes guardar la informacion en un archivo\n");
					system("pause");
				}
				else
				{
					printf("Esta seguro que desea salir? Ingrese s o n: ");
					fflush(stdin);
					scanf("%c",&auxChar);
					auxChar = tolower(auxChar);
					if(auxChar=='s')
					{
						salir='s';
					}
				}
                break;
			default:
				printf("Numero de opcion inexistente, elija opcion valida\n");
				system("pause");
				break;
        }
    }while(salir != 's');
    return 0;
}

