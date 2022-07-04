#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "inputs.h"
#include "arrayPassenger.h"


int initPassengers(ePassenger lista[], int tam)   //-1 error, 0 ok
{
    int todoOk=-1;
    if(lista != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=0;
    }
    return todoOk;
}


int buscarLibre(ePassenger lista[], int tam, int* pIndice)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && pIndice != NULL)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if( lista[i].isEmpty)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int cargarPasajero(ePassenger lista[], int tam, int* pId)
{
    int todoOk=0;
    int indice;
    char auxCad[51];
    char auxFly[10];
    float auxFloat;
    int auxInt;
    ePassenger auxPass;

    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        if(buscarLibre(lista, tam, &indice))
        {
            if(indice==-1)
            {
                printf("No hay lugar para mas pasajeros\n");
                system("pause");
            }
            else
            {
                // Nombre
                if((utn_getNombre(auxCad,51,"Ingrese nombre del pasajero: ","No se ingreso un nombre correcto. ",3))==0)
                {
                    strcpy(auxPass.name, auxCad);
                }
                // Apellido
                if((utn_getNombre(auxCad,51,"Ingrese apellido del pasajero: ","No se ingreso un apellido correcto. ",3))==0)
                {
                    strcpy(auxPass.lastName, auxCad);
                }

                // Precio
                if((utn_getNumeroFlotante(&auxFloat, "Ingrese precio del vuelo: ", "Error, ingrese precio valido.\n", 0, 100000000, 3))==0)
                {
                    auxPass.price=auxFloat;
                }

                // Flycode
                if(utn_getAlfanumerico("Ingrese el flycode: ","Error, ingrese un flycode valido.\n", 1, 10, 3, auxFly))
                {
                    strcpy(auxPass.flycode, auxFly);
                }

                //Tipo pasajero
                if((utn_getNumero(&auxInt,"Ingrese tipo de pasajero: ","Error, dato invalido. \n",1,3,3))==0)
                {
                    auxPass.typePassenger=auxInt;
                }
                // status flight
                if((utn_getNumero(&auxInt,"Ingrese estado de vuelo: ","Error, dato invalido. \n",1,3,3))==0)
                {
                    auxPass.statusFlight=auxInt;
                }

                //Is empty
                auxPass.isEmpty=0;

                auxPass.id=*pId;
                *pId=*pId+1;

                lista[indice]=auxPass;

                todoOk=1;
            }
        }
    }
    return todoOk;
}

void mostrarPasajero(ePassenger pasajero)
{
    system("cls");
    printf("     *** AEROLINEAS  - Sistema de pasajeros ***\n\n");
    printf("---------------------------------------------------------------------------------\n\n");
    printf("  Id    Nombre     Apellido        Precio      Flycode     Tipo pasajero  Estado de vuelo\n");
    printf("---------------------------------------------------------------------------------\n\n");
    printf("  %03d     %s         %s       %6.2f       %s        %d      %d  \n\n", pasajero.id,pasajero.name,pasajero.lastName,pasajero.price,pasajero.flycode,pasajero.typePassenger,pasajero.statusFlight);
}


int mostrarPasajeros(ePassenger lista[], int tam)
{
    int todoOk=0;
    int flag=1;
    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("     *** AEROLINEAS  - Sistema de pasajeros ***\n\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n\n");
        printf("  Id                  Nombre                     Apellido         Precio            Flycode     Tipo  Estado de vuelo\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                printf("  %03d     %20s         %20s       %6.2f       %10s        %d      %d  \n", lista[i].id,lista[i].name,lista[i].lastName,lista[i].price,lista[i].flycode,lista[i].typePassenger,lista[i].statusFlight);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay pasajeros cargados para mostrar\n\n");
            system("pause");
        }
        todoOk=1;
    }
    return todoOk;
}



/*int addPassenger(ePassenger* lista, int tam, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
    int todoOk=0;
    return todoOk;
}

    */

int findPassengerById(ePassenger lista[], int tam,int id)
{
    int indice=-1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int removePassenger(ePassenger lista[], int tam)
{
    int todoOk=0;
    int indice;
    int idBuscar;
    char confirma;
    if(lista!=NULL && tam>0)
    {
        system("cls");
        printf("     *** AEROLINEAS  - Sistema de pasajeros ***\n\n");
        mostrarPasajeros(lista,tam);
        printf("Ingrese id a dar de baja: ");
        scanf("%d", &idBuscar);
        indice=(findPassengerById(lista, tam, idBuscar));
        if(indice==-1)
        {
            printf("El pasajero id %d no se encuentra cargado\n",idBuscar);
        }
        else
        {
            mostrarPasajero(lista[indice]);
            printf("Confirma baja de pasajero?");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                lista[indice].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("Baja cancelada\n");
                system("pause");
            }
        }
    }
    return todoOk;
}



int modificarPasajero (ePassenger lista[], int tam)
{
    int todoOk=0;
    int indice;
    int idBuscar;
    char salir='n';
    char auxCad[50];

    if(lista!=NULL && tam>0)
    {
        mostrarPasajeros(lista,tam);
        printf("Ingrese id a modificar: ");
        scanf("%d", &idBuscar);
        indice=findPassengerById(lista,tam,idBuscar);
        if(indice==-1)
        {
            printf("No hay pasajero con ese id\n");
        }
        else
        {
            mostrarPasajero(lista[indice]);

            do
            {
                switch(menuModificarPasajero())
                {
                case 1://nombre
                    printf("Ingrese nuevo nombre: \n");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(lista[indice].name,auxCad);
                    printf("Se ha modificado el nombre\n");
                    break;

                case 2://apellido
                    printf("Ingrese nuevo apellido: \n");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(lista[indice].lastName,auxCad);
                    printf("Se ha modificado el apellido\n");
                    break;

                case 3://precio
                    printf("Ingrese el nuevo precio: ");
                    scanf("%f", &lista[indice].price);
                    printf("Se ha modificado el precio\n");
                    break;

                case 4://tipo pasajero
                    printf("Ingrese el nuevo tipo de pasajero: ");
                    scanf("%d", &lista[indice].typePassenger);
                    printf("Se ha modificado el tipo de pasajero\n");
                    break;

                case 5://codigo vuelo
                    printf("Ingrese nuevo codigo de vuelo: \n");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(lista[indice].flycode,auxCad);
                    printf("Se ha modificado el codigo de vuelo\n");
                    break;

                case 6://salir
                    salir=confirmarSalida();
                    break;
                }

            }
            while(salir!= 's');
        }
        todoOk=1;
    }
    return todoOk;
}

//promedio, total y cuantos superan
int informarPromedio(ePassenger lista[], int tam)
{
    int todoOk=0;
    float acumuladorPrecios=0;
    float promedioPrecios;
    int contadorActivos=0;
    int contadorSuperan=0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                acumuladorPrecios+=lista[i].price;
                contadorActivos++;
            }
        }

        if(contadorActivos>0)
        {
            promedioPrecios=acumuladorPrecios/contadorActivos;
        }

        for(int i=0; i<tam; i++)
        {
            if(lista[i].price>promedioPrecios)
            {
                mostrarPasajero(lista[i]);
                contadorSuperan++;
            }
        }

        system("cls");
        printf("  *   Informe  promedio  de  precios   *\n\n");
        printf("El total de los precios de los vuelos es $ %6.2f\n",acumuladorPrecios);
        printf("El promedio de precio de los vuelos es $ %6.2f\n",promedioPrecios);
        printf("La cantidad de pasajeros que superan el promedio es %d\n",contadorSuperan);
        for(int i=0; i<tam; i++)
        {
            if(lista[i].price>promedioPrecios)
            {
                printf("  %03d     %20s         %20s       %6.2f       %10s        %d      %d  \n", lista[i].id,lista[i].name,lista[i].lastName,lista[i].price,lista[i].flycode,lista[i].typePassenger,lista[i].statusFlight);
            }
        }
        system("pause");

    }
    return todoOk;
}

int sortPassengers(ePassenger lista[], int tam) //1 asc, 2 desc
{
    int todoOk=0;
    int orden;
    ePassenger auxPasajero;
    if(lista!=NULL && tam>0)
    {
        utn_getNumero(&orden,"0_Ordenar de modo descendente\n1_Ordenar de modo ascendente\nElija opcion: ","Error en la opcion ingresada. \n",0,1,3);

        if(orden==0)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(((lista[i].typePassenger==lista[j].typePassenger)
                            && (strcmp(lista[i].lastName,lista[j].lastName)<0))
                            || ((lista[i].typePassenger!=lista[j].typePassenger) &&
                                (strcmp(lista[i].lastName,lista[j].lastName)>0)))
                    {
                        auxPasajero= lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPasajero;
                    }
                }
            }
        }
        else if(orden==1)
        {
              for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(((lista[i].typePassenger==lista[j].typePassenger)
                            && (strcmp(lista[i].lastName,lista[j].lastName)>0))
                            || ((lista[i].typePassenger!=lista[j].typePassenger) &&
                                (strcmp(lista[i].lastName,lista[j].lastName)<0)))
                    {
                        auxPasajero= lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPasajero;
                    }
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    ePassenger altaForzada[]=
    {
        {0,"Andres","Carreras",25000,"AB304",2,1,0},
        {0,"Luciana","Martinez",18250,"FL707",1,1,0},
        {0,"Valentina","Gutierrez",40000,"BB210",2,2,0},
        {0,"Ciro","Pertusi",12000,"AT777",1,1,0},
        {0,"Dave","Grohl",33000,"FF304",2,1,0}
    };

    if(vec != NULL && tam>0 && pId != NULL && cant>0 && cant<= tam)
    {
        for(int i=0; i<cant; i++)
        {
            vec[i] = altaForzada[i];
            vec[i].id = *pId;
            *pId = *pId + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}



/** \brief Sort the elements in the array of passengers
*
* \param list Passenger*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int sortPassengersByCode(ePassenger lista[], int tam) //1 asc, 0 desc
{
    int todoOk=0;
    int orden;
    ePassenger auxPasajero;
    if(lista!=NULL && tam>0)
    {
        utn_getNumero(&orden,"0_Ordenar de modo descendente\n1_Ordenar de modo ascendente\nElija opcion: ","Error en la opcion ingresada. \n",0,1,3);

        if(orden==0)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(((lista[i].statusFlight==lista[j].statusFlight)
                            && (strcmp(lista[i].flycode,lista[j].flycode)<0))
                            || ((lista[i].statusFlight!=lista[j].statusFlight) &&
                                (strcmp(lista[i].flycode,lista[j].flycode)>0)))
                    {
                        auxPasajero= lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPasajero;
                    }
                }
            }
        }
        else if(orden==1)
        {
              for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(((lista[i].statusFlight==lista[j].statusFlight)
                            && (strcmp(lista[i].flycode,lista[j].flycode)>0))
                            || ((lista[i].statusFlight!=lista[j].statusFlight) &&
                                (strcmp(lista[i].flycode,lista[j].flycode)<0)))
                    {
                        auxPasajero= lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPasajero;
                    }
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}
