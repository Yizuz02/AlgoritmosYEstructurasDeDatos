// DEFINICION DEL TAD
#ifndef  _listaSimple_
#define  _listaSimple_

#define TRUE    1
#define FALSE  0

typedef struct{
    int clave;
    char nombre[30];
    float precio;
}Producto;

typedef struct Nodo_Lista{
    Producto dato;
    struct Nodo_Lista * siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

LISTA crearLista(  );
int es_vaciaLista(LISTA L);
Nodo_Lista * crearNodoLista(  );
LISTA insertar(LISTA L, Producto e);
void visualizaLista(LISTA L);
void  buscarElem(LISTA L, Producto elem);
LISTA borrar(LISTA L, Producto elem);
Producto extraer(LISTA L, int pos);


#endif