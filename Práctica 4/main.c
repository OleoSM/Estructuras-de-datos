/*
                            *******PRACTICA 04: Diccionario con Hashing abierto*******

    Equipo: Los tios Pelones
    Profesor: Franco Martinez Edgardo Adrian
    Grupo: 2CM1
    Integrantes:
        Buendia Velazco Abel
        Hernandez Molina Leonardo Gaell
        Carpio Becerra Erick Gustavo
        Velazquez Diaz Luis Francisco

*/

//Compilacion: gcc TADList.c main.c -o "Programa_Name"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADList.h"



//Compilación: gcc TADList.c main.c -o TH

/*
------PROTOTIPOS DE FUNCIONES------
*/
int IdPal(char *Pal);
void InsertaDef(lista *TH, char *Pal, char *Def);
void menu();
void archivos();
/*
------FUNCION PRINCIPAL------
*/

int main() {

    int opcion=0, respuesta=0, opcion2=0;
    char CadenaAux[CadenaSize];//Cadena temporal para guardar las palabras y su definicion
    char Pal[PalSize], Def[DefSize];
    int i=0,j=0;
    int indice=0, TotalDeColisiones=0;
    char ArchAux[40];
    char *auxq= "Lunfardo.txt";
  FILE *archivo;   //Conexion entre el programa el archivo a manipular
  FILE *PF;
    PF= fopen ("Tu_Diccionario.txt","w");
  lista THC[TablaSize];

  for(int i=0; i<TablaSize; i++){
    Init(&THC[i]);
  }

  do{
    menu();
    printf("\nDIGITE UNA OPCION: ");
    scanf("%d",&opcion);

    switch (opcion) {

      case 1:
    printf("Con que archivo quiere trabar");
    puts ("");
    archivos();
    scanf("%s", &ArchAux);
    archivo = fopen(ArchAux,"r"); //r INDICA QUE ES DE SOLO LECTURA    // //PalabrasEnMaya.txt
    if(archivo == NULL) printf("\nARCHIVO INVALIDO\n");
        else
        {
        while(!feof(archivo))   //devuelve un valor distinto de cero si una operación de lectura ha intentado leer más allá del final del archivo
            {
        fgets(CadenaAux,200,archivo);   //EN CADENAAUX guardamos el string. EN 200 lee esa cantidad de char. EN ARCHIVO es de donde está leyendo las definiciones
        i=0;
        while(CadenaAux[i] != ':')    //mientras que no sean :, entonces lee caracter x caracter y guardala en cadenaaux
            {
        Pal[i] = CadenaAux[i];
        i++;
            }
        Pal[i] = '\0';    //Pone el valor nulo al final de la cadena para indicar que terminó
        i++;              //incrementa i porque insertamos un "caracter" mas
        j=i;              //guardamos en j para no perder el dato

        i=0;              //reiniciamos i en 0
        while(CadenaAux[j] != '\0')   //"HOLA:\0" hasta ahí leyó su definicion
									{
        Def[i] = CadenaAux[j];  // En donde se quedo guardas la definicion que leyó cadena auxiliar del fgets()
        j++;                    //Indica el tamaño total de la palabra y su def (incluidos ambos
        i++;                    //Marca el inicio de la definicion (donde inicia despues de :\0)
            }

        Def[i] = '\0';            //por ultimo, pones caracter final a la definicion

        indice = IdPal(&Pal[0])%TablaSize;    //Obtenemos el valor HASH de la palabra a partir de su ID (suma de valores ASCII de cada CHAR) mòdulo el tam de la TH
        if(Tam_Lista(&THC[indice]) > 1)
        TotalDeColisiones++; //detecta una colision a partir de ver que en la THC es mayor a 1 (porque ya tiene un valor guardado)
        InsertaDef(&THC[indice],&Pal[0],&Def[0]); //Guarda el índice, la palabra y su definicion de UNA palabra
        printf("Palabra) %d \t%s : %s",indice, Pal, Def);//Imprime el índice, la palabra y su definicion de UNA palabra

            }

            }
            break;
			case 2:

        while(getchar() != '\n');   //Mientras lo que leamos NO sea un salto de linea
        printf("\nIngresa la palabra: ");
        gets(Pal);
        fputs(Pal,PF );
        fputs(": ",PF);
        printf ("INTRO.");  //LO USAMOS JUNTO CON EL GETCH POR SI EL USUARIO PONE UN ESPACIO ENTONCES EL PROGRAMA NO LO MARQUE COMO QUE YA AVANZO, SI NO COMO UNA SOLA PALABRA
        while(getchar() != '\n');
        printf("\nIngresa una Definicion: ");
        gets(Def);

        fputs(Def,PF );
        fputs("\n",PF);
        indice = IdPal(&Pal[0])%TablaSize;
        InsertaDef(&THC[indice],&Pal[0],&Def[0]);
        printf("\nIndice: %d \t%s : %s",indice, Pal, Def);

            break;
		 case 3:
        while(getchar() != '\n');
        printf("\nIngresa la palabra: ");
        gets(Pal);
        indice = IdPal(&Pal[0])%TablaSize;  //BUSCA UN ELEMENTO EN LA TH A PARTIR DE SU INDICE
        if(Tam_Lista(&THC[indice]) > 0)
        Buscar_Elemento(&THC[indice],Pal);
        else printf("\nNo existe la palabra.");

        break;
		 case 4:
        while(getchar() != '\n');
        printf("Ingresa la palabra: ");
        gets(Pal);
        indice = IdPal(&Pal[0])%TablaSize;
        if(Tam_Lista(&THC[indice]) > 0)
        CambiaPal(&THC[indice],Pal);
        else printf("\nPALABRA NO REGISTRADA EN LA TH. POR FAVOR INTRODUZCALA PRIMERO.");

        break;

		 case 5:
		while(getchar() != '\n');
		printf("Ingresa la palabra: ");
		scanf ("%s", &Pal);
		indice = IdPal(&Pal[0])%TablaSize;
		if(Tam_Lista(&THC[indice]) > 0)
		Eliminar(&THC[indice], Pal);
		else printf("\nPALABRA NO REGISTRADA EN LA TH. POR FAVOR INTRODUZCALA PRIMERO.");


		 break;
		 case 6:

		printf("\nEstadísticas:\n\n");
		TotalDeColisiones=0;
		for(int i=0; i<TablaSize; i++)
		{
		if(Tam_Lista(&THC[i]) >= 2)
		TotalDeColisiones =TotalDeColisiones + Tam_Lista(&THC[i])-1;

		printf("Lista: %d ",i+1);
		ImpColisiones(&THC[i]);
		printf("\n\n");
							}
		printf("\nNumero de colisiones: %d",TotalDeColisiones);

		 break;
		 case 7:
        printf ("\n\t\t------------NO OLVIDE GUARDAR SU ARCHIVO EN OTRO LUGAR PARA QUE EL PROGRAMA NO LO SOBREESCRIBA LA PROXIMA EJECUCION------------\n\n");
		exit(0);
		break;

      default:
      printf("\nOPCION INVALIDA, PRUEBE DE NUEVO CON LOS VALORES PROPUESTOS");
      break;
    }

    printf("\nINTRODUZCA 1 SI QUIERE SEGUIR EN EL MENU: ");
    scanf("%d",&respuesta);




  }while(respuesta == 1);


  return 0;
}


void BorrarPantalla(){
    system ("cls");
}
int IdPal(char *Pal){

	int SumaNum=0,i=0,Total,sumatotal=0;
	Total=strlen(Pal);
	for (i=0 ; i<Total; i++ ){
        SumaNum=SumaNum +Pal[i];
	}
	return SumaNum;
}

/*Funcion Agregar_Definicion:
	Se copian las cadenas de palabra y definicion
	en una variable de tipo "elment" para insertarlas
	después en la tabla hash dependiendo de
*/
void InsertaDef(lista *TH, char *Pal, char *Def) {

  element E;
	int i=0,j=0;    //Variable para controlar los ciclos

  E.id_palabra = IdPal(Pal); //Guarda el ID de la palabra a partir de la suma de sus valores ASCII de cada letra

	while(Pal[i] != '\0')   //A medida que avance en los caracteres de Pal, no terminará hasta encontrar \0 (FIN DE LA CADENA)
        {
		E.palabra[i] = Pal[i];
		i++;
	}
	E.palabra[i] = '\0';    //Una vez terminado el while, entonces la i queda en la utlima posicion del arreglo, por lo que aprovechamos para meter el final de caracter

	while(Def[j] != '\0'){
		E.significado[j] = Def[j];  //Guarda la definicion en el campo correspondiente a nuestro elemento
		j++;
	}
	E.significado[j] = '\0';    //Una vez terminado el while, entonces la i queda en la utlima posicion del arreglo, por lo que aprovechamos para meter el final de caracter

  Insertar(TH,E); //Insertamos en nuestra TH el elemento E
}

void menu(){ //Funcion que Genera un menu para poder utilizar nuestro programa

	BorrarPantalla();
    puts ("\n--------------MENU--------------\n");

    printf ("\nOpcion 1) Cargar un archivo de definiciones\n");
    printf ("Opcion 2) Agregar una palabra nueva y su definicion\n");
    printf ("Opcion 3) Buscar una palabra y revisar su definicion\n");
    printf ("Opcion 4) Modificar la definicion de una palabra\n");
    printf ("Opcion 5) Eliminar una palabra\n");
    printf ("Opcion 6) Ver estadisticas HASH\n");
    printf ("Opcion 7) SALIR\n");

    puts ("\n--------------------------------\n");

}

void archivos (){
    puts ("\n--------------ARCHIVOS DISPONIBLES--------------\n");

    printf("1) Glosario_BIOQUANTUM.txt\n ");
    printf("2) Lunfardo.txt\n ");
    printf("3) PalabrasEnMaya.txt\n ");
}


