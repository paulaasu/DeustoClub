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
	char nombre[15];
	float precio;
	char disponibilidad[15];
	//char* director; //yo lo quitaria ns
	char genero[20];
	int valoracion;
	//duracion??
}Pelicula;

void imprimirPelicula(Pelicula p);


#endif /* PELICULA_H_ */
