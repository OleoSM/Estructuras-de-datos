#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
                INTEGRANTES
        Equipo: Los tíos pelones
        Grupo: 2CM1
        Buendía Velazco Abel
        Carpio Becerra Erick Gustavo
        Hernandez Molina Leonardo Gaell
        Velazquez Diaz Luis Francisco


*/


//Definición de variables para el algoritmo
#define TRUE 1
#define FALSE 0

//Prototipo de la función
void BurbujaOptimizada(int *A,int n);

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

	BurbujaOptimizada(A,n);

	//Termina medición del tiempo
	t_final = clock();

	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;


	//Enviar a la salida estandar el arreglo final
	printf("\n\nOrdenamiento por burbuja optimizada:");
	for(i=0;i<n;i++)
		printf("\nA[%d]=%d",i,A[i]);


	//Mostrar el tiempo medido
	printf("\n\nTiempo medido: %.15f segundos.", t_intervalo);
	return 0;
}


/*
void BurbujaOptimizada(int *A,int n)
Recibe: int * Referencia/Dirección al arreglo A, int tamaño del arreglo
Devuelve: void (No retorna valor explicito)
Observaciones: Programa que realiza el ordenamiento de un arreglo en orden de complejidad  O(n^2)
*/

//Algoritmo de ordenamiento "Burbuja optimizada"
void BurbujaOptimizada(int *A,int n)
{
	int i=0,aux, cambios = 1;
	int j,k;

    while(i<=(n-1) && cambios==1){
            cambios = 0;
            for (j=0;j<(n-1)-i; j++){

                if (A[j] < A[j+1]){

                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                cambios = 1;

                }
            }

            i++;
	}

	//Voltear el arreglo O(n), ya que el pseudocodigo nos da el ordenamiento invertido
	for(i=0,j=n-1;i<n/2;i++,j--)
	{
		aux=A[i];
		A[i]=A[j];
		A[j]=aux;
	}


	return;
}

