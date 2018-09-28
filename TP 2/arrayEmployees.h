#ifndef arrayEmployees

typedef struct
{
int id;
char name[51];
char lastNam[51];
float salary;
int sector;
int isEmpty;
}sEmployee;

int initEmployees(sEmployee*,int);
/*indica matriz vacia, coloca bandera en TRUE, retorna error, caso de error 0;*/
//r=initEmployees(arrayEmployees,ELEMENTS);

int addEmployee(sEmployee*,int,int,char,char,float,int);
/*agrega los valores recibidos en el primer espacio libre,retorna -1 en error, si no 0,OK*/
//r=addEmployee(arrayEmployes,Elements);

#endif // arrayEmployees


