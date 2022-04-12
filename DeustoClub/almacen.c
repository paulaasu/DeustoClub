/*
 * almacen.c
 *
 *  Created on: 5 abr 2022
 *      Author: IKER MARCELO
 */

#include "bd.h"
#include "pelicula.h"
#include "almacen.h"
#include <stdlib.h>
#include "usuario.h"
#include <math.h>
#include <stdio.h>
#include "menu.h"
#include <string.h>

void crearAlmacen(Almacen *a, Pelicula *ap, int tamanyo){

	a->ArrayP= (Pelicula *) malloc(sizeof(Pelicula) * numPelis());
	for (int var = 0; var < numPelis(); ++var) {
		a->ArrayP[var] = ap[var];
	}
	a->numPeliculas = numPelis();
}

void listarPeliculas(Almacen a){
	printf("LISTA DE PELICULAS\n");
	printf("------------------\n");
	for (int var = 0; var < a.numPeliculas; ++var) {

		imprimirPelicula(a.ArrayP[var]);
	}
	printf("..................\n");
}
void filtrarDisponibles(Almacen a){
	printf("PELICULAS DISPONIBLES\n");
		printf("------------------\n");
		for (int var = 0; var < a.numPeliculas; ++var) {
			if (a.ArrayP[var].disponibilidad == 1) {
				imprimirPelicula(a.ArrayP[var]);
			}

		}
		printf("..................\n");
}
void filtrarGenero(Almacen a, int genero){
	printf("PELICULAS \n");
		printf("------------------\n");
		for (int var = 0; var < a.numPeliculas; ++var) {
			if (a.ArrayP[var].genero == genero) {
				imprimirPelicula(a.ArrayP[var]);
			}
		}
		printf("..................\n");
}

void filtrarPrecioMax(Almacen a, int precio){
	printf("PELICULAS A MENOS DE %i€\n", precio);
		printf("------------------\n");
		for (int var = 0; var < a.numPeliculas; ++var) {
			if (a.ArrayP[var].precio <= precio) {
				imprimirPelicula(a.ArrayP[var]);
			}
		}
		printf("..................\n");
}


