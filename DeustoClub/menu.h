/*
 * menu.h
 *
 *  Created on: 8 abr 2022
 *      Author: IKER MARCELO
 */

#ifndef MENU_H_
#define MENU_H_
#include"almacen.h"

void mostrarMenu(Almacen a);
Usuario inicioSesion();
Usuario registrarUsuario();
int comprobarcontrasenya(char* c1, char* c2);

#endif /* MENU_H_ */
