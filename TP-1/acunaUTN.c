#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "acunaUTN.h"

int getOption(int* pResultado, char* mensajeError, int minimo, int maximo)
{
    int retorno = -1;
    int opcion;
    if(pResultado != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("\nIngrese opcion\n");
            scanf("%d", &opcion);
            if(opcion >= minimo && opcion <= maximo)
            {
                *pResultado = opcion;
                retorno = 0;
            }
            else
            {
                printf("%s\n", mensajeError);
                system("pause");
            }
        }
        while(retorno != 0);
    }
    return retorno;
}

int menu(int b1, int b2, float operando1, float operando2)
{
    system("cls");
    printf("***************************************\n");
    printf("        Trabajo Practico nro. 1        \n");
    printf("***************************************\n");
    printf("          Menu de opciones             \n");
    printf("***************************************\n");

    if(b1 == 0 && b2 == 0)
    {
        printf("1. Ingresar 1er operando (A = x)\n");
        printf("2. Ingresar 2do operando (B = y)\n");
    }
    else if(b1 == 1 && b2 == 0)
    {
        printf("1. Ingresar 1er operando (A = %.2f)\n", operando1);
        printf("2. Ingresar 2do operando (B = y)\n");
    }
    else if(b1 == 0 && b2 == 1)
    {
        printf("1. Ingresar 1er operando (A = x)\n");
        printf("2. Ingresar 2do operando (B = %.2f)\n", operando2);
    }
    else
    {
        printf("1. Ingresar 1er operando (A = %.2f)\n", operando1);
        printf("2. Ingresar 2do operando (B = %.2f)\n", operando2);
    }
    printf("3. Calcular todas las operaciones\n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    return 0;
}

int mostarResultado(int bandera, float operando1, float operando2)
{
    int reset = 0;
    if(!bandera)
    {
        printf("\nAun no hiciste los calculos...\n");
    }
    else
    {
        printf("***************************************\n");
        printf("              RESULTADOS               \n");
        printf("***************************************\n");
        printf("a) Resultado de (A+B): %.2f\n", suma(operando1, operando2));
        printf("b) Resultado de (A-B): %.2f\n", resta(operando1, operando2));

        float resultadoDivision;
        int divisionError = division(&resultadoDivision, operando1, operando2);
        if(!divisionError)
        {
            printf("c) Division de (A/B): %f\n", resultadoDivision);
        }
        else
        {
            printf("c) Division de (A/B): No se puede dividir por cero.\n");
        }

        printf("d) Multiplicacion de (A*B): %.2lf\n", multiplicacion(operando1, operando2));
        printf("e) Factorial (A!) y (B!): %lld - %lld\n", factorial(operando1), factorial(operando2));

        reset = 1;
    }
    return reset;
}

float obtNum()
{
    float num;
    printf("Ingresar operando\n");
    scanf("%f", &num);

    return num;
}

float suma(float a, float b)
{
    float resultado = a + b;
    return resultado;
}

float resta(float a, float b)
{
    float resultado = a - b;
    return resultado;
}

double multiplicacion(float a, float b)
{
    double resultado = a * b;
    return resultado;
}

long long int factorial(int a)
{
    long long int resultado = 1;
    for(int i = 1; i <= a; i++)
    {
        resultado *= i;
    }
    return resultado;
}

int division(float* pResultado, float a, float b)
{
    int error = -1;
    if(b == 0)
    {
        return error;
    }
    else
    {
        *pResultado = a / b;
        error = 0;
        return error;
    }
}
