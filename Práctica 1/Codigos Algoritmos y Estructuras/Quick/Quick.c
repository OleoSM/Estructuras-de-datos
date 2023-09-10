#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


void intercambiar(int *A, int i, int j);
int Pivot(int *A, int p, int r);
void QuickSort(int *A,int p, int r);

int main(int argc, char* argv[])
{
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

	QuickSort(A, 0, n-1);

	//Termina medición del tiempo
	t_final = clock();

	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;


	//Enviar a la salida estandar el arreglo final
	printf("\n\nOrdenamiento por Quick:");
	for(i=0;i<n;i++)
		printf("\nA[%d]=%d",i,A[i]);


	//Mostrar el tiempo medido
	printf("\n\nTiempo medido: %.15f segundos.", t_intervalo);
	return 0;
}


/*
void intercambiar(int *A, int i, int j)
Recibe: int * Referencia/Dirección al arreglo A
Devuelve: void (No retorna valor explicito)
Observaciones: Funcion que intercambia los valores que se vayan comparando
*/

void intercambiar(int *A, int i, int j){
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

int Pivot(int *A, int p, int r){
    int i = p + 1; //Segundo elemento del arreglo
    int j = r; //Tam del arreglo
    int piv = A[p]; //El pivote es la primer posicion del arreglo

    while (1)
    {
        while (A[i] < piv && i < r)
            i++;

        while (A[j] > piv)
            j--;

        if (i < j)
            intercambiar(A, i, j);

        else
        {
            intercambiar(A, p, j);
            return j;
        }
    }
}

void QuickSort(int *A,int p, int r){
    if (p < r)
    {
        int j = Pivot(A, p, r); //Se obtiene el pivote
        QuickSort(A, p, j - 1); //Se ordena de 0 al (pivote-1)
        QuickSort(A, j + 1, r); //Se ordena del pivote +1 hasta el final
    }
}
