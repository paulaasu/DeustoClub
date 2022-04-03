
#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>


void imprimirPelicula(Pelicula p){
	printf("[Cod: %i, Nombre: %s, Precio: %f, Genero: %s, Valoracion: %f, Disponibilidad: %s]", p.codPelicula, p.nombre, p.precio, p.genero, p.valoracion, p.disponibilidad);
}

