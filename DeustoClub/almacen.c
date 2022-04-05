/*
 * almacen.c
 *
 *  Created on: 5 abr 2022
 *      Author: IKER MARCELO
 */
#include "almacen.h"

crearAlmacen(Almacen a, Pelicula *ap, int tamanyo){
	a.ArrayP = ap;
	a.numPeliculas = tamanyo;
}

listarPeliculas(Almacen a){
	printf("LISTA DE PELICULAS\n");
	printf("------------------\n");
	for (int var = 0; var < a.numPeliculas; ++var) {

		imprimirPelicula(a.ArrayP[var]);
	}
	printf("..................\n");
}
filtrarDisponibles(Almacen a){
	printf("PELICULAS DISPONIBLES\n");
		printf("------------------\n");
		for (int var = 0; var < a.numPeliculas; ++var) {
			if (a.ArrayP[var].disponibilidad == 1) {
				imprimirPelicula(a.ArrayP[var]);
			}

		}
		printf("..................\n");
}
filtrarGenero(Almacen a, int genero){
	printf("PELICULAS \n");
		printf("------------------\n");
		for (int var = 0; var < a.numPeliculas; ++var) {
			if (a.ArrayP[var].genero == genero) {
				imprimirPelicula(a.ArrayP[var]);
			}
		}
		printf("..................\n");
}

filtrarPrecioMax(Almacen a, int precio){
	printf("PELICULAS A MENOS DE %i€\n", precio);
		printf("------------------\n");
		for (int var = 0; var < a.numPeliculas; ++var) {
			if (a.ArrayP[var].precio == precio) {
				imprimirPelicula(a.ArrayP[var]);
			}
		}
		printf("..................\n");
}


