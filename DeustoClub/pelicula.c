
#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>


void imprimirPelicula(Pelicula p){
	printf("[Cod: %i, Nombre: %s, Precio: %f, Genero: %i, Valoracion: %f, Disponibilidad: %i]\n", p.codPelicula, p.nombre, p.precio, p.genero, p.valoracion, p.disponibilidad);
}

void editarPelicula(Pelicula *p, int cod, char* nom, float prec, int gen, float val, int dis){
	p->codPelicula = cod;
	p->nombre = nom;
	p->precio = prec;
	p->genero = gen;
	p->valoracion = val;
	p->disponibilidad = dis;
}
void alquilarPelicula(Pelicula *p){
	p->disponibilidad = 0;
}
void devolverPelicula(Pelicula *p){
	p->disponibilidad = 1;
}
