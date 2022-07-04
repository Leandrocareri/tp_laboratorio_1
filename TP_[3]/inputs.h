/*
 * inputs.h
 *
 *  Created on: 26 jun. 2022
 *      Author: leand
 */

#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */


int validarNumero(char* numero);
int getString(char* input,char message[],char eMessage[], int min, int max);
int isChar(char auxString[]);
int getIntPositive(int* pResultado, char mensaje[]);
int esNumerica(char* pResultado);
//int myGets(char* pResultado, int tResultado, char* mensaje);
int getContinuar(char mensaje[]);
//int getInt(int* pResultado, char mensaje[]);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos);
int isChar(char auxString[]);
int esNumerica2(char* cadena, int limite);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getString3(char* cadena, int longitud);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado, int longitud);










