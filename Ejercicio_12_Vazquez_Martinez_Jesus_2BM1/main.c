#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

LISTA darDatos(LISTA, int *);
LISTA elmismismisimoSorteador(LISTA, LISTA, int);

void main(){
    LISTA L1,L2;
    int n=0;
    L1 = crearLista();
    L2 = crearLista();
    L1 = darDatos(L1,&n);
    L2=elmismismisimoSorteador(L1,L2,n);
    visualizaLista(L1);
    visualizaLista(L2);
}

LISTA darDatos(LISTA L, int *n){
    int op=0;
    Producto e;
    do{
        printf("Ingrese los datos del producto:\n");
        printf("Clave: ");
        scanf("%d",&e.clave);
        getchar();
        printf("Nombre: ");
        scanf("%[^\n]",e.nombre);
        getchar();
        printf("Precio: ");
        scanf("%f",&e.precio);
        getchar();
        L=insertar(L,e);
        *n=*n+1;
        printf("Desea ingresar otro cliente al registro? (1=Si 0=No)\n");
		scanf("%d",&op);
		getchar();
    } while (op);
    return L;
}

LISTA elmismismisimoSorteador(LISTA L1, LISTA L2, int n){
    Producto temp1, temp2;
    for(int i=0;i<n;i++){
        printf("Extrayendo elem %d\n",i);
        temp1 = extraer(L1,i);
        if(es_vaciaLista(L2))
            L2=insertar(L2,temp1);
        else{
            for(int j=0;j<i;j++){
                temp2=extraer(L2,j);
                L2=borrar(L2,temp2);
                if(strcmp(temp1.nombre,temp2.nombre)>0)
                    L2=insertar(L2,temp2);
                else{
                    L2=insertar(L2,temp1);
                    temp1=temp2;
                }
                if(j==i-1)
                    L2=insertar(L2,temp1); 
            }
        }
    }
    return L2;
}

void mostrar(Producto e, int msg, int p){
    int i;

    if(msg == 0)
	    printf("El producto %s no se encuentra en la lista\n", e.nombre);
    else if(msg == 1){
	    printf("Producto %d:\n",p);
        printf("Clave: %d\n",e.clave);
        printf("Nombre: %s\n",e.nombre);
        printf("Precio: %.2f\n",e.precio);
    }
    else
       printf("El producto %s se encuentra en la posición %d\n", e.nombre, p);
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola Llena","Cola liberada","Lista Vacia","Violacion de Segmento :)"};
	printf("%s\n", mensajes[msg] );
}