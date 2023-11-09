#include<stdio.h>
#include<stdlib.h>
#include "evaPostfija.h"

void mostrarSalida(char * ent, float ev);
float evalua(PILA S, char *ent);
void lee(char *ent);
float yizExp(float, float);
void manejaMsg(int e);
void liberar(PILA);

/*Programa Principal*/
void main(){
	PILA S;
  float ev;
  char ent[TAMPILA];
  
  crearPila(&S);
  
  lee(ent);
  ev = evalua(S, ent);
  mostrarSalida(ent, ev);
  liberar(S);  
}

/* Lee una expresión en Postfija */
void lee(char *ent){

  int pos=0;
  
  printf("\n\tEvaluacion de expresiones Postfijas\n");
  printf("Operaciones Basicas: Suma, Resta, Producto, Division y Potencia\n\n");
  printf("\n\n Introduzca la expresion en Postfija: ");
  while( (ent[pos++] = getchar()) != '\n');
  ent[--pos]='\0';
}


/*Evalua la expresion*/
float evalua(PILA S, char *ent){
  float a,b;
  double conv;
  int pos=0;
  char op[1];

  while(ent[pos] != '\0'){
      *op = ent[pos++];
      
      switch(*op){
        case '+': b=desapilar(S);
                  a=desapilar(S);
                  apilar(S, a+b);
                  break;
       case '-': b=desapilar(S);
                 a=desapilar(S);
                 apilar(S, a-b);
                 break;
       case '*': b=desapilar(S);
                 a=desapilar(S);
                 apilar(S, a*b);
                 break;
       case '/': b=desapilar(S);
                 a=desapilar(S);
                 if(b==0){
		    manejaMsg(3);
                    exit(0);
                }
                apilar(S, a/b);
                break;
      case '^': b=desapilar(S);
                 a=desapilar(S);
                 apilar(S, yizExp(a,b));
                 break;
      default: conv = atof(op);//convierte un caracter a float
               apilar(S, conv); //Almacena el valor (numero) en la pila

      }
  }
return (desapilar(S));
}

float yizExp(float a, float b){
	if(b==0)
		return 1;
	else if (b>0)
		return yizExp(a,b-1)*a;
	else
		return  1/(yizExp(a,b*-1));
}

void mostrarSalida(char * ent, float ev){
   printf("\n\n\t %s = %.2f \n\n", ent, ev);
}

void liberar(PILA S){
    free(S);
    manejaMsg(4);
}
void manejaMsg(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n", "\n\n Division por CERO\n", "Memoria Liberada ..."};
  printf("%s", errores[e]);
}
