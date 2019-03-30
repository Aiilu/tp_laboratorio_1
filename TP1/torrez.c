#include "torrez.h"

float ingresarNumero()
{
    float valor;

    printf("\n\n");
    printf("     Ingrese un numero: ");
    fflush(stdin);
    scanf("%f",&valor);

    return valor;
}

float sumar(float sumaUno, float sumaDos)
{
    float suma;

    suma = sumaUno+sumaDos;

    return suma;
}

float restar(float restaUno, float restaDos)
{
    float resta;

    resta = restaUno-restaDos;

    return resta;
}

float multiplicar(float multUno, float multDos)
{
    float multiplicacion;

    multiplicacion = multUno*multDos;

    return multiplicacion;
}

float dividir(float dividUno, float dividDos)
{
    float division;

    if(dividDos !=0)
    {
        division = dividUno/dividDos;

        printf("           El resultado de A/B es: %.2f               \n",division);
    }
    else
    {
        printf("           No es posible dividir por cero.            \n");
    }

    return division;
}


float factorial(float primerFactor, float segundoFactor)
{
	int factorUno = 1, factorDos = 1, i;

	if (primerFactor>=0)
	{
		for (i = (int)primerFactor; i >= 1; i--)
		{
			factorUno = factorUno * i;
		}
		printf("           El factorial de A! es: %.2i             \n",factorUno);
		printf(" \n");
	}
	else
    {
        printf("         No se puede factorizar el 1er operando: A!\n");
		printf("         porque es un numero negativo.\n");
		printf(" \n");
    }

	if (segundoFactor>=0)
	{

		for (i = 1; i <= (int)segundoFactor; i++) {

			factorDos = factorDos * i;
		}
		printf("           El factorial de B! es: %.2i             \n",factorDos);
		printf(" \n");
	}
	else {
		printf("         No se puede factorizar el 2do operando: B!\n");
		printf("         porque es un numero negativo.\n");
	}

	return 0;
}
