#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    FILE* pFile;
    int retorno=-1;
    int cant;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");

        if(pFile!=NULL)
        {
            cant=parser_EmployeeFromText(pFile,pArrayListEmployee);
            if(cant!=-1)
            {
                retorno=cant;
            }
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    FILE* pFile;
    int retorno=-1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");

        if(pFile!=NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                retorno=0;
            }
            fclose(pFile);
        }
    }
    system("pause");
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{
    int retorno=0;
    Employee* auxEmployee=employee_new();
    //int indice=ll_indexOf(pArrayListEmployee,&auxEmployee);
    //printf("Este es el indice %d",indice);
    /*if(indice==-1)
    {
        printf("Sistema completo.\n");
    }
    else
    {*/
        if(id!=NULL && pArrayListEmployee!=NULL)
        {
            auxEmployee->id=*id;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmployee->nombre);
            printf("Ingrese horas trabajadas: ");
            scanf("%d",&auxEmployee->horasTrabajadas);
            printf("Ingrese sueldo: ");
            scanf("%d",&auxEmployee->sueldo);

            printf("%d",ll_add(pArrayListEmployee,auxEmployee));
        }
    //}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idBuscado;
    int indice=0;
    int opcion;
    char nuevoNombre[128];
    int nuevasHoras;
    int nuevoSueldo;
    Employee* auxEmployee;
    printf("Ingrese id del empleado a modificar: ");
    scanf("%d",&idBuscado);
    indice=findEmployeeById(idBuscado,pArrayListEmployee);
    printf("Este es el indice: %d\n",indice);
    if(indice==-1)
    {
        printf("No existe empleado con ese id\n");
    }
    else
    {
        auxEmployee=((Employee*)ll_get(pArrayListEmployee,indice));
        listEmployee(auxEmployee);
        printf("Que dato desea modificar?:\n");
        printf("1-Nombre\n");
        printf("2-Horas Trabajadas\n");
        printf("3-Sueldo\n");
        printf("Ingrese el numero de la opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            {
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nuevoNombre);
                strcpy(auxEmployee->nombre,nuevoNombre);
                printf("Se ha actualizado el nombre con exito.\n");
                break;
            }
            case 2:
            {
                printf("Ingrese nuevas horas trabajadas: ");
                scanf("%d",&nuevasHoras);
                auxEmployee->horasTrabajadas=nuevasHoras;
                printf("Se han actualizado las horas trabajadas con exito.\n");
                break;
            }
            case 3:
            {
                printf("Ingrese nuevo sueldo: ");
                scanf("%d",&nuevoSueldo);
                auxEmployee->sueldo=nuevoSueldo;
                printf("Se ha actualizado el sueldo con exito.\n");
                break;
            }
            default:
            {
                printf("Error. Opcion incorrecta.\n");
            }

        }
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     int idBuscado;
    int indice=0;
    char confirma;
    Employee* auxEmployee;
    printf("Ingrese id del empleado a dar de baja: ");
    scanf("%d",&idBuscado);
    indice=findEmployeeById(idBuscado,pArrayListEmployee);
    //printf("Este es el indice: %d\n",indice);
    if(indice==-1)
    {
        printf("No existe empleado con ese id\n");
    }
    else
    {
        auxEmployee=((Employee*)ll_get(pArrayListEmployee,indice));
        listEmployee(auxEmployee);
        printf("Confirma la baja del empleado?(s/n):\n");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            ll_remove(pArrayListEmployee,indice);
            printf("Se ha realizado la baja con exito.\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion;");
        }

    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    if(listEmployees(pArrayListEmployee))
    {
        printf("No se pudo mostrar");
    }
    else
    {
        printf("Se pudo mostrar");
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;


    printf("Por que dato desea ordenarlos?: \n");
    printf("1-Id\n");
    printf("2-Nombre\n");
    printf("3-Horas Trabajadas\n");
    printf("4-Sueldo\n");
    printf("Ingrese el numero de opcion\n");
    scanf("%d",&opcion);

    if(opcion==1)
    {
        printf("Tenga paciencia, esto puede tardar un poco.\n");
        ll_sort(pArrayListEmployee,compararEmpleadosId,0);
        printf("Se ordenaron los empleados por id.\n");
        retorno=0;

    }
    else if(opcion==2)
    {
        printf("Tenga paciencia, esto puede tardar un poco.\n");
        ll_sort(pArrayListEmployee,compararEmpleadosNombre,0);
        printf(" Se ordenaron los empleados por nombre.\n");
        retorno=0;

    }
    else if(opcion==3)
    {
        printf("Tenga paciencia, esto puede tardar un poco.\n");
        ll_sort(pArrayListEmployee,compararEmpleadosHorasTrab,0);
        printf("Se ordenaron los empleados por horas de trabajo.\n");
        retorno=0;
    }
    else if(opcion==4)
    {
        printf("Tenga paciencia, esto puede tardar un poco.\n");
        ll_sort(pArrayListEmployee,compararEmpleadosSueldo,0);
        printf("Se ordenaron los empleados por sueldo.\n");
        retorno=0;
    }
    else
    {
        printf("Opcion Incorrecta.\n");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    FILE* pFile;
    int retorno=-1;
    Employee* auxEmployee;
    int tam;


    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            tam=ll_len(pArrayListEmployee);
            retorno=0;
            for(int i=0; i<tam; i++)
            {
                auxEmployee=((Employee*)ll_get(pArrayListEmployee,i));
                if (auxEmployee!=NULL)
                {
                    fprintf(pFile,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                }
            }
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    system("cls");
    FILE* pFile;
    int retorno=-1;
    Employee* auxEmployee;
    int tam;


    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile!=NULL)
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            tam=ll_len(pArrayListEmployee);
            retorno=0;
            for(int i=0; i<tam; i++)
            {
                auxEmployee=((Employee*)ll_get(pArrayListEmployee,i));
                if (auxEmployee!=NULL)
                {
                    fprintf(pFile,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                }
            }
            fclose(pFile);
        }
    }
    return retorno;
    return 1;
}

