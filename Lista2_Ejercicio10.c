#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[25];
    int boleta;
    char semestre[15];
    char sexo;
    int calificaciones[5];
} Estudiante;

void solicitarNumEst(int*);
Estudiante * crearArregloEst(Estudiante*, int);
Estudiante * pedirDatos(Estudiante*, int);
void mayorCal(Estudiante*, int);
float promedio(Estudiante);
void liberar(Estudiante*);
void Mensajes(int);

void main(){
	Estudiante *p1;
	int n;
	
	solicitarNumEst(&n);
	p1 = crearArregloEst(p1, n);
	p1 = pedirDatos(p1, n);
    mayorCal(p1,n);
	liberar(p1);
}

void solicitarNumEst(int* elem){
	printf("Ingrese la cantidad de estudiantes del grupo de Algoritmia: \n");
	scanf("%d", elem);
	getchar();
}

Estudiante * crearArregloEst(Estudiante * p1, int n){
	p1=(Estudiante *)malloc(n*sizeof(Estudiante));
	if(p1==NULL){
		Mensajes(0);
		exit(0);
	}
	return p1;
}

Estudiante * pedirDatos(Estudiante* p1, int n){
	int i,j;
	for(i=0;i<n;i++){
		printf("Introduzca los datos del estudiante %d\n",i+1);
		printf("Nombre Completo:\n");
		scanf("%[^\n]", p1[i].nombre);
		getchar();
		printf("Boleta:\n");
		scanf("%d", &p1[i].boleta);
		getchar();
		printf("Semestre:\n");
		scanf("%[^\n]", p1[i].semestre);
		getchar();
        printf("Sexo: (F/M)\n");
		scanf("%c", &p1[i].sexo);
		getchar();
		printf("Calificaciones:\n");
        for (j=0;j<5;j++){
            printf("%d: ",j+1);
		    scanf("%d", &p1[i].calificaciones[j]);
		    getchar();
        }
	}
	return p1;
}

void mayorCal(Estudiante* p1, int n){
    int i;
    float mayor = 0, temp;
    for(i=0;i<n;i++){
        temp=promedio(p1[i]);
        if (temp>mayor)
            mayor = temp;
    }
    printf("El promedio mas alto del salon es: %.2f\n",mayor);
}

float promedio(Estudiante p1){
    float sum=0;
    for (int i=0;i<5;i++)
        sum += p1.calificaciones[i];
    return sum/5;
}

void liberar(Estudiante* p1){
	free(p1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}