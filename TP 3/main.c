#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();

int main()
{
    char seguir = 's';

    //Aca hago la struct y le doy los valores, retorna un nuevoLinkedList
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==-1)
                {
                    printf("No hay ningun .csv a levantar\n");
                }
                else
                {
                printf("Cargo exitosamente\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.csv",listaEmpleados)==-1)
                {
                    printf("No hay ningun .csv a levantar\n");
                }
                else
                {
                    printf("Cargo exitosamente\n");
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                printf("Bay\n");
                seguir = 'n';
                break;
            default:
                printf("Esto no existe\n");
                break;
        }

        system("pause");
        system("cls");

    }while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    printf("1. Cargar en texto\n");
    printf("2. Cargar en binario\n");
    printf("3. Alta\n");
    printf("4. Modificar\n");
    printf("5. Baja\n");
    printf("6. Listar\n");
    printf("7. Ordenar\n");
    printf("8. Guardar en texto\n");
    printf("9. Guardar en binario\n");
    printf("10. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
