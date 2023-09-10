/*
Autor: Edgardo Adri�n Franco Mart�nez
Versi�n 1.0 (11 de Septiembre 2012)
Descripci�n: Programa que dibuja un bloque de "*" cuadrado de ANCHO * ALTO en la consola

El programa imprime ALTO filas de *'s columna por columna hasta la columna ANCHO.

Observaciones: El programa requerira de la libreria "presentacion.h", la cu�l tiene las implementaciones
para mover el cursor de la pantalla, esperar un tiempo y borrar pantalla, la compilaci�n debera incluir
las definiciones de las funciones seg�n la plataforma que se este utilizando (Windows o Linux)

Compilaci�n: 	gcc -o marco marco.c presentacion(Win|Lin).o) (Win si se correra en Windows | Lin si se ejecutar� en Linux)  "Si se tiene el c�digo objeto"
				gcc -o marco marco.c presentacion(Win|Lin).c) (Win si se correra en Windows | Lin si se ejecutar� en Linux)  "Si se tiene el c�digo fuente"
Ejecuci�n: Windows marco.exe  &  Linux ./marco
*/
//LIBRERIAS
#include<stdio.h>
#include "presentacion.h"

//CONSTANTES
#define ALTO 8			//Se piensa en un pantalla de 24 filas x 79 columnas
#define ANCHO 6

#define TIEMPO_BASE	3	//Tiempo base en milisegundos

void DibujaCaja(int num, int cliente);

//PROGRAMA PRINCIPAL
int main(void)
{
	int fila,columna;
	//Borrar la pantalla
	BorrarPantalla();
	DibujaCaja(1,7);
	DibujaCaja(2,2);
	DibujaCaja(3,3);
	DibujaCaja(4,30);
	DibujaCaja(5,34);
	DibujaCaja(6,32);
	DibujaCaja(7,82);
	DibujaCaja(8,32);

	return 0;
}

void DibujaCaja(int num, int cliente)
{
	int columna,fila,i;
	//Recorrer cada columna
	for(columna=num+(num*8),i=0;i<ANCHO;columna++,i++)
	{
		//Recorrer cada fila
		for(fila=1;fila<ALTO;fila++)
		{
			//Mover el cursor, dibujar un * y esperar TIEMPO_BASE milisegundos
			MoverCursor(columna,fila);
			printf("*");
			EsperarMiliSeg(100);
		};
	};

	MoverCursor(num+(num*8)+1,2);
	printf("A:%d",cliente);
}
