
#include "pelicula.h"
#include <stdio.h>
#include <stdlib.h>

int codPelicula;
	char nombre[15];
	float precio;
	char disponibilidad[20];
	//char* director; //yo lo quitaria ns
	char genero[20];
	int valoracion;

void imprimirPelicula(Pelicula p){
	printf("[Cod: %i, Nombre: %s, Precio: %f, Genero: %s, Valoracion: %f, Disponibilidad: %s]", p.codPelicula, p.nombre, p.precio, p.genero, p.valoracion, p.disponibilidad);
}

