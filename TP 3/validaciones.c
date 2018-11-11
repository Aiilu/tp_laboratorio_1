
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include <ctype.h>

int ObtenerName(char* pNombre, char* msg, char* msgError)
{
    int retorno = -1;
    int max=50;
    char bufferString[max];
    if(pNombre != NULL && msg != NULL && msgError != NULL)
    {
        printf("%s", msg);
        if(getChar(bufferString, max) == 0 && esLetra(bufferString) == 0 && esEntero(bufferString) != 0)
        {
            retorno = 0;
            strncpy(pNombre, bufferString, max);
        }else
        {
            printf("%s", msgError);
            system("pause");
        }
    }
    return retorno;
}

/**
    library_getEntero: Pide un numero entero y utiliza getInt para validarlo.
    @param pNum: Puntero a numero.
    @param reint: Cantidad de reintentos.
    @param msg: Mensaje a mostrar.
    @param msgError: Mensaje de error.
    @param maximo: Numero maximo.
    @param minimo: Numero minimo.
    @return return 0 OK, -1 Error.
*/

int BibliotecaObtenerEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getEntero(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;
            }else
            {
                printf(msgError);
            }
        }else
        {
            printf(msgError);
        }
    }
    return retorno;
}

/**
    library_getEnteroSinLimites: Pide un numero entero y utiliza getInt para validarlo.
    @param pNum: Puntero a numero.
    @param reint: Cantidad de reintentos.
    @param msg: Mensaje a mostrar.
    @param msgError: Mensaje de error.
    @return return 0 OK, -1 Error.
*/

int ObtenerNumeroSinLimitacion(int* pNum, int reint, char* msg, char* msgError)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getEntero(&auxiliarNum) == 0)
        {
                *pNum = auxiliarNum;
                retorno = 0;
                break;
        }else
        {
            printf(msgError);
        }
    }
    return retorno;
}

/**
    library_getNumeroDecimal: Pide un numero con coma y utiliza a getFloat para validarlo.
    @param pNum: Puntero a numero.
    @param reint: Pantidad de reintentos al fallar.
    @param msg: Mensaje a mostrar.
    @param msgError: Mensaje de error.
    @return return 0 OK, -1 Error.
*/

int obtenerNumeroConComa(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {
        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 && buffer <= maximo && buffer >= minimo)
            {
                *pNum = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }
        }while(reint >= 0);
    }
    return retorno;
}

/**
    getString: Permite ingresar una cadena de caracteres recibieno un array.
    @param pBuffer: Cadena de caracteres que recibe.
    @param limite: Guarda el int del limite del array.
    @return : 0 OK, -1 Error.
*/

int getChar(char* pBufferString,int limite)
{
    fflush(stdin);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}

/**
    getInt: Permite ingresar un numero entero en una cadena de caracteres y lo transforma a int.
    @param pResultado: Guarda el numero 1 ingresado luego de validarlo.
    @return : 0 OK, -1 Error
*/

int getEntero(int* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(getChar(bufferString,4096) == 0 && esEntero(bufferString)==0)
        {
            *pResultado=atof(bufferString);
            retorno=0;
        }
    }
    return retorno;
}

/**
    getFloat: Permite ingresar un numero con coma en una cadena de caracteres y lo transforma a float.
    @param pResultado: Guarda el numero 1 ingresado luego de validarlo.
    @return : 0 OK, -1 Error
*/

int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(getChar(bufferString,4096) == 0 && esFlotante(bufferString)==0)
        {
            *pResultado=atof(bufferString);
            retorno=0;
        }
    }
    return retorno;
}

/**
    isFloat: Valida si la cadena de caracteres solo tiene numeros y una coma.
    @param pBuffer: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int esFlotante(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i]=='.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
        }
        if((pBuffer[i] < '0' || pBuffer[i] > '9'))
        {

            retorno=-1;
            break;
        }
        i++;
    }
    if(contadorPuntos > 2)
    {
        retorno=-1;
    }
    return retorno;
}

/**
    isInt: Valida si la cadena de caracteres solo tiene numeros.
    @param pBuffer: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int esEntero(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
    isIntConGuiones: Valida si la cadena de caracteres solo tiene numeros y guiones.
    @param pBuffer: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int EnteroConGuiones(char* pBuffer)
{
    int i = 0;
    int retorno = 0;
    int contadorDeGuiones = 0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '-' && contadorDeGuiones == 0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/**
    isLetra: Valida si la cadena de caracteres solo tiene letras, guiones y espacios.
    @param pBuffer: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int esLetra(char* pBuffer)
{
    int i = 0;
    int retorno = 0;
    int flag = 0;
    int contadorGuiones=0;
    while(pBuffer[i] != '\0')
    {
        if(flag == 0)
        {
            pBuffer[i] = toupper(pBuffer[i]);
            flag = 1;
        }else if ((pBuffer[i] != ' ') && (pBuffer[i] < 'A' || pBuffer[i] > 'Z') &&
                (pBuffer[i] < 'a' || pBuffer[i] > 'z') && pBuffer[i] != '-')
        {
            retorno = -1;
            break;
        }
        if(pBuffer[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }
    return retorno;
}

/**
    isValidHoursWorked: Valida si las horas ingresadas son validas(numeros).
    @param HoursWorked: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int isValidHoursWorked(char* HoursWorked)
{
    int retorno = -1;
    if(esEntero(HoursWorked) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("           lAS HORAS TRABAJADAS NO SON VALIDAS       \n");
        printf("   ----------------------------------------------    \n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    isValidName: Valida si el nombre ingresado es correcto(letras).
    @param Name: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int isValidName(char* Name)
{
    int retorno = -1;
    if(esLetra(Name) == -1)
    {
        printf("\nName invalido\n");
        printf("\n%s\n", Name);
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    isValidSalary: Valida si el salario ingresado es valido(numeros).
    @param Salary: Cadena de caracteres que recibe para validar.
    @return : 0 OK, -1 Error.
*/

int isValidSalary(char* Salary)
{
    int retorno = -1;
    if(esEntero(Salary) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("            EL Salary NO ES VALIDO                  \n");
        printf("   ----------------------------------------------    \n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    isValidId: Valida si el id ingresado existe(numeros).
    @param id: Cadena de caracteres que recibe para validar, tambien si tiene guiones.
    @return : 0 OK, -1 Error.
*/

int isValidId(char* id)
{
    int retorno = -1;
    if(EnteroConGuiones(id) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("             EL ID ES INVALIDO                       \n");
        printf("   ----------------------------------------------    \n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

