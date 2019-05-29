#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* emp = (Employee*)malloc(sizeof(Employee));

    return emp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

void employee_delete();

int employee_setId(Employee* this,int id)
{
    int retorno = 0;

    if(this !=NULL && id > 0)
    {
         this->id = id;
         retorno = 1;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;

    if(this !=NULL && id !=NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this !=NULL && nombre !=NULL && strlen(nombre) > 128)
    {
        strcpy(this->nombre,nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this !=NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this !=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;

    if(this !=NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;

    if(this !=NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if(this !=NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

void mostrarEmpleado(Employee* this)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(this !=NULL)
    {
        if(employee_getId(this,&id) && employee_getNombre(this,nombre) && employee_getHorasTrabajadas(this,&horas) && employee_getSueldo(this,&sueldo))
        {
            printf("%d %s %d %d\n",id,nombre,horas,sueldo);
        }
    }
}

