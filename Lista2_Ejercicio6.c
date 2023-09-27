#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[15];
    char ap_pater[15];
    int edad;
    char sexo;
    char aficiones[7];
}Cliente;

int imprimirMenu();
void menu(Cliente*);
Cliente * crearArreglo(Cliente*);
Cliente * agregarCliente(Cliente*, int*);
Cliente pedirDatos(Cliente *);
int buscarNombre(Cliente*, int);
void casar(Cliente*, int *);
void mostrar(Cliente);
void liberar(Cliente*);
void Mensajes(int);

void main(){
    Cliente * p1;
    p1 = crearArreglo(p1);
    menu(p1);
}

int imprimirMenu(){
    int op;
    printf("Agencia Matrimonial\n");
    printf("1.- Agregar Cliente\n");
    printf("2.- Buscar Por Nombre\n");
    printf("3.- Casar\n");
    printf("4.- Salir\n");
    printf("Ingrese una opcion:\n");
    scanf("%d",&op);
    getchar();
    return op;
}

void menu(Cliente * p1){
    int op = 0, n=0;
    do
    {
        op = imprimirMenu();
        switch (op){
            case 1:
                p1 = agregarCliente(p1,&n);
                break;
            case 2:
                buscarNombre(p1,n);
                break;
            case 3:
                casar(p1,&n);
                break;
            case 4:
                liberar(p1);
                break;
            default:
                printf("Opcion no valida");
                break;
    }
    } while (op!=4);
    
}

Cliente * crearArreglo(Cliente * p1){
	p1=(Cliente *)malloc(1000*sizeof(Cliente));
	if(p1==NULL){
		Mensajes(0);
		exit(0);
	}
	return p1;
}


Cliente * agregarCliente(Cliente * p1, int * n){
	printf("Introduzca los datos de la persona\n");
	printf("Nombre:\n");
	scanf("%[^\n]", p1[*n].nombre);
	getchar();
    printf("Apellido Paterno:\n");
	scanf("%[^\n]", p1[*n].ap_pater);
	getchar();
	printf("Edad:\n");
	scanf("%d", &p1[*n].edad);
	getchar();
	printf("Sexo: (M, F)\n");
	scanf("%c", &p1[*n].sexo);
	getchar();
	printf("Aficiones: (Y/N)\n");
    printf("1.- Lectura: ");
    scanf("%c", &p1[*n].aficiones[0]);
    getchar();
    printf("2.- Viajes: ");
    scanf("%c", &p1[*n].aficiones[1]);
    getchar();
    printf("3.- Deportes:");
    scanf("%c", &p1[*n].aficiones[2]);
    getchar();
    printf("4.- Cine: ");
    scanf("%c", &p1[*n].aficiones[3]);
    getchar();
    printf("5.- Gastronomia: ");
    scanf("%c", &p1[*n].aficiones[4]);
    getchar();
    printf("6.- Juegos De Mesa: ");
    scanf("%c", &p1[*n].aficiones[5]);
    getchar();
    printf("7.- Perros: ");
    scanf("%c", &p1[*n].aficiones[6]);
    getchar();
    *n=*n+1;
	return p1;
}

int buscarNombre(Cliente* p1, int n){
    char nombre[15];
    printf("Ingrese el nombre que desea buscar: \n");
    scanf("%[^\n]", nombre);
	getchar();
    for(int i = 0; i<n; i++){
        if(strcmp(nombre,p1[i].nombre)==0){
            printf("Mostrando datos de %s:\n",nombre);
            mostrar(p1[i]);
            return i;
        }
    }
    printf("No hay ningun cliente registrado con el nombre %s\n",nombre);
    return -1;
}

void casar(Cliente * p1, int * n){
    int index,val=1,k;
    char borrar;
    index = buscarNombre(p1,*n);
    if(index != -1){
        for(int i = 0; i<*n; i++){
            if(p1[index].sexo != p1[i].sexo && index != i){
                for(int j=0;j<7;j++){
                    if(p1[index].aficiones[j]=='Y' && p1[i].aficiones[j]!='Y'){
                        val=0;
                        break;
                    }
                }
                if (val){
                    printf("Mostrando datos de posible pareja:\n");
                    mostrar(p1[i]);
                    printf("Confirmar Eliminacion: (Y/N)\n");
                    scanf("%c",&borrar);
                    if(borrar=='Y'){
                        for(k = i; k < *n-1; k++)
                            p1[k] = p1[k+1];
                        for(k = index; k < *n-1; k++)
                            p1[k] = p1[k+1];
                        *n=*n-2;
                        printf("Eliminados correctamente\n");
                    }
                    return;
                }
            }
        }
        
    }
    printf("No hay parejas compatibles\n");
}

void mostrar(Cliente p1){
    char aficiones[7][20]={"Lectura","Viajes","Deportes","Cine", "Gastronomia"
    ,"Juegos de mesa", "Perros"};
    printf("Nombre: %s\n",p1.nombre);
    printf("Apellido Paterno: %s\n",p1.ap_pater);
	printf("Edad: %d\n",p1.edad);
    printf("Sexo: ");
    if(p1.sexo=='M'){
        printf("Masculino\n");
    } else if (p1.sexo=='F'){
        printf("Femenino\n");
    } else {
        printf("No valido\n");
    }
    printf("Aficiones: \n");
    for(int i;i<7;i++){
        if(p1.aficiones[i]=='Y')
            printf("-%s\n",aficiones[i]);
    }
}

void liberar(Cliente* p1){
	free(p1);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}