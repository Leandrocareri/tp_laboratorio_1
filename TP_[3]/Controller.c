#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "inputs.h"
#include <ctype.h>
#include "sorts.h"
#include "menu.h"
#include <string.h>
#include "utn_inputs.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	FILE* f;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL)
		{
			parser_PassengerFromText(f,pArrayListPassenger);
			fclose(f);
			todoOk = 1;
		}
	}
	return todoOk;
}

int controller_loadIdFromText(char* path , int* nextId)
{
	int todoOk=0;
	FILE* f;
	if(path != NULL && nextId != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL)
		{
			parser_nextId(f,nextId);
			fclose(f);
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
   int todoOk = 0;
   FILE* f = NULL;
   if(path != NULL && pArrayListPassenger != NULL)
   {
	   f = fopen(path,"rb");
	   if(f != NULL)
	   {
		   parser_PassengerFromBinary(f, pArrayListPassenger);
		   fclose(f);
		   todoOk=1;
	   }
   }
	return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextId)
{
    int todoOk=0;
    char nombre[20];
    char apellido[20];
    char codigoVuelo[8];
    char tipoPasajero[20];
    char estadoVuelo[12];
    int precio;
    int id;
    Passenger* auxPass;

    auxPass = Passenger_new();

    system("cls");
    printf(" * * *   Alta de pasajero * * *\n\n");

    if(pArrayListPassenger != NULL && auxPass != NULL)
    {
    	id = *nextId;
    	if(
		((utn_getNombre(nombre,20,"Ingrese nombre del pasajero: ","No se ingreso un nombre correcto. ",3))==0) &&
		((utn_getNombre(apellido,20,"Ingrese apellido del pasajero: ","No se ingreso un apellido correcto. ",3))==0) &&
		(utn_getNumero(&precio,"Ingrese precio: ","Error\n",1,10000000,3)==0) &&
		utn_getAlfanumerico("\nIngrese nuevo codigo de vuelo: ","\nError",1,8,3, codigoVuelo) &&
		((utn_getNombre(tipoPasajero,20,"Ingrese tipo de pasajero: ","No se ingreso un tipo correcto. ",3))==0) &&
		((utn_getNombre(estadoVuelo,12,"Ingrese estado del vuelo: ","No se ingreso un estado correcto. ",3))==0))
		{
		Passenger_setId(auxPass,id);
		Passenger_setNombre(auxPass,nombre);
		Passenger_setApellido(auxPass,apellido);
		Passenger_setPrecio(auxPass,precio);
		Passenger_setCodigoVuelo(auxPass,codigoVuelo);
		Passenger_setTipoPasajero(auxPass,tipoPasajero);
		Passenger_setEstadoVuelo(auxPass,estadoVuelo);

		ll_add(pArrayListPassenger,auxPass);
		*nextId = *nextId+1;

		todoOk=1;
	}

		}
	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	Passenger* auxPass;

	int opcion;
	int posicion;
	int auxId;
	int auxPrecio;
	char auxNombre[20];
	char auxApellido[20];
	char auxTipo[20];
	char auxEstado[12];
	char auxCodigo[8];
	int tam = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
		utn_getNumero(&auxId,"Ingrese numero de ID a modificar: ","Error en ID ingresado\n",1,tam,3);
		posicion =  passenger_findPassengerById(pArrayListPassenger,auxId);
		if(posicion==-1)
		{
		//	printf("%d",posicion);
		printf("%d",auxId);
			printf("\nNo existe este ID\n");
		}
		else
		{
			do{
				auxPass = ll_get(pArrayListPassenger, posicion);
				utn_getNumero(&opcion,"\n Indique que desea modificar del pasajero:\n1_Nombre\n2_Apellido\n3_Precio\n4_Codigo vuelo\n5_Tipo pasajero\n6_Estado vuelo\n7_Salir\nOpcion elegida: ","\nError, no se ingreso opcion correcta\n",1,7,3);
				switch(opcion)
				{
				case 1:
					utn_getTexto("\nIngrese nuevo nombre de pasajero: ","\nError",1,20,3, auxNombre);                      //mensaje + cambiar campo nombre
					Passenger_setNombre(auxPass, auxNombre);
					break;
				case 2:
					utn_getTexto("\nIngrese nuevo apellido de pasajero: ","\nError",1,20,3, auxApellido);                      //mensaje + cambiar campo apellido
					Passenger_setApellido(auxPass, auxApellido);
					break;
				case 3:
					if(utn_getNumero(&auxPrecio,"Ingrese nuevo precio: ","Error\n",1,10000000,3)==0)
					{
						Passenger_setPrecio(auxPass, auxPrecio);
					}
					break;
				case 4:
					utn_getAlfanumerico("\nIngrese nuevo codigo de vuelo: ","\nError",1,8,3, auxCodigo);                      //mensaje + cambiar campo codigo vuelo
					Passenger_setCodigoVuelo(auxPass, auxCodigo);
					break;
				case 5:
					utn_getTexto("\nIngrese nuevo tipo de pasajero: ","\nError",1,20,3, auxTipo);                      //mensaje + cambiar campo tipo pasajero
					Passenger_setTipoPasajero(auxPass, auxTipo);
					break;
				case 6:
					utn_getTexto("\nIngrese nuevo estado de vuelo: ","\nError",1,12,3, auxEstado);                      //mensaje + cambiar campo estado vuelo
					Passenger_setEstadoVuelo(auxPass, auxEstado);
					break;
				case 7:
					break;
				}
			}while(opcion!=7);

			todoOk = 1;
			}
		}
	return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	    if(pArrayListPassenger != NULL)
	    {
	        int auxId=0;
	        int auxId2=0;
			char seguir='s';
	        char confirma='n';

	        do{
	            Passenger* auxPass = Passenger_new();
	            if(auxPass != NULL)
	            {
	                int largoArray=ll_len(pArrayListPassenger);
	                system("cls");
	                printf("* * * ELIMINAR PASAJERO * * *\n\n");
	                controller_ListPassenger(pArrayListPassenger);
					utn_getNumero(&auxId,"\n Indique ID que desea eliminar: ","\nError, no se ingreso opcion correcta\n",1,1000000003,3);

					for(int i=0;i<largoArray;i++){
						auxPass=(Passenger*)ll_get(pArrayListPassenger,i);
						Passenger_getId(auxPass,&auxId2);

	                        if(auxId==auxId2)
	                        {
	                            system("cls");
	                            printf("* PASAJERO A DAR DE BAJA *\n\n");
	                            mostrarPasajero(auxPass);
	                            printf("Confirma eliminacion del pasajero? ingrese s o n: ");
	                            fflush(stdin);
	                            scanf("%c",&confirma);
	                            confirma = tolower(confirma);

	                            if(confirma=='s')
	                            {
	                                ll_remove(pArrayListPassenger,i);
	                                todoOk=1;
	                            }
	                        }
	                        if(i==largoArray){
	                            todoOk=2;
	                        }
	                    }
	                }

	        else
	            {
	                todoOk=0;
	            }

	            printf("Desea eliminar otro pasajero? ingrese s o n: ");
	            fflush(stdin);
	            scanf("%c",&seguir);
	            seguir = tolower(seguir);
	        }while(seguir=='s');
	    }
	    return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;

	if(pArrayListPassenger != NULL)
	{
		todoOk = 1;
		Passenger* auxPass;
		int tam = ll_len(pArrayListPassenger);

		printf("%6s %22s %22s %10s %14s %22s %14s\n","ID","NOMBRE","APELLIDO","PRECIO","CODIGO VUELO","TIPO PASAJERO","ESTADO VUELO");
		printf("%6s %22s %22s %10s %14s %22s %14s\n","--","------","--------","------","-------------","------------","------------");
		for(int i=0;i<tam;i++)
		{
			auxPass = (Passenger*)ll_get(pArrayListPassenger,i);
			mostrarPasajero(auxPass);
		}
		if(tam==0)
		{
			printf("No hay pasajeros cargados para mostrar.\n");
		}
		system("pause");
	}
	return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	 int todoOk = 0;
	    if(pArrayListPassenger != NULL)
	    {
	        char seguir='s';
	        char confirma='n';
	        do{
	            switch(menuOrdenar())
	            {
	                case 1:
	                    ll_sort(pArrayListPassenger,ordenarPorId,1);
	                    printf("Pasajeros ordenados exitosamente\n");
	                    system("pause");
	                    todoOk = 1;
	                    break;
	                case 2:
	                    ll_sort(pArrayListPassenger,ordenarPorId,0);
	                    printf("Pasajeros ordenados exitosamente\n");
	                    system("pause");
	                    todoOk = 1;
	                    break;
	                case 3:
	                    ll_sort(pArrayListPassenger,ordenarPorNombre,1);
	                    printf("Pasajeros ordenados exitosamente\n");
	                    system("pause");
	                    todoOk = 1;
	                    break;
	                case 4:
	                    ll_sort(pArrayListPassenger,ordenarPorNombre,0);
	                    printf("Pasajeros ordenados exitosamente\n");
	                    system("pause");
	                    todoOk = 1;
	                    break;
	                case 5:
	                    ll_sort(pArrayListPassenger,ordenarPorApellido,1);
	                    printf("Pasajeros ordenados exitosamente\n");
	                    system("pause");
	                    todoOk = 1;
	                    break;
	                case 6:
	                    ll_sort(pArrayListPassenger,ordenarPorApellido,0);
	                    printf("Pasajeros ordenados exitosamente\n");
	                    system("pause");
	                    todoOk = 1;
	                    break;
	                case 7:
	                    ll_sort(pArrayListPassenger,ordenarPorPrecio,1);
	                    printf("Pasajeros ordenados exitosamente\n");
						system("pause");
	                    todoOk = 1;
	                    break;
	                case 8:
	                    ll_sort(pArrayListPassenger,ordenarPorPrecio,0);
	                    printf("Pasajeros ordenados exitosamente\n");
						system("pause");
	                    todoOk = 1;
	                    break;
	                case 9:
						ll_sort(pArrayListPassenger,ordenarPorTipoPasajero,1);
						printf("Pasajeros ordenados exitosamente\n");
						system("pause");
						todoOk = 1;
						break;
					case 10:
						ll_sort(pArrayListPassenger,ordenarPorTipoPasajero,0);
						printf("Pasajeros ordenados exitosamente\n");
						system("pause");
						todoOk = 1;
						break;
					 case 11:
						ll_sort(pArrayListPassenger,ordenarPorCodigoVuelo,1);
						printf("Pasajeros ordenados exitosamente\n");
						system("pause");
						todoOk = 1;
						break;
					case 12:
						ll_sort(pArrayListPassenger,ordenarPorCodigoVuelo,0);
						printf("Pasajeros ordenados exitosamente\n");
						system("pause");
						todoOk = 1;
						break;
					 case 13:
						ll_sort(pArrayListPassenger,ordenarPorEstadoVuelo,1);
						printf("Pasajeros ordenados exitosamente\n");
						system("pause");
						todoOk = 1;
						break;
					case 14:
						ll_sort(pArrayListPassenger,ordenarPorEstadoVuelo,0);
						printf("Pasajeros ordenados exitosamente\n");
						system("pause");
						todoOk = 1;
						break;
	                case 15:
	                    printf("Esta seguro que desea salir?, ingrese s o n: ");
	                    fflush(stdin);
	                    scanf("%c",&confirma);
	                    confirma = tolower(confirma);
	                    if(confirma=='s')
	                    {
	                        seguir='n';
	                    }
	                    break;
	                default:
	                    printf("Opcion invalida..!!\n");
	                    break;
	            }
	        }while(seguir=='s');
	    }
	    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    if(path != NULL && pArrayListPassenger != NULL)
    {
    	FILE* f = fopen(path,"w");

    	if(f != NULL)
    	{
    		int auxId;
    		char auxNombre[20];
    		char auxApellido[20];
    		int auxPrecio;
    		char auxTipo[20];
			char auxCodigo[8];
			char auxEstado[12];

			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				Passenger* auxPass = (Passenger*)ll_get(pArrayListPassenger,i);

				Passenger_getId(auxPass,&auxId);
				Passenger_getNombre(auxPass,auxNombre);
				Passenger_getApellido(auxPass,auxApellido);
				Passenger_getPrecio(auxPass,&auxPrecio);
				Passenger_getTipoPasajero(auxPass,auxTipo);
				Passenger_getCodigoVuelo(auxPass,auxCodigo);
				Passenger_getEstadoVuelo(auxPass,auxEstado);


				fprintf(f,"%d,%s,%s,%d,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipo,auxCodigo,auxEstado);
			}
			fclose(f);
			todoOk = 1;
		}
    }
	return todoOk;
}

int controller_saveIdAsText(char* path , int* proxId)
{
	 int todoOk = 0;
	    if(path != NULL && proxId != NULL)
	    {
	    	FILE* f = fopen(path,"w");

	    	if(f != NULL)
	    	{
	    		fprintf(f,"%d", *proxId);
				}
				fclose(f);
				todoOk = 1;
			}

		return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen(path,"wb");

		if(f != NULL)
		{
			for(int i=0;i<ll_len(pArrayListPassenger);i++)
			{
				Passenger* auxPass = (Passenger*)ll_get(pArrayListPassenger,i);
				fwrite(auxPass,sizeof(Passenger),1,f);
			}
			fclose(f);
			todoOk = 1;
		}
	}
	return todoOk;
}

