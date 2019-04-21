#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "arrayEmployees.h"

void inicializarX(eEmpleado x[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        x[i].isEmpty = VACIO;
    }
}

void menuPrincipal(eEmpleado x[],int tam)
{
    int opcion;
    int flag;
    char seguir = 's';
    char valOpcion[10];

    do
    {
        system ("COLOR F0");
        system("cls");
        printf("     =================================================\n");
        printf("     #            Trabajo Practico Nro. 2            #\n");
        printf("     #                                               #\n");
        printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
        printf("     =================================================\n");
        printf("     |                                               |\n");
        printf("                       1- Alta                        \n");
        printf("     |                                               |\n");
        printf("                       2- Modificar                   \n");
        printf("     |                                               |\n");
        printf("                       3- Baja                        \n");
        printf("     |                                               |\n");
        printf("                       4- Informes                    \n");
        printf("     |                                               |\n");
        printf("                       5- Salir                       \n");
        printf("     |                                               |\n");
        printf("     =================================================\n");
        printf("                                                      \n");
        printf("     Ingrese una opcion del menu: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = atoi(valOpcion);

        while(opcion == 0)
        {
            printf("ERROR. Ingrese un valor valido: ");
            gets(valOpcion);

            opcion = atoi(valOpcion);
        }

        switch(opcion)
        {
        case 1:
            system("cls");
            darAlta(x,tam);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                system("cls");
                darModificacion(x,tam);
            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los datos!\n");
            }
            break;
        case 3:
            if(flag == 1)
            {
                system("cls");
                darBaja(x,tam);
            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los datos!\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                menuInformes(x,tam);

            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los datos!\n");
            }
            break;
        case 5:
            system("cls");
            seguir = 'n';

            printf("     ==========================================\n");
            printf("     #               Saliendo...              #\n");
            printf("     ==========================================\n");
            printf("     |                                        |\n");
            printf("     |              Hasta luego!!!            |\n");
            printf("     |                                        |\n");
            printf("     ==========================================\n");

            break;
        default:
            printf("\n\n");
            printf("     ERROR. Esta opcion no es correcta\n");
        }

        fflush(stdin);
        printf("     Presione ENTER para continuar");
        getchar();

    }
    while(seguir == 's');
}

void menuInformes(eEmpleado x[],int tam)
{
    char seguir = 's';
    int opcion;
    char valOpcion[10];

    system("cls");

    do
    {
        printf("     =================================================\n");
        printf("     #                                               #\n");
        printf("     #               >>>> INFORMES <<<<              #\n");
        printf("     #                                               #\n");
        printf("     =================================================\n");
        printf("     |                                               |\n");
        printf("         1- Mostrar ordenados por Sector/Apellido     \n");
        printf("     |                                               |\n");
        printf("         2- Promedio y Total de Salarios              \n");
        printf("     |                                               |\n");
        printf("         3- Salir                                      \n");
        printf("     |                                               |\n");
        printf("     =================================================\n");
        printf("                                                      \n");
        printf("     Ingrese una opcion del menu: ");
        gets(valOpcion);

        opcion = atoi(valOpcion);

        while(opcion == 0)
        {
            printf("ERROR. Ingrese un valor valido: ");
            gets(valOpcion);

            opcion = atoi(valOpcion);
        }

        switch(opcion)
        {
        case 1:
            system("cls");
            ordenar(x,tam);
            system("pause");
            break;
        case 2:
            system("cls");
            promediar(x,tam);
            system("pause");
            break;
        case 3:
            seguir = 'n';
            break;
        default:
            printf("Esta opcion no es valida\n");
            system("pause");
        }

        system("cls");
    }
    while(seguir == 's');

}

int buscarLibre(eEmpleado x[],int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(x[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarXid(eEmpleado x[],int tam, int id)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(x[i].id == id && x[i].isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void darAlta(eEmpleado x[],int tam)
{
    int index;
    char seguir = 's';
    char nombre[51];
    char apellido[51];
    char sueldo[10];
    char sector[5];

    do
    {
        printf("     =================================================\n");
        printf("     #                                               #\n");
        printf("     #              >>>> Alta Empleado <<<<          #\n");
        printf("     #                                               #\n");
        printf("     =================================================\n");

        index = buscarLibre(x,tam);

        if(index == -1)
        {
            printf("     No hay mas espacio para cargar\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {
            printf("     Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            validarString(nombre);

            strcpy(x[index].nombre,nombre);

            printf("     Ingrese apellido: ");
            fflush(stdin);
            gets(apellido);

            validarString(apellido);

            strcpy(x[index].apellido,apellido);

            printf("     Ingrese sueldo: ");
            fflush(stdin);
            gets(sueldo);

            x[index].sueldo = validarFloat(sueldo);

            //x[index].sueldo = atof(sueldo);

            /*while(x[index].sueldo == 0)
            {
                printf("Reingrese un valor numerico: ");
                gets(sueldo);

                x[index].sueldo = atof(sueldo);
            }*/

            printf("     Ingrese sector: ");
            fflush(stdin);
            gets(sector);

            /*for(int i=0; i<strlen(sector); i++)
            {
                valsec = sector[i];
                x[index].sector = atoi(valsec);

                if(x[index].sector == 0)
                {
                    printf("Reingrese un valor numerico: ");
                    i=0;
                    gets(sector);

                    //x[index].sector = atoi(valsec);
                }

            }*/

            x[index].sector = atoi(sector);

            while(x[index].sector == 0)
            {
                printf("ERROR. Ingrese un valor valido: ");
                gets(sector);

                x[index].sector = atoi(sector);
            }

            x[index].id  = cargarID();

            x[index].isEmpty = OCUPADO;

            printf("\n\n");

            printf("     Empleado cargado con exito!!\n");

            printf("\n\n");

            printf("Desea ingresar otro? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);

            while(seguir !='s' && seguir !='S' && seguir !='n' && seguir !='N')
            {
                printf("La opcion ingresada no es valida\n");

                printf("Desea ingresar otro? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }

        system("cls");

    }
    while(seguir == 's' || seguir =='S');

}

int cargarID()
{
    static int id = 1;

    return id++;
}

void mostrarEmpleado(eEmpleado x)
{
    printf("%2d %4s %8s %14.2f %7d\n",x.id,x.nombre,x.apellido,x.sueldo,x.sector);
}

void mostrarEmpleados(eEmpleado x[],int tam)
{
    int cont = 0;

    system("cls");

    printf("     =================================================\n");
    printf("     #                                               #\n");
    printf("     #               >>>> Empleados <<<<             #\n");
    printf("     #                                               #\n");
    printf("     =================================================\n");
    printf("\n\n");
    printf(" ID  Nombre  Apellido    Sueldo     Sector\n\n");

    for(int i=0; i<tam; i++)
    {
        if(x[i].isEmpty == OCUPADO)
        {
            cont++;
            mostrarEmpleado(x[i]);
        }
    }

    if(cont == 0)
    {
        printf("     No hay ningun empleado que mostrar\n");
    }
}

void darModificacion(eEmpleado x[],int tam)
{
    int id;
    char valId[10];
    int opcion;
    int indice;
    char seguir;
    char nuevoNombre[51];
    char nuevoApellido[51];
    char valOpcion[10];
    char nuevoSalario[10];
    char nuevoSector[5];

    mostrarEmpleados(x,tam);

    printf("\n\n");

    printf("Ingrese el ID del empleado a modificar: ");
    gets(valId);

    id = atoi(valId);

    while(id == 0)
    {
        printf("ERROR. Ingrese un valor valido: ");
        gets(valId);

        id = atoi(valId);
    }

    indice = buscarXid(x,tam,id);

    if(indice == -1)
    {
        printf("No hay ningun empleado con el ID %d\n",id);
    }
    else
    {
        system("cls");
        printf("     =================================================\n");
        printf("     #                                               #\n");
        printf("     #               >>>> Empleado <<<<              #\n");
        printf("     #                                               #\n");
        printf("     =================================================\n");

        mostrarEmpleado(x[indice]);

        printf("Que desea modificar?\n");
        printf("1. Nombre\n2.Apellido\n3.Salario\n4.Sector\n");
        fflush(stdin);
        gets(valOpcion);

        opcion = atoi(valOpcion);

        while(opcion == 0)
        {
            printf("ERROR. Ingrese un valor valido: ");
            gets(valOpcion);

            opcion = atoi(valOpcion);
        }

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #           >>>> Modificar nombre <<<<          #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");
            printf("Esta seguro de esta modificacion? s/n \n");
            fflush(stdin);
            scanf("%c",&seguir);

            while(seguir !='s' && seguir !='S' && seguir !='n' && seguir !='N')
            {
                printf("La opcion ingresada no es valida\n");

                printf("Desea ingresar otro? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }

            if(seguir == 's' || seguir == 'S')
            {
                printf("Ingrese un nuevo nombre: ");
                fflush(stdin);
                gets(nuevoNombre);


                for(int i=0; i<strlen(nuevoNombre); i++)
                {
                    while(isalpha(nuevoNombre[i]) == 0)
                    {
                        printf("Reingrese nombre: ");
                        fflush(stdin);
                        gets(nuevoNombre);
                        i=0;
                    }
                }

                strcpy(x[indice].nombre,nuevoNombre);

                printf("Modificacion exitosa!\n");

            }
            else
            {
                printf("Modificacion cancelada\n");
            }
            break;
        case 2:
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #           >>>> Modificar apellido <<<<        #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");
            printf("Esta seguro de esta modificacion? s/n \n");
            fflush(stdin);
            scanf("%c",&seguir);

            while(seguir !='s' && seguir !='S' && seguir !='n' && seguir !='N')
            {
                printf("La opcion ingresada no es valida\n");

                printf("Desea ingresar otro? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }

            if(seguir == 's' || seguir == 'S')
            {
                printf("Ingrese un nuevo apellido: ");
                fflush(stdin);
                gets(nuevoApellido);


                for(int i=0; i<strlen(nuevoApellido); i++)
                {
                    while(isalpha(nuevoApellido[i]) == 0)
                    {
                        printf("Reingrese apellido: ");
                        fflush(stdin);
                        gets(nuevoApellido);
                        i=0;
                    }
                }

                strcpy(x[indice].apellido,nuevoApellido);

                printf("Modificacion exitosa!\n");

            }
            else
            {
                printf("Modificacion cancelada\n");
            }
            break;
        case 3:
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #           >>>> Modificar salario <<<<         #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");
            printf("Esta seguro de esta modificacion? s/n \n");
            fflush(stdin);
            scanf("%c",&seguir);

            while(seguir !='s' && seguir !='S' && seguir !='n' && seguir !='N')
            {
                printf("La opcion ingresada no es valida\n");

                printf("Desea ingresar otro? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }

            if(seguir == 's' || seguir == 'S')
            {
                printf("Ingrese un nuevo salario: ");
                fflush(stdin);
                gets(nuevoSalario);

                x[indice].sueldo = atof(nuevoSalario);

                while(x[indice].sueldo == 0)
                {
                    printf("Reingrese un valor numerico: ");
                    fflush(stdin);
                    gets(nuevoSalario);

                    x[indice].sueldo = atof(nuevoSalario);
                }

                printf("Modificacion exitosa!\n");

            }
            else
            {
                printf("Modificacion cancelada\n");
            }
            break;
        case 4:
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #            >>>> Modificar sector <<<<         #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");
            printf("Esta seguro de esta modificacion? s/n \n");
            fflush(stdin);
            scanf("%c",&seguir);

            while(seguir !='s' && seguir !='S' && seguir !='n' && seguir !='N')
            {
                printf("La opcion ingresada no es valida\n");

                printf("Desea ingresar otro? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }

            if(seguir == 's' || seguir == 'S')
            {
                printf("Ingrese un nuevo sector: ");
                fflush(stdin);
                gets(nuevoSector);

                x[indice].sector = atoi(nuevoSector);

                while(x[indice].sector == 0)
                {
                    printf("Reingrese un valor numerico: ");
                    fflush(stdin);
                    gets(nuevoSector);

                    x[indice].sector = atoi(nuevoSector);
                }

                printf("Modificacion exitosa!\n");

            }
            else
            {
                printf("Modificacion cancelada\n");
            }
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
}

void darBaja(eEmpleado x[],int tam)
{
    int id;
    char valId[10];
    int indice;
    char seguir;

    mostrarEmpleados(x,tam);

    printf("Ingrese ID empleado a eliminar: ");
    gets(valId);

    id = atoi(valId);

    while(id == 0)
    {
        printf("ERROR. Ingrese un valor valido: ");
        gets(valId);

        id = atoi(valId);
    }


    indice = buscarXid(x,tam,id);

    printf("\n\n");

    if(indice == -1)
    {
        printf("No hay ningun empleado con el ID %d",id);
    }
    else
    {
        mostrarEmpleado(x[indice]);

        printf("Esta seguro de querer borrar este empleado? s/n: \n");
        fflush(stdin);
        scanf("%c",&seguir);

        while(seguir !='s' && seguir !='S' && seguir !='n' && seguir !='N')
        {
            printf("La opcion ingresada no es valida\n");

            printf("Desea ingresar otro? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

        if(seguir == 's' || seguir == 'S')
        {
            x[indice].isEmpty = VACIO;
            printf("Empleado eliminado con exito\n");
        }
        else
        {
            printf("Baja cancelada\n");
        }
    }
}

void ordenar(eEmpleado x[],int tam)
{
    printf("     =================================================\n");
    printf("     #                                               #\n");
    printf("     #           >>>> Ordenar empleados  <<<<        #\n");
    printf("     #                                               #\n");
    printf("     =================================================\n");

    eEmpleado aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(x[i].apellido,x[j].apellido)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
            else if(strcmp(x[i].apellido,x[j].apellido) == 0 && x[i].sector > x[j].sector)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }

    mostrarEmpleados(x,tam);
}

void promediar(eEmpleado x[],int tam)
{
    printf("     =================================================\n");
    printf("     #                                               #\n");
    printf("     #      >>>> Promedio y Total de Salarios <<<<    \n");
    printf("     #                                               #\n");
    printf("     =================================================\n");

    int contSueldos = 0;
    float sumaSueldos = 0;
    int contMaxSueldo = 0;
    float promSueldos;
    int esta = 0;

    for(int i=0; i<tam; i++)
    {
        if(x[i].isEmpty == OCUPADO)
        {
            esta++;
            contSueldos++;
            sumaSueldos+=x[i].sueldo;
        }
    }

    if(esta == 0)
    {
        printf("     No hay empleados\n");
    }
    else
    {
        promSueldos = sumaSueldos/contSueldos;

    printf("La suma total de los salarios es de: %.2f y el promedio total seria: %.2f\n", sumaSueldos,promSueldos);

    for(int i=0; i<tam; i++)
    {
        if(x[i].isEmpty == OCUPADO && x[i].sueldo > promSueldos)
        {
            mostrarEmpleado(x[i]);
            contMaxSueldo++;
            printf("La cant de empleados que superan el sueldo promedio  es de: %d\n",contMaxSueldo);
        }
    }
    }
}

void validarString(char x[])
{
    for(int i=0; i<strlen(x); i++)
    {
        while(isalpha(x[i]) == 0)
        {
            printf("Reingrese solo caracteres alfabeticos: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

float validarFloat(char sueldo[])
{
    float sueldoK;

    for(int i=0; i<strlen(sueldo); i++)
    {
           if(sueldo[i] == ',')
            {
                sueldo[i] = '.';
            }
    }

    sueldoK = atof(sueldo);

    while(sueldoK == 0)
    {
        printf("Reingrese un valor numerico: ");
        gets(sueldo);

        sueldoK = atof(sueldo);
    }

    return sueldoK;
}
