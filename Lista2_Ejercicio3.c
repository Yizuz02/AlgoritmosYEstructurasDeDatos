#include <stdio.h>
#include <stdlib.h>

typedef struct datos{
    char nombre[15];
    char ap_pater[15];
    int edad;
    char carrera[20];
}Datos;

typedef struct deportista{
    Datos pers;
    char deportes[30];
    int medallas;
}Deportista;

void solicitarNumDep(int*);
Deportista * crearArregloDep(Deportista*, int);
Deportista * pedirDatos(Deportista*, int);
void mostrar(Deportista*, int);
int promedioMed(Deportista*, int);
void mostrar(Deportista*, int);
void liberar(Deportista*);
void Mensajes(int);

void main(){
	Deportista *p1;
	int n;
	
	solicitarNumDep(&n);
	p1 = crearArregloDep(p1, n);
	p1 = pedirDatos(p1, n);
	mostrar(p1, n);
	liberar(p1);
}

void solicitarNumDep(int* elem){
	printf("Ingrese la cantidad de estudiantes que desea registrar: \n");
	scanf("%d", elem);
	getchar();
}

Deportista * crearArregloDep(Deportista * p1, int n){
	p1=(Deportista *)malloc(n*sizeof(Deportista));
	if(p1==NULL){
		Mensajes(0);
		exit(0);
	}
	return p1;
}

Deportista * pedirDatos(Deportista* p1, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Introduzca los datos de la persona %d\n",i+1);
		printf("Nombre:\n");
		scanf("%[^\n]", p1[i].pers.nombre);
		getchar();
        printf("Apellido Paterno:\n");
		scanf("%[^\n]", p1[i].pers.ap_pater);
		getchar();
		printf("Edad:\n");
		scanf("%d", &p1[i].pers.edad);
		getchar();
		printf("Carrera:\n");
		scanf("%[^\n]", p1[i].pers.carrera);
		getchar();
		printf("Deportes:\n");
		scanf("%[^\n]", p1[i].deportes);
		getchar();
        printf("Medallas:\n");
		scanf("%d", &p1[i].medallas);
        getchar();
	}
	return p1;
}

int promedioMed(Deportista* p1, int n){
    int i, totalMed=0;
	for(i=0;i<n;i++){
        totalMed += p1[i].medallas;
    }
    return totalMed/n;
}

void mostrar(Deportista * pa1, int n){
	int i, pM, mayorSum=0;
    Deportista mayor, menor;
    pM = promedioMed(pa1,n);
	printf("Promedio de medallas obtenidas: %d\n",pM);
    mayor = pa1[0];
    menor = pa1[0];
    for(i=0;i<n;i++){
		if(pa1[i].medallas>pM)
			mayorSum++;
        if(pa1[i].medallas>mayor.medallas)
            mayor = pa1[i];
        if(pa1[i].medallas<menor.medallas)
            menor = pa1[i];
	}
    printf("Numero de estudiantes con un numero de medallas mayor al promedio: %d\n", mayorSum);
	printf("Estudiante con mayor numeros de medallas:\n");
    printf("Nombre: %s\n",mayor.pers.nombre);
	printf("Carrera: %s\n",mayor.pers.carrera);
    printf("Estudiante con menor numeros de medallas:\n");
    printf("Nombre: %s\n",menor.pers.nombre);
	printf("Carrera: %s\n",menor.pers.carrera);
}

void liberar(Deportista* pa1){
	free(pa1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}