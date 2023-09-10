/*
InfijaPostfija_Din.c
V 1.0 Noviembre 2022
-----------------------------------------------------
Autores: Los tíos pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
Programa que convierte una expresión infija a una expresión postfija, utilizando una pila dinamica.
-----------------------------------------------------

Compilacion:
Windows: gcc InfijaPostfija_Din.c -o InfijaPostfija_Din.exe
Windows: gcc InfijaPostfija_Din.c -o InfijaPostfija_Din
*/

// Librerias a usar para la ejecucion del programa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "C:\Users\USER\Downloads\Practica2\Ejercicio2-InfijaPostfija\Dinamico\pila_din.c"

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

/*
    Son iguales (isOperand): recibe <- char; retorna -> int;
    isOperand(ch)
    Efecto: Si la letra esta en mayuscula o miniscula le da la misma
    precedencia
*/

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

/*
    Precedencia (Prec): recibe <- char; return -> int;
    Prec(ch)
    Efecto: Asigna un valor de prioridad dependiendo de el caracter
*/

int Prec(char ch)
{
    switch (ch){
        case '+':
        case '-':
            return 1; //Verifica el operador y le da una prioridad de 1

        case '*':
        case '/':
            return 2; //Verifica el operador y le da una prioridad de 2

        case '^':
            return 3; //Verifica el operador y le da una prioridad de 3
    }
    return -1;
}

/*
    Infija a postfija (infixToPostfix): recibe <- elemento *(expresion);
    infixToPostfix(expresion)
    Efecto: Cambia una expresión infija a una expresión postfija
*/

int infixToPostfix(elemento *expresion)
{
    int i, k; //Declaración de iteradores
    pila stack; //Declaración de pila
    Initialize(&stack); //Inicialización de pila

    for (i = 0, k = -1; expresion[i]; ++i){

        if (isOperand(expresion[i])) //Verifica si el caracter es mayuscula o miniscula
            expresion[++k] = expresion[i]; // En ls posición 0(++k) guardas lo que tienes en la posición 1 (i++)

        else if (expresion[i] == '(') // Si el caracter de la posición actual es = '('
            Push(&stack, expresion[i]); // Mete a la pila el caracter

        else if (expresion[i] == ')'){ // Si el caracter de la posición actual es = ')'


            while (!Empty(&stack) && Top(&stack) != '(') // Mientras la pila no este vacia y el tope no sea '('
                expresion[++k] = Pop(&stack); //En el pre incremento (++k) se guarda el ultimo caracter de la pila (tope)

            if (!Empty(&stack) && Top(&stack) != '(') //Si la pila no este vacia y el tope no sea '(' (despues de el ciclo)
                return -1; //El programa termina de manera incorrecta

            else // En caso de que no se cumpla
                Pop(&stack); // Saca el caracter de la pila
        }
        else {
            while (!Empty(&stack) &&                        //Mientras la pila no sea vacia
                 Prec(expresion[i]) <= Prec(Top(&stack)))   // y la precedencia de el operador actual sea menor a la precedencia del tope
                expresion[++k] = Pop(&stack);    // En el pre incremento (++k) se guarda el ultimo caracter de la pila (tope)
            Push(&stack, expresion[i]);          // Metemos el caracter a la pila
        }
    }

    while (!Empty(&stack))      //Mientras la pila no sea vacia
        expresion[++k] = Pop(&stack ); //En el pre incremento (++k) se guarda el ultimo caracter de la pila (tope)

    expresion[++k] = '\0';      //Guarda el final la cadena utilizando el caracter nulo '\'
    printf( "\nEl resultado de la expresion es: \n %s", expresion);

    return 0;
}
