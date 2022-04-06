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
	int disponibilidad;
	int genero;
	float valoracion;
	int minutos;
}Pelicula;

void imprimirPelicula(Pelicula p);
void editarPelicula(Pelicula *p, int cod, char* nom, float prec, int gen, float val, int dis);
void alquilarPelicula(Pelicula *p);
void devolverPelicula(Pelicula *p);


#endif /* PELICULA_H_ */
