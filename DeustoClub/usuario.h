/*
 * usuario.h
 *
 *  Created on: 5 abr 2022
 *      Author: Propietario
 */

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct{
	char *nombre;
	char *contrasenia;


}Usuario;
void editarUsuario(Usuario *u, char* n, char* c);
void imprimirUsuario(Usuario u);
int comprobarDatos(char* c1, char* c2);

#endif /* USUARIO_H_ */
