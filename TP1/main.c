#include <stdio.h>
#include <stdlib.h>
#include "torrez.h"

int main()
{

    int opcion;
    char seguir = 's';
    float numA;
    float numB;
    int flagA = 0;
    int flagB = 0;
    int flag = 0;

    do{
      system ("COLOR F0");
      system("cls");
      printf("     =================================================\n");
      printf("     #            Trabajo Practico Nro. 1            #\n");
      printf("     #                                               #\n");
      printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
      printf("     =================================================\n");
      printf("     |                                               |\n");
      if(flagA == 1)
      {
          printf("          1- Ingresar 1er Operando (A=%.2f)            \n",numA);
      }
      else
      {
          printf("          1- Ingresar 1er Operando (A=x)              \n");
      }
      printf("     |                                               |\n");
      if(flagB == 1)
      {
          printf("          2- Ingresar 2do Operando (B=%.2f)           \n",numB);
      }
      else
      {
          printf("          2- Ingresar 2do Operando (B=y)              \n");
      }
      printf("     |                                               |\n");
      printf("          3- Calcular todas las Operaciones           \n");
      printf("     |                                               |\n");
      printf("          4- Informar resultados                      \n");
      printf("     |                                               |\n");
      printf("          5- Salir                                    \n");
      printf("     |                                               |\n");
      printf("     =================================================\n");
      printf("                                                     \n");
      printf("     Ingrese una opcion del menu: ");

      fflush(stdin);
      scanf("%d",&opcion);

      switch(opcion)
      {
      case 1:
          numA=ingresarNumero();
          flagA=1;
        break;
      case 2:
          numB=ingresarNumero();
          flagB=1;
        break;
      case 3:
          if (flagA == 1 && flagB == 1)
            {
                flag = 1;
                system("cls");
                printf("     ================================================\n");
                printf("     #                  Calculando...               #\n");
                printf("     ================================================\n");
                printf("     |                                              |\n");
                printf("           La suma de %.2f + %.2f                     \n",numA,numB);
                printf("     |                                              |\n");
                printf("           La resta de %.2f - %.2f                    \n",numA,numB);
                printf("     |                                              |\n");
                printf("           La multiplicacion de %.2f * %.2f           \n",numA,numB);
                printf("     |                                              |\n");
                printf("           La division de %.2f / %.2f                 \n",numA,numB);
                printf("     |                                              |\n");
                printf("           El factorial de %.2f! y %.2f!              \n",numA,numB);
                printf("     |                                              |\n");
                printf("     ================================================\n");

            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los numeros!\n");
            }
        break;
      case 4:
          if(flagA == 1 && flagB == 1 && flag == 1)
          {
                system("cls");
                printf("     ================================================\n");
                printf("     #                  Resultados                  #\n");
                printf("     ================================================\n");
                printf("     |                                              |\n");
                printf("           El resultado de %.2f + %.2f es: %.2f        \n",numA,numB,sumar(numA,numB));
                printf("     |                                              |\n");
                printf("           El resultado de %.2f - %.2f es: %.2f        \n",numA, numB,restar(numA,numB));
                printf("     |                                              |\n");
                printf("           El resultado de %.2f * %.2f es: %.2f        \n",numA,numB,multiplicar(numA,numB));
                printf("     |                                              |\n");
                dividir(numA,numB);
                printf("     |                                              |\n");
                factorial(numA,numB);
                printf("     |                                              |\n");
                printf("     ================================================\n");

            }
            else
            {
                printf("\n\n");
                printf("     Primero debe calcular las operaciones!\n");
            }
        break;
      case 5:
                system("cls");

                seguir = 'n';
                printf("     ==========================================\n");
                printf("     #               Saliendo...              #\n");
                printf("     ==========================================\n");
                printf("     |                                        |\n");
                printf("     |              Hasta luego!!!            |\n");
                printf("     |                                        |\n");
                printf("     ==========================================\n");

        break;
      default:
               printf("\n\n");
               printf("     ERROR. Esta opcion no es valida\n");

        break;
      }

      fflush(stdin);
      printf("     Presione ENTER para continuar");
      getchar();

    }while(seguir == 's');

    return 0;
}


