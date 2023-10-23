#include<stdlib.h>
#include<math.h>
#include "natural.h"

void manejaMsg(int);

NATURAL crearNatural(int n){
   NATURAL C = fabs(n);
   return C;
}
int esCero(NATURAL N){
    if(N == 0)
        return 1;
    else
        return 0;
}
NATURAL sucesor(NATURAL N1){
    int valor = N1 + 1;
    NATURAL N2 = crearNatural(valor);
    return N2;
}
int esMenor(NATURAL N1, NATURAL N2){
    int valores[2];
    valores[0] = N1;
    valores[1] = N2;
    int menor;
    for (int i=0; i<valores[0]; i++){
        valores[1] = valores[1]-1;
        menor=1;
        if(valores[1]<=0)
            menor=0;
    }
    if(menor==0)
        return 0;
    else
        return 1;
}
int esMenorIgual(NATURAL N1, NATURAL N2){
    int valores[2];
    valores[0] = N1;
    valores[1] = N2;
    int menorIgual;
    for (int i=0; i<valores[0]; i++){
        valores[1] = valores[1]-1;
        menorIgual=1;
        if(valores[1]<0)
            menorIgual=0;
    }
    if(menorIgual==0)
        return 0;
    else
        return 1;
}
int esMayor(NATURAL N1, NATURAL N2){
    int valores[2];
    valores[0] = N1;
    valores[1] = N2;
    int mayor;
    for (int i=0; i<valores[0]; i++){
        valores[1] = valores[1]-1;
        mayor=1;
        if(valores[1]>=0)
            mayor=0;
    }
    if(mayor==0)
        return 0;
    else
        return 1;
}
int esMayorIgual(NATURAL N1, NATURAL N2){
    int valores[2];
    valores[0] = N1;
    valores[1] = N2;
    int mayor;
    for (int i=0; i<valores[0]; i++){
        valores[1] = valores[1]-1;
        mayor=1;
        if(valores[1]>0)
            mayor=0;
    }
    if(mayor==0)
        return 0;
    else
        return 1;
}
NATURAL predecesor(NATURAL N1){
    int valor = N1 - 1;
    NATURAL N2 = crearNatural(valor);
    return N2;
}