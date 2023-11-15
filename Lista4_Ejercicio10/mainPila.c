#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void menu(PILA);
void mostrarOpciones();
void manejaMsg(int);
int numElem(PILA);
Vehiculo registrarVehiculo();
void sacarPlaca(PILA);
void agregarVehiculo(PILA);
void liberarMem(PILA);

void main(){
	PILA P=crearPila();
	menu(P);
}

void menu(PILA P){
    int op;
    do{
        mostrarOpciones();
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d",&op);
        printf("\n");
        switch (op)
        {
        case 1:
			agregarVehiculo(P); 
            break;
        case 2:
			sacarPlaca(P);
            break;
        case 3:
			liberarMem(P);
            break;
        default:
            printf("¡Opcion no valida! Ingrese una opcion valida\n");
            break;
        }
    }while(op!=3);
}

void mostrarOpciones(){
    printf("\n\t\tEstacionamiento\n\n");
    printf("1.- Registrar Vehiculo\n");
    printf("2.- Sacar Vehiculo\n");
    printf("3.- Salir\n\n");
}

Vehiculo registrarVehiculo(){
	Vehiculo car;
	printf("Ingrese los datos del vehiculo\n");
	printf("Placa: ");
	scanf("%d",&car.placa);
	getchar();
	printf("Estado: ");
	scanf("%[^\n]",car.estado);
	getchar();
	printf("Marca: ");
	scanf("%[^\n]",car.marca);
	getchar();
	printf("Modelo: ");
	scanf("%[^\n]",car.modelo);
	getchar();
	printf("Año: ");
	scanf("%d",&car.año);
	getchar();
	printf("Nombre del propietario: ");
	scanf("%[^\n]",car.propietario);
	getchar();
	return car;
}

int numElem(PILA P){
	PILA temp = crearPila();
	int sum=0;
	while(!es_vaciaPila(P)){
		sum++;
		apilar(temp, desapilar(P));
	}
	printf("\n");
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
	return sum;
}

void agregarVehiculo(PILA P){
	Vehiculo car;
	if(numElem(P)<10){
		car = registrarVehiculo();
		apilar(P, car);
	}else
		printf("Estacionamiento lleno\n");
}

void sacarPlaca(PILA P){
	PILA temp = crearPila();
	Vehiculo car;
	int placa;
	printf("Ingrese la placa del vehiculo: \n");
	scanf("%d",&placa);
	if(es_vaciaPila(P))
		printf("Estacionamiento vacio\n");
	while(!es_vaciaPila(P)){
		car = desapilar(P);
		if(car.placa == placa){
			printf("Sacando vehiculo...\n");
			break;
		}
		apilar(temp, car);
	}
	if(es_vaciaPila(P) && !es_vaciaPila(temp))
		printf("Vehiculo no encontrado\n");
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","La Pila esta llena . . .","La Pila esta vacia . . ."};
	printf("%s", mensajes[msg] );
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}


