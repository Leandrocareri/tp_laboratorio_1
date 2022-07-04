#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include <string.h>
#include "inputs.h"
/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


Passenger* Passenger_new()
{
	Passenger* this = (Passenger*) malloc(sizeof(Passenger));

	if(this != NULL)
	{
		this->id=0; //VER
		strcpy(this->nombre,"");
		strcpy(this->apellido,"");
		this->precio=0;
		strcpy(this->codigoVuelo,"");
		strcpy(this->tipoPasajero,"");
	}
	return this;
}



Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr)
{
	Passenger* this;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL)
	{
		this = Passenger_new();
		if(this != NULL)
		{
			if(!Passenger_SetIdTxt(this,idStr)  ||
			(!Passenger_setNombre(this,nombreStr)) ||
			(!Passenger_setApellido(this,apellidoStr)) ||
			(!Passenger_SetPrecioTxt(this,precioStr)) ||
			(!Passenger_setTipoPasajero(this,tipoPasajeroStr)) ||
			(!Passenger_setCodigoVuelo(this,codigoVueloStr)) ||
			(!Passenger_setEstadoVuelo(this,estadoVueloStr)))
			{
				free(this);
				this = NULL;
			}
		}
	}
	return this;
}



int Passenger_setId(Passenger* this,int id)
{
	int todoOk = 0;

	if(this != NULL && id>0)
	{
		this->id=id;
		todoOk=1;
	}
	return todoOk;
}


int Passenger_SetIdTxt(Passenger* this, char* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		if(esNumerica2(id,10))
		{
			todoOk = 1;
			this->id = atoi(id);
		}
	}
	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk=0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk=1;
	}
	return todoOk;
}




int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL && strlen(nombre)>1)
	{
		strcpy(this->nombre,nombre);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = 0;

	if(this != NULL && apellido != NULL && strlen(apellido)>1)
	{
		strcpy(this->apellido,apellido);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{int todoOk = 0;

if(this != NULL && apellido != NULL)
{
	strcpy(apellido,this->apellido);
	todoOk = 1;
}
return todoOk;

}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;

		if(this != NULL && codigoVuelo != NULL && strlen(codigoVuelo)>1)
		{
			strcpy(this->codigoVuelo,codigoVuelo);
			todoOk = 1;
		}
		return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		todoOk = 1;
	}
	return todoOk;
}


int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int todoOk = 0;

		if(this != NULL && tipoPasajero != NULL && strlen(tipoPasajero)>1)
		{
			strcpy(this->tipoPasajero,tipoPasajero);
			todoOk = 1;
		}
		return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int todoOk = 0;

		if(this != NULL && tipoPasajero != NULL)
		{
			strcpy(tipoPasajero,this->tipoPasajero);
			todoOk = 1;
		}
		return todoOk;
}



int Passenger_setPrecio(Passenger* this,int precio)
{
	int todoOk = 0;

		if(this != NULL && precio>0)
		{
			this->precio=precio;  //ver
			todoOk=1;
		}
		return todoOk;
}

int Passenger_SetPrecioTxt(Passenger* this, char* precio)
{
	int todoOk = 0;
	if(this != NULL && precio != NULL)
	{
		if(esNumerica2(precio,12))
		{
			todoOk = 1;
			this->precio = atoi(precio);
		}
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger* this,int* precio)
{
	int todoOk=0;

		if(this != NULL && precio != NULL)
		{
			*precio = this->precio;
			todoOk=1;
		}
		return todoOk;
}




int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int todoOk = 0;

		if(this != NULL && estadoVuelo != NULL && strlen(estadoVuelo)>1)
		{
			strcpy(this->estadoVuelo,estadoVuelo);
			todoOk = 1;
		}
		return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int todoOk = 0;

		if(this != NULL && estadoVuelo != NULL)
		{
			strcpy(estadoVuelo,this->estadoVuelo);
			todoOk = 1;
		}
		return todoOk;
}



/** \brief Muestra un pasajero
 *
 * \param pass Passenger*
 * \return void
 *
 */
void mostrarPasajero(Passenger* pass)
{
    if(pass!=NULL){
    	printf("%6d %22s %22s %10d %14s %22s %14s\n",pass->id,pass->nombre,pass->apellido,pass->precio,pass->tipoPasajero,pass->codigoVuelo,pass->estadoVuelo);
    }else{
        printf("No hay pasajeros para mostrar\n");
        system("pause");
    }
}



int passenger_getNextId(LinkedList* pArrayListPassenger)
{
    int maxValue = -1;
    int arrayLength = 0;
    int i;
    int contador = 0;
    Passenger* aux;

    if(pArrayListPassenger != NULL)
    {
        arrayLength = ll_len(pArrayListPassenger);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = (Passenger*)ll_get(pArrayListPassenger, i);

                if(aux != NULL)
                {
                    if(contador == 0)
                    {
                        maxValue = aux->id;
                    }
                    else
                    {
                        if(aux->id > maxValue)
                        {
                            maxValue = aux->id;
                        }
                    }
                    contador++;
                }
            }
        }
        if(contador > 0)
        {
            maxValue++;
        }
        else
        {
            maxValue = 1;
        }
    }
    return maxValue;
}


/*
int searchPassenger(LinkedList* pArrayListPassenger, int* id_Get, int* id_Index, char* msgMenu, char* msgGet, char* msgErrorID)
{
	int flagEmpleado_Buscar = 0;
	int todoOk = 0;

	do
	{
		todoOk = subMenu(msgMenu);
		if(todoOk)
		{
			if(eb_getIntPositive(id_Get, msgGet) == TRUE)
			{
				*id_Index = controller_validateID(pArrayListEmployee, *id_Get);
				if(*id_Index != FALSE)
				{
					flagEmpleado_Buscar = TRUE;
					break;
				}else
				{
					if(eb_getContinuar(msgErrorID) == TRUE)
					{
						flagEmpleado_Buscar = FALSE;
					}else
					{
						flagEmpleado_Buscar = NO;
					}
				}
			}else
			{
				break;
			}
		}else
		{
			if(rtn == SALIR)
			{
				flagEmpleado_Buscar = SALIR;
			}else
			{
				controller_ListEmployee(pArrayListEmployee);
				eb_pulseToContinue();
			}

		*/


int passenger_findPassengerById(LinkedList* pArrayListPassenger, int id)
{
	int todoOk = -1;
	Passenger* pPass;
	int auxId;
	int len;

	if (pArrayListPassenger != NULL && id >= 0)
	{
		len = ll_len(pArrayListPassenger);

		for (int i = 0;i < len;i++)
		{
			pPass = ll_get(pArrayListPassenger,i);
			Passenger_getId(pPass,&auxId);

			if (id==auxId)
			{
				todoOk = i;
				break;
			}
		}
	}
	else
	{
		printf("\nLa lista esta vacia");
	}
	return todoOk;
}
