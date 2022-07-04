#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <string.h>
#include <ctype.h>


/*
 * inputs.c
 *
 *  Created on: 26 jun. 2022
 *      Author: leand
 */


/** \brief Valida si la cadena ingresada es numero o no
 *
 * \param cadena char*
 *
 * \return int  0 si no se ingreso numero, 1 si se ingreso un numero
 *
 */
int validarNumero(char* numero)
{
	int todoOk=0;
	for (int i=0; i<strlen(numero); i++)
	{
		if(!(isdigit(numero[i])))
		{
			printf("Error, no se ingreso un numero\n");
			break;
		}
		else
		{
			todoOk=1;
		}
	}
	return todoOk;
}

int validarNumeroPositivo(char* numero)
{
	int todoOk=0;
	int num;
	for (int i=0; i<strlen(numero); i++)
	{
		if(!(isdigit(numero[i])))
		{
			printf("Error, no se ingreso un numero\n");
			break;
		}
		else
		{
			num = atoi(numero);
			if(num<1)
			{
				printf("Error, se debe ingresar un numero mayor a 0\n");
			}
			else
			{
				todoOk=1;
			}
		}
	}
	return todoOk;
}

/*
int getString(char* input,char message[],char eMessage[], int min, int max)
{
    char auxString[20]={"0"};
    int sizeOfString=0;
    int todoOk=0;

    printf("%s: ", message);
    fflush(stdin);
    scanf("%s", auxString);

    if(isChar(auxString))
    {
      sizeOfString=strlen(auxString);
        if(sizeOfString>max|| sizeOfString<min){
            system("cls");
            printf("%s ", eMessage);
            todoOk=0;
        }
        else
        {
            auxString[0]=toupper(auxString[0]);
            strcpy(input,auxString);
            todoOk=1;
        }
    }
    else{
        printf("Ingrese solo letras!\n");
        todoOk=0;
    }
    return todoOk;
}*/

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxString[100]={"0"};
    int sizeOfString=0;
    int todoOk=0;

    printf("%s: ", message);
    fflush(stdin);
    scanf("%s", auxString);

    if(isChar(auxString))
    {
      sizeOfString=strlen(auxString);
        if(sizeOfString>hiLimit || sizeOfString<lowLimit)
        {
            system("cls");
            printf("%s ", eMessage);
            todoOk=0;
        }
        else
        {
            auxString[0]=toupper(auxString[0]);
            strcpy(input,auxString);
            todoOk=1;
        }
    }
    else
    {
        printf("Ingrese solo letras!\n");
        todoOk=0;
    }
    return todoOk;
}


int isChar(char auxString[])
{
   int i=0;
   int todoOk = 1;
   while(auxString[i] != '\0'){
       if((auxString[i] < 'a' || auxString[i] > 'z') && (auxString[i] < 'A' || auxString[i] > 'Z'))
       {
           todoOk = 0;
           printf("Error en los datos ingresados\n");
           break;
       }
       i++;
   }
   return todoOk;
}


int getIntPositive(int* pResultado, char mensaje[])
{
    char buffer[15];
    int todoOk = 0;
    int flagCorrecto = 0;

    if(pResultado != NULL)
    {
    	do
    	{
        	myGets(buffer, sizeof(buffer));
    		if(validarNumeroPositivo(buffer))
    		{
    			todoOk = 1;
    			flagCorrecto = 1;
    			*pResultado = atoi(buffer);
    		}
			else
    		{
    			printf("Error, no se ingreso un precio correcto, vuelva a ingresarlo: ");
    		}
    	}while(flagCorrecto == 0);
    }
    return todoOk;
}



int esNumerica(char* pResultado)
{
	int todoOk = 1;
	if (strlen(pResultado) > 0)
	{
		for(int i = 0; i < strlen(pResultado); i++)
		{
			if (isdigit(pResultado[i]) == 0)
			{
				todoOk = 0;
				break;
			}
		}
	}else
	{
		todoOk = 0;
	}
	return todoOk;
}


/*
int myGets(char* pResultado, int tResultado, char* mensaje)
{
	char buffer[30];
	int todoOk = 0;
	int flagCorrecto = 0;
	if(pResultado != NULL && tResultado > 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);

			if(strlen(buffer) > tResultado || strlen(buffer) < 1)
			{
				if(!getContinuar("[ERROR] EN EL LIMITE DE CARACTERES PERMITIDOS. QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> "))
				{
					flagCorrecto = 1;
					todoOk = -1;
				}
			}
			else
			{
				strncpy(pResultado, buffer, tResultado);
				todoOk = 1;
			}
		} while(flagCorrecto == 0);
	}
	return todoOk;
}

*/


int getContinuar(char mensaje[])
{
	int todoOk = -1;

	do
	{
		getInt(&todoOk);
		if(todoOk != 1 && todoOk != 0)
		{
			printf("[ERROR] OPCION INVALIDA: '%d'\n", todoOk);
		}else
		{
			if(todoOk == 1)
			{
				todoOk = 1;
			}else
			{
				todoOk = 0;
			}
		}

	}while(todoOk == -1);
	return todoOk;
}

/*
int getInt(int* pResultado, char mensaje[])
{
    char buffer[30];
    int todoOk = 0;

	while(todoOk == 0)
	{
		myGets(buffer, sizeof(buffer), mensaje);
		if(esNumerica(buffer) == 0)
		{
			if(!getContinuar("[ERROR] INGRESE UN NUMERO. QUIERE VOLVER A INTENTARLO? (1) SI (0) NO:\n-> "))
			{
				todoOk = -1;
				break;
			}
		}else
		{
			*pResultado = atoi(buffer);
			todoOk = 1;;
		}
	}
    return todoOk;
}
*/



int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos)
{
int bufferInt;
int todoOk = 0;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getInt(&bufferInt))
		{
				if(bufferInt >= minimo)
				{
					*pResultado = bufferInt;
					todoOk = 1;
					break;
				}
		}
		else
		{
			printf("%s",mensajeError);
		}

	}
	return todoOk;
}


int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL && getString3(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica2(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}


int myGets(char* cadena, int longitud)
{
	int todoOk = 0;
		if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
		{
			fflush(stdin);
			if(cadena[strlen(cadena)-1] == '\n')
			{
				cadena[strlen(cadena)-1] = '\0';
			}
			todoOk = 1;
		}
	return todoOk;
}




int esNumerica2(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}




int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int getString3(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un string valido y -1 (ERROR) si no
 *
 */
int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[51];

    if(pResultado != NULL)
    {
    	if(	getString3(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int esNombre(char* cadena,int longitud)
{
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(int i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i]!= ' ')
            {
                retorno = 0;
				break;
			}
		}
		if(cadena[0]=='\0')
        {
            retorno = 0;
        }
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[51];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
