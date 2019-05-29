#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* f;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        f = fopen(path,"r");

        if(f !=NULL)
        {
            //FALTA EL PARSER
            retorno = 0;
        }

        fclose(f);
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* f;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        f = fopen(path,"rb");

        if(f !=NULL)
        {
            //FALTA EL PARSER
            retorno = 0;
        }

        fclose(f);
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* auxEmp;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf("Listado de Empleados\n");
        printf("\n");
        if(ll_len(pArrayListEmployee) == 0)
        {
            retorno = 2;
        }
        else
        {
             for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
            if(i%32==0)
            {
                auxEmp = ll_get(pArrayListEmployee,i);
                mostrarEmpleado(auxEmp);
            }
            else
            {
                auxEmp = ll_get(pArrayListEmployee,i);
                mostrarEmpleado(auxEmp);
            }
           }

           retorno = 1;
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* f;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        f = fopen(path,"w");

        if(f !=NULL)
        {
            fprintf(f,"ID  Nombre  Horas trabajadas  Sueldo\n");

            //RECORRO, BUSCO EL INDICE QUE  QUIERO E IMPRIMO
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}
