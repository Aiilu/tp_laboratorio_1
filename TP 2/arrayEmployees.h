#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define OCUPADO 1
#define VACIO 0
#define T 3

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

void inicializarX(eEmpleado[],int);
void menuPrincipal(eEmpleado[],int);
void menuInformes(eEmpleado[],int);
int buscarLibre(eEmpleado[],int);
int buscarXid(eEmpleado[],int,int);
int cargarID();
void darAlta(eEmpleado[],int);
void mostrarEmpleado(eEmpleado x);
void mostrarEmpleados(eEmpleado[],int);
void darModificacion(eEmpleado[],int);
void darBaja(eEmpleado[],int);
void ordenar(eEmpleado[],int);
void promediar(eEmpleado[],int);
void validarString(char x[]);
float validarFloat(char sueldo[]);
