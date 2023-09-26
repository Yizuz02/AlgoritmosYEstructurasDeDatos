#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[15];
    char ap_pater[15];
    char ap_mater[15];
    int num_uni;
    float precio_uni;
    char estado[20];
}Factura;

void solicitarNumFac(int*);
Factura * crearArregloFac(Factura*, int);
Factura * pedirDatos(Factura*, int);
void mostrarOpciones(Factura*, int);
void mostrarApPater(Factura*, int);
void mostrarEstado(Factura*, int);
void mostrarTodo(Factura*, int);
void mostrar(Factura);
void liberar(Factura*);
void Mensajes(int);

void main(){
	Factura *p1;
	int n;
	
	solicitarNumFac(&n);
	p1 = crearArregloFac(p1, n);
	p1 = pedirDatos(p1, n);
	mostrarOpciones(p1, n);
	liberar(p1);
}

void solicitarNumFac(int* elem){
	printf("Ingrese la cantidad de estudiantes que desea registrar: \n");
	scanf("%d", elem);
	getchar();
}

Factura * crearArregloFac(Factura * p1, int n){
	p1=(Factura *)malloc(n*sizeof(Factura));
	if(p1==NULL){
		Mensajes(0);
		exit(0);
	}
	return p1;
}

Factura * pedirDatos(Factura* p1, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Introduzca los datos de la persona %d\n",i+1);
		printf("Nombre:\n");
		scanf("%[^\n]", p1[i].nombre);
		getchar();
        printf("Apellido Paterno:\n");
		scanf("%[^\n]", p1[i].ap_pater);
		getchar();
        printf("Apellido Materno:\n");
		scanf("%[^\n]", p1[i].ap_mater);
		getchar();
		printf("Numero De Unidades Solicitadas:\n");
		scanf("%d", &p1[i].num_uni);
		getchar();
		printf("Precio Por Unidad:\n");
		scanf("%f", &p1[i].precio_uni);
		getchar();
		printf("Estado: (moroso,atrasado,pagado)\n");
		scanf("%[^\n]", p1[i].estado);
		getchar();
	}
	return p1;
}

void mostrarOpciones(Factura* p1, int n){
    char op;
    printf("Mostrar Facturas Por:\n");
    printf("a) Apellido Paterno\n");
    printf("b) Estado\n");
    printf("c) Todas las existentes\n");
    printf("Ingrese una opcion: ");
    scanf("%c",&op);
    switch (op){
    case 'a':
        mostrarApPater(p1, n);
        break;
    case 'b':
        mostrarEstado(p1, n);
        break;
    case 'c':
        mostrarTodo(p1, n);
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
}

void mostrarApPater(Factura * p1, int n){
    char ap_pater[15];
    printf("Ingresar apellido a buscar: ");
    scanf("%[^\n]", ap_pater);
    getchar();
    printf("Resultados de la busqueda:\n");
    for(int i=0;i<n;i++){
        if(strcmp(ap_pater,p1[i].ap_pater)==0)
            mostrar(p1[i]);
    }
}

void mostrarEstado(Factura * p1, int n){
    int op;
    printf("1) Moroso\n");
    printf("2) Atrasado\n");
    printf("3) Pagado\n");
    printf("Ingrese una opcion:");
    scanf("%d",op);
    printf("Resultados de la busqueda:\n");
    for(int i=0;i<n;i++){
        if(strcmp("moroso",p1[i].estado)==0)
            mostrar(p1[i]);
        else if(strcmp("atrasado",p1[i].estado)==0)
            mostrar(p1[i]);
        else if(strcmp("pagado",p1[i].estado)==0)
            mostrar(p1[i]);
    }
}

void mostrarTodo(Factura * p1, int n){
    for(int i=0;i<n;i++){
        mostrar(p1[i]);
    }
}

void mostrar(Factura p){
    printf("Nombre: %s\n",p.nombre);
    printf("Apellido Paterno: %s\n",p.ap_pater);
    printf("Apellido Materno: %s\n",p.ap_mater);
	printf("Numero De Unidades Solicitadas: %d\n",p.num_uni);
    printf("Precio Por Unidad: %.2f\n",p.precio_uni);
    printf("Estado: %s\n",p.estado);
}

void liberar(Factura* pa1){
	free(pa1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}
