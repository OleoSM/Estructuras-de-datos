#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdlib.h>

#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio1-Validar_Parentesis\Estatico\Validar_Est.c"
#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio1-Validar_Parentesis\Dinamico\Validar_Din.c"

#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio2-InfijaPostfija\Dinamico\InfijaPostfija_Din.c"
#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio2-InfijaPostfija\Estatico\InfijaPostfija_Est.c"

#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio3-EvaluarPostfija\Pila_Dinamica\EvaluaPost_Din.c"
#include "C:\Users\leona\OneDrive\Escritorio\Practica2\Ejercicio3-EvaluarPostfija\Pila_Estatica\EvaluaPost_Est.c"
void menu_vis();
int validaest ();
int validadin ();
int InfPosEst();
int InfPosDin();
int EvaluaPostEst();
int EvaluaPostDin();

void MenuPro();
int main (){
    int valor;
     menu_vis();
    puts("Digite una opcion: ");
    scanf ("%d",&valor);
    system("cls");



    MenuPro(valor);

}




void menu_vis (){
printf ("BIENVENIDO AL MENU DE SELECCION\n");

puts("----------------------------------------------\n");

printf ("Opcion 1: Verificar parentesis estatico\n");
printf ("Opcion 2: Verificar parentesis dinamico\n");

puts("----------------------------------------------\n");

printf ("Opcion 3: Expresion infija a postfija estatico\n");
printf ("Opcion 4: Expresion infija a postfija dinamico\n");

puts("----------------------------------------------\n");

printf ("Opcion 5: Evaluar expresion postfija estatico\n");
printf ("Opcion 6: Evaluar expresion postfija dinamico\n");

puts("----------------------------------------------\n");

printf ("Opcion 7: Salir del programa\n");

puts("");




}

void MenuPro (int valor){

switch (valor){
case 1:
    validaest();
    break;

case 2:
    validadin();
    break;

case 3:
    InfPosEst();
    break;

case 4:
    InfPosDin();
    break;

case 5:
    EvaluaPostEst();
    break;

case 6:
    EvaluaPostDin();
    break;

case 7:
    exit(1);
    break;
}

    }


int validaest (){
    printf ("Opcion 1: Verificar parentesis estatico\n");
    char opcion;
    int q;
    pila s;
    char e[100];
    Initialize(&s);
    cargarFormula(e);

    q=VerificarParentesis(&s,e);
    if (q==1)
        puts("La expresion es correcta\n");
    else
    puts("La expresion es incorrecta\n");


	printf ("Desea agregar otra formula? [S/N]");
	scanf("%c",&opcion);
	system ("cls");

	if (opcion == 'S' || opcion == 's'){
        validaest();}

    else if (opcion == 'N' || opcion == 'n'){
    system ("cls");
    main();
}}

int validadin (){

printf ("Opcion 2: Verificar parentesis dinamico\n");
    char opcion;
    int q;
    pila s;
    char e[100];
    Initialize(&s);
    cargarFormula(e);
    q=VerificarParentesis(&s,e);
    if (q==1)
        puts("La expresion es correcta\n");
    else
        puts("La expresion es incorrecta\n");


	printf ("Desea agregar otra formula? [S/N]");
	scanf("%c",&opcion);
	system ("cls");

	if (opcion == 'S' || opcion == 's'){
        validadin(); }

    else if (opcion == 'N' || opcion == 'n'){
    system ("cls");
    main();
    }


}

int InfPosEst(){
    char opcion;
    printf ("Opcion 3: Expresion infija a postfija estatico\n");
    int q;
    pila s;
    char e[100];
    Initialize(&s);
    cargarFormula(e);
    infixToPostfix(e);


	printf ("Desea agregar otra formula? [S/N]");
	scanf("%c",&opcion);
	system ("cls");

	if (opcion == 'S' || opcion == 's'){
        InfPosEst();}

    else if (opcion == 'N' || opcion == 'n'){
    system ("cls");
    main();
}}


int InfPosDin(){
    char opcion;
    printf ("Opcion 4: Expresion infija a postfija dinamico\n");
    int q;
    pila s;
    char e[100];
    Initialize(&s);
    cargarFormula(e);
    infixToPostfix(e);

	printf ("Desea agregar otra formula? [S/N]");
	scanf("%c",&opcion);
	system ("cls");

	if (opcion == 'S' || opcion == 's'){
        InfPosDin();}

    else if (opcion == 'N' || opcion == 'n'){
    system ("cls");
    main();

}}

int EvaluaPostEst(){
    char opcion;
    printf ("Opcion 5: Evaluar expresion postfija estatico\n");
    int q;
    pila s;
    char expresion[100];
    Initialize(&s);
    cargarFormula(expresion);
    printf ("\nEl resultado de la expresion es: %d \n", EvalPosfija(expresion));


	printf ("Desea agregar otra formula? [S/N]");
	scanf("%c",&opcion);
	system ("cls");

	if (opcion == 'S' || opcion == 's'){
        EvaluaPostEst();}

    else if (opcion == 'N' || opcion == 'n'){
    system ("cls");
    main();
}}

int EvaluaPostDin(){
    char opcion;
    printf ("Opcion 6: Evaluar expresion postfija dinamico\n");
    int q;
    pila s;
    char expresion[100];
    Initialize(&s);
    cargarFormula(expresion);
    printf ("\nEl resultado de la expresion es: %d \n", EvalPosfija(expresion));


	printf ("Desea agregar otra formula? [S/N]");
	scanf("%c",&opcion);
	system ("cls");

	if (opcion == 'S' || opcion == 's'){
        EvaluaPostDin();}

    else if (opcion == 'N' || opcion == 'n'){
    system ("cls");
    main();
}
    }

