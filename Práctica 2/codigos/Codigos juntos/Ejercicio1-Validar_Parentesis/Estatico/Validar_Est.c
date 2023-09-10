/*
Validar_Est.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los tíos pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que valida los parentesis de una expresión, usando una pila estatica.
-----------------------------------------------------

Compilacion:
Windows: gcc Validar_Est.c -o ValidarEst.exe
Windows: gcc Validar_Est.c -o ValidarEst
*/

// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio1-Validar_Parentesis\Estatico\pila_est.c"

// Prototipos de las funciones
int VerificarParentesis(pila *s, elemento *e);
void cargarFormula(char *formula);


/*
    Cargar Formula (cargarFormula): recibe <- char *(formula);
    cargarFormula(formula)
    Efecto: Función para digitar la expresion y guardarla en una cadena "formula"
*/

void cargarFormula(char *formula)
{
    printf("Ingrese la formula:");
    fflush(stdin); // Limpia la entrada de el bufer
    gets(formula); // Guarda la cadena introducida en "formula"
    return;
}

int VerificarParentesis (pila *s, elemento *e){
    int f;

    for( f=0 ;f < strlen(e) ;f++ ){
        if (e[f] == '(' || e[f] == '[' || e[f] == '{' )
        {Push (s, e[f]);}

        else{
        if (e[f] == ')' ){
        if (Pop(s) != '(')
        return 0;
                    }

        else if (e[f] == ']'){
        if (Pop(s) != '[')
        return 0;
        }

        else if (e[f] == '}'){
        if (Pop(s) != '{')
        return 0;
                             }
            }
                                }

        if (Empty(s))
            return 1;
        else
            return 0;
    }




