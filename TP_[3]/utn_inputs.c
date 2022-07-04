#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "parser.h"
#include "utn_inputs.h"



/*
 * utn_inputs.c
 *
 *  Created on: 1 jul. 2022
 *      Author: leand
 */



int utn_getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input) // solo acepta numeros sin signo positivo o negativo
{
    int todoOk = 0;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<=maxSize && min<=max && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
    {
        do
        {
            if(getString2(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr))
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    todoOk=1;
                    break;
                }
                else
                {
                    printf("\n%s \n",msgError);
                    printf("\nQuedan %d reintentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}

int utn_getUnsignedIntTxt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,char* input) // solo acepta numeros sin signo positivo o negativo
{
    int todoOk = 0;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<=maxSize && min<=max && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
    {
        do
        {
            if(getString2(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr))
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    todoOk=1;
                    break;
                }
                else
                {
                    printf("\n%s \n",msgError);
                    printf("\nQuedan %d reintentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}


int getString2(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado) // Valida tamaño minimo y maximo del string
{
    int todoOk = 0;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL) // valida los parametros de la funcion
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin); //atencion
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                todoOk = 1;
                break;
            }
            else
            {
                printf("\n%s \n",msgError);
                printf("\nQuedan %d reintentos\n", *(reintentos));
            }

            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return todoOk;
}



int isValidNumber(char* stringRecibido)
{
    int todoOk = 1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    for(int i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            todoOk = 0;
            break;
        }
    }
    return todoOk;
}




int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input) // Valida texto con letras y espacios
{
    int todoOk=0;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
    {
        do
        {
            if(getString2(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTexto(bufferStr))
                {
                    strncpy(input,bufferStr,maxSize);
                    todoOk=1;
                    break;
                }
                else
                {
                    printf("\n%s \n",msgError);
                    printf("\nQuedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}


int utn_getTextoBreve(char* msg, char* msgError, int reintentos, char* input) // Valida texto con letras y espacios
{
    int todoOk=0;
    char bufferStr[10];

    if(msg!=NULL && msgError!=NULL && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
    {
        do
        {
            if(getString2(msg,msgError,1,10,&reintentos,bufferStr))
            {
                if(isValidTexto(bufferStr))
                {
                    strncpy(input,bufferStr,10);
                    todoOk=1;
                    break;
                }
                else
                {
                    printf("\n%s \n",msgError);
                    printf("\nQuedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}



int isValidTexto(char* stringRecibido)
{
    int todoOk=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	for(int i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}


int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input) // Valida texto con datos alfanumericos
{
    int todoOk = 0;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL) // valida los parametros de la funcion
    {
        do
        {
            if(getString2(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidAlphanumeric(bufferStr))
                {
                    strncpy(input,bufferStr,maxSize);
                    todoOk = 1;
                    break;
                }
                else
                {
                    printf("\n%s \n",msgError);
                    printf("\nQuedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}

int isValidAlphanumeric(char* stringRecibido)
{
    int todoOk = 1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    for(int i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}
/*


int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado) // Valida el ingreso de un solo caracter, solo letras
{
    int retorno=-1;
    char bufferChar[256];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)  // valida los parametros de la funcion
    {
        do
        {
            if(!getString(msg,msgError,1,3,&reintentos,bufferChar)) //==0
            {
                if(isValidChar(bufferChar[0])==1)
                {
                    printf("\nCaracter ingresado correctamente\n");
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("\n%s \n",msgError);
                    printf("\nQuedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char charRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=0;
    return retorno;
}
*/
