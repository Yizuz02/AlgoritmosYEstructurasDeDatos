#include<stdlib.h>
#include<math.h>
#include "complejo.h"

void manejaMsg(int);

COMPLEJO crearComplejo(void){
   COMPLEJO C;
   C = (COMPLEJO)malloc(sizeof(Complejo));
   if( C == NULL){
        manejaMsg(0);
        exit(0);
   }
}
void asignaReal(COMPLEJO C,  float r){
    C -> real = r;
}
void asignaImaginario(COMPLEJO C, float i){
      C -> imaginario = i;
}

float obtenReal(COMPLEJO C){
       return ( C -> real);
}

float obtenImaginario(COMPLEJO C){
      return ( C -> imaginario);
}

COMPLEJO suma(COMPLEJO C1, COMPLEJO C2){
      COMPLEJO C3 =  crearComplejo();
      asignaReal( C3, obtenReal(C1) + obtenReal(C2) );
      asignaImaginario( C3, obtenImaginario(C1) + obtenImaginario(C2) );
       return C3;
}

COMPLEJO resta(COMPLEJO C1, COMPLEJO C2){
      COMPLEJO C3 =  crearComplejo();
      asignaReal( C3, obtenReal(C1) - obtenReal(C2) );
      asignaImaginario( C3, obtenImaginario(C1) - obtenImaginario(C2) );
      return C3;
}

float mod(COMPLEJO C){
      float modulo = sqrt((pow(obtenReal(C),2))+(pow(obtenImaginario(C),2)));
      return modulo;
}

float angulo(COMPLEJO C){
      float a = atan(obtenImaginario(C)/(obtenReal(C)*1.00));
      return a;
}

float convPolar(COMPLEJO C){
      return angulo(C)*mod(C);
}

COMPLEJO convTrigonometrica(COMPLEJO C1){
      COMPLEJO C2 =  crearComplejo();
      asignaReal( C2, mod(C1) * cos(angulo(C1)));
      asignaImaginario( C2, mod(C1) * sin(angulo(C1)));
      return C2;
}


