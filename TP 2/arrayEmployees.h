#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define EMP 5

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

/** \brief muestra las opciones al usuario
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void menuOpcion(eEmpleado[],int);

/** \brief inicializa a los empleados
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void inicializarEmpleados( eEmpleado empleados[], int tam);

/** \brief busca espacio libre, y lo devuelve si esta vacio, si no, salta un mensaje de error
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return int
 *
 */
int buscarLibre( eEmpleado empleados[], int tam);

/** \brief carga de manera incremental el ID de un empleado
 *
 * \param void
 * \return int
 *
 */
int cargarId(void);

/** \brief Busca si hay lugar libre
 *
 * \param eEmpleado
 * \param int
 * \return void
 *
 */
void validarLugar (eEmpleado empleados[],int tam);

/** \brief
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado empleados[], int tam);

/** \brief permite encontrar a un empelado mediante su ID
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarEmpleadoxID(eEmpleado empleados[], int tam,int id);

/** \brief muestra datos de un empleado
 *
 * \param emp eEmpleado
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado emp);

/** \brief muestra los datos de todos los empleados mediante un recorrido de todo el array
 *
 * \param nomina[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado nomina[], int tam);

/** \brief Ingresa los datos de los empleados
 *
 * \return eEmpleado
 *
 */
eEmpleado agregarEmpleado();

/** \brief Da de baja a un empleado, segun su ID
 *
 * \param empleados eEmpleado*
 * \param tam int
 * \return void
 *
 */
void eliminarEmpleado(eEmpleado *empleados, int tam);

/** \brief Modifica los valores a elegir por parte del usuario
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void modificarEmpleado(eEmpleado empleados[], int tam);

/** \brief Ordena por Sector y Apellido a los empleados
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void ordenarXSectorYapellido(eEmpleado empleados[],int tam);

/** \brief Calcula y muestra el total, promedio y el maximo de los promedios de un empleado
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void promediar(eEmpleado empleados[], int tam);

/** \brief Muestra al usuario las opciones a elegir para Informar
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void subMenuOpcionInformar(eEmpleado empleados  [],int tam);

/** \brief valida que se ingresen valores numericos
 *
 * \return int
 *
 */
int validarNumero();

/** \brief valida que apellido reciba solo chars alfabeticos
 *
 * \param apellido[] char
 * \return void
 *
 */
void validarApellido(char apellido[]);

/** \brief valida que nombre reciba solo chars alfabeticos
 *
 * \param nombre[] char
 * \return void
 *
 */
void validarNombre(char nombre[]);





