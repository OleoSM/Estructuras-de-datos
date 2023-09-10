/*
EvaluaPost_Din.c
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
/*
    Evalua Postfija (EvalPosfija): recibe <- elemento *(exp); devuelve -> int
    EvalPosfija(exp)
    Efecto: Calcula el valor de una expresi�n postfija
*/
int EvalPosfija(elemento *exp){

    pila pilita; //Declaraci�n pila
    int i; //Declaraci�n iterador

    Initialize(&pilita); //Inicializaci�n de la pila

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




