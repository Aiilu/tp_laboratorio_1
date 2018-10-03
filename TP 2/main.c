
#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"

int main()
{
   eEmpleado lista[EMP];
   inicializarEmpleados(lista,EMP);
   menuOpcion(lista,EMP);

    return 0;
}
