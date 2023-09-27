#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    int cant_ejem;
    char autor[30];
    char titulo[50];
}Libro;

int imprimirMenu();
void menu(Libro*,int);
void solicitarNumLib(int*);
Libro * crearArregloLib(Libro*, int);
Libro * pedirDatos(Libro*, int);
void mostrar(Libro);
Libro * prestamo(Libro*, int);
Libro * devolucion(Libro*, int);
void liberar(Libro*);
void Mensajes(int);

void main(){
	Libro *p1;
	int n;
	
	solicitarNumLib(&n);
	p1 = crearArregloLib(p1, n);
	p1 = pedirDatos(p1, n);
    menu(p1,n);
}

void solicitarNumLib(int* elem){
	printf("Ingrese la cantidad de libros que desea registrar: \n");
	scanf("%d", elem);
	getchar();
}

Libro * crearArregloLib(Libro * p1, int n){
	p1=(Libro *)malloc(n*sizeof(Libro));
	if(p1==NULL){
		Mensajes(0);
		exit(0);
	}
	return p1;
}

Libro * pedirDatos(Libro* p1, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Introduzca los datos del libro %d\n",i+1);
        p1[i].codigo = i+1;
		printf("Titulo:\n");
		scanf("%[^\n]", p1[i].titulo);
		getchar();
        printf("Autor:\n");
		scanf("%[^\n]", p1[i].autor);
		getchar();
		printf("Numero de ejemplares:\n");
		scanf("%d", &p1[i].cant_ejem);
		getchar();
	}
	return p1;
}

int imprimirMenu(){
    int op;
    printf("Biblioteca Sistema\n");
    printf("1.- Prestamos de Libros\n");
    printf("2.- Devolucion de Libros\n");
    printf("3.- Salir\n");
    printf("Ingrese una opcion:\n");
    scanf("%d",&op);
    getchar();
    return op;
}

void menu(Libro * p1, int n){
    int op=0;
    do
    {
        op = imprimirMenu();
        switch (op){
            case 1:
                p1 = prestamo(p1,n);
                break;
            case 2:
                p1 = devolucion(p1,n);
                break;
            case 3:
                liberar(p1);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (op!=3);
    
}

void mostrar(Libro p1){
    printf("Autor: %s\n", p1.autor);
    printf("Titulo: %s\n", p1.titulo);
}

Libro * prestamo(Libro* p1, int n){
    int cod;
    printf("Ingresar codigo del libro:\n");
    scanf("%d",&cod);
    if (cod>0 && cod<=n){
        mostrar(p1[cod-1]);
        if (p1[cod-1].cant_ejem>1){
            p1[cod-1].cant_ejem--;
            printf("Prestamo realizado!\n");
        } else {
            printf("Solo queda el ejemplar de lectura en la sala\n");
        }
        return p1;
    } else{
        printf("Codigo no valido\n");
        return prestamo(p1,n);
    }
}

Libro * devolucion(Libro* p1, int n){
    int cod;
    char op;
    printf("Ingresar codigo del libro:\n");
    scanf("%d",&cod);
    getchar();
    if (cod>0 && cod<=n){
        printf("Confirmar devolucion: (S/N)\n");
        scanf("%c",&op);
        getchar();
        if (op=='S'){
            p1[cod-1].cant_ejem++;
            mostrar(p1[cod-1]);
            printf("Devolucion confirmada!\n");
        }
        return p1;
    } else{
        printf("Codigo no valido\n");
        return prestamo(p1,n);
    }
}

void liberar(Libro* pa1){
	free(pa1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}