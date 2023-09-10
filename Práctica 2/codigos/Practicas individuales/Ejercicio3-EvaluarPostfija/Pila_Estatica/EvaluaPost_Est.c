/*
EvaluaPost_Est.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los t�os pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que evalua (calcula) el valor de una expresi�n postfija utilizando una pila estatica.
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
#include "C:\Users\USER\Downloads\Practica2\Ejercicio3-EvaluarPostfija\Estatico\pila_est.c"

// Prototipos de las funciones
int EvalPosfija(elemento * exp);
void cargarFormula(char *formula);

int main()
{
    //Declaraci�n de variable
    int q;

    //Declaraci�n de nuestra pila s
    pila s;

    //Declaraci�n de la cadena e con tama�o 100
    char expresion[100];

    // Inicializamos nuestra pila s
    Initialize(&s);

    // Llamamos a la funci�n que permite digitar la expresi�n
    cargarFormula(expresion);

    //Imprime el resultado de la evaluaci�n de la expresi�n
    printf ("\nEl resultado de la expresion es: %d \n", EvalPosfija(expresion));

    return 0;
}

/*
    Cargar Formula (cargarFormula): recibe <- char *(formula);
    cargarFormula(formula)
    Efecto: Funci�n para digitar la expresion y guardarla en una cadena "formula"
*/

void cargarFormula(char *formula)
{
    printf("Ingrese la formula:");
    fflush(stdin); // Limpia la entrada de el bufer
    gets(formula); // Guarda la cadena introducida en "formula"
    return;
}

int EvalPosfija(elemento *exp){

    pila pilita;
    int i;

    Initialize(&pilita);

    for (i = 0; exp[i]; ++i){

        if (isdigit(exp[i]))
            Push(&pilita, exp[i] - '0');

        else{
            int val1 = Pop(&pilita);
            int val2 = Pop(&pilita);

            switch (exp[i]){

            case '+': Push(&pilita, val2 + val1);
                break;
            case '-': Push(&pilita, val2 - val1);
                break;
            case '*': Push(&pilita, val2 * val1);
                break;
            case '/': Push(&pilita, val2/val1);
                break;
            }
        }
    }

    return Pop(&pilita);
}

