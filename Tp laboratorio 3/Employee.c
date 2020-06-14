#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*) malloc(sizeof(Employee));

    if(newEmployee!=NULL)
    {
            newEmployee->id=0000;
            strcpy(newEmployee->nombre,"Vacio");
            newEmployee->horasTrabajadas=0000;
            newEmployee->sueldo=00000;
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee=employee_new();

    if(newEmployee!=NULL)
    {
        if(employee_setNombre(newEmployee,nombreStr) ||
           employee_setHorasTrabajadas(newEmployee,*horasTrabajadasStr) ||
           employee_setSueldo(newEmployee,*sueldoStr))
        {
            free(newEmployee);
            newEmployee=NULL;
        }
        else
        {
            newEmployee->id=atoi(idStr);
            strcpy(newEmployee->nombre,nombreStr);
            newEmployee->horasTrabajadas=atoi(horasTrabajadasStr);
            newEmployee->sueldo=atof(sueldoStr);
        }
    }
    return newEmployee;
}


void employee_delete()
{


}
// ---------------GETTER Y SETTER DE ID
//--------------------------------------
int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0 && id<=2000)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

// ---------------GETTER Y SETTER DE NOMBRE
//-----------------------------------------
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && strlen(nombre)>=1 && strlen(nombre)<20)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

// ---------------GETTER Y SETTER DE HORASTRABAJADAS
//-------------------------------------------------
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0 && horasTrabajadas<=500)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

// ---------------GETTER Y SETTER DE SUELDO
//------------------------------------------
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0 && sueldo<=10000)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
    }
    return retorno;
}



int listEmployee(Employee* this)
{
    int retorno=1;

    if(this!=NULL )
    {
        printf("|------------------------------------------------------------------|\n");
        printf("| %04d  | %15s    |        %4d         |   %5d       |\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        retorno=0;
    }

    return retorno;
}

int listEmployees(LinkedList* lista)
{
    int retorno=1;
    int flag=0;
    int tam=ll_len(lista);
    Employee* auxEmpleado;
    if(lista!=NULL )
    {
        printf("|------------------------------------------------------------------|\n");
        printf("|   ID         NOMBRE            HORASTRABAJADAS         SUELDO    |\n");
        printf("|------------------------------------------------------------------|\n");
        for(int i=0;i<tam;i++)
        {
            auxEmpleado=((Employee*)ll_get(lista,i));
            if(auxEmpleado!=NULL)
            {
                listEmployee(auxEmpleado);
                flag=1;
            }
        }
        retorno=0;
    }
    if(flag==0)
    {
        printf("No hay empleados para mostrar\n");
    }
    printf("\n\n");
    return retorno;
}

int findEmployeeById(int id,LinkedList* lista)
{
    int indice=-1;
    Employee* auxEmployee;
    int tam=ll_len(lista);
    if(lista!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            auxEmployee=((Employee*)ll_get(lista,i));
            if (auxEmployee!=NULL && auxEmployee->id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int compararEmpleadosNombre(void* emp1,void* emp2)
{
    int rta;
    Employee* a=(Employee*)emp1;
    Employee* b=(Employee*)emp2;
    if(strcmp(a->nombre,b->nombre)==0)
    {
        rta=0;
    }
    else if(strcmp(a->nombre,b->nombre)>0)
    {
        rta=-1;
    }
    else
    {
        rta=1;
    }
    return rta;
}

int compararEmpleadosHorasTrab(void* emp1,void* emp2)
{
    int rta;
    Employee* a=(Employee*)emp1;
    Employee* b=(Employee*)emp2;
    if(a->horasTrabajadas==b->horasTrabajadas)
    {
        rta=0;
    }
    else if(a->horasTrabajadas>b->horasTrabajadas)
    {
        rta=-1;
    }
    else
    {
        rta=1;
    }
    return rta;
}

int compararEmpleadosSueldo(void* emp1,void* emp2)
{
    int rta;
    Employee* a=(Employee*)emp1;
    Employee* b=(Employee*)emp2;
    if(a->sueldo==b->sueldo)
    {
        rta=0;
    }
    else if(a->sueldo>b->sueldo)
    {
        rta=-1;
    }
    else
    {
        rta=1;
    }
    return rta;
}


int compararEmpleadosId(void* emp1,void* emp2)
{
    int rta;
    Employee* a=(Employee*)emp1;
    Employee* b=(Employee*)emp2;
    if(a->id==b->id)
    {
        rta=0;
    }
    else if(a->id>b->id)
    {
        rta=-1;
    }
    else
    {
        rta=1;
    }
    return rta;
}
