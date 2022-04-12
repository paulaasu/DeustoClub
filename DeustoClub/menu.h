/*
 * menu.h
 *
 *  Created on: 8 abr 2022
 *      Author: IKER MARCELO
 */

#ifndef MENU_H_
#define MENU_H_
#include"almacen.h"

int comprobarcontrasenya(char* c1, char* c2);
void mostrarMenu(Almacen a);
Usuario inicioSesion(Almacen a);
Usuario registrarUsuario();
void menuPrincipal(Almacen a, Usuario u);
void mostrarMenuFiltro(Almacen a);
void mostrarMenuGenero(Almacen a);
int introducirPeliAlq();
void mostrarMenuAdmin(Almacen a);
Pelicula anyadirPeli();
Pelicula eliminarPeli(Almacen a);
void escFich();

#endif /* MENU_H_ */
