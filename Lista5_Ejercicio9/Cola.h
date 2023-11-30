// DEFINICION DEL TAD
#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct
{
    int num_cliente;
    char nombre[20];
    int estado;
    float monto;
}Cliente;


typedef struct{
Cliente cola [TAMCOLA];
int primero, ultimo;
int tam;
}Cola;

typedef Cola * COLA;
COLA crearCola ();
int es_vaciaCola(COLA C);
void encolar (COLA C, Cliente x);
Cliente desencolar (COLA C);
Cliente primero(COLA C);
void liberarCOLA(COLA C);
void manejaMsg(int msg);
#endif