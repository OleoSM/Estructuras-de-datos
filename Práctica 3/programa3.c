/*
programa3.c    (Banco)
V 1.0   Diciembre 2022
-----------------------------------------------------
Autores: Los tíos pelones
       Grupo: 2CM1
       Buendia Velazco Abel
       Carpio Becerra Erik Gustavo
       Hernandez Molina Leonardo Gaell
       Velazquez Diaz Luis Francisco
-----------------------------------------------------
DESCRIPCIÓN:
	   Programa que simula la llegada de personas a un banco.
	   El banco consta de tres colas para distintos tipos de personas:
	   -cola 0: preferentes
	   -cola 1: clientes
	   -cola 2: usuarios
	   Contamos con n cajeros disponibles, y los tiempos de llegada y de atencion son fijos
	   durante la simulación.
	   El orden de preferencia es: preferentes > clientes > usuarios.
	   Sin embargo, no se debe permitir que pasen más de 5 preferentes o clientes sin que un
	   usuario en espera sea atendido.
-----------------------------------------------------

Compilacion:
       Windows: gcc Banco.c ColaDin.c presentacionWin.c -o programa3.exe    (Banco)
       Windows: gcc Banco.c ColaDin.c presentacionWin.c -o programa3        (Banco)

*/


//Librerias a utilizar para la ejecucion del programa
#include "ColaDin.h"
#include <stdio.h>
#include "presentacion.h"

/*
	Definimos a un cajero, podremos saber si está ocupado o libre;
	y la persona atendida actualmente en caso de que esté ocupado
*/
typedef struct{
	boolean ocupado;
	elemento persona;
} cajero;

/*
	Definimos a la simulación:
	-n_cajeros: cuántos cajeros hay disponibles para atender a las personas
	-tiempo_atencion: cada cuándo se desocupan todos los cajeros
	-tiempo_clientes: cada cuándo llegan los clientes
	-tiempo_usuarios: cada cuándo llegan los usuarios
	-tiempo_preferentes: cada cuánto llegan los preferentes
	-clientes_y_preferentes: cuántos clientes y preferentes han pasado desde el último
	 usuario
	-colas[3]: las tres colas de nuestra simulación, 0:preferentes, 1:clientes, 2:usuarios
	-cajeros[9]: los cajeros de nuestra simulacion
*/
typedef struct
{
	int n_cajeros;
	int tiempo_atencion;
	int tiempo_clientes;
	int tiempo_usuarios;
	int tiempo_preferentes;
	int clientes_y_preferentes;
	cola colas[3];
	cajero cajeros[9];
} simulacion;


// Protipos de funciones

int LiberaCajeros(simulacion * S);
int CajeroEstaLibre(simulacion * S);
void FormarPersona(int n_persona, int tipo, simulacion * S);
void PasarPersona(int n_persona, int tipo, int donde, simulacion * S);
int PuedePasar(int tipo, simulacion * S);
void EjecutaPersonaXD(int n_persona, int tipo, simulacion * S);
int EjecutaColas(simulacion * S);

//Programa principal
int main(){
	//Creamos una simulacion e inicializamos en 0 el campo de clientes y preferentes
	simulacion S;
	S.clientes_y_preferentes = 0;

	//Variables para controlar el tiempo multiplos de 10
	int tiempo_actual = 0;
	int tiempo_base = 10;

	//Contadores auxiliar
	int i, j;

	//Dato del tipo elemento que nos sera de auxiliar
	elemento e;

	//Contador para identificar el numero de personas que vayan llegando
	int n_persona = 0;

	//Estas variables sirven para llevar el control de los mensajes de la simulacion
	int refrescar = 1;  //Variable auxiliar que nos ayudara a determinar si es que hubo o no un cambio en la expresion para poder actualizar pantalla
	char mensajes[5][100];  // Nos servira para poder mostrar los mensajes que se vayan generando en pantalla

	//Leemos la entrada de la simulación
	printf("Introduce el numero de cajeros disponibles: ");
	scanf("%d", &(&S)->n_cajeros);  //&S.n_cajeros; A final de cuentas es lo mismo, solo que utilizamos la nomenclatura documentada para "ahorrar" caracteres
	printf("Introduce el tiempo de atencion: ");
	scanf("%d", &S.tiempo_atencion);
	printf("Introduce el tiempo de llegada de los clientes: ");
	scanf("%d", &S.tiempo_clientes);
	printf("Introduce el tiempo de llegada de los usuarios: ");
	scanf("%d", &S.tiempo_usuarios);
	printf("Introduce el tiempo de llegada de los preferentes: ");
	scanf("%d", &S.tiempo_preferentes);

	//Inicializamos las tres colas con un forsito
	for(i = 0; i < 3; i++)
		Initialize(&S.colas[i]);

	//Para iniciar, debemos asegurarnos que todos los cajeros esten desocupados
	LiberaCajeros(&S);

	//Inicamos de manera indefinida
	while(TRUE){
		EsperarMiliSeg(tiempo_base);
		tiempo_actual += tiempo_base;   //Avanzará en razón de 10 ms cada vez que el ciclo vuelva a iniciar
		i = 0;

		//Los cajeros han finalizado de atender a las personas que estaban atendiendo
		if(tiempo_actual % S.tiempo_atencion == 0){ //Utilizando el módulo determinaremos si ya llego al tiempo maximo de atencion
			if(LiberaCajeros(&S) > 0)
				sprintf(mensajes[i++], "Los cajeros terminaron de atender.\n");
			if(EjecutaColas(&S) > 0)
				sprintf(mensajes[i++], "Pasaron nuevas personas a los cajeros.\n");
			refrescar = 1;
		}

		//Llegó un preferente
		if(tiempo_actual % S.tiempo_preferentes == 0){
			n_persona++;
			EjecutaPersonaXD(n_persona, 0, &S); //El 0 indica que es un preferente
			sprintf(mensajes[i++], "Llego un preferente con ID %d.\n", n_persona);
			refrescar = 1; //Indica con un 1 si hubo cambio, esto para poder saber mas adelante si debemos actualizar la pantalla
		}

		//Llegó un cliente
		if(tiempo_actual % S.tiempo_clientes == 0){
			n_persona++;
			EjecutaPersonaXD(n_persona, 1, &S);   //El 1 indica que llego un usuario del tipo cliente, por ello le asignamos una prioridad de 1
			sprintf(mensajes[i++], "Llego un cliente con ID %d.\n", n_persona);
			refrescar = 1;
		}

		//Llegó un usuario
		if(tiempo_actual % S.tiempo_usuarios == 0){
			n_persona++;
			EjecutaPersonaXD(n_persona, 2, &S);   //El 2 indica que llego un usuario promedio, por lo que le asignamos una prioridad de 2
			sprintf(mensajes[i++], "Llego un usuario con ID %d.\n", n_persona);
			refrescar = 1;
		}

		//Mostramos la información de la simulación, solo si hubo algun cambio
		if(refrescar){
			BorrarPantalla();
			printf("Informacion del banco\n\n");
			for(j = 0; j < i; j++)
				printf("%s", mensajes[j]);
			printf("\n");
			for(i = 0; i < 3; i++){
				printf("Cola de ");
				if(i == 0)
					printf("preferentes (%d): ", Size(&S.colas[i]));
				else if(i == 1)
					printf("clientes    (%d): ", Size(&S.colas[i]));    //Utilizamos este ciclo para imprimir que tipo de cliente es a partir de su "prioridad"
				else if(i == 2)
					printf("usuarios    (%d): ", Size(&S.colas[i]));
				for(j = 1; j <= Size(&S.colas[i]); j++){    //Este ciclo se va a repetir segun cuantos clientes haya formados en la cola
					if(Size(&S.colas[i]) > 10 && j >= 6 && j <= (Size(&S.colas[i]) - 5)){   //Solo mostramos en pantalla hasta 10 clientes, y utilizamos ...<-- Si hay mas de 10 clientes formados
						printf("... <-- ");
						j = Size(&S.colas[i]) - 5;
					}else{
						e = Element(&S.colas[i], j);
						printf("%d", e.ID);
						if(j < Size(&S.colas[i]))
							printf(" <-- ");
					}
				}
				printf("\n\n");
			}
			for(i = 0; i < S.n_cajeros; i++){
				e = S.cajeros[i].persona;
				printf("Cajero %d: ", i + 1);
				if(S.cajeros[i].ocupado){
					printf("ocupado: (ID: %d, tipo: ", e.ID);
					switch(e.tipo){
						case 0:{
							printf("preferente)");
							break;
						}
						case 1:{
							printf("cliente)");
							break;
						}
						case 2:{
							printf("usuario)");
							break;
						}
					}
				}else
					printf("desocupado");
				printf("\n");
			}
			printf("\nTiempo actual: %dms\n\n\n", tiempo_actual);
			refrescar = 0;
		}
	}
	return 0; //FIN
}


/*
    Desocupar Cajeros (DesocuparCajeros): recibe <- simulacion *S; retorna -> int cuantos;
    DesocuparCajeros(*S)
	Efecto: Dada una simulación, pone en FALSE la propiedad de todos los cajeros.
*/
int LiberaCajeros(simulacion * S){
	int i, cuantos = 0;
	for(i = 0; i < S->n_cajeros; i++){
		if(S->cajeros[i].ocupado)
			cuantos++;
		S->cajeros[i].ocupado = FALSE;
	}
	return cuantos;
}

/*
    Revisar Cajero Libre (RevisarCajeroLibre): recibe <- simulacion *S; retorna -> -1;
    RevisarCajeroLibre (*S)
	Efecto: Dada una simulación, verifica qué cajero está disponible.
	Si hay varios, devuelve el primero que encuentra. Si no hay ninguno, devuelve -1
*/
int CajeroEstaLibre(simulacion * S){
	int i;
	for(i = 0; i < S->n_cajeros; i++){
		if(S->cajeros[i].ocupado == FALSE){
			return i;
		}
	}
	return -1;
}

/*
    Formar Persona (FormarPersona): recibe <- int n_persona; recibe <- int tipo; recibe <- simulacion *S;
	Efecto: Dada una persona y su tipo de acuerdo a la jerarquía de atención del
	banco, la encola en la cola de acuerdo a su tipo en la simulación.
*/

void FormarPersona(int n_persona, int tipo, simulacion * S){
	elemento persona;
	persona.ID = n_persona;
	persona.tipo = tipo;
	Queue(&S->colas[tipo], persona);
	return;
}
/*
    Pasar Persona (PasarPersona): recibe <- int n_persona; recibe <- int tipo; recibe <- int donde; recibe <- simulacion *S
    PasarPersona (n_persona, tipo, donde, *S)
	Efecto: Dada una persona, su tipo y una posición de cajero válida,
	la pone como la persona atendida en ese cajero y lo pone como ocupado.
*/

void PasarPersona(int n_persona, int tipo, int donde, simulacion * S){
	elemento persona;
	persona.ID = n_persona;
	persona.tipo = tipo;
	S->cajeros[donde].persona = persona;
	S->cajeros[donde].ocupado = TRUE;
	if(tipo == 2)
		S->clientes_y_preferentes = 0;
	else
		S->clientes_y_preferentes++;
    return;
}

/*
    Persona Puede Pasar (PerosnaPuedePasar): recibe <- int tipo: recibe <- simulacion *S; retorna -> int disponible;
    PerosnaPuedePasar (tipo, simulacion, *S)
	Efecto: Dado un tipo de persona y la simulación, determina si esa persona puede pasar a algún cajero,
	respetando las políticas del banco. Si sí puede pasar, devuelve la posición del cajero candidato, si no
	devuelve -1.
*/
int PuedePasar(int tipo, simulacion * S){
	int disponible = CajeroEstaLibre(S);
	if(disponible == -1) return -1;
	if(S->clientes_y_preferentes == 5){
		if((tipo == 0 || tipo == 1) && !Empty(&S->colas[2]))
			return -1;
		return disponible;
	}
	return disponible;
}

/*
    Procesar Llegada Persona (ProcesarLlegadaPersona): recibe <- int n_persona; recibe <- int tipo; recibe <- si,ulacion *S;
    ProcesarLlegadaPersona (n_persona, tipo, *S)
	Efecto: Dada una persona, su tipo y la simulación, determina
	si la persona podría pasar directamente a algún cajero disponible
	o se tendría que formar a su cola determinada.
*/
void EjecutaPersonaXD(int n_persona, int tipo, simulacion * S){
	int pos = PuedePasar(tipo, S);
	if(Empty(&S->colas[tipo]) && pos != -1){
		PasarPersona(n_persona, tipo, pos, S);
	}else{
		FormarPersona(n_persona, tipo, S);
	}
	return;
}

/*
    Procesar Colas (ProcesarColas): recibe <- simulacion *S; retorna -> int cuantas;
    ProcesarColas (*S)
	Efecto: Esta función se ejecuta cada que es tiempo de atención,
	y determina si las personas esperando al frente de cada cola pueden pasar a algún cajero.
	Si sí pueden, las pasa y las desencola.
*/
int EjecutaColas(simulacion * S){
	int i = 0, pos, cuantas = 0;
	elemento persona;
	for(i = 0; i < 3; i++){
		if(!Empty(&S->colas[i])){
			persona = Front(&S->colas[i]);
			pos = PuedePasar(persona.tipo, S);
			if(pos != -1){
				PasarPersona(persona.ID, persona.tipo, pos, S);
				Dequeue(&S->colas[i]);
				cuantas++;
			}
		}
	}
	return cuantas;

}

