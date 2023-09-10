/*
EvaluaPost_Est.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los tíos pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que evalua (calcula) el valor de una expresión postfija utilizando una pila estatica.
-----------------------------------------------------

Compilacion:
Windows: gcc EvaluaPost_Est.c -o EvaluaPost_Est.exe
Windows: gcc EvaluaPost_Est.c -o EvaluaPost_Est
*/

// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>


// Prototipos de las funciones
int EvalPosfija(elemento * exp);
void cargarFormula(char *formula);

