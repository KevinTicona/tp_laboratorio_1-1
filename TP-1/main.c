#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

/*
1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y\n3. Calcular todas las operaciones\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n4. Informar resultados\na) “El resultado de A+B es: r”\nb) “El resultado de A-B es: r”\nc) “El resultado de A/B es: r”\nd) “El resultado de A*B es: r”\ne) “El factorial de A es: r1 y El factorial de B es: r2”\n 5. Salir\n
*/


/**
* / brief Solicita un numero al usuario, valida, verifica y devuelve el resultado
* / param pResultado se guarda el numero ingresado por el usuario
* / param mensajeError mensaje de error si hay un error
* / param minimo valor aceptado
* / param maximo valor aceptado
* / return Exitoso = 0. Error = -1
*/
int getOption(int* pResultado, char* mensajeError, int minimo, int maximo);

int menu(int b1, int b2, int b3, int operando1, int operando2);
int mostarResultado(int bandera, int operando1, int operando2);
int obtNum();
int suma(int a, int b);
int resta(int a, int b);
long long int multiplicacion(int a, int b);
long long int factorial(int a);
int division(float* pResultado,int a, int b);


int main()
{
    int opcion;
    int x;
    int y;
    int opc1 = 0;
    int opc2 = 0;
    int opc3 = 0;
    int respuesta;
    int reset;

    do
    {
        menu(opc1, opc2, opc3, x, y);
        respuesta = getOption(&opcion, "\nOpcion invalida\n", 1, 5);
        if (!respuesta)
        {
            switch(opcion)
            {
            case 1:
                //Obtener numero
                x = obtNum();
                opc1 = 1;
                break;
            case 2:
                //Obtener otro numero
                y = obtNum();
                opc2 = 1;
                break;
            case 3:
                if(!opc1 || !opc2)
                {
                    printf("Primero debes ingresar ambos operandos\n");
                }
                else
                {
                    opc3 = 1;
                    printf("Calculando...\n");
                }
                break;
            case 4:
                reset = mostarResultado(opc3, x, y);
                if(reset)
                {
                    opc1 = 0;
                    opc2 = 0;
                    opc3 = 0;
                }
                break;
            case 5:
                //Salir
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcion != 5);

    return 0;
}

int menu(int b1, int b2, int b3, int operando1, int operando2)
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
        printf("1. Ingresar 1er operando (A = %d)\n", operando1);
        printf("2. Ingresar 2do operando (B = y)\n");
    }
    else if(b1 == 0 && b2 == 1)
    {
        printf("1. Ingresar 1er operando (A = x)\n");
        printf("2. Ingresar 2do operando (B = %d)\n", operando2);
    }
    else
    {
        printf("1. Ingresar 1er operando (A = %d)\n", operando1);
        printf("2. Ingresar 2do operando (B = %d)\n", operando2);
    }
    printf("3. Calcular todas las operaciones\n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");
    return 0;
}

int mostarResultado(int bandera, int operando1, int operando2)
{
    int reset = 0;
    if(!bandera)
    {
        printf("\nAun no hiciste los calculos...\n");
    }
    else
    {
        printf("***************************************\n");
        printf("               RESULTADOS              \n");
        printf("***************************************\n");
        printf("a) Resultado de (A+B): %d\n", suma(operando1, operando2));
        printf("b) Resultado de (A-B): %d\n", resta(operando1, operando2));

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

        printf("d) Multiplicacion de (A*B): %lld\n", multiplicacion(operando1, operando2));
        printf("e) Factorial (A!) y (B!): %lld - %lld\n", factorial(operando1), factorial(operando2));

        reset = 1;
    }
    return reset;
}

int obtNum()
{
    int num;
    printf("Ingresar operando\n");
    scanf("%d", &num);

    return num;
}

int suma(int a, int b)
{
    int resultado = a + b;
    return resultado;
}

int resta(int a, int b)
{
    int resultado = a - b;
    return resultado;
}

long long int multiplicacion(int a, int b)
{
    long long int resultado = a * b;
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

int division(float* pResultado,int a, int b)
{
    int error = -1;
    if(b == 0)
    {
        return error;
    }
    else
    {
        *pResultado = (float) a / b;
        error = 0;
        return error;
    }
}


int getOption(int* pResultado, char* mensajeError, int minimo, int maximo)
{
    int retorno = -1;
    int opcion;
    if(pResultado != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("\nIngrese opcion\n\n");
            scanf("%d", &opcion);
            if(opcion >= minimo && opcion <= maximo)
            {
                *pResultado = opcion;
                return 0;
            }
            else
            {
                printf("%s", mensajeError);
                system("pause");
            }
        }
        while(!retorno);
    }
    return retorno;
}


