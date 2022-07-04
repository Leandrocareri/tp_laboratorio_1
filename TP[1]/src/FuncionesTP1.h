 /*
 * FuncionesTP1.h
 *
 *  Created on: 10 abr. 2022
 *      Author: leand
 */

#ifndef FUNCIONESTP1_H_
#define FUNCIONESTP1_H_

int menu(int k,float a, float l);
int ingresarKms();
float ingresarPrecioVueloAerolineas();
float ingresarPrecioVueloLatam();
float calcularDebito(float a);
float calcularCredito(float a);
float calcularBTC(float a);
float calcularUnitario(float a, int b); // a precio, b km
float calcularDiferenciaPrecio(float a, float b); // a Latam, b Aerolineas
void mostrarCalculosAerolineas(int z,float a, float b, float c, float d, float e);
void mostrarCalculosLatam (float a, float b, float c, float d, float e, float f);
char confirmarSalida();

#endif /* FUNCIONESTP1_H_ */
