#ifndef arrayEmployees

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define OCUPADO 1
#define VACIO 0
#define T 3

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

/** \brief inicializa a los empleados
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void inicializarX(eEmpleado[],int);

/** \brief muestra las opciones al usuario
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void menuPrincipal(eEmpleado[],int);

/** \brief Muestra al usuario las opciones a elegir para Informar
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void menuInformes(eEmpleado[],int);

/** \brief busca espacio libre, y lo devuelve si esta vacio, si no, salta un mensaje de error
 *
 * \param Eempleado[]
 * \param int
 * \return int
 *
 */
int buscarLibre(eEmpleado[],int);

/** \brief permite encontrar a un empleado mediante su ID
 *
 * \param Eempleado[]
 * \param int
 * \param int
 * \return int
 *
 */
int buscarXid(eEmpleado[],int,int);

/** \brief carga de manera incremental el ID de un empleado
 *
 * \param void
 * \return int
 *
 */
int cargarID();

/** \brief Ingresa los datos de los empleados y carga secuencialmente(pregunta si deseas continuar)
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void darAlta(eEmpleado[],int);

/** \brief muestra datos de un empleado
 *
 * \param eEmpleado
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado x);

/** \brief muestra los datos de todos los empleados mediante un recorrido de todo el array
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado[],int);

/** \brief Modifica los valores a elegir por parte del usuario
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void darModificacion(eEmpleado[],int);

/** \brief Da de baja a un empleado, segun su ID
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void darBaja(eEmpleado[],int);

/** \brief Ordena por Sector y Apellido a los empleados
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void ordenar(eEmpleado[],int);

/** \brief Calcula y muestra el total, promedio y el maximo de los promedios de un empleado
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void promediar(eEmpleado[],int);

/** \brief valida que una cadena de caracteres reciba solo chars alfabeticos
 *
 * \param char[]
 * \return void
 *
 */
void validarString(char x[]);

/** \brief valida que se ingresen solo valores numericos y positivos, ingresa en modo char y si esta todo ok, hace la conversion
 *
 * \param char[]
 * \return int
 *
 */
int validarEntero(char entero[]);

/** \brief valida que se ingresen solo valores numericos y positivos, ingresa en modo char y si esta todo ok, hace la conversion
 *
 * \param char[]
 * \return float
 *
 */
float validarFloat(char sueldo[]);

/** \brief recorre el array buscando una coma, una vez encontrada la cambia a un (.),de forma que se permita ingresar un salario con coma o punto
 *
 * \param char[]
 * \return void
 *
 */
void comapunto(char sueldo[]);

/** \brief valida que se ingresen solo char s/n
 *
 * \return char
 *
 */
char validarSeguir();
#endif // arrayEmployees
