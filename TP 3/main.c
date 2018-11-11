#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

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


int main()
{
    int opcion = 0;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    printf("\n----------------------------------------------------------------------------------");
    printf("\n                                MENU                                              ");
    printf("\n----------------------------------------------------------------------------------");
    printf("\n                                                                                  ");
    printf("\n* 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)    *");
    printf("\n* 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)  *");
    printf("\n* 3. Alta de empleado                                                            *");
    printf("\n* 4. Modificar datos de empleado                                                 *");
    printf("\n* 5. Baja de empleado                                                            *");
    printf("\n* 6. Listar empleados                                                            *");
    printf("\n* 7. Ordenar empleados                                                           *");
    printf("\n* 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)      *");
    printf("\n* 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)    *");
    printf("\n* 10. Salir                                                                      *");
    printf("\n  Ingrese una opcion: ");
    scanf("%d" , & opcion);

    switch(opcion)
    {
        case 1:
            system("cls");
            controller_loadFromText("data.csv",listaEmpleados);
            system("pause");
            flag = 1;
            break;
        case 2:
            system("cls");
            if(flag==1)
            {
            controller_loadFromBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los datos");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(flag==1)
            {
            controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los datos");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(flag==1)
            {
            controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los datos");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(flag==1)
            {
            controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los datos");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(flag==1)
            {
            controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los datos");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(flag==1)
            {
            controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los datos");
            }
            system("pause");
            break;
        case 8:
            system("cls");
            if(flag==1)
            {
            controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 9:
            system("cls");
            if(flag==1)
            {
            controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 10:
            break;
        default:
            printf("Esta opcion no existe");
            system("pause");
    }
    }while(opcion != 10);
    return 0;
}

