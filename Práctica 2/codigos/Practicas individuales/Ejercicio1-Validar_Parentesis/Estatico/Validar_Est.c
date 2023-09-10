/*
Validar_Est.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los t�os pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que valida los parentesis de una expresi�n, usando una pila estatica.
-----------------------------------------------------

Compilacion:
Windows: gcc Validar_Est.c -o ValidarEst.exe
Windows: gcc Validar_Est.c -o ValidarEst
*/

// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "C:\Users\USER\Downloads\Practica2\Ejercicio1-Validar_Parentesis\Estatico\pila_est.c"

// Prototipos de las funciones
int VerificarParentesis(pila *s, elemento *e);
void cargarFormula(char *formula);

int main()
{
    //Declaraci�n de variable
    int q;

    //Declaraci�n de nuestra pila s
    pila s;

    //Declaraci�n de la cadena e con tama�o 100
    char e[100];

    // Inicializamos nuestra pila s
    Initialize(&s);

    // Llamamos a la funci�n que permite digitar la expresi�n
    cargarFormula(e);

    /*Llamamos a la funci�n encargada de evaluar si la
    expresi�n es correcta o no */
    q=VerificarParentesis(&s,e);

    //Condicion que nos ayuda a evaluar si la expresi�n es correcta
    if (q==1)
        puts("La expresion es correcta");
    else
    puts("La expresion incorrecta");

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




