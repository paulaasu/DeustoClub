/*
 * menu.c
 *
 *  Created on: 8 abr 2022
 *      Author: IKER MARCELO
 */

#include <stdlib.h>
#include "usuario.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINE 30
#include "menu.h"
#include "almacen.h"
#include "bd.h"

int comprobarcontrasenya(char* c1, char* c2){
	int correcto = 1;
	if (strcmp(c1, c2)) {
		correcto = 0;
	}
	return correcto;
}
void mostrarMenu(Almacen a){
	char c;
	printf("----------------------\n");
	printf("DEUSTOCLUB\n");
	printf("----------------------\n");
	printf("Bienvenido a DeustoClub:\n");
	do{

	if (c == '1') {
		fflush(stdin);
		inicioSesion(a);
	}

	if (c == '2') {
		fflush(stdin);
		anyadirUsuario(registrarUsuario());
	}

	if(c != '\n'){
		printf("1.Iniciar sesion\n");
		printf("2.Registrar usuario\n");
		printf("3.Salir\n");
	}

	fflush(stdout);
	c = getchar();

	}while(c != '3' );
	printf("ACABADO \n");
}


Usuario inicioSesion(Almacen a){
	printf("----------------------\n");
	printf("INICIO SESION\n");
	printf("----------------------\n");
	char str[MAX_LINE];
	Usuario u;

	char *formato1 = (char*)(malloc(sizeof(char*)*(MAX_LINE)));
	printf("Introduce el usuario:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", formato1);
	fflush(stdin);
	int tamanyo = strlen(formato1);
	u.nombre = (char*)(malloc(sizeof(char*)*(tamanyo+1)));
	strcpy(u.nombre, formato1);
	free(formato1);

	char *formato2 = (char*)(malloc(sizeof(char*)*(MAX_LINE)));
	printf("Introduce contrase�a:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", formato2);
	fflush(stdin);
	int tamanyo2 = strlen(formato2);
	u.contrasenia = (char*)(malloc(sizeof(char)*(tamanyo2+1)));
	strcpy(u.contrasenia, formato2);
	free(formato2);
	int comprobar = comprobarUsuario(u.nombre, u.contrasenia);
//	int comprobarAdmin = comprobarUsuarioAdmin(u.nombre, u.contrasenia);
	if(comprobar != 1){
	printf("Usuario incorrecto \n");
	}
	else if(strcmp(u.nombre, "admin") == 0 && strcmp(u.contrasenia, "admin") == 0){
	mostrarMenuAdmin(a);
	}else{
	menuPrincipal(a);
	}
	return u;

}
Usuario registrarUsuario(){
	printf("----------------------\n");
		printf("REGISTRO USUARIO\n");
		printf("----------------------\n");
		char str[MAX_LINE];
		Usuario u;

		char *formato1 = (char*)(malloc(sizeof(char*)*(MAX_LINE)));
		printf("Introduce el nombre de usuario:\n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", formato1);
		int tamanyo = strlen(formato1);
		u.nombre = (char*)(malloc(sizeof(char*)*(tamanyo+1)));
		strcpy(u.nombre, formato1);


		printf("Introduce contrase�a:\n");

		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", formato1);
		int tamanyo2 = strlen(formato1);

		char* contrasenia = (char*)(malloc(sizeof(char)*(tamanyo2+1)));
		strcpy(contrasenia, formato1);

		printf("Repita la contrase�a: \n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", formato1);
		int tamanyo3 = strlen(formato1);
		char* contraseniaRepe = (char*)(malloc(sizeof(char)*(tamanyo3+1)));
		strcpy(contraseniaRepe, formato1);
//		printf("Contrasenia: %s \n", contrasenia);
//		printf("ContraseniaRepe: %s \n", contraseniaRepe);
		int correcta = comprobarcontrasenya(contrasenia, contraseniaRepe);
//		printf("Correcta: %i", correcta);

		while(correcta != 1){
			printf("�ERROR! la contrase�a es incorrecta, vuelve a introducirla \n");
			printf("Repita la contrase�a:\n");
			fflush(stdout);
			fgets(str, MAX_LINE, stdin);
			sscanf(str, "%s", formato1);
			int tamanyo4 = strlen(formato1);
			contraseniaRepe = (char*)(malloc(sizeof(char)*(tamanyo4+1)));
			strcpy(contraseniaRepe, formato1);
			correcta = comprobarcontrasenya(contrasenia, contraseniaRepe);
		}
		if (correcta == 1) {
			u.contrasenia = contrasenia;
		}

		printf("Usuario registrado correctamente!\n");



		return u;
}


void menuPrincipal(Almacen a){

	char c;
		printf("...........................\n");
		printf("Bienvenido a DeustoClub!\n");
		printf("...........................\n");
	do{

	if (c == '1') {
		fflush(stdin);
		visualizarPeliculasDisp();
	}

	if (c == '2') {
		fflush(stdin);
		introducirPeliAlq();

	}
	if (c == '4') {
		fflush(stdin);
		mostrarMenuFiltro(a);

	}

	if(c != '\n'){
		printf("1. Visualizar pel�culas disponibles\n");
		printf("2. Alquilar pel�cula\n");
		printf("3. Devolver pel�cula\n");
		printf("4. Filtrar pel�cula\n");
		printf("5. Volver\n");
	}

	fflush(stdout);
	c = getchar();

	}while(c != '5' );
	printf("ACABADO \n");
}
void mostrarMenuFiltro(Almacen a){

	char c;
	printf("----------------------\n");
	printf("FILTROS\n");
	printf("----------------------\n");
	printf("Eliga un filtro:\n");
	do{

	if (c == '1') {
		fflush(stdin);
		mostrarMenuGenero(a);

	}

	if (c == '2') {
		fflush(stdin);
		char str[MAX_LINE];
		float precio;

		//char formato1 = (char)(malloc(sizeof(char*)*(MAX_LINE)));
		printf("Precio maximo: \n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%f", &precio);
		filtrarPrecioMax(a, precio);




	}

	if(c != '\n'){
		printf("1.G�nero\n");
		printf("2.Precio m�ximo\n");
		printf("3.Volver\n");
	}

	fflush(stdout);
	c = getchar();

	}while(c != '3' );
	printf("ACABADO \n");
}
void mostrarMenuGenero(Almacen a){

	char c;
	printf("----------------------\n");
	printf("GENEROS\n");
	printf("----------------------\n");
	printf("Eliga un genero:\n");
	do{

	if (c == '1') {
		fflush(stdin);
		filtrarGenero(a, 1);

	}

	if (c == '2') {
		fflush(stdin);
		filtrarGenero(a, 2);

	}
	if (c == '3') {
		fflush(stdin);
		filtrarGenero(a, 3);

	}

	if (c == '4') {
		fflush(stdin);
		filtrarGenero(a, 4);

	}
	if (c == '5') {
		fflush(stdin);
		filtrarGenero(a, 5);

	}

	if (c == '6') {
		fflush(stdin);
		filtrarGenero(a, 6);

	}

	if(c != '\n'){
		printf("1.Ciencia ficci�n\n");
		printf("2.Aventura\n");
		printf("3.Romance\n");
		printf("4.Terror\n");
		printf("5.Comedia\n");
		printf("6.Thriller\n");
		printf("7.Volver\n");
	}

	fflush(stdout);
	c = getchar();

	}while(c != '7' );
	printf("ACABADO \n");
}

int introducirPeliAlq(){
	char str[MAX_LINE];
	int codP;

	printf("Introduce el c�digo de pel�cula que quieres alquilar:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &codP);

	return codP;

}

void mostrarMenuAdmin(Almacen a){
	char c;
	printf("----------------------\n");
	printf("DEUSTOCLUB\n");
	printf("----------------------\n");
	printf("Bienvenido al menu Administrador:\n");
	do{

	if (c == '1') {
		fflush(stdin);
		anyadirPelicula(anyadirPeli());
}

	if (c == '2') {
		fflush(stdin);
		eliminarPelicula(eliminarPeli(a));
}
	if (c == '3') {
		fflush(stdin);
		escFich();
	}


	if(c != '\n'){
	printf("1.A�adir peliculas \n");
	printf("2.Borrar peliculas \n");
	printf("3.Escribir fichero \n");
	printf("4.Salir\n");
	}

	fflush(stdout);
	c = getchar();

	}while(c != '4' );
	printf("ACABADO \n");
}

Pelicula anyadirPeli(){
		char str[MAX_LINE];
		Pelicula peli;
		int max = buscarMaxCodPel();
		int cod= max+1;

		peli.codPelicula = cod;

		char *formato1 = (char*)(malloc(sizeof(char*)*(MAX_LINE)));
		printf("Nombre pel�cula:\n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", formato1);
		fflush(stdin);
		int tamanyo = strlen(formato1);
		peli.nombre = (char*)(malloc(sizeof(char*)*(tamanyo+1)));
		strcpy(peli.nombre, formato1);
		free(formato1);

		float precio;
		printf("Precio:\n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%f", &precio);
		fflush(stdin);
		peli.precio = precio;

		peli.disponibilidad=1; //la disponibilidad es 1


		printf("Introduce el numero del g�nero:\n");
		printf("1.Ciencia ficci�n\n");
		printf("2.Aventura\n");
		printf("3.Romance\n");
		printf("4.Terror\n");
		printf("5.Comedia\n");
		printf("6.Thriller\n");
		int genero;
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%i", &genero);
		fflush(stdin);
		peli.genero=genero;

		float valoracion;
		printf("Valoraci�n:\n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%f", &valoracion);
		fflush(stdin);
		peli.valoracion = valoracion;

		int minutos;
		printf("Duraci�n en minutos:\n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%i", &minutos);
		fflush(stdin);
		peli.minutos = minutos;

		return peli;
}

Pelicula eliminarPeli(Almacen a){
	char str[MAX_LINE];
	Pelicula peli;

	int cod_p;
	printf("Introduce el codigo de la pelicula que deseas eliminar:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &cod_p);
	fflush(stdin);
	for (int var = 0; var < a.numPeliculas; ++var) {
		if (a.ArrayP[var].codPelicula==cod_p) {
			peli = a.ArrayP[var];
		}
	}
return peli;
}
void escFich(){
		FILE* f;
		Usuario * au;
		au = arrayUsuarios(numUsuario);
		f = fopen("usuario.txt", "w");
		fprintf(f, "-------------- \n");
		fprintf(f, "Gastos por usuario \n");
		fprintf(f, "-------------- \n");
		for (int var = 0; var < numUsuario() ; ++var) {
			fprintf(f, "%s-----%f\n", au[var].nombre, au[var].gastado);
		}
		printf("Datos guardados correctamente\n");
		fclose(f);
}
