#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#include "utn_mengassini.h"
#include "ArrayEmployees.h"

#define LEN 10
#define LENSEC 5
#define LENHARDCODE 8


//void hardcodeEmployees(eEmployee vec[],int len);
int menu();

int main()
{
    char seguir='s';
    char confirma;
    int nextId=1000;
    eEmployee list[LEN];
    initEmployees(list,LEN);

    //hardcodeEmployees(list,LENHARDCODE);
    //nextId+=LENHARDCODE;


    int triggerNro1=0;
    do
    {
        switch(menu())
        {
            case 1:
            {
                if(addEmployee(nextId,list,LEN)==1)
                {
                    nextId++;
                    triggerNro1=1;
                }
                break;
            }
            case 2:
            {
                if(triggerNro1==0)
                {
                    printf("  |  No ingresaste ningun empleado todavia.\n");
                }
                else
                {
                    modifyEmployee(list,LEN);
                }
                break;
            }
            case 3:
            {
                if(triggerNro1==0)
                {
                    printf("  |  No ingresaste ningun empleado todavia.\n");
                }
                else
                {
                    removeEmployee(list,LEN);
                }
                break;
            }
            case 4:
            {
                if(triggerNro1==0)
                {
                    printf("  |  No ingresaste ningun empleado todavia.\n");
                }
                else
                {
                    reportEmployees(list,LEN);
                }
                break;
            }
            case 5:
            {
                printf("  |  Confirma salir de gestion de empleados?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    seguir='n';
                }
                break;
            }
        }
        system("pause");
    }
    while(seguir=='s');
    return 0;
}


void hardcodeEmployees(eEmployee vec[],int len)
{
    for(int i=0;i<len;i++)
    {
        vec[i].id=ids[i];
        strcpy(vec[i].name,nombres[i]);
        strcpy(vec[i].lastName,apellidos[i]);
        vec[i].salary=sueldos[i];
        strcpy(vec[i].sector,sectores[i]);
        vec[i].isEmpty=0;
    }
}

int menu()
{
    int opcion;
    system("cls");
    printf("  |------------------------------------|\n");
    printf("  |  *****Gestion de Empleados*****    |\n");
    printf("  |  1- Alta                           |\n");
    printf("  |  2- Modificar                      |\n");
    printf("  |  3- Baja                           |\n");
    printf("  |  4- Informes                       |\n");
    printf("  |  5- Salir                          |\n\n");
    printf("  |  Ingrese numero de opcion: ");
    scanf("%d",&opcion);
    while(opcion>5||opcion<1)
    {
        printf("  |   Error. Opcion incorrecta.\n");
        printf("  |   Ingrese numero de opcion: ");
        scanf("%d",&opcion);
    }
    return opcion;
}
