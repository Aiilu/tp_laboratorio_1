#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "validaciones.h"

//VALIDAR TELEFONO

int funcion_ValidarTelefono(char* str)
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

void validarTel(char* x)
{
    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(!funcion_ValidarTelefono(x))
        {
            printf("     Reingrese un telefono en formato xxxx-xxxx: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR EMAIL

int funcion_validarEmail(char* str)
{
    int i=0;
    int contadorArroba=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && (str[i] != '@') && (str[i] != '.')&& (str[i] != '_')&& (str[i] != '-')&& (str[i] != '/'))
            return 0;
        if(str[i] == '@')
            contadorArroba++;

        i++;
    }
    if(contadorArroba==1) // debe tener un guion
        return 1;
    return 0;
}

void validarEmail(char* x)
{
    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(!funcion_validarEmail(x))
        {
            printf("     Reingrese un Email valido: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR NOMBRE

void validarString(char* x)
{

    if(x !=NULL)
    {
        while(strlen(x)<=0)
        {
            printf("Vacio: ");
            fflush(stdin);
            gets(x);
        }

        for(int i=0; i<strlen(x); i++)
        {
            while(isalpha(x[i]) == 0 || strlen(x)>51 || (x+0) == '\0')
            {
                printf("Reingrese nuevamente: ");
                fflush(stdin);
                gets(x);
                i=0;
            }
        }
    }
}

//VALIDAR NOMBRE CON MAX

void validarStringTam(char* x, int largo)
{

    while(strlen(x)<=0)
    {
        printf("Vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(isalpha(x[i]) == 0 || strlen(x)>largo || x[0] == '\0')
        {
            printf("Reingrese > %d:",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR INT CON MAX

int validarEnteroTam(char* entero, int largo)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || strlen(entero)>largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d: ",largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


//VALIDAR INT

int validarEntero(char* entero)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.')
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


//VALIDAR FLOAT
//FALTA AGREGAR EL COMA PUNTO
float validarFloat(char* sueldo)
{
    float sueldoK;

    while(strlen(sueldo)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(sueldo);
    }

    for(int i=0; i<strlen(sueldo); i++)
    {

        sueldoK = atof(sueldo);

        while(isalpha(sueldo[i]) != 0 || sueldoK <= 0 || sueldo[i] == ' ')
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(sueldo);
            i=0;
            sueldoK = atof(sueldo);
        }

    }

    return sueldoK;
}

//VALIDAR SEXO

char validarSexo()
{
    char sexos;

    printf("     Ingrese sexo f/m: ");
    fflush(stdin);
    sexos = getchar();
    sexos = toupper(sexos);

    while(sexos != 'F'  && sexos !='M' && sexos !='f' && sexos !='m')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Ingrese f/m: ");
        fflush(stdin);
        sexos = getchar();
        sexos = toupper(sexos);
    }

    return sexos;
}

//VALIDAR SEGUIR

char validarSeguir()
{
    char seguir;

    printf(" Esta seguro? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}

//COMPARAR FECHAS

/*int compararFechas(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}*/

//VALIDAR DIRECCION

void validarAlfaNum(char* x, int largo)
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(strlen(x)>largo || (x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z') && (x[i] < '0' || x[i] > '9') && x[i] != ' ')
        {
            printf("     Reingrese solo caracteres alfanum >%d: ",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR PATENTE

void ValidarPatente(char* x)
{

    for(int i=0; i<=2; i++)
    {
        while(strlen(x)!=6)
        {
            printf("La patente deben ser 3 letras y 3 numeros: ");
            fflush(stdin);
            gets(x);
        }
        for(int j=3; j<strlen(x); j++)
        {
            while((x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z'))
            {
                printf("Reingrese patente valida, 3 letras y 3 numeros: ");
                fflush(stdin);
                gets(x);
            }
            while(x[j] < '0' || x[j] > '9')
            {
                printf("Reingrese patente valida: ");
                fflush(stdin);
                gets(x);
            }
        }

    }
}

//VALIDAR INT FECHA

int validarEnteroFecha(char* entero, int corto, int largo)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}

//VALIDAR INT MIN/MAX

int validarEnteroRango(char* entero, int corto, int largo)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}

//VALIDAR FECHA
/*         printf("Fecha de Inicio\n");

            printf("Ingrese anio: ");
            fflush(stdin);
            gets(valAnio);

            tra[indice].fechaTrabajo.anio = validarEnteroRango(valAnio,2019,2080);

            printf("Ingrese mes: ");
            fflush(stdin);
            gets(valMes);

            tra[indice].fechaTrabajo.mes = validarEnteroRango(valMes,1,12);

            printf("Ingrese dia: ");
            fflush(stdin);
            gets(valDia);

            if (tra[indice].fechaTrabajo.mes == 4 ||tra[indice].fechaTrabajo.mes == 6 || tra[indice].fechaTrabajo.mes == 9 || tra[indice].fechaTrabajo.mes == 11)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,30);
            }
            else if(tra[indice].fechaTrabajo.mes == 2)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,28);
            }
            else
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,31);
            }
*/
