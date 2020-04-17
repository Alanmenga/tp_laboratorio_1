#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "utn-alan.h"


int main()
{
    float nro1,nro2;
    float resultadoSuma,resultadoResta,resultadoDivi,resultadoMulti,resultadoFactA,resultadoFactB;
    int triggerNro1=0,triggerNro2=0,triggerCalculos=0;
    char seguir='s';
    int f1=0;
    int f2=0;
    do
    {
        //Este es el switch principal
        switch(menu(nro1,nro2, f1, f2))
        {
            //Caso 1: Ingresar el primer numero y volver al menu mostrandolo
            case 1: printf("  |-------------------------------------------|\n");
                    printf("  | Ingresa el primer numero: ");
                    scanf("%f",&nro1);
                    f1=1;
                    triggerNro1=1;
                    break;
            //Caso 2: Ingresar el segundo numero y volver al menu mostrandolo
            case 2: if(triggerNro1==0)
                    {
                        printf("  |-------------------------------------------|\n");
                        printf("  | No ingresaste el primer numero.\n");
                    }
                    else
                    {
                    printf("  |-------------------------------------------|\n");
                    printf("  | Ingresa el segundo numero: ");
                    scanf("%f",&nro2);
                    f2=1;
                    triggerNro2=1;
                    }
                    break;
            //Caso 3: Hacer los calculos con los numeros ingresados
            case 3: if(triggerNro2==0 && triggerNro1==0)
                    {
                        printf("  |-------------------------------------------|\n");
                        printf("  | No ingresaste ningun numero.\n");
                    }
                    else if (triggerNro2==0)
                    {
                        printf("  |-------------------------------------------|\n");
                        printf("  | No ingresaste el segundo numero.\n");
                    }
                    else
                    {
                    printf("  |-------------------------------------------|\n");
                    printf("  | Calculado las operaciones....\n");
                    resultadoSuma=suma(nro1,nro2);
                    resultadoResta=resta(nro1,nro2);
                    resultadoDivi=division(nro1,nro2);
                    resultadoMulti=multiplicacion(nro1,nro2);
                    resultadoFactA=factorial1(nro1);
                    resultadoFactB=factorial2(nro2);
                    triggerCalculos=1;
                    }
                    break;
            //Caso 4: Mostrar los resultados obtenidos
            case 4: if(triggerCalculos==0)
                    {
                        printf("  |-------------------------------------------|\n");
                        printf("  | Todavia no hiciste los calculos.\n");
                    }
                    else
                    {
                    printf("  |-------------------------------------------|\n");
                    printf("  | Los resultados son: \n");
                    printf("  | El resultado de A+B es: %.2f\n",resultadoSuma);
                    printf("  | El resultado de A-B es: %.2f\n",resultadoResta);
                    if(resultadoDivi==0)
                    {
                        printf("  | No se puede dividir un numero por 0.\n");
                    }
                    else
                    {
                        printf("  | El resultado de A/B es: %.2f\n",resultadoDivi);
                    }
                    printf("  | El resultado de A*B es: %.2f\n",resultadoMulti);
                    if(resultadoFactA==0 && resultadoFactB==0)
                    {
                        printf("  | El resultado de A! es muy grande y B! es muy grande\n\n");
                    }
                    else if(resultadoFactA==0 && resultadoFactB!=0)
                    {
                        printf("  | El resultado de A! es muy grande y B! es %.2f\n\n",resultadoFactB);
                    }
                    else if(resultadoFactB==0 && resultadoFactA!=0)
                    {
                        printf("  | El resultado de A! es %.2f y B! es muy grande\n\n",resultadoFactA);
                    }
                    else if(resultadoFactB!=0 && resultadoFactA!=0)
                    {
                        printf("  | El resultado de A! es %.2f y B! es %.2f\n\n",resultadoFactA,resultadoFactB);
                    }
                    triggerNro1=0;
                    triggerNro2=0;
                    triggerCalculos=0;
                    f1=0;
                    f2=0;
                    }
                    break;
            //Caso 5: Sale del programa.
            case 5: printf("\n Saliendo del programa. Hasta luego.\n\n");
                    seguir='n';
                    break;
            default: printf("\n Opcion incorrecta. Vuelva a intentarlo.\n\n");


            system("pause");
        }
        fflush(stdin);
        system("pause");
    }while(seguir=='s');

    return 0;
}
