#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "parser.h"
#include "sorts.h"
/*
 * sorts.c
 *
 *  Created on: 28 jun. 2022
 *      Author: leand
 */



/** \brief Compara ID de 2 pasajeros
 *
 * \param pass1 void*
 * \param pass2 void*
 * \return int todoOk (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorId(void* pass1,void* pass2)
{
    int todoOk = 0;
    Passenger* p1= Passenger_new();
    Passenger* p2= Passenger_new();

    if(pass1!=NULL && pass2!=NULL){
        p1=(Passenger*)pass1;
        p2=(Passenger*)pass2;

        if(p1->id > p2->id)
        {
            todoOk = 1;
        }
        else if(p1->id < p2->id)
        {
            todoOk = -1;
        }
        else
        {
            todoOk = 0;
        }
    }
	return todoOk;
}


/** \brief Compara nombres de 2 pasajeros
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int retorno (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorNombre(void* pass1,void* pass2)
{
    int todoOk=0;
    Passenger* p1=Passenger_new();
    Passenger* p2=Passenger_new();

    if(pass1 != NULL && pass2 != NULL)
    {
        p1=(Passenger*)pass1;
        p2=(Passenger*)pass2;

        if(stricmp(p1->nombre,p2->nombre)==1)
        {
            todoOk=1;
        }
        else if(stricmp(p1->nombre,p2->nombre)==-1)
        {
            todoOk=-1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}

/** \brief Compara apellidos de 2 pasajeros
 *
 * \param pass1 void*
 * \param pass2 void*
 * \return int todoOk (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorApellido(void* pass1,void* pass2)
{
	int todoOk=0;
	    Passenger* p1=Passenger_new();
	    Passenger* p2=Passenger_new();

	    if(pass1 != NULL && pass2 != NULL)
	    {
	        p1=(Passenger*)pass1;
	        p2=(Passenger*)pass2;

	        if(stricmp(p1->apellido,p2->apellido)==1)
	        {
	            todoOk=1;
	        }
	        else if(stricmp(p1->apellido,p2->apellido)==-1)
	        {
	            todoOk=-1;
	        }
	        else
	        {
	            todoOk=0;
	        }
	    }
	    return todoOk;
}

/** \brief Compara precio de vuelo de 2 pasajeros
 *
 * \param pass1 void*
 * \param pass2 void*
 * \return int todoOk (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorPrecio(void* pass1,void* pass2)
{
	int todoOk = 0;
	    Passenger* p1 = Passenger_new();
	    Passenger* p2 = Passenger_new();

	    if(pass1 != NULL && pass2 != NULL)
	    {
	        p1=(Passenger*)pass1;
	        p2=(Passenger*)pass2;

	        if(p1->precio > p2->precio)
	        {
	            todoOk=1;
	        }
	        else if(p1->precio < p2->precio)
	        {
	            todoOk = -1;
	        }
	        else
	        {
	            todoOk=0;
	        }
	    }
	    return todoOk;
}



/** \brief Compara tipo de 2 pasajeros
 *
 * \param pass1 void*
 * \param pass2 void*
 * \return int todoOk (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorTipoPasajero(void* pass1,void* pass2)
{
	int todoOk=0;
	    Passenger* p1=Passenger_new();
	    Passenger* p2=Passenger_new();

	    if(pass1 != NULL && pass2 != NULL)
	    {
	        p1=(Passenger*)pass1;
	        p2=(Passenger*)pass2;

	        if(stricmp(p1->tipoPasajero,p2->tipoPasajero)==1)
	        {
	            todoOk=1;
	        }
	        else if(stricmp(p1->tipoPasajero,p2->tipoPasajero)==-1)
	        {
	            todoOk=-1;
	        }
	        else
	        {
	            todoOk=0;
	        }
	    }
	    return todoOk;
}




/** \brief Compara codigo de vuelo de 2 pasajeros
 *
 * \param pass1 void*
 * \param pass2 void*
 * \return int todoOk (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorCodigoVuelo(void* pass1,void* pass2)
{
	int todoOk=0;
	    Passenger* p1=Passenger_new();
	    Passenger* p2=Passenger_new();

	    if(pass1 != NULL && pass2 != NULL)
	    {
	        p1=(Passenger*)pass1;
	        p2=(Passenger*)pass2;

	        if(stricmp(p1->codigoVuelo,p2->codigoVuelo)==1)
	        {
	            todoOk=1;
	        }
	        else if(stricmp(p1->codigoVuelo,p2->codigoVuelo)==-1)
	        {
	            todoOk=-1;
	        }
	        else
	        {
	            todoOk=0;
	        }
	    }
	    return todoOk;
}



/** \brief Compara estado de vuelo de 2 pasajeros
 *
 * \param pass1 void*
 * \param pass2 void*
 * \return int todoOk (1-> el primero mayor, -1-> el segundo mayor)
 *
 */
int ordenarPorEstadoVuelo(void* pass1,void* pass2)
{
	int todoOk=0;
	    Passenger* p1=Passenger_new();
	    Passenger* p2=Passenger_new();

	    if(pass1 != NULL && pass2 != NULL)
	    {
	        p1=(Passenger*)pass1;
	        p2=(Passenger*)pass2;

	        if(stricmp(p1->estadoVuelo,p2->estadoVuelo)==1)
	        {
	            todoOk=1;
	        }
	        else if(stricmp(p1->estadoVuelo,p2->estadoVuelo)==-1)
	        {
	            todoOk=-1;
	        }
	        else
	        {
	            todoOk=0;
	        }
	    }
	    return todoOk;
}


