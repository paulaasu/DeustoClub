#include "pelicula.h"
#include <math.h>
#include <stdio.h>

int main(void) {
	Pelicula p1;
	strcpy(p1.nombre,"Encanto");p1.codPelicula=0;strcpy(p1.disponibilidad,"Disponible");strcpy(p1.genero,"Fantasía");
	p1.codPelicula = 0; p1.precio= 10.5; p1.valoracion=9.5;
	imprimirPelicula(p1);

	return 0;
}
