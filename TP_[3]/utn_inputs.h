/*
 * utn_inputs.h
 *
 *  Created on: 1 jul. 2022
 *      Author: leand
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int utn_getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input); // solo acepta numeros sin signo positivo o negativo
int utn_getUnsignedIntTxt(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,char* input); // solo acepta numeros sin signo positivo o negativo
int getString2(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado); // Valida tamaño minimo y maximo del string
int isValidNumber(char* stringRecibido);
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input); // Valida texto con letras y espacios
int isValidTexto(char* stringRecibido);
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input); // Valida texto con datos alfanumericos
int isValidAlphanumeric(char* stringRecibido);
int utn_getTextoBreve(char* msg, char* msgError, int reintentos, char* input); // Valida texto con letras y espacios


#endif /* UTN_INPUTS_H_ */
