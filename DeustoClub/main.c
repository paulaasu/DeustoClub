#include "pelicula.h"
#include "almacen.h"
#include <stdlib.h>
#include "usuario.h"
#include <math.h>
#include <stdio.h>
#include "menu.h"
#include <string.h>
#include "bd.h"

#define MAX_LINE 20



int main(void) {

	Almacen a;
	Pelicula *arrayPeliDisp = (Pelicula*)(malloc(sizeof(Pelicula)*numPelis()));
	arrayPeliDisp = arrayPeliculas(numPelis());
	crearAlmacen(&a, arrayPeliDisp, numPelis());

	Usuario *arrayU = (Usuario*)(malloc(sizeof(Usuario)*numUsuario()));
	arrayU = arrayUsuarios(numUsuario());
//	for(int i=0; i<numUsuario();i++){
//		imprimirUsuario(arrayU[i]);
//	}

	mostrarMenu(a);

//	introducirPeliAlq();
//	Usuario u;
//	u.nombre= "Paula";
//	float cantidad = 80.5;
//	printf("Cantidad1: %f", cantidad);
//	cambiarGastado(u, cantidad);
//	printf("OK");



	return 0;
}
