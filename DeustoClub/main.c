#include "pelicula.h"
#include <stdlib.h>
#include "usuario.h"
#include <math.h>
#include <stdio.h>

#define MAX_LINE 10

char mostrarMenu(){
	printf("----------------------\n");
	printf("DEUSTOCLUB\n");
	printf("----------------------\n");
	printf("Bienvenido a DeustoClub:\n");
	printf("1.Iniciar sesion\n");
	printf("2.Registrar usuario\n");
	printf("3.Salir\n");

	fflush(stdout);
	char linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	printf("%s", linea);
	return *linea;
}

Usuario inicioSesion(){
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
	printf("Introduce contraseña:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", formato2);
	fflush(stdin);
	int tamanyo2 = strlen(formato2);
	u.contrasenia = (char*)(malloc(sizeof(char)*(tamanyo2+1)));
	strcpy(u.contrasenia, formato2);
	free(formato2);

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
		fflush(stdin);
		int tamanyo = strlen(formato1);
		u.nombre = (char*)(malloc(sizeof(char*)*(tamanyo+1)));
		strcpy(u.nombre, formato1);
		free(formato1);


		printf("Introduce contraseña:\n");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", formato1);
		fflush(stdin);
		int tamanyo2 = strlen(formato1);
		u.contrasenia = (char*)(malloc(sizeof(char)*(tamanyo2+1)));
		strcpy(u.contrasenia, formato1);
		free(formato1);

		printf("Repita la contraseña: \n");
//		fflush(stdout);
//		fgets(str, MAX_LINE, stdin);
//		sscanf(str, "%s", formato1);
//		fflush(stdin);
//		int tamanyo3 = strlen(formato1);
//		char* contraseniaRepe = (char*)(malloc(sizeof(char)*(tamanyo3+1)));
//		strcpy(contraseniaRepe, formato1);
//		while(u.contrasenia!=contraseniaRepe){
//			//aqui deberia repetirtelo hasta poner la contraseña bien?
//			printf("¡ERROR! la contraseña es incorrecta, vuelve a introducirla");
//			printf("Repita la contraseña:\n");
//			fflush(stdout);
//			fgets(str, MAX_LINE, stdin);
//			sscanf(str, "%s", formato1);
//			fflush(stdin);
//			int tamanyo4 = strlen(formato1);
//			char* contraseniaRepe2 = (char*)(malloc(sizeof(char)*(tamanyo2+1)));
//			strcpy(contraseniaRepe2, formato1);
//			free(formato1);
//
//		}

		return u;
}


int main(void) {
//	strcpy(p1.nombre,"Encanto");p1.codPelicula=0;strcpy(p1.disponibilidad,"Disponible");strcpy(p1.genero,"Fantasía");
//	p1.codPelicula = 0; p1.precio= 10.5; p1.valoracion=9.5;
//	imprimirPelicula(p1);

	//TE MUESTRA LOS MENUS Y ESO
	char opcion;
	// con el dowhile al menos se ejecuta una vez lo que esta en el do
	//do{
		opcion = mostrarMenu();
		switch (opcion) {
			case '1': //si pone 1 se inicia sesion
				inicioSesion();
				break;
			case '2': // se registra
				registrarUsuario();
				break;
			case '3': //salir

				break;
			}
		//}while(opcion!="q"); //esto no funciona!!!



	return 0;
}
