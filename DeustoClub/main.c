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


	mostrarMenu(a);





	return 0;
}
