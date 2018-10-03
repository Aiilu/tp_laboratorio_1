
#include "arrayEmployees.h"

void menuOpcion(eEmpleado list[],int len)
{
    char opcion;
    char carga='N';
    do
    {
        system("cls");
        printf("MENU OPCIONES\n");
        printf("A. Dar de alta\n");
        printf("M. Modificar\n");
        printf("B. Dar de baja\n");
        printf("I. Informar\n");
        printf("Ingrese una opcion");
        opcion=getche();
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'A':
            system("cls");
            agregarEmpleado(list,len);
            carga = 'S';
            break;

        case 'M':
            if(carga=='S')
            {
                //modificar(list,len);
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

int buscarEmpleado(eEmpleado x[], int tam)
{
    int indice = -1;
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

void agregarEmpleado(eEmpleado empleados[], int tam)
{
    eEmpleado nuevoEmpleado;
    int indice;


    system("cls");
    printf("  *** Alta Empleado ***\n\n");

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        indice = buscarEmpleado(empleados, tam);


            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
            printf("Ingrese salario: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);
            printf("Ingrese sector: ");
            fflush(stdin);
            scanf("%d", &nuevoEmpleado.sector);

            nuevoEmpleado.id=cargarId();

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }

    }

void mostrarEmpleado(eEmpleado emp)
{
    printf(("ID  Nombre  Apellido    Sueldo     Sector\n\n"));
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
        printf("La opci�n ingresada no existe");

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

}

void Promediar(eEmpleado x[], int tam)
{
    int i;
    int contsueldos=0;
    float sumasueldos=0;
    float promediosueldos;
    int contMassueldo=0;
    for (i=0; i<tam; i++)
    {
        if(x[i].isEmpty==0)
        {
            sumasueldos+=x[i].sueldo;
            contsueldos++;
        }
    }
    promediosueldos=sumasueldos/contsueldos;
    printf("La suma de los sueldos es de: %f \n el promedio total seria: %f \n", sumasueldos, promediosueldos);

    for(i=0; i<tam; i++)
    {
        if(x[i].isEmpty==0 && x[i].sueldo>promediosueldos)
        {
            mostrarEmpleado(x[i]);
            contMassueldo++;
        }
    }
    printf("La cantidad de empleados que superan el sueldo promedio es de: %d \n ", contMassueldo);

    system("pause");
}
