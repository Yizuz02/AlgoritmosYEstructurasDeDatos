#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char direccion[30];
	char ciudad[30];
	char provincia[30];
	int cod_postal;
}info_dir;

typedef struct {
	char estado_paciente[30];
} c_paciente;

typedef struct {
	char * nombre;
	int edad;
	char sexo;
	info_dir direccion;
	c_paciente * condicion;
} paciente;


void solicitarNumPacientes(int*);
paciente * crearArregloPacientes(paciente*, int);
paciente * pedirDatos(paciente*, int);
void mostrarGraves(paciente*, int);
void liberar(paciente*, int);
void Mensajes(int);

void main(){
	paciente *pa1;
	int n;
	
	solicitarNumPacientes(&n);
	pa1 = crearArregloPacientes(pa1, n);
	pa1 = pedirDatos(pa1, n);
	mostrarGraves(pa1, n);
	liberar(pa1, n);
}

void solicitarNumPacientes(int* elem){
	printf("Ingrese la cantidad de pacientes que desea registrar: \n");
	scanf("%d", elem);
	getchar();
}

paciente * crearArregloPacientes(paciente * pa1, int n){
	pa1=(paciente *)malloc(n*sizeof(paciente));
	if(pa1==NULL){
		Mensajes(0);
		exit(0);
	}
	for(int i=0;i<n;i++){
		pa1[i].nombre=(char*)malloc(50*sizeof(char));
		if(pa1[i].nombre==NULL){
			Mensajes(0);
			exit(0);
		}
		pa1[i].condicion=(c_paciente *)malloc(sizeof(c_paciente));
		if(pa1[i].condicion==NULL){
			Mensajes(0);
			exit(0);
		}
	}
	return pa1;
}

paciente * pedirDatos(paciente* pa1, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Introduzca los datos del paciente %d\n",i+1);
		printf("Nombre Completo:\n");
		scanf("%[^\n]", pa1[i].nombre);
		getchar();
		printf("Edad:\n");
		scanf("%d", &pa1[i].edad);
		getchar();
		printf("Sexo(M=Masculino, F=Femenino):\n");
		scanf("%c", &pa1[i].sexo);
		getchar();
		printf("Dirección:\n");
		scanf("%[^\n]", pa1[i].direccion.direccion);
		getchar();
		printf("Ciudad:\n");
		scanf("%[^\n]", pa1[i].direccion.ciudad);
		getchar();
		printf("Provincia:\n");
		scanf("%[^\n]", pa1[i].direccion.provincia);
		getchar();
		printf("Codigo Postal:\n");
		scanf("%d", &pa1[i].direccion.cod_postal);
		getchar();
		printf("Ingrese la condicion en minusculas (grave, estable o delicado):\n");
		scanf("%[^\n]", pa1[i].condicion->estado_paciente);
		getchar();
	}
	return pa1;
}

void mostrarGraves(paciente * pa1, int n){
	int i;
	printf("Pacientes con condicion grave\n");
	for(i=0;i<n;i++){
		if(pa1[i].condicion->estado_paciente[0]=='g'){
			printf("Nombre: %s\n",pa1[i].nombre);
			printf("Ciudad: %s\n",pa1[i].direccion.ciudad);
		}
	}
}

void liberar(paciente* pa1, int n){
	int i;
	for(i=0;i<n;i++){
		free(pa1[i].nombre);
		free(pa1[i].condicion);
	}
	free(pa1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}
