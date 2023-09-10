/*
InfijaPostfija_Est.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los tíos pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que convierte una expresión infija a una expresión postfija, utilizando una pila estatica.
-----------------------------------------------------

Compilacion:
Windows: gcc InfijaPostfija_Est.c -o InfijaPostfija_Est.exe
Windows: gcc InfijaPostfija_Est.c -o InfijaPostfija_Est
*/

// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "C:\Users\USER\Downloads\Practica2\Ejercicio2-InfijaPostfija\Estatico\pila_est.c"

// Prototipos de las funciones
void cargarFormula(char *formula);
int isOperand(char ch);
int Prec(char ch);
int infixToPostfix(elemento *expresion);

int main()
{
    //Declaración de variable
    int q;

    //Declaración de nuestra pila s
    pila s;

    //Declaración de la cadena e con tamaño 100
    char e[100];

    // Inicializamos nuestra pila s
    Initialize(&s);

    // Llamamos a la función que permite digitar la expresión
    cargarFormula(e);

    /*Llamamos a la función que convierte la expresión infija
    a expresión postfija */
    infixToPostfix(e);

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

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch)
{
    switch (ch){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

int infixToPostfix(elemento *expresion)
{
    int i, k;
    pila stack;
    Initialize(&stack);

    for (i = 0, k = -1; expresion[i]; ++i){

        if (isOperand(expresion[i]))
            expresion[++k] = expresion[i];

        else if (expresion[i] == '(')
            Push(&stack, expresion[i]);

        else if (expresion[i] == ')'){

            while (!Empty(&stack) && Top(&stack) != '(')
                expresion[++k] = Pop(&stack);

            if (!Empty(&stack) && Top(&stack) != '(')
                return -1;

            else
                Pop(&stack);
        }
        else {
            while (!Empty(&stack) &&
                 Prec(expresion[i]) <= Prec(Top(&stack)))
                expresion[++k] = Pop(&stack);
            Push(&stack, expresion[i]);
        }
    }

    while (!Empty(&stack))
        expresion[++k] = Pop(&stack );

    expresion[++k] = '\0';
    printf( "\nEl resultado de la expresion es: \n %s", expresion);

    return 0;
}
