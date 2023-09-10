#define TRUE 1
#define FALSE 0

typedef int boolean;
typedef char elemento;
/*
typedef struct elemento
{
    char *e;
} elemento;
*/
typedef struct nodo
{
	elemento e;
	struct nodo *abajo;
} nodo;

typedef struct pila
{
	int size;
	nodo * tope;
} pila;

/*
Inicializar pila (Initialize): recibe<- pila (S);
Initialize(S);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *S);

/*
Empilar (Push): recibe<- pila (S); recibe<- elemento (e)
Push(S,e);
Efecto: Recibe la pila y aumenta su tama�o, poniendo el elemento en la cima de la pila.
*/
void Push(pila *S,elemento e);

/*
Desempilar (Pop): recibe<- pila (S); retorna -> elemento
e=Pop(S);
Efecto: Recibe la pila, remueve el elemento tope y lo retorna.
Excepci�n: Si la pila esta vac�a, produce error.
*/
elemento Pop(pila *S);

/*
Es vac�a (Empty): recibe<- pila (S); retorna -> boolean
b=Empty(S);
Efecto: Recibe una pila y devuelve true si esta vac�a y false en caso contrario.
*/
boolean Empty(pila *S);


/*
Tope pila (Top): recibe<- pila (S); retorna -> elemento
e=Top(S);
Efecto: Devuelve el elemento cima de la pila.
Excepci�n: Si la pila esta vac�a produce error
*/
elemento Top(pila *S);


/*
Tama�o pila (Size): recibe<- pila (S); retorna -> tama�o de la pila (entero)
n=Size(S);
Efecto: Devuelve el n�mero de elementos que contiene la pila (Altura de la pila).
*/
int Size(pila *S);

/*
Eliminar pila (Destroy): recibe<- pila (S)
Destroy(S);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *S);

/*ValidarPar
*/

