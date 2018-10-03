
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define EMP 5

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

void menuOpcion(eEmpleado[],int);
void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam);
int buscarEmpleadoxID(eEmpleado x[], int tam,int id);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado nomina[], int tam);
void agregarEmpleado(eEmpleado empleados[], int tam);
void eliminarEmpleado(eEmpleado *empleados, int tam);
void modificarEmpleado(eEmpleado empleados[], int tam);
void ordenarXSectorYapellido(eEmpleado x[],int tam);
void Promediar(eEmpleado x[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
// PROTOCOLO DE GENERADOR ID
