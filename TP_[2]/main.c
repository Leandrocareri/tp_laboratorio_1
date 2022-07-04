#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "arrayPassenger.h"
#include "inputs.h"

#define TAM 5

int main()
{
    setbuf(stdout,NULL);
    char salir='n';
    char salirInformes='n';
    ePassenger lista[TAM];
    int id=1;
    int flagAlta=0;

    initPassengers(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1://alta pasajero
            if(cargarPasajero(lista, TAM,&id))
            {
                printf("Pasajero cargado con exito\n");
                flagAlta=1;
                system("pause");
            }
            else
            {
                printf("No se pudo dar de alta al pasajero.\n");
            }
            break;
        case 2:  // Modificacion
            if(flagAlta==0)
            {
                printf("No se puede modificar datos hasta no cargar un pasajero\n");
                system("pause");
            }
            else
            {
                if(modificarPasajero(lista,TAM))
                {
                    printf("Modificacion realizada con exito\n");
                    system("pause");
                }
                else
                {
                    printf("Problema al modificar pasajero");
                }
            }

            break;
        case 3:
            if(flagAlta==0)
            {
                printf("No se puede dar de baja hasta no cargar un pasajero\n");
                system("pause");
            }
            else
            {
                if(removePassenger(lista,TAM))
                {
                    printf("Baja realizada con exito\n");
                    system("pause");
                }
                else
                {
                    printf("No se realizo la baja del pasajero\n");
                    system("pause");
                }
            }
            break;
        case 4:
            if(flagAlta==0)
            {
                printf("No se puede informar hasta no cargar un pasajero\n");
                system("pause");
            }
            else
            {
                do
                {
                    switch(menuInformar())
                    {
                    case 1:// por apellido y tipo
                        if(sortPassengers(lista,TAM))
                        {
                            mostrarPasajeros(lista, TAM);
                            printf("\n\n");
                        }
                        else
                        {
                            printf("No se pudo ordenar\n");
                        }
                        break;

                    case 2:
                        if(informarPromedio(lista,TAM));
                        break;

                    case 3:
                        if(sortPassengersByCode(lista,TAM))
                        {
                            mostrarPasajeros(lista, TAM);
                            printf("\n\n");
                        }
                        else
                        {
                            printf("No se pudo ordenar\n");
                        }
                        break;

                    case 4:
                        salirInformes=confirmarSalida();
                        break;

                    }
                }
                while(salirInformes!='s');
            }
            break;
        case 5:
            //alta forzada pasajeros
            if(hardcodearPasajeros(lista,TAM,5,&id))
            {
                printf("Carga realizada con exito.\n");
                flagAlta=1;
            }
            else
            {
                printf("Error al cargar pasajeros.\n");
            }
            system("pause");
            break;
        case 6:
            salir=confirmarSalida();
            break;
        default:
            printf("No se ingreso opcion correcta, vuelva a intentarlo\n");
            break;
        }
    }
    while(salir != 's');


    return 0;
}
