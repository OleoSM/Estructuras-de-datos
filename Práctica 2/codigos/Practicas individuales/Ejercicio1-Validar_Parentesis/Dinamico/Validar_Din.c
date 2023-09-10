/*
Validar_Din.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los t�os pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que valida los parentesis de una expresi�n, usando una pila dinamica.
-----------------------------------------------------

Compilacion:
Windows: gcc Validar_Din.c -o ValidarDin.exe
Windows: gcc Validar_Din.c -o ValidarDin
*/


// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "C:\Users\USER\Downloads\Practica2\Ejercicio1-Validar_Parentesis\Dinamico\pila_din.c"

// Prototipos de las funciones
int VerificarParentesis(pila *s, char *formula);
void cargarFormula(char *formula);

int main()
{
    /*Declaraci�n de variable para determinar si el programa termino de
    forma correcta*/
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
        puts("La expresion es correcta"); //En caso de que sea correcta
    else
        puts("La expresion incorrecta");//En caso de que sea incorrecta

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
    Verificar Parentesis (VerificarParentesis): recibe <- pila*(s); recibe <- elemento*(e); retorna-> int
    VerificarParentesis (s, e)
    Efecto: Funci�n para verificar si la cantidad de parentesis de una expresi�n es correcta
*/

int VerificarParentesis (pila *s, elemento *e)
{
    int f; //Declaraci�n de iterador

    for( f=0 ;f < strlen(e) ;f++ ){ //Lee la cadena caracter por caracter
        if (e[f] == '(' || e[f] == '[' || e[f] == '{' ) // Busca si hay algun '(', '{' o '['
        {Push (s, e[f]);} // Si cumple con la condici�n lo mete a la pila

        else{
        if (e[f] == ')' ){  //Si encuentra un ')'
        if (Pop(s) != '(')  //Saca de la pila un ')'
        return 0;
         }

        else if (e[f] == ']'){ //Si encuentra un ']'
        if (Pop(s) != '[')     //Saca de la pila un ']'
        return 0;
        }

        else if (e[f] == '}'){ //Si encuentra un '}'
        if (Pop(s) != '{')      //Saca de la pila un '}'
        return 0;
        }
            }
                }

        if (Empty(s))     // Si la pila esta vacia
            return 1;     // Termina de forma incorrecta
        else
            return 0;     //Termina de forma correcta
    }





