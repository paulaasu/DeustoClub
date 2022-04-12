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

void alqPelicula(Usuario u, int cod_p);
int numPelis();
Pelicula* arrayPeliculas(int numPelis);
void verMisPelis(Usuario u);
void cambiarGastado(Usuario u, float cantidad);
int numUsuario();
Usuario* arrayUsuarios(int numUsuario);
void eliminarAlq(Usuario u);
int buscarMaxCodPel();


int comprobarAlquiler(Usuario u);
Pelicula devolverAlquiler(Usuario u);
void cambiaDisponibilidad(int codPeli, int dispo);
void cambiarGastado(Usuario u, float cantidad);


#endif /* BD_H_ */
