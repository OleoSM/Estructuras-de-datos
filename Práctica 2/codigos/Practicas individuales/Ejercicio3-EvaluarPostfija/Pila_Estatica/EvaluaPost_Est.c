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
#include "C:\Users\USER\Downloads\Practica2\Ejercicio3-EvaluarPostfija\Estatico\pila_est.c"

// Prototipos de las funciones
int EvalPosfija(elemento * exp);
void cargarFormula(char *formula);

int main()
{
    //Declaración de variable
    int q;

    //Declaración de nuestra pila s
    pila s;

    //Declaración de la cadena e con tamaño 100
    char expresion[100];

    // Inicializamos nuestra pila s
    Initialize(&s);

    // Llamamos a la función que permite digitar la expresión
    cargarFormula(expresion);

    //Imprime el resultado de la evaluación de la expresión
    printf ("\nEl resultado de la expresion es: %d \n", EvalPosfija(expresion));

    return 0;
}

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

