//El actual es menor que el anterior? Si la respuesta es sí entonces intercambia

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

//Prototipo de la función
void Inserccion(int *A,int n);

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

	Inserccion(A,n);

	//Termina medición del tiempo
	t_final = clock();

	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;


	//Enviar a la salida estandar el arreglo final
	printf("\n\nOrdenamiento por insercion:");
	for(i=0;i<n;i++)
		printf("\nA[%d]=%d",i,A[i]);


	//Mostrar el tiempo medido
	printf("\n\nTiempo medido: %.15f segundos.", t_intervalo);
	return 0;
}


/*
void Inserccion(int *A,int n)
Recibe: int * Referencia/Dirección al arreglo A, int tamaño del arreglo
Devuelve: void (No retorna valor explicito) dado que solo cambia de posicion los valores
Observaciones: Función que revierte el orden de los valores de A (voltea el arreglo)
y posteriormente pierde tiempo en razón de O(n²)
*/
void Inserccion(int *A,int n)
{
    int i, j, temp;

    for (i = 0; i <= n - 1; i++)
    {
        j = i;
        temp = A[i];
        //Seccion de recorrido de numeros en caso de que el termino anterior sea mayor
        while ((j > 0) && (temp < A[j - 1]))
        {
            A[j] = A[j - 1];
            j--;
        }
        //Asignacion del lugar que ocupara el numero
        A[j] = temp;
    }

}
