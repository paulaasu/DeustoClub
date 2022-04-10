#include "pelicula.h"
#include <stdlib.h>
#include "usuario.h"
#include <math.h>
#include <stdio.h>
#include "menu.h"
#include <string.h>
//#include "bd.c"

#define MAX_LINE 20



int main(void) {

//	mostrarMenu();
	Pelicula *arrayPeliDisp = (Pelicula*)(malloc(sizeof(Pelicula)*numPelis()));
	arrayPeliDisp = devolPelicula(numPelis());

	for(int i=0; i<numPelis(); i++){
			imprimirPelicula(arrayPeliDisp[i]);
		}

//	Usuario u;
//	imprimirUsuario(u);
//	editarUsuario(&u, "Joseba", "5555");
//	imprimirUsuario(u);
//	printf("Igual= %i\n", comprobarDatos(u.contrasenia, "5655"));
//	printf("Correcta= %i\n", comprobarcontrasenya("aaa", "aaa"));
//	registrarUsuario();

//	Usuario J;
//	J.nombre = "Joseba";
//	J.contrasenia ="313";
//
//	printf("Usuario:%i\n", comprobarUsuario(J.nombre, J.contrasenia));

//	Usuario u1;
//	u1.nombre = "Maria";
//	u1.contrasenia= "2222";
//	anyadirUsuario(u1);
//	visualizarPeliculasDisp();


	return 0;
}
