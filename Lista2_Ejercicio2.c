#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[40];
    int edad;
    char direccion[255];
    int telefono;
} Persona;

void solicitarNumPersonas(int*);
Persona * crearArregloPersonas(Persona*, int);
Persona * pedirDatos(Persona*, int);
void ordenar(Persona*, int);
void mostrar(Persona*, int);
void liberar(Persona*);
void Mensajes(int);

void main(){
	Persona *p1;
	int n;
	
	solicitarNumPersonas(&n);
	p1 = crearArregloPersonas(p1, n);
	p1 = pedirDatos(p1, n);
    ordenar(p1, n);
	mostrar(p1, n);
	liberar(p1);
}

void solicitarNumPersonas(int* elem){
	printf("Ingrese la cantidad de personas que desea registrar: \n");
	scanf("%d", elem);
	getchar();
}

Persona * crearArregloPersonas(Persona * p1, int n){
	p1=(Persona *)malloc(n*sizeof(Persona));
	if(p1==NULL){
		Mensajes(0);
		exit(0);
	}
	return p1;
}

Persona * pedirDatos(Persona* p1, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Introduzca los datos de la persona %d\n",i+1);
		printf("Nombre Completo:\n");
		scanf("%[^\n]", p1[i].nombre);
		getchar();
		printf("Edad:\n");
		scanf("%d", &p1[i].edad);
		getchar();
		printf("Dirección:\n");
		scanf("%[^\n]", p1[i].direccion);
		getchar();
		printf("Telefono:\n");
		scanf("%d", &p1[i].telefono);
		getchar();
	}
	return p1;
}

void ordenar(Persona* p1, int n){
    int i,j;
    Persona t;
    for (i=1;i<n;i++){
        j=i-1;
        t=p1[i];
        while(j>=0 && t.edad>p1[j].edad){
            p1[j+1]=p1[j];
            j--;
        }
        p1[j+1]=t;
    }
}

void mostrar(Persona * p1, int n){
	int i;
	printf("Personas ordenados por edad\n");
	for(i=0;i<n;i++){
		printf("Nombre: %s\n",p1[i].nombre);
        printf("Edad: %d\n",p1[i].edad);
		printf("Direccion: %s\n",p1[i].direccion);
        printf("Telefono: %d\n",p1[i].telefono);
	}
}

void liberar(Persona* p1){
	free(p1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}