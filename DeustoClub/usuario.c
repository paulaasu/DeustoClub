/*
 * usuario.c
 *
 *  Created on: 5 abr 2022
 *      Author: IKER MARCELO
 */

#include "usuario.h"

void editarUsuario(Usuario *u, char* n, char* c){
	(*u).nombre = n;
	(*u).contrasenia = c;

}

void imprimirUsuario(Usuario u){
	printf("Usuario: %s, Contraseña: %s , Gastado: %f \n", u.nombre, u.contrasenia, u.gastado);
}

int comprobarDatos(char* c1, char* c2){
	int igual=0;
	if (c1 == c2) {
		igual =1;
	}
	return igual;
}



