#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/** \brief Ingresa al menu y devuelve una opcion.
 * \param Opcion 1: Pide un numero.
 * \param Opcion 2: Pide otro numero.
 * \param Opcion 3: Calcula las operaciones.
 * \param Opcion 4: Muestra los resultados de las operaciones.
 * \param Opcion 5: Sale del programa.
 * \return Devuelve una opcion.
 */

int menu(float a,float b,int f1,int f2)
{
    int opcion;

    system("cls");
    printf("  |------CALCULADORA TP1--MENGASSINI ALAN-----|\n");
    printf("  |-------------------------------------------|\n");
    printf("  |-------------MENU DE OPCIONES--------------|\n\n");
    printf("  |-------------------------------------------|\n");
    if (f1==0)
    {
        printf("  | 1-  Ingresar primer numero.(A=x)          \n");
    }
    else if (f1==1)
    {
        printf("  | 1-  Ingresar primer numero.(A=%.2f)          \n",a);
    }
    if (f2==0)
    {
        printf("  | 2-  Ingresar segundo numero.(B=y)         \n");
    }
    else if (f2==1)
    {
        printf("  | 2-  Ingresar segundo numero.(B=%.2f)         \n",b);
    }
    printf("  | 3-  Calcular operaciones.                 |\n");
    printf("  | 4-  Informar los resultados.              |\n");
    printf("  | 5-  Salir del programa.                   |\n\n");
    printf("  |-------------------------------------------|\n");
    printf("  | Ingrese una opcion: ");
    scanf("%d",&opcion);


    return opcion;
}


/** \brief Toma dos numeros y los suma.
 * \param Primer numero.
 * \param Segundo numero.
 * \return Devuelve el resultado de la suma.
 */

float suma (float a, float b)
{
    float total;
    total=a+b;
    return total;
}

/** \brief Toma dos numeros y los resta.
 * \param Primer numero.
 * \param Segundo numero.
 * \return Devuelve el resultado de la resta.
 */

float resta (float a, float b)
{
    float total;
    total=a-b;
    return total;
}

/** \brief Toma dos numeros y los divide.
 * \param Primer numero.
 * \param Segundo numero.
 * \return Devuelve el resultado de la division.
 */

float division (float a,float b)
{

    float total;
    if(b==0)
    {
       //No se puede dividir por 0.
       return 0;
    }
    else if (b!=0)
    {
        total=(float)a/b;
        return total;
    }
    return 0;
}

/** \brief Toma dos numeros y los multiplica.
 * \param Primer numero.
 * \param Segundo numero.
 * \return Devuelve el resultado de la multiplicacion.
 */

float multiplicacion (float a,float b)
{
    float total;
    total=a*b;
    return total;
}

/** \brief Toma un numero y realiza su factorial.
 * \param Primer numero.
 * \return Devuelve el resultado del factorial.
 */

float factorial1 (float a)
{
    float resp;
    if(a==1||a==0)
    {
        return 1;
    }
    else if (a>=20)
    {
        // El factorial de A es demasiado grande.
        return 0;
    }
    else
    {
        resp=a* factorial1(a-1);
        return (resp);
    }
}

/** \brief Toma un numero y realiza su factorial.
 * \param Primer numero.
 * \return Devuelve el resultado del factorial.
 */

float factorial2 (float b)
{
    float resp;
    if(b==1||b==0)
    {
        return 1;
    }
    else if (b>=20)
    {
        //El factorial de B es demasiado grande.
        return 0;
    }
    else
    {
        resp=b* factorial2(b-1);
        return (resp);
    }
}
