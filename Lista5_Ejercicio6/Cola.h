// DEFINICION DEL TAD
#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct
{
    char nombre[20];
    char sexo;
    int edad;
    int ticket;
    int atencion;
}Persona;


typedef struct{
Persona cola [TAMCOLA];
int primero, ultimo;
int tam;
}Cola;

typedef Cola * COLA;
COLA crearCola ();
int es_vaciaCola(COLA C);
void encolar (COLA C, Persona x);
Persona desencolar (COLA C);
Persona primero(COLA C);
void liberarCOLA(COLA C);
void manejaMsg(int msg);
#endif