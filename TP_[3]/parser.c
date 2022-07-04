#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_nextId(FILE* pFile, int* nextId)
{
	int todoOk = 0;
	int auxId;
	int cant;

	if(pFile!= NULL)
	{
		do{
			cant = fscanf(pFile,"%d",&auxId);
			if(cant<1)
			{
				break;
			}
			*nextId = auxId;
			todoOk = 1;
		} while(!feof(pFile));

	}
	return todoOk;
}

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)  // VER ID 1.55
{
	char buffer[7][20];
	int cant;
	int todoOk = 0;
	//int a; //ver
	Passenger* newPass;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]); //lectura fantasma

		do{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
			if(cant<7)
			{
				break;
			}
			newPass = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
			ll_add(pArrayListPassenger,newPass);
			todoOk = 1;
		} while(!feof(pFile));
	}
    return todoOk;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	int cant;
	Passenger* newPass = NULL;
	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			newPass = Passenger_new();
			if(newPass != NULL)
			{
				cant = fread(newPass, sizeof(Passenger), 1,pFile);
				if(cant<1)
				{
					break;
				}
				else
				{
					ll_add(pArrayListPassenger,newPass);
					todoOk=1;
				}
			}
		}
	}
    return todoOk;
}

