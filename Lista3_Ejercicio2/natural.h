#include<stdio.h>
#ifndef  _natural_
#define  _natural_

typedef int NATURAL;

// operaciones
NATURAL crearNatural(int);
int esCero(NATURAL);
NATURAL sucesor(NATURAL); 
int esMenor(NATURAL, NATURAL);
int esMenorIgual(NATURAL, NATURAL);
int esMayor(NATURAL, NATURAL);
int esMayorIgual(NATURAL, NATURAL);
NATURAL predecesor(NATURAL);

#endif
