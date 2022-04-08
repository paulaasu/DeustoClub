#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "usuario.h"
#include "almacen.h"
#include "pelicula.h"

/*COSAS QUE HACER:
1.- Reservar pelicula-> cambiar la disponibilidad de la película a 0 (UPDATE)
2.- Devolver pelicula-> cambiar la disponibilidad de la película a 1 (UPDATE)
3.- Filtrar película por género

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
	sqlite3_bind_int(stmt, 4, 1); //porque al insertar si o si tiene que estar disponible la película
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
	sqlite3_bind_int(stmt, 4, 1); //porque al insertar si o si tiene que estar disponible la película
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
	printf("Mostrando películas disponibles:\n"); //te muestra el codigo
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("[Cod: %s, Nombre: %s, Precio: %s, Genero: %s, Valoracion: %s, Minutos: %s]\n",sqlite3_column_text(stmt, 0) , sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 4), sqlite3_column_text(stmt, 5), sqlite3_column_text(stmt, 6));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

	sqlite3_close(db);

}
//comprueba si el usuario y contraseña están en la bd y si está te devuelve un 1
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



//hace que la disponibilidad se cambie a 0, es decir, no esté disponible ESTÁ MAL
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
