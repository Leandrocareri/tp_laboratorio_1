/*
 * inputs.h
 *
 *  Created on: 2 jul. 2022
 *      Author: leand
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);
int esDescripcion(char* cadena,int longitud);
int getDescripcion(char* pResultado, int longitud);
int isValidAlphanumeric(char* stringRecibido);
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int getString2(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado); // Valida tamaño minimo y maximo del string



#endif /* INPUTS_H_ */
