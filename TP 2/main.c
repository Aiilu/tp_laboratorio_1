#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "menu.h"
#define ELEMENTS 2

int main()
{
sEmployee arrayEmployee[ELEMENTS];

char opcion;
char carga='N';
do
{
system("cls");
printf("MENU OPCIONES");
printf("1.Dar de alta");
printf("2.Modificar");
printf("3.Dar de baja");
printf("4.Informar");
printf("Ingrese una opcion");
opcion=getch();
opcion=toupper(opcion);

switch(opcion)
{
case 'A':
system("cls");
carga='S';
break;

case 'M':
if(carga=='S')
{
system("cls");
break;
}
else
{
printf("Debe ingresar los datos primero\n");
break;
}

case 'B':
if(carga=='S')
{
system("cls");
break;
}
else
{
printf("Debe ingresar los datos primeros\n");
break;
}

case 'I':
if(carga=='S')
{
system("cls");
break;
}
else
{
printf("Debe ingresar los datos primero\n");
break;
}

case 'S':
break;

default:
printf("Esta opcion no es valida");
}
}while(opcion!='S');


return 0;
}

