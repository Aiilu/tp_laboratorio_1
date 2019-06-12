#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    char valOpcion[3];
    char seguir = 's';

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system ("COLOR F4");
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                         Trabajo Practico Nro. 3                            #\n");
        printf(" #                                                                            #\n");
        printf(" #                         >>>> MENU DE OPCIONES <<<<                         #\n");
        printf(" ==============================================================================\n");
        printf(" |                                                                            |\n");
        printf("   1- Cargar datos de los empleados desde el archivo data.csv (modo texto)     \n");
        printf(" |                                                                            |\n");
        printf("   2- Cargar datos de los empleados desde el archivo data.bin (modo binario)   \n");
        printf(" |                                                                            |\n");
        printf("   3- Alta de empleado                                                         \n");
        printf(" |                                                                            |\n");
        printf("   4- Modificar datos de empleado                                              \n");
        printf(" |                                                                            |\n");
        printf("   5- Baja de empleado                                                         \n");
        printf(" |                                                                            |\n");
        printf("   6- Listar de empleados                                                      \n");
        printf(" |                                                                            |\n");
        printf("   7- Ordenar empleados                                                        \n");
        printf(" |                                                                            |\n");
        printf("   8- Guardar datos de los empleados en el archivo data.csv (modo texto)       \n");
        printf(" |                                                                            |\n");
        printf("   9- Guardar datos de los empleados en el archivo data.bin (modo binario)     \n");
        printf(" |                                                                            |\n");
        printf("   10- Salir                                                                   \n");
        printf(" |                                                                            |\n");
        printf(" ==============================================================================\n");
        printf("                                                                               \n");
        printf(" Ingrese una opcion del menu: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            printf("\n");
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            printf("\n");
            controller_loadFromBinary("data.bin",listaEmpleados);
            break;
        case 3:
            printf("\n");
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            printf("\n");
            if(ll_len(listaEmpleados)==0)
            {
                printf(" No hay ningun empleado\n");
            }
            else
            {
               controller_editEmployee(listaEmpleados);
            }
            break;
        case 5:
            printf("\n");
            if(ll_len(listaEmpleados)==0)
            {
                printf(" No hay ningun empleado que mostrar\n");
            }
            else
            {
                controller_removeEmployee(listaEmpleados);
            }
            break;
        case 6:
            printf("\n");
            if(ll_len(listaEmpleados)==0)
            {
                printf(" No hay ningun empleado que mostrar\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }
            break;
        case 7:
            printf("\n");
            if(ll_len(listaEmpleados)==0)
            {
                printf(" No hay ningun empleado que mostrar\n");
            }
            else
            {
                 controller_sortEmployee(listaEmpleados);
            }
            break;
        case 8:
            printf("\n");
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            printf("\n");
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;
        case 10:
            system("cls");
            seguir = 'n';

            printf(" ==============================================================================\n");
            printf(" #                              Saliendo...                                   #\n");
            printf(" ==============================================================================\n");
            printf(" |                                                                            |\n");
            printf(" |                             Hasta luego!!!                                 |\n");
            printf(" |                                                                            |\n");
            printf(" ==============================================================================\n");

            break;
        default:
            printf("\n\n");
            printf(" ERROR. Esta opcion no es correcta\n");
        }

        fflush(stdin);
        printf(" Presione ENTER para continuar");
        getchar();
    }
    while(seguir == 's');

    return 0;
}
