#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_mengassini.h"

#define LEN 10
#define LENSEC 5
#define LENHARDCODE 8

/** \brief Lista todos los empleados
 *
 * \param eEmployee* vec: vectores de empleados
 * \param  int len: tamaño del vector
 * \return No retorna nada
 *
 */

void listEmployees(eEmployee* vec, int len)
{
    int flag=0;
    system("cls");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  |                    ****** Listado de Empleados *****                 \n\n");
    printf("  |    id       Nombre     Apellido     Sueldo            Sector\n");
    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0)
        {
            listEmployee(&vec[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("  |  ******No hay empleados que listar******\n");
    }
}

/** \brief Lista un empleado
 *
 * \param eEmployee* vec: vector de empleado
 * \param
 * \return No retorna nada
 *
 */

void listEmployee(eEmployee* vec)
{
    //char descripcion[20];
    //cargarDescripcionSector(descripcion,emp.idSector,sectores,tamsec);
    printf("  |  %d   %10s   %10s    %.2f    %13s\n", vec->id,vec->name,vec->lastName,vec->salary,vec->sector);
}

/** \brief Busca un lugar libre en la estructura de empleados
 *
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño del vector
 * \return No retorna nada
 *
 */

int searchFree(eEmployee* vec, int len)
{
    int indice=-1;
    for(int i=0; i<len; i++)
    {
        if (vec[i].isEmpty==1)//==(vec[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief Indica que todas las posiciones del vector estan vacias.
 *         Esta funcion pone la bandera isEmpty en TRUE en todas las posiciones del vector.
 * \param list Employee* Puntero al vectorer Employees.
 * \param tam int Longitud del vector.
 * \return int Retorna (-1) si hay ERROR (longitud invalida o puntero NULL)
 *         (0) si esta todo bien.
 */

int initEmployees(eEmployee* vec,int len)
{
    int retorno=-1;
    if (vec!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            vec[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Agrega un empleado al sistema
 *
 * \param int idx: es el proximo numero de id
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño del vector
 * \return Retorna 0 si no pudo dar de alta, 1 si se pudo de dar de alta al empleado
 *
 */
int addEmployee(int idx,eEmployee* vec, int len)
{
    int retorno=0;
    int indice=searchFree(vec,len);
    eEmployee auxEmployee;
    system("cls");
    printf("  |------------------------------------|\n");
    printf("  |   ******Alta Empleado******        |\n");
    if (indice==-1)
    {
        printf("  |   Sistema Completo\n\n");
    }
    else
    {
            auxEmployee.id=idx;
            printf("  |   Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmployee.name);
            while(esSoloLetras(auxEmployee.name)!=1)
            {
                printf("  |   Error. Nombre incorrecto.\n");
                printf("  |   Ingrese nombre: ");
                gets(auxEmployee.name);
            }
            printf("  |   Ingrese apellido: ");
            fflush(stdin);
            gets(auxEmployee.lastName);
            while(esSoloLetras(auxEmployee.lastName)!=1)
            {
                printf("  |   Error. Apellido incorrecto.\n");
                printf("  |   Ingrese apellido: ");
                gets(auxEmployee.lastName);
            }
            printf("  |   Ingrese sueldo(0-100000): ");
            scanf("%f",&auxEmployee.salary);
            while(auxEmployee.salary<0||auxEmployee.salary>100000)
            {
                printf("  |   Error. Sueldo incorrecto.\n");
                printf("  |   Ingrese sueldo(0-100000): ");
                scanf("%f",&auxEmployee.salary);
            }
            printf("  |--------------------------------|\n");
            printf("  |  ****Listado de Sectores****   |\n");
            printf("  |   -sistemas.                   |\n");
            printf("  |   -RRHH.                       |\n");
            printf("  |   -compras.                    |\n");
            printf("  |   -ventas.                     |\n");
            printf("  |   -contable.                   |\n");
            printf("  |   Ingrese sector: ");
            fflush(stdin);
            gets(auxEmployee.sector);
            while(  strcmp(auxEmployee.sector,"sistemas")!=0
                  &&strcmp(auxEmployee.sector,"RRHH")!=0
                  &&strcmp(auxEmployee.sector,"compras")!=0
                  &&strcmp(auxEmployee.sector,"ventas")!=0
                  &&strcmp(auxEmployee.sector,"contable")!=0)
            {
                printf("  |   Error. Sector incorrecto.\n");
                printf("  |   Ingrese sector: ");
                gets(auxEmployee.sector);
            }
            auxEmployee.isEmpty=0;
            vec[indice]=auxEmployee;//Copio al vector al empleado nuevo
            retorno=1;
    }
    return retorno;
}

/** \brief Busca empleado por numero de id
 *
 * \param int id: numero de id para buscar empleado
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño del vector
 * \return Retorna -1 si no encontro empleado con ese id o el indice de dicho empleado si lo encontro
 *
 */

int findEmployeeById(int id,eEmployee* vec,int len)
{
    int indice=-1;
    for(int i=0; i<len; i++)
    {
        if (vec[i].id==id && vec[i].isEmpty==0)//==(vec[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief Elimina empleado de el sistema
 *
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño del vector
 * \return No retorna nada
 *
 */


void removeEmployee(eEmployee* vec, int len)
{
    int id;
    int existe;
    char confirma;
    system("cls");
    printf("  |------------------------------------|\n");
    printf("  |  ******Baja Empleado******         |\n");
    printf("  |  Ingrese id: ");
    scanf("%d",&id);
    existe=findEmployeeById(id,vec,len);
    if(existe==-1)
    {
        printf("  |  No existe empleado con este id: %d\n",id);
    }
    else
    {
        listEmployee(&vec[existe]);
        printf("  |  Confirma Baja?(s/n): ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            vec[existe].isEmpty=1;
            printf("  |  Se ha realizado la baja con exito.\n\n");
        }
        else
        {
            printf("  |  Se ha cancelado la operacion;");
        }
    }
}


/** \brief Ordena los empleados por sector y por apellido
 *
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño del vector
 * \param int order: manera de ordenar. 1 ascendente 2 descendente
 * \return No retorna nada
 *
 */

void sortEmployees(eEmployee* vec,int len,int order)
{
    eEmployee auxEmployee;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(order==1)
            {
                if(strcmp(vec[i].sector,vec[j].sector)>0)
                {
                    auxEmployee=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmployee;
                }
                else if(strcmp(vec[i].sector,vec[j].sector)>0 && strcmp(vec[i].lastName,vec[j].lastName)>0)
                {
                    auxEmployee=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmployee;
                }
            }
            else if(order==2)
            {
                if(strcmp(vec[i].sector,vec[j].sector)<0)
                {
                    auxEmployee=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmployee;
                }
                else if(strcmp(vec[i].sector,vec[j].sector)>0 && strcmp(vec[i].lastName,vec[j].lastName)<0)
                {
                    auxEmployee=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmployee;
                }
            }
        }
    }
    printf("  |  Se ordenaron los empleados por sector y por apellido.\n");
}


/** \brief  Informes de empleados
 *
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño del vector
 * \return No retorna nada
 *
 */

void reportEmployees(eEmployee* vec,int len)
{
    char seguir2='s';
    char confirma2;
    int opcionOrdenar;
    do
    {
        switch(menuReports())
        {
            case 'a':
            {
                listEmployees(vec,LEN);
                break;
            }
            case 'b':
            {
                printf("  |  1-Ascendente.\n");
                printf("  |  2-Descendente.\n");
                printf("  |  Como ordenar los datos?: ");
                scanf("%d",&opcionOrdenar);
                if(opcionOrdenar==1 || opcionOrdenar==2)
                {
                    sortEmployees(vec,LEN,opcionOrdenar);
                }
                else
                {
                    printf("  |   Error. Opcion incorrecta.\n");
                }
                break;
            }
            case 'c':
            {
                reportSalaryTotalAverage(vec,LEN);
                break;
            }
            case 'o':
            {
                printf("  |  Confirma salir de menu informes?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma2);
                if(confirma2=='s')
                {
                    seguir2='n';
                }
                break;
            }
            default:
            {
                printf("  |   Error. Opcion incorrecta.\n");
            }
        }
        system("pause");
    }
    while(seguir2=='s');
}


/** \brief Modifica empleado del sistema
 *
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño de vector
 * \return No retorna nada
 *
 */

void modifyEmployee(eEmployee* vec, int len)
{
    int id;
    int existe;
    int opcion;
    eEmployee auxEmployee;
    system("cls");
    printf("  |------------------------------------------|\n");
    printf("  |      ******Modificar Empleado******      |\n");
    printf("  |      Ingrese id: ");
    scanf("%d",&id);
    existe=findEmployeeById(id,vec,len);
    if(existe==-1)
    {
        printf("  |      No existe empleado con este id: %d\n",id);
    }
    else
    {
        listEmployee(&vec[existe]);
        printf("  |------------------------------------|\n");
        printf("  | *** Que dato desea modificar? ***  |\n");
        printf("  |  1- Nombre                         |\n");
        printf("  |  2- Apellido.                      |\n");
        printf("  |  3- Salario.                       |\n");
        printf("  |  4- Sector.                        |\n");
        printf("  |  Ingrese el numero de opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
                printf("  |  Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(auxEmployee.name);
                while(esSoloLetras(auxEmployee.name)!=1)
                {
                    printf("  |   Error. Nombre incorrecto.\n");
                    printf("  |   Ingrese nombre: ");
                    gets(auxEmployee.name);
                }
                strcpy(vec[existe].name,auxEmployee.name);
                printf("  |  Se ha actualizado el nombre con exito.\n");
                break;
            }
            case 2:
            {
                printf("  |  Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(auxEmployee.lastName);
                while(esSoloLetras(auxEmployee.lastName)!=1)
                {
                    printf("  |   Error. Apellido incorrecto.\n");
                    printf("  |   Ingrese apellido: ");
                    gets(auxEmployee.lastName);
                }
                strcpy(vec[existe].lastName,auxEmployee.lastName);
                printf("  |  Se ha actualizado el apellido con exito.\n");
                break;
            }
            case 3:
            {
                printf("  |   Ingrese sueldo(0-100000): ");
                scanf("%f",&auxEmployee.salary);
                while(auxEmployee.salary<0||auxEmployee.salary>100000)
                {
                    printf("  |   Error. Sueldo incorrecto.\n");
                    printf("  |   Ingrese sueldo(0-100000): ");
                    scanf("%f",&auxEmployee.salary);
                }
                vec[existe].salary=auxEmployee.salary;
                printf("  |  Se ha actualizado el salario con exito.\n");
                break;
            }
            case 4:
            {
                printf("  |  ******Listado de Sectores*****\n");
                printf("  |  -Sistemas.\n");
                printf("  |  -RRHH.\n");
                printf("  |  -Cmpras.\n");
                printf("  |  -Ventas.\n");
                printf("  |  -Contable.\n");
                printf("  |  Ingrese sector: ");
                fflush(stdin);
                gets(auxEmployee.sector);
                while(  strcmp(auxEmployee.sector,"sistemas")!=0
                      &&strcmp(auxEmployee.sector,"RRHH")!=0
                      &&strcmp(auxEmployee.sector,"compras")!=0
                      &&strcmp(auxEmployee.sector,"ventas")!=0
                      &&strcmp(auxEmployee.sector,"contable")!=0)
                {
                    printf("  |   Error. Sector incorrecto.\n");
                    printf("  |   Ingrese sector: ");
                    gets(auxEmployee.sector);
                }
                strcpy(vec[existe].sector,auxEmployee.sector);
                printf("  |  Se ha actualizado el sector con exito.\n");
                break;
            }
            default:
            {
                printf("  |  Error. Opcion incorrecta.");
            }

        }
    }
}
/** \brief Informe de sueldos totales y promedio
 *
 * \param eEmployee* vec: vectores de empleados
 * \param int len: tamaño de vector
 * \return No retorna nada
 *
 */

void reportSalaryTotalAverage(eEmployee* vec,int len)
{
    float sueldoAcumulado=0;
    int cantSueldos=0;
    float promedioSueldos;
    int cantEmpleadosSueldoMayorQuePromedio=0;
    system("cls");
    printf("  |------------------------------------|\n");
    printf("  |   ******Informe de Sueldos******   |\n\n");
    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0)
        {
            sueldoAcumulado=sueldoAcumulado+vec[i].salary;
            cantSueldos++;
        }
    }
    promedioSueldos=sueldoAcumulado/cantSueldos;
    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==0&&vec[i].salary>promedioSueldos)
        {
            cantEmpleadosSueldoMayorQuePromedio++;
        }
    }
    printf("  |  Total sueldos de empleados: $ %.2f\n",sueldoAcumulado);
    printf("  |  Promedio de sueldos: $ %.2f\n",promedioSueldos);
    printf("  |  Cantidad de empleados que superan el sueldo promedio: %d\n\n",cantEmpleadosSueldoMayorQuePromedio);
}


/** \brief Menu de informes
 *
 * \param
 * \param
 * \return Retorna el caracter de la opcion elegida
 *
 */

char menuReports()
{
    char opcion2;
    system("cls");
    printf("  |------------------------------------|\n");
    printf("  |  *****Informes de Empleados*****   |\n");
    printf("  |  a- Listar Empleados               |\n");
    printf("  |  b- Ordenar Empleados              |\n");
    printf("  |  c- Total Sueldos y Promedio       |\n");
    printf("  |  o- Salir                          |\n");
    printf("  |  Ingrese letra de opcion: ");
    fflush(stdin);
    scanf("%c",&opcion2);

    return opcion2;
}
