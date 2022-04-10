/*
 * bd.h
 *
 *  Created on: 10 abr 2022
 *      Author: IKER MARCELO
 */
#include "usuario.h"
#include "pelicula.h"
#ifndef BD_H_
#define BD_H_

void anyadirUsuario(Usuario u);
void anyadirPelicula(Pelicula p);
void updatePelicula(Pelicula p);
void visualizarPeliculasDisp();
int comprobarUsuario(char *u, char *c);
void alqPelicula(Usuario u, Pelicula p, int codAlquiler);
int numPelis();
Pelicula* devolPelicula(int numPelis);
void verMisPelis(Usuario u);

#endif /* BD_H_ */
