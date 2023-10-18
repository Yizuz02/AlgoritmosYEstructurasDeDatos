#ifndef  _fraccion_
#define  _fraccion_

typedef struct{
   int numerador;
   int denominador;
}Fraccion;

typedef Fraccion * FRACCION;


// operaciones
FRACCION crearFraccion(void);
void asignaNum(FRACCION F,  int n);
void asignaDenom(FRACCION F, int d);
int obtenNum(FRACCION F);
int obtenDenom(FRACCION F);
FRACCION producto(FRACCION F1, FRACCION F2);
FRACCION division(FRACCION F1, FRACCION F2);
int impropia(FRACCION F);
FRACCION mayor(FRACCION F1, FRACCION F2);
int igual(FRACCION F1, FRACCION F2);
#endif

