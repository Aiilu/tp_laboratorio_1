#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char buffer[4][128];
    int cant;
    Employee* auxEmp;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);

                if(cant < 4)
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    else
                    {
                        printf("Problemas para leer el archivo\n");
                        break;
                    }
                }

                //ACA LO AUMENTO COMO CON EL REALLOC

                if(auxEmp !=NULL)
                {
                    //ACA LO METO EN LA STRUCT
                }
        }

        retorno = 0;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
     int retorno = -1;
     int cant;
     Employee* auxEmp;

     if(pFile !=NULL && pArrayListEmployee !=NULL)
     {
        while(!feof(pFile))
        {
            //aca va a seguir pidiendo espacio en la memoria para meterlo
            auxEmp = employee_new();

            if(auxEmp !=NULL)
            {
                cant = fread(auxEmp,sizeof(Employee),1,pFile);

                if(cant < 1)
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    else
                    {
                        printf("Problemas para leer el archivo\n");
                        break;
                    }
                }

                //ACA COPIO LOS VALORES ENCONTRADOS
            }
        }

        retorno = 0;
     }

     return retorno;
}
