#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void Merge(int *A, int p, int q, int r);
void MergeSort(int *A, int p, int r);

int main(int argc, char* argv[])
{
    //Compleidad de O NLogN
    //Variables para la medición de tiempos
    clock_t t_inicio, t_final;
    double t_intervalo;

	//Variables para el algoritmo
	int i,j,n,*A;

	//Recibir por argumento el tamaño de n y el valor a buscar
	if (argc!=2)
	{
		printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	//Tomar el argumento del main
	n=atoi(argv[1]); //n

	//Apartar memoria para n números  enteros
	A=malloc(n*sizeof(int));
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);
		exit(1);
	}

	//Leer de la entrada estandar los n valores y colocarlos en el arreglo de números
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

	//*****************************************
	//Algoritmo a medir el tiempo
	//*****************************************
	//Inicia medición del tiempo
	t_inicio = clock();

	//Llamar al algoritmo

	MergeSort(A, 0, n-1);

	//Termina medición del tiempo
	t_final = clock();

	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;


	//Enviar a la salida estandar el arreglo final
	printf("\n\nOrdenamiento por Merge:");
	for(i=0;i<n;i++)
		printf("\nA[%d]=%d",i,A[i]);


	//Mostrar el tiempo medido
	printf("\n\nTiempo medido: %.15f segundos.", t_intervalo);
	return 0;
}


/*
void Algoritmo(int *arreglo,int size)
Recibe: int * Referencia/Dirección al arreglo A, int tamaño del arreglo
Devuelve: void (No retorna valor explicito)
Observaciones: Función que revierte el orden de los valores de A (voltea el arreglo)
y posteriormente pierde tiempo en razón de O(n^3)
*/
void Merge(int *A, int p, int q, int r){ //A= Arreglo desordenado
    int *C; //Arreglo auxiliar           //P= Parte izquierda
                                         //Q= Tamaño del arreglo
    //Variables para los ciclos          //R= Parte derecha
    int l, i, j;
    l = r - p + 1;//Inicio del arreglo
    i = p; //Parte izquierda
    j = q + 1; //Parte derecha
    C = malloc(sizeof(int) * (l + 2)); //Espacio en memoria para guarda el arreglo que  vaya ordenando

    for (int k = 0; k <= l; k++)
    {
        if (i <= q && j <= r)
        {
            if (A[i] < A[j])
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = A[j];
                j++;
            }
        }
        else
        {
            if (i <= q)
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = A[j];
                j++;
            }
        }
    }

    //Terminando de ordenar los numeros, se pasan los numeros del arreglo temporal al arreglo donde se van almacenar todos los numeros a ordenar
    int o = 0;
    for (int m = p; m <= r; m++)
    {
        A[m] = C[o];
        o++;
    }

}

void MergeSort(int *A, int p, int r){
    int q;
    if (p < r)
    {
        q = trunc((p + r) / 2); //Se obtiene la mitad (parte entera) del arreglo

        //Recursividad hasta llegar a 2 elementos
        MergeSort(A, p, q);     //Se ordenan de 0 a la mitad del arreglo
        MergeSort(A, q + 1, r); //Se ordenan de la mitad al final del arreglo
        Merge(A, p, q, r);      //Junta los mini arreglos que se van arreglando
    }


}
