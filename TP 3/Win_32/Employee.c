#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "Employee.h"
#include "LinkedList.h"
#include "validaciones.h"

/** \brief Set del ID del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        retorno = 1;
    }

    return retorno;

}


/** \brief Obtiene el ID del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->id;
        retorno = 1;
    }
    return retorno;
}


/** \brief Set del nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief Obtiene el nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

    int retorno = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief Set de horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int retorno = 0;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

/** \brief Obtiene las horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int retorno = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;

}

/** \brief Set del sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{

    int retorno = 0;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;

}

/** \brief Obtiene el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

/** \brief Lllama a los set del empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(idStr))|| !employee_setNombre(this, nombreStr) || !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||   !employee_setSueldo(this, atoi(sueldoStr)))

            {
                employee_delete(this);
                this = NULL;
            }
        }
    }

    return this;
}

/** \brief Libera memoria
 *
 * \param emp Employee*
 * \return void
 *
 */
void employee_delete(Employee* emp)
{
    if(emp !=NULL)
    {
        free(emp);
    }
}

/** \brief Obtiene a los empleados y lo muestra
 *
 * \param pEmp Employee*
 * \return void
 *
 */
void mostrarEmpleado(Employee* pEmp)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(pEmp !=NULL)
    {
        if(employee_getId(pEmp,&id) && employee_getNombre(pEmp,nombre) && employee_getHorasTrabajadas(pEmp,&horas) && employee_getSueldo(pEmp,&sueldo))
        {
            printf("%5d %8s %6d %8d\n",id,nombre,horas,sueldo);
        }
    }
}

int ordenarXid(void* numA, void* numB)
{
    int retorno = -1;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(pUno->id > pDos->id)
        {
            retorno = 1;
        }
        else if(pUno->id < pDos->id)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;

}

int ordenarXnombre(void* numA, void* numB)
{
    int retorno = -1;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(stricmp(pUno->nombre,pDos->nombre)>0)
        {
            retorno = 1;
        }
        else if(stricmp(pUno->nombre,pDos->nombre)<0)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ordenarXhoras(void* numA, void* numB)
{
    int retorno = 0;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(pUno->horasTrabajadas > pDos->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(pUno->horasTrabajadas < pDos->horasTrabajadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int ordenarXsueldo(void* numA, void* numB)
{
    int retorno = -1;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(pUno->sueldo > pDos->sueldo)
        {
            retorno = 1;
        }
        else if(pUno->sueldo < pDos->sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int darAlta(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* nuevoEmpleado;
    char nombre[128];
    int horas;
    int sueldo;

    nuevoEmpleado = employee_new();

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                          >>>> Alta Empleado <<<<                           #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        printf(" Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre);
        employee_setNombre(nuevoEmpleado,nombre);

        printf("\n");

        printf(" Ingrese Horas: ");
        fflush(stdin);
        scanf("%d",&horas);
        employee_setHorasTrabajadas(nuevoEmpleado,horas);

        printf("\n");

        printf(" Ingrese sueldo: ");
        fflush(stdin);
        scanf("%d",&sueldo);
        employee_setSueldo(nuevoEmpleado,sueldo);

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->id = generadorId(pArrayListEmployee);
            ll_add(pArrayListEmployee,nuevoEmpleado);

            retorno = 1;
        }
    }

    return retorno;
}

int ordenarEmpleados(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int opcion;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                         >>>> Ordenar empleados <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

            printf("\n");
            printf(" AVISO: Debido a la enorme cantidad de empleados,\n");
            printf(" va a demorar un poco el ordenarlos.\n");
            printf(" Por favor, espere. Gracias!!!\n");

            printf("\n");

            printf(" Que desea ordenar?\n");
            printf(" 1. ID\n 2. Nombre\n 3. Horas\n 4. Sueldo\n");
            printf(" Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                if(ll_sort(pArrayListEmployee, ordenarXid, 1)==-1)
                {
                    retorno = 0;
                }
                else
                {
                    retorno = 1;
                }
                break;
            case 2:
                if(ll_sort(pArrayListEmployee, ordenarXnombre, 1)==-1)
                {
                    retorno = 0;
                }
                else
                {
                    retorno = 1;
                }
                break;
            case 3:
                if(ll_sort(pArrayListEmployee, ordenarXhoras, 1)==-1)
                {
                    retorno = 0;
                }
                else
                {
                    retorno = 1;
                }
                break;
            case 4:
                if(ll_sort(pArrayListEmployee, ordenarXsueldo, 1)==-1)
                {
                    retorno = 0;
                }
                else
                {
                    retorno = 1;
                }
                break;
            default:
                printf("\n");
                printf(" Esta opcion no existe\n");
                break;
            }
    }

    return retorno;
}

int listarEmpleados(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i=0;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                             >>>> Empleados <<<<                            #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los empleados\n");
        printf(" en forma encolumnada de a 200.\n");

        retorno = 1;

        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   Nombre   Horas   Sueldo\n");
                printf("   --   ------   -----   ------\n");
                empleado = (Employee*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }
            else
            {
                empleado = (Employee*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }

        }
    }

    system("pause");
    return retorno;
}

int darBaja(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    int indice;
    char seguir;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                             >>>> Baja Empleado <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");
        system("pause");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese ID del empleado: ");
        scanf("%d",&id);

        indice = searchId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" Este empleado no existe\n");
        }
        else
        {
            system("cls");
            printf(" ==============================================================================\n");
            printf(" #                                                                            #\n");
            printf(" #                              >>>> Empleado <<<<                            #\n");
            printf(" #                                                                            #\n");
            printf(" ==============================================================================\n");

            printf("   Id   Nombre   Horas   Sueldo\n");
            printf("   --   ------   -----   ------\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));

            printf("\n");

            seguir = validarSeguir();

            if(seguir == 'S'  || seguir == 's')
            {
                ll_remove(pArrayListEmployee,indice);

                printf("\n");

                printf(" Empleado eliminado con exito\n");
            }
            else
            {
                printf("\n");
                printf(" Baja cancelada\n");
            }
        }

        retorno = 1;

    }

    return retorno;
}

int darModificacion(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* pEmp;
    int id;
    int indice;
    int opcion;
    char seguir;
    char nuevoNombre[128];
    int horas;
    int sueldo;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                     >>>> Modificacion Empleado <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");
        system("pause");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese el ID del empleado: ");
        scanf("%d",&id);

        indice = searchId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" Este empleado no existe\n");
        }
        else
        {
            system("cls");
            printf(" ==============================================================================\n");
            printf(" #                                                                            #\n");
            printf(" #                              >>>> Empleado <<<<                            #\n");
            printf(" #                                                                            #\n");
            printf(" ==============================================================================\n");

            printf("   Id   Nombre   Horas   Sueldo\n");
            printf("   --   ------   -----   ------\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));
            pEmp = (Employee*)ll_get(pArrayListEmployee,indice);

            printf("\n");

            printf(" Que desea modificar?\n");
            printf(" 1. Nombre\n 2. Horas\n 3. Sueldo\n");
            printf(" Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                system("cls");

                printf(" ***Modificar nombre***\n");

                printf("\n");

                printf(" Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nuevoNombre);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    strcpy(pEmp->nombre,nuevoNombre);
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            case 2:
                printf(" ***Modificar horas***\n");

                printf("\n");

                printf(" Ingrese horas trabajadas: ");
                fflush(stdin);
                scanf("%d",&horas);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    pEmp->horasTrabajadas = horas;
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            case 3:
                printf(" ***Modificar sueldo***\n");

                printf("\n");

                printf(" Ingrese sueldo: ");
                fflush(stdin);
                scanf("%d",&sueldo);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    pEmp->sueldo = sueldo;
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            default:
                printf("\n");
                printf(" Esta opcion no existe\n");
            }
        }

        retorno = 1;
    }

    return retorno;
}


/** \brief Busca el ID de un empleado
 *
 * \param pAux Employee*
 * \param id int
 * \param pArrayEmp LinkedList*
 * \return int
 *
 */
int searchId(int id, LinkedList* pArrayEmp)
{
    int indice = -1;
    Employee* pAux;

    if(pArrayEmp !=NULL)
    {
        for(int i=0; i<ll_len(pArrayEmp); i++)
        {
            pAux = (Employee*)ll_get(pArrayEmp,i);

            if(pAux !=NULL && pAux->id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int generadorId(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int cant;
    int auxId;
    int maxID = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        cant = ll_len(pArrayListEmployee);
        for(i=0; i<cant; i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            employee_getId(auxiliar, &auxId);
            if(auxId > maxID)
            {
                maxID = auxId;
            }
        }
    }
    maxID += 1;
    return maxID;
}
