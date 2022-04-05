/*
 * pelicula.h
 *
 *  Created on: 3 abr 2022
 *      Author: Propietario
 */

#ifndef PELICULA_H_
#define PELICULA_H_

typedef struct{
	int codPelicula;
	char *nombre;
	float precio;
	char *disponibilidad;
	//char* director; //yo lo quitaria ns
	char genero[20];
	int valoracion;
	//duracion??
}Pelicula;

void imprimirPelicula(Pelicula p);


#endif /* PELICULA_H_ */
