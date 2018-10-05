#include <conio.h>
#include <ctype.h>
#include "arrayEmployees.h"

void menuOpcion(eEmpleado x[],int tam)
{
    char opcion;
    char carga='N';
    do
    {
        system("cls");
        printf("   MENU OPCIONES\n");
        printf("   ***************\n");
        printf("   A. Dar de alta \n");
        printf("                  \n");
        printf("   M. Modificar   \n");
        printf("                  \n");
        printf("   B. Dar de baja \n");
        printf("                  \n");
        printf("   I. Informar    \n");
        printf("                  \n");
        printf("   S. Salir    \n");
        printf("   ***************\n");
        printf("Ingrese una opcion");
        opcion=getch();
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'A':
            system("cls");
            validarLugar(x,tam);
            carga = 'S';
            break;
        case 'M':
            if(carga=='S')
            {
                modificarEmpleado(x,tam);
                system("pause");
                break;
            }
            else
            {
                printf("No se han cargado datos \n");
                system("pause");
                break;
            }

        case 'B':
            if(carga=='S')
            {
               eliminarEmpleado(x,tam);
               system("pause");
               break;
            }
            else
            {
                printf("No se han cargado datos \n");
                system("pause");
                break;
            }
        case 'I':
            if(carga=='S')
            {
              subMenuOpcionInformar(x,tam);
              system("pause");
              break;
            }
            else
            {
                printf("No se han cargado datos \n");
                system("pause");
                break;
            }
        case 'S':
            break;

        default:
            printf("Esta opcion es invalida. Intente de nuevo");
        }
    }
    while(opcion !='S');
}
void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}


int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void validarLugar (eEmpleado x[],int tam)
{
    int indice;
    char seguir='s';
    do
    {
        indice = buscarLibre(x,tam);
        if(indice>=0)
        {
            x[indice]=agregarEmpleado();
                }
        else
        {
            printf("El espacio esta lleno. ");
            system("pause");
            break;
        }

        printf("Desea ingresar otro? s / n \n");
        seguir=getch();
    }
    while(seguir=='s');
}


int buscarEmpleado(eEmpleado x[], int tam)
{
    int indice=-1;
    int i;
    for(i=0; i < tam; i++)
    {
        if(x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleadoxID(eEmpleado x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {


        if( x[i].id == id && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int cargarId(void)
{
    static int id = 0;

    return id ++;
}

eEmpleado agregarEmpleado()
{
    eEmpleado nuevoEmpleado;
    system("cls");
    printf("  *** Alta Empleado ***\n\n");

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            validarNombre(nuevoEmpleado.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
                        validarApellido(nuevoEmpleado.apellido);
            printf("Ingrese salario: ");
                        fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.sector=validarNumero();

            nuevoEmpleado.id=cargarId();

            nuevoEmpleado.isEmpty = 1;

return nuevoEmpleado;
}
void mostrarEmpleado(eEmpleado emp)
{
    printf("%4d %10s %10s %5.2f  %10d \n\n", emp.id, emp.nombre, emp.apellido, emp.sueldo, emp.sector);
}


void mostrarEmpleados(eEmpleado nomina[], int tam)
{
    int i;

    system("cls");
    printf(("ID  Nombre  Apellido    Sueldo     Sector\n\n"));
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i]);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam)
{

    int id;
    int indice;
    char borrar;

    mostrarEmpleados(empleados, tam);

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleadoxID(empleados, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el id %d\n", id);
    }
    else
    {
        mostrarEmpleado(empleados[indice]);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(eEmpleado empleados[], int tam)
{

    int id;
    int indice;
    char opcion;
    char modificar;
    char nuevoNombre[51];
    char nuevoApellido[51];
    float nuevoSueldo;
    int nuevoSector;

    mostrarEmpleados(empleados, tam);

    printf("Ingrese ID: ");
    scanf("%d", &id);

    indice = buscarEmpleadoxID(empleados, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el ID %d\n", id);
    }
    else
    {
        mostrarEmpleado( empleados[indice]);

        printf("\nQue desea Modificar?: \t s-Sueldo. r-Sector. a-Apellido. n-Nombre.");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);

        switch (opcion)
{
        case 's':

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
        break;

        case 'r':
        printf("\nModifica sector?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sector: ");
            scanf("%d", &nuevoSector);

            empleados[indice].sector = nuevoSector;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
        break;

        case 'n':
        printf("\nModifica nombre?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo nombre: ");
            gets(nuevoNombre);
            strcpy(nuevoNombre,empleados[indice].nombre);
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
        break;

        case 'a':
        printf("\nModifica nombre?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo nombre: ");
            gets(nuevoApellido);
            strcpy(nuevoApellido,empleados[indice].apellido);
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
        break;
        default:
        printf("La opción ingresada no existe");

}
}
}

void ordenarXSectorYapellido(eEmpleado x[],int tam)
{
    int i, j;
    eEmpleado auxEmpleado;

    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            if( strcmp(x[i].apellido, x[j].apellido) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(x[i].apellido, x[j].apellido) == 0 && x[i].sector > x[j].sector)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }
mostrarEmpleados(x, tam);
}

void promediar(eEmpleado x[], int tam)
{
    int i;
    int contadorDeSueldos=0;
    float sumaDeSueldos=0;
    float promDeSueldos;
    int contadorMaximoSueldo=0;
    for (i=0; i<tam; i++)
    {
        if(x[i].isEmpty==1)
        {
            sumaDeSueldos+=x[i].sueldo;
            contadorDeSueldos++;
        }
    }
    promDeSueldos=sumaDeSueldos/contadorDeSueldos;
    printf("La suma de los sueldos es de: %f \n el promedio total seria: %f \n", sumaDeSueldos, promDeSueldos);

    for(i=0; i<tam; i++)
    {
        if(x[i].isEmpty==1 && x[i].sueldo>promDeSueldos)
        {
            mostrarEmpleado(x[i]);
            contadorMaximoSueldo++;
        }
    }
    printf("La cantidad de empleados que superan el sueldo promedio es de: %d \n ", contadorMaximoSueldo);

    system("pause");
}

void subMenuOpcionInformar(eEmpleado x[],int tam)
 {
    char opcion;
    do
    {
        system("cls");
        printf("        ****************************************************\n ");
        printf("                             Informes    \n ");
        printf("        ******************************************************\n ");

        printf("          M. Mostrar alumnos ordenados por Sector y Apellido\n");
        printf("                                                             \n ");
        printf("          P. Promedio y Total de salarios\n");
        printf("                                                           \n ");
        printf("          V. Volver\n");
        printf("        ******************************************************\n ");
        printf("          Ingrese una opcion: ");
        opcion=getch();
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'M':
            system("cls");
            ordenarXSectorYapellido(x,tam);
            system("pause");
            break;
        case 'P':
            system("cls");
            promediar(x,tam);
                        system("pause");
            break;
        case 'A':
            system("cls");
            break;

        case 'S':
            system("cls");
            break;
        }
    }
    while(opcion!='V');
 }

 int validarNumero()
{
    int i;
    char sector[3];
    int sectorV;
    printf("Ingrese el sector: ");
    scanf("%s", sector);
            fflush(stdin);
        for(i=0;i<strlen(sector);i++)
    {
         do
        {
            printf("reingrese valor: ");
            fflush(stdin);
            scanf("%s", sector);
        }while(!(isdigit(sector[i])));
    sectorV=atoi(sector);
    }
    return sectorV;
}

void validarApellido(char apellido[])
{
    int i;
    for(i=0;i<strlen(apellido);i++)
    {
        if(apellido[i]==' ')
        {
         break;
        }
        while (isdigit(apellido[i]))
        {
            printf("Reingrese un apellido valido \n");
            gets(apellido);
        }
    }
}

    void validarNombre(char nombre[])
{
    int i;
    for(i=0;i<strlen(nombre);i++)
    {
        if(nombre[i]==' ')
        {
         break;
        }
        while (isdigit(nombre[i]))
        {
            printf("Reingrese un nombre valido \n");
            gets(nombre);
        }

    }
}
