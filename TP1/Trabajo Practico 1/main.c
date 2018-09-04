#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
	int flagSalida = 1, opcion, flagA = 0, flagB = 0;
	float numA, numB;
	do
	{
		printf("=========================================\n");
		printf("       >>>> MENU CALCULADORA >>>> \n"       );
		printf("=========================================\n");
		printf("\n");
		if (flagA == 1)
		{
			printf("1. Ingresar 1er operando (A=%.2f)\n", numA);
		}
		else
		{
			printf("1. Ingresar 1er operando (A=x)\n");
		}
		printf("\n");
		if (flagB == 1)
		{
			printf("2. Ingresar 2do operando (B=%.2f)\n", numB);
		}
		else
		{
			printf("2. Ingresar 2do operando (B=y)\n");
		}
		printf("\n");
		printf("3. Calcular todas las operaciones\n");
		printf("\n");
		printf("4. Informar resultados\n");
		printf("\n");
		printf("5. Salir\n");
		printf("=============================================\n");
		printf("\n");
		printf("Ingrese una opcion del menu:");

		fflush(stdin);
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1:
			ingresarOpcion(&numA);
			flagA = 1;
			break;
		case 2:
			ingresarOpcion(&numB);
			flagB = 1;
			break;
		case 3:
			if (flagA == 1 && flagB == 1)
			{
				printf("\n=========================================");
				printf("\n          Calculando..                   ");
				printf("\n=========================================");
				printf("\nLa suma de %.2f + %.2f",numA,numB);
				printf("\nLa resta de %.2f - %.2f",numA,numB);
				printf("\nLa multiplicacion de %.2f * %.2f",numA,numB);
				printf("\nLa division de %.2f / %.2f",numA,numB);
				printf("\nEl factorial de %.2f! y %.2f!",numA,numB);
				float sumar(float numA, float numB);
				float restar(float numA, float numB);
				float multiplicar(float numA, float numB);
				float dividir(float numA, float numB);
				float factorial(float numA, float numB);

			}
			else
			{
				printf("Ingrese los numeros!");
			}
			break;
		case 4:

			if (flagA == 1 && flagB == 1) {

				printf("\n=========================================");
				printf("\n          RESULTADOS");
				printf("\n=========================================");
				printf("\n");
				printf("\n El resultado de A+B es: %.2f", sumar(numA, numB));
				printf("\n");
				printf("\n El resultado de A-B es: %.2f", restar(numA, numB));
				printf("\n");
				printf("\n El resultado de A*B es: %.2f", multiplicar(numA, numB));
				printf("\n");
				dividir(numA, numB);
				printf("\n");
				factorial(numA, numB);
			}
			else {
				printf("Primero debe ingresar los valores");
			}

			break;
		case 5:
			printf("Saliendo...");
			flagSalida = 0;
			break;
		default:
			printf("Ingrese una opcion valida!\n");
		}
		fflush(stdin);
		printf("\nIngrese ENTER para continuar...");
		getchar();
		system("cls");
	} while (flagSalida != 0);
	return 0;
}
