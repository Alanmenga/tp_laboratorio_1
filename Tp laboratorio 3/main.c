#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menu();


int main()
{
    char seguir = 's';
    char confirma;
    int proximoId=1;
    int cant;
    LinkedList* listaEmpleados;
    listaEmpleados = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                {
                    printf("Cargar desde texto.\n");
                    cant=controller_loadFromText("data.csv",listaEmpleados);
                    if(cant==-1)
                    {
                        printf("Problemas para cargar los empleados.\n");
                    }
                    else
                    {
                        proximoId+=cant;
                        printf("Empleados cargados correctamente y proximo id es: %d\n",proximoId);
                    }
                    break;
                }
            case 2:
                {
                    printf("Cargar desde binario.\n");
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("Problemas para cargar los empleados.\n");
                    }
                    else
                    {
                        printf("Empleados cargados correctamente\n");
                    }
                    break;
                }
            case 3:
                {
                    printf("Agregar Empleado.\n");
                    if(controller_addEmployee(listaEmpleados,&proximoId))
                    {
                        printf("Problemas para cargar los empleados.\n");
                    }
                    else
                    {
                        proximoId++;
                        printf("Empleados cargados correctamente y proximo id es: %d\n",proximoId);
                    }
                    break;
                }
            case 4:
                {
                    printf("Modificar datos de empleado.\n");
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("Problemas para modificar empleado.\n");
                    }
                    else
                    {
                        printf("Empleado modificado correctamente\n");
                    }
                    break;
                }
            case 5:
                {
                    printf("Baja de empleado.\n");
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Problemas para modificar empleado.\n");
                    }
                    else
                    {
                        printf("Empleado modificado correctamente\n");
                    }
                    break;
                }
            case 6:
                {
                    printf("Listar empleados.\n");
                    if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("Problemas para listar los empleados.\n");
                    }
                    else
                    {
                        printf("\n-----------Empleados listados correctamente-----------\n");
                    }
                    break;
                }
            case 7:
                {
                    printf("Ordenar empleados.\n");
                    if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("Problemas para ordenar los empleados.\n");
                    }
                    else
                    {
                        printf("\n-----------Empleados ordenadoscorrectamente-----------\n");
                    }
                    break;
                }
            case 8:
                {
                    printf("Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
                    if(controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("Problemas para guardar como texto los empleados.\n");
                    }
                    else
                    {
                        printf("\n-----------Empleados guardados como texto correctamente-----------\n");
                    }
                    break;
                }
            case 9:
                {
                    printf("Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
                    if(controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("Problemas para guardar como binario los empleados.\n");
                    }
                    else
                    {
                        printf("\n-----------Empleados guardados como binario correctamente-----------\n");
                    }
                    break;
                }
            case 10:
                {
                    printf("Confirma salir de gestion de empleados?(s/n): ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma=='s')
                    {
                        seguir='n';
                    }
                    break;
                }
            default:
                {
                    printf("Opcion incorrecta.\n");
                }
        }
        system("pause");
    }while(seguir== 's');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

int menu()
{
    system("cls");
    int opc;
    printf("|---------------------------MENU DE OPCIONES------------------------------|\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Ingrese numero de opcion: ");
    scanf("%d",&opc);
    return opc;

}
