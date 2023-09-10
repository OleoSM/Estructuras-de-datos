#define TRUE 1
#define FALSE 0


#define TablaSize 400 //definimos el tamaño de la tabla HASH.
#define PalSize 50 //definimos el tamaño de la palabra.
#define DefSize 150 //definimos el tamaño de la definicion.
#define CadenaSize DefSize+PalSize
typedef char boolean;

typedef struct element{

    long id_palabra;
    char palabra[50];
    char significado[150];

}element;

typedef struct nodo{

    element e;
    struct nodo *sig;
    struct nodo *ant;

}nodo;

typedef struct lista{

    int tam;
    nodo *frente;
    nodo *fin;

}lista;

void BorrarPantalla();
void Init(lista *l);
void Insertar(lista *l, element e);
boolean Lista_Vacia(lista *l);
void Eliminar(lista *l, char *p);
void Imprimir_Lista(lista *l);
void ImpColisiones (lista *l);
int Tam_Lista(lista *l);
void Buscar_Elemento(lista *l, char *p);
void CambiaPal(lista *l, char *p);
