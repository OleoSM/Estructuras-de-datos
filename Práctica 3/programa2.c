/*
programa2.c    (Procesos)
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
       Programa que emula la gestion de programas de un sistema operativo.
-----------------------------------------------------

Compilacion:
       Windows: gcc programa2.c ColaDin.c presentacionWin.c -o programa2.exe   (Procesos)
       Windows: gcc programa2.c ColaDin.c presentacionWin.c -o programa2       (Procesos)

*/

//Librerias a utilizar para la ejecucuion del programa
#include <string.h>
#include <stdio.h>
#include "ColaDin.h"
#include "presentacion.h"

/*  el elemento e esta conformado por su nombre, actividad (lo que hace), su ID,
    tiempo propuesto para la ejecucion del programa y un contador que se usara
    mas adelante (En la funcion procesar, para ser exactos).    */

//  Redefinimos el tipo elemento a programa para entrar mas en contexto.
typedef elemento programa;

// Protipos de funciones

void prueba (cola *c);
void MuestraActual (programa p, int espera);
void MuestraUltimo (programa p);
void MuestraSiguiente (programa p);
void mostrarTerminado (programa p);
void mostrarFinalizados (cola *c);
void ProcesaCola (cola *c);
void ProtFunc (char *s, int lim);
void PideDatos (cola *c);

/*  Manda a llamar a la funcion pedirDatos (), forma los programas en la cola c.
    Si la cola esta vacia, muetra un mensaje "No hay nada que mostrar", si no,
    procede a ejecutar el algoritmo propuesto para la practica 2, programa 2.   */
int main (void){
    cola c;
    Initialize (&c);
    PideDatos (&c);

    if (Empty (&c)){
        puts ("No hay nada que mostrar.");
        Destroy (&c);
        return 0;
    }
    ProcesaCola (&c);
    Destroy (&c);
    return 0;
}

/*
    Mostrar Actual (mostrarActual): recibe <- programa p; recibe <- int espera
    MuestraActual(p, espera)
    Efecto: Dado un programa p y un tiempo de espera, esta funcion imprime los campos del programa
    y su tiempo de espera.
*/
void MuestraActual (programa p, int espera){
    puts ("\nProceso en Ejecucion");
    printf ("Nombre del programa: %s \n", p.Nombre);
    printf ("ID: %s \n", p.id);
    printf ("Actividad: %s \n", p.Act);
    printf ("Tiempo total que lleva ejecutandose: %d segundos \n", p.contador + espera);
    return;
}

/*
    Mostrar Ultimo(mostrarUltimo): recibe <- programa p;
    MuestraUltimo(p)
    Efecto: Muestra el ID y nombre del ultimo programa, junto con su tiempo restante para culminar
    su ejecucion. Recibe el ultimo programa formado en la cola.
*/
void MuestraUltimo (programa p){
    puts ("\nUltimo proceso");
    printf ("ID: %s \t Nombre: %s \n", p.id, p.Nombre);
    printf ("Tiempo restante: %d segundos \n", p.tiempo - p.contador);
    return;
}

/*
    Mostrar Siguiente (mostrarSiguiente): recibe <- programa p;
    MuestraSiguiente p)
    Efecto: Muestra el programa que esta en el frente de la cola, con su tiempo que hace falta para
    que se culmine su ejecucion.
    */
void MuestraSiguiente (programa p){
    puts ("\nProceso siguiente");
    printf ("ID: %s \t Nombre: %s \n", p.id, p.Nombre);
    printf ("Tiempo restante: %d segundos \n", p.tiempo - p.contador);
    return;
}

/*
    Mostrar Terminado (mostrarTerminado): recibe <- programa p;
    mostrarTerminado(p)
    Efecto: Imprime el nombre de el programa que ya finalizo.
*/
void mostrarTerminado (programa p){
    printf ("\nEl programa %s se ha acabado de ejecutar. \n", p.Nombre);
    return;
}

/*
    Mostrar Finalizados (mostrarFinalizados): recibe <- cola *c
    mostrarFinalizados(*c)
    Efecto: Dada una cola, en la cual se fueron formando los programas conforme se
    acabaron de ejecutar, esta funcion imprime sus campos y su tiempo total
    que se empleo para su ejecucion.
*/
void mostrarFinalizados (cola *c){
    programa p;

    puts ("\nProgramas ejecutados exitosamente :D");
    while (!Empty (c)){
        p = Dequeue (c);
        printf ("\nNombre: %s \t ID: %s \n", p.Nombre, p.id);
        printf ("Tiempo usado para finalizar el programa: %d segundos \n", p.tiempo);
    }
    Destroy (c);
    return;
}

/*
    Procesar (procesar): recibe <- cola *c;
    ProcesaCola(*c)
    Efecto: Funcion que procesa una cola de programas conforme el siguiente criterio:
    Se desencolara el programa p y se incrementara su contador ya definido en
    su campo, si el contador es menor al tiempo propuesto por el usuario, se
    volvera a encolar el programa p, si no, se formara en la cola "Finalizados",
    la cual se enviara a la funcion de aqui arriba.
*/
void ProcesaCola (cola *c){
    programa p;
    cola Finalizados;
    int Segundos = 1000, TiempoEspera = 0;

    Initialize (&Finalizados);

    while (!Empty (c)){
        p = Dequeue (c);
        MuestraActual (p, TiempoEspera);

        if (Size (c) >= 1){
            MuestraUltimo (Final (c));
            MuestraSiguiente (Front (c));
        }
        p.contador++;
        TiempoEspera++;

        if (p.contador < p.tiempo)
            Queue (c, p);
        else {
            mostrarTerminado (p);
            p.tiempo += TiempoEspera;
            Queue (&Finalizados, p);
        }
        EsperarMiliSeg (1 * Segundos);
        BorrarPantalla ();
    }
    mostrarFinalizados (&Finalizados);
    return;
}

/*
    ProtFunc(ProtFunc): recibe <- char *s; recibe <- int lim;
    ProtFunc (*s, lim)
    Efecto: Funcion para recibir datos por el teclado.
    En comparacion con fgets(), esta pone un
    fin de cadena al final de cada string (\0)
*/

void ProtFunc (char *s, int lim){
    char c;
    int i = 0;

    while ((c = getchar ()) != '\n' && i < lim){
        s[i++] = c;
    }
    s[i] = '\0';
    return;
}

/*
    Pide Datos (Pide Datos): recibe <- cola *c;
    PideDatos(*c)
    Efecto: Funcion destinada a preguntar los campos del programa al usuario y formarlos
    en la cola c.
*/
void PideDatos (cola *c){
    programa p;
    char aux[9];

    printf ("\nDesea encolar un programa? (s/n): ");
    ProtFunc (aux, 9);
    if (aux[0] == 'n' || aux[0] == 'N')
        return;
    while (TRUE){
        printf ("\nNombre del programa: ");
        ProtFunc (p.Nombre, 45);
        printf ("Actividad del programa: ");
        ProtFunc (p.Act, 200);
        printf ("ID: ");
        ProtFunc (p.id, 45);
        printf ("Tiempo: ");
        ProtFunc (aux, 9);
        sscanf (aux, "%d", &p.tiempo);
        p.contador = 0;
        Queue (c, p);
        printf ("Desea encolar otro programa? (s/n): ");
        ProtFunc (aux, 9);
        if (aux[0] == 'n' || aux[0] == 'N'){
            BorrarPantalla ();
            return;
        }
    }
    return;
}

