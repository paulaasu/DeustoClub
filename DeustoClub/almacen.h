/*
 * almacen.h
 *
 *  Created on: 5 abr 2022
 *      Author: IKER MARCELO
 */
#include "pelicula.h"
#ifndef ALMACEN_H_
#define ALMACEN_H_

typedef struct{
	int numPeliculas;
	Pelicula *ArrayP;
}Almacen;
void crearAlmacen(Almacen *a, Pelicula *ap, int tamanyo);
void listarPeliculas(Almacen a);
void filtrarDisponibles(Almacen a);
void filtrarGenero(Almacen a, int genero);
void filtrarPrecioMax(Almacen a, int precio);


#endif /* ALMACEN_H_ */
