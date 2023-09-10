/*
EvaluaPost_Din.c
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
Windows: gcc EvaluaPost_Din.c -o EvaluaPost_Din.exe
Windows: gcc EvaluaPost_Din.c -o EvaluaPost_Din
*/

// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "C:\Users\USER\Downloads\Practica2\Ejercicio3-EvaluarPostfija\Dinamico\pila_din.c"

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
/*
    Evalua Postfija (EvalPosfija): recibe <- elemento *(exp); devuelve -> int
    EvalPosfija(exp)
    Efecto: Calcula el valor de una expresión postfija
*/
int EvalPosfija(elemento *exp){

    pila pilita; //Declaración pila
    int i; //Declaración iterador

    Initialize(&pilita); //Inicialización de la pila

    for (i = 0; exp[i]; ++i){

        if (isdigit(exp[i]))        //Si el caracter que se esta leyendo es un digito, lo transforma a un caracter
            Push(&pilita, exp[i] - '0'); //Lo mete a la pila

        else{
            int val1 = Pop(&pilita); //Guarda el ultimo digito de pila
            int val2 = Pop(&pilita);

            switch (exp[i]){ //Evalua el operador

            case '+': Push(&pilita, val2 + val1); //En caso que el operador sea '+', se suman los 2 digitos guardados
                break;
            case '-': Push(&pilita, val2 - val1); //En caso que el operador sea '-', se restan los 2 digitos guardados
                break;
            case '*': Push(&pilita, val2 * val1); //En caso que el operador sea '*', se multiplican los 2 digitos guardados
                break;
            case '/': Push(&pilita, val2/val1); //En caso que el operador sea '/', se dividen los 2 digitos guardados
                break;
            }
        }
    }

    return Pop(&pilita); //Retorna el ultimo elemento de la pila
}




