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
crearAlmacen(Almacen a, Pelicula *ap, int tamanyo);
listarPeliculas(Almacen a);
filtrarDisponibles(Almacen a);
filtrarGenero(Almacen a, int genero);
filtrarPrecioMax(Almacen a, int precio);


#endif /* ALMACEN_H_ */
