#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#define VACIO -1
int initEmployees(sEmployee* list,int len)
/*indica matriz vacia, coloca bandera en TRUE, retorna error, caso de error 0;*/
//r=initEmployees(arrayEmployees,ELEMENTS);
{
int empty = -1;
int i;
if(list !=NULL && len>0)
{
for(i=0;i<len;i++)
{
if(list[i].isEmpty==VACIO)
{
empty = i;
break;

}
}
}
return empty;
}

/*int addEmployee(sEmployee* list,int len ,int id ,char name[] ,char lastName[] ,float salary ,int sector)*/
/*agrega los valores recibidos en el primer espacio libre,retorna -1 en error, si no 0,OK*/
/*r=addEmployee(arrayEmployes,Elements);
int empty = 0;
int id = 0;
int i;
int indice = initEmployees(list,len);

for(i=0;i<len;i++)
{

if(indice>-1)
{
if(list[i].ID)
{
list[i].ID ++:
}

    printf("Ingrese su nombre");
    fflush(stdin);
    gets(list[i].name);

    printf("Ingrese su apellido:");
    fflush(stdin);
    gets(list[i].lastName);

    printf("Ingrese el salario");
    fflush(stdin);
    scanf("%f",&list[i].salary);

    printf("Ingrese el sector");
    fflush(stdin);
    scanf("%d",&list[i].sector);

empty = 1;

}
else
{
printf("NO HAY ESPACIO");
}

return retorno;
}*/
