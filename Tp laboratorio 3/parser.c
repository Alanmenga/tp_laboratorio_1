#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer [4][2000];
    int retorno=-1;
    Employee* auxEmployee;
    int cant;
    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        //LECTURA DEL ENUNCIADO
        //printf("|------------------------------------------------------------------|\n");
        //printf("|------------------------------------------------------------------|\n");
        cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        //printf("|  %s   |    %s          |   %s   |    %s     |\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        //printf("|------------------------------------------------------------------|\n");
        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant==4)
            {
                auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                //printf("|------------------------------------------------------------------|\n");
                //printf("| %04d  | %15s    |        %4d         |   %5d       |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                ll_add(pArrayListEmployee,auxEmployee);
                retorno=auxEmployee->id;
            }
            else
            {
                break;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer [4][2000];
    int retorno=-1;
    Employee* auxEmployee;
    int cant;
    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        //LECTURA DEL ENUNCIADO
        //printf("|------------------------------------------------------------------|\n");
        //printf("|------------------------------------------------------------------|\n");
        cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        //printf("|  %s   |    %s          |   %s   |    %s     |\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        //printf("|------------------------------------------------------------------|\n");
        while(!feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant==4)
            {
                auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                //printf("|------------------------------------------------------------------|\n");
                //printf("| %04d  | %15s    |        %4d         |   %5d       |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                ll_add(pArrayListEmployee,auxEmployee);
                retorno=auxEmployee->id;
            }
            else
            {
                break;
            }
        }
    }
    return retorno;
}
