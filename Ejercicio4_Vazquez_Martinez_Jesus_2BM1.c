#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num_folio;
	char nombre_cliente[30];
	char tramite;
	float costo;
}Expediente;

Expediente * crearEstructura();
void darDatos(Expediente*);
void mostrar(Expediente*);
void Mensajes(int);
void liberar(Expediente*);

void main(){
	Expediente *expediente1;
	
	expediente1 = crearEstructura();
	darDatos(expediente1);
	mostrar(expediente1);
	liberar(expediente1);
}

Expediente * crearEstructura(){
	Expediente * nvo;
	nvo = (Expediente*)malloc(sizeof(Expediente));
	if(nvo==NULL){
		Mensajes(0);
		exit(0);
	}
	return nvo;

}

void darDatos(Expediente * exp){
	printf("Introduzca el numero de folio:\n");
	scanf("%d", &exp->num_folio);
	getchar();
	printf("Introduzca el nombre del cliente:\n");
	scanf("%[^\n]", exp->nombre_cliente);
	getchar();
	printf("Introduzca el tramite(P=penal o D=divorcio):\n");
	scanf("%c", &exp->tramite);
	getchar();
	printf("Introduzca el costo:\n");
	scanf("%f", &exp->costo);
}

void mostrar(Expediente* exp){
	printf("\nNumero de folio: %d",exp->num_folio);
	printf("\nNombre del cliente: %s",exp->nombre_cliente);
	printf("\nTipo de tramite: ");
	if (exp->tramite=='P')
		printf("Penal");
	else if (exp->tramite=='D')
		printf("Divorcio");
	else
		printf("No valido");
	printf("\nCosto: $%.2f",exp->costo);
	printf("\n");
}

void liberar(Expediente* exp){
	free(exp);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}
