#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>
#include "usuario.h"
#include "almacen.h"
#include "pelicula.h"

/*COSAS QUE HACER:
1.- Reservar pelicula-> cambiar la disponibilidad de la pel�cula a 0 (UPDATE)
2.- Devolver pelicula-> cambiar la disponibilidad de la pel�cula a 1 (UPDATE)
3.- Filtrar pel�cula por g�nero

*/

void anyadirUsuario(Usuario u){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("BaseDeDatos", &db);
	/* --- INSERT --- */
	char sql1[] = "insert into usuario (usuario, contrasnya, gastado) values (?, ?, ?)";
	int gastado = 0;

	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, u.nombre, strlen(u.nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, u.contrasenia, strlen(u.contrasenia), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, gastado);


	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error en el usuario registrado!\n");
	}else{
		printf("Usuario correctamente registrado\n");
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

void anyadirPelicula(Pelicula p){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("BaseDeDatos", &db);

	char sql1[] = "insert into pelicula(cod_p, nombre, precio, disponibilidad, genero, valoracion, minutos) values (?, ?, ?, ?, ?, ? ,?)";


	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, p.codPelicula);
	sqlite3_bind_text(stmt, 2, p.nombre, strlen(p.nombre), SQLITE_STATIC);
	sqlite3_bind_double(stmt, 3, p.precio);
	sqlite3_bind_int(stmt, 4, 1); //porque al insertar si o si tiene que estar disponible la pel�cula
	sqlite3_bind_int(stmt, 5, p.genero);
	sqlite3_bind_int(stmt, 6, p.valoracion);
	sqlite3_bind_int(stmt, 7, p.minutos);


	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error en el usuario registrado!\n");
	}else{
		printf("Usuario correctamente registrado\n");
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}
void updatePelicula(Pelicula p){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("BaseDeDatos", &db);
	int codigo = p.codPelicula;
	char sql2[] = "delete from pelicula where cod_p = codigo";
	char sql1[] = "insert into pelicula(cod_p, nombre, precio, disponibilidad, genero, valoracion, minutos) values (?, ?, ?, ?, ?, ? ,?)";

	sqlite3_prepare_v2(db, sql2, strlen(sql2) + 1, &stmt, NULL);

	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, p.codPelicula);
	sqlite3_bind_text(stmt, 2, p.nombre, strlen(p.nombre), SQLITE_STATIC);
	sqlite3_bind_double(stmt, 3, p.precio);
	sqlite3_bind_int(stmt, 4, 1); //porque al insertar si o si tiene que estar disponible la pel�cula
	sqlite3_bind_int(stmt, 5, p.genero);
	sqlite3_bind_int(stmt, 6, p.valoracion);
	sqlite3_bind_int(stmt, 7, p.minutos);


	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error en el usuario registrado!\n");
	}else{
		printf("Usuario correctamente registrado\n");
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

void visualizarPeliculasDisp(){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;
	sqlite3_open("BaseDeDatos", &db);
	int dispo=1;

	char sql2[] = "select cod_p, pelicula.nombre, precio, disponibilidad, generos.nombre, valoracion, minutos from pelicula, generos where disponibilidad=? and pelicula.cod_p=generos.cod;";

	sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, dispo);

	printf("\n");
	printf("Mostrando pel�culas disponibles:\n"); //te muestra el codigo
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("[Cod: %s, Nombre: %i, Precio: %s, Genero: %s, Valoracion: %s, Minutos: %s]\n",sqlite3_column_text(stmt, 0) , sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 4), sqlite3_column_text(stmt, 5), sqlite3_column_text(stmt, 6));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

	sqlite3_close(db);

}
//comprueba si el usuario y contrase�a est�n en la bd y si est� te devuelve un 1
int comprobarUsuario(char *u, char *c){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;
	sqlite3_open("BaseDeDatos", &db);
	int usuario=0;

	char sql2[] = "select * from usuario where usuario=? and contrasnya=?;";

	sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, u, strlen(u), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, c, strlen(c), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if(result == SQLITE_ROW){
		usuario=1;
	}
	sqlite3_finalize(stmt);

	sqlite3_close(db);
	return usuario;

}

//a�ade a la tabla alquilar el usuario y pelicula y el codigo alquiler
void alqPelicula(Usuario u, Pelicula p, int codAlquiler){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("BaseDeDatos", &db);
	/* --- INSERT --- */
	char sql1[] = "insert into alquiler(cod_alquiler, cod_pelicula, usuario) values (?, ?, ?)";
	int gastado = 0;

	sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, codAlquiler);
	sqlite3_bind_int(stmt, 2, p.codPelicula);
	sqlite3_bind_text(stmt, 3, u.nombre, strlen(u.nombre), SQLITE_STATIC);



	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error al alquilar la pel�cula!\n");
	}else{
		printf("Pel�cula alquilada correctamente\n");
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

int numPelis(){
	sqlite3 *db;
		sqlite3_stmt *stmt;
		int result;
		sqlite3_open("BaseDeDatos", &db);
		int dispo=1;

		////////////////////////
		int numPelis = 0;

		////////////////////////

		char sql2[] = "select cod_p, nombre, precio, disponibilidad, genero, valoracion, minutos from pelicula where disponibilidad=?;";

		sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL) ;
		sqlite3_bind_int(stmt, 1, dispo);

		printf("\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
			numPelis++;
			}
		} while (result == SQLITE_ROW);
	//	return arrayP;
		sqlite3_finalize(stmt);
		return numPelis;
		sqlite3_close(db);

}

//devuelve un array de peliculas de todas las peliculas de la bd
Pelicula* devolPelicula(int numPelis){
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;
	sqlite3_open("BaseDeDatos", &db);
	int dispo=1;

	////////////////////////
	int numPelis2=0;
	Pelicula *arrayP;
	arrayP = (Pelicula*)(malloc(sizeof(Pelicula)*numPelis));

	////////////////////////

	char sql2[] = "select cod_p, nombre, precio, disponibilidad, genero, valoracion, minutos from pelicula where disponibilidad=?;";

	sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, dispo);

	printf("\n");
	//printf("Mostrando pel�culas disponibles:\n"); //te muestra el codigo
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			Pelicula peli;
		//	peli.nombre = (char*)(malloc(sizeof(char)* strlen(sqlite3_column_text(stmt, 1))));
			peli.nombre = (char*)sqlite3_column_text(stmt, 1);
		//	strcpy(peli.nombre, sqlite3_column_text(stmt, 1));
			peli.codPelicula = sqlite3_column_int(stmt, 0);
			peli.precio = sqlite3_column_double(stmt, 2);
			peli.genero = sqlite3_column_int(stmt, 4);
			peli.valoracion = sqlite3_column_double(stmt, 5);
			peli.disponibilidad = sqlite3_column_int(stmt, 3);
			peli.minutos = sqlite3_column_int(stmt, 4);

			arrayP[numPelis2].nombre= (char*)(malloc(sizeof(char)*strlen(peli.nombre)));
			strcpy(arrayP[numPelis2].nombre, peli.nombre);
			arrayP[numPelis2].codPelicula= peli.codPelicula;
			arrayP[numPelis2].precio= peli.precio;
			arrayP[numPelis2].genero= peli.genero;
			arrayP[numPelis2].valoracion= peli.valoracion;
			arrayP[numPelis2].disponibilidad= peli.disponibilidad;
			numPelis2++;

		}
	} while (result == SQLITE_ROW);

	sqlite3_finalize(stmt);

	return arrayP;
	sqlite3_close(db);

}


//hace que la disponibilidad se cambie a 0, es decir, no est� disponible EST� MAL
//void reservarPelicula(Pelicula p){
//	sqlite3 *db;
//	sqlite3_stmt *stmt;
//	int result;
//
//	sqlite3_open("BaseDeDatos", &db);
//	/* --- INSERT --- */
//	int disponibilidadN=0;
//	char sql1[] = "update pelicula set disponibilidad="+ disponibilidadN +" where cod_p= " + p.codPelicula+" ;";
//
//
//	result = sqlite3_step(stmt);
//	if (result != SQLITE_DONE) {
//		printf("Error en el usuario registrado!\n");
//	}else{
//		printf("Usuario correctamente registrado\n");
//	}
//
//	sqlite3_finalize(stmt);
//
//}
