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
* / param mensaje es el mensaje que se mostrara
* / param mensajeError mensaje de error si hay un error
* / param minimo valor aceptado
* / param maximo valor aceptado
* / return Exitoso = 0. Error = -1
*/
int getOption(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

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

    respuesta = getOption(&opcion, "1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\na) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion (A*B)\ne) Calcular el factorial (A!)\n 4. Informar resultados\n a) El resultado de A+B es: r\n b) El resultado de A-B es: r\n c) El resultado de A/B es: r\n d) El resultado de A*B es: r\n e) El factorial de A es: r1 y El factorial de B es: r2\n 5. Salir.\n", "Opción invalida", 1, 5);

    if(!respuesta)
    {
        do
        {
            printf("Ingrese opcion\n\n");

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
                    printf("Primero debes ingresar ambos operandos");
                }
                else
                {
                    opc3 = 1;
                    printf("Calculando...");
                    system("pause");
                }
                break;
            case 4:
            {
                if(!opc3)
                {
                    printf("Aun no hiciste los calculos...");
                    break;
                }

                float resultadoDivision;
                int divisionError = division(&resultadoDivision, x, y);
                if(!divisionError)
                {
                    system("cls");
                    printf("******Menu de opciones******\n");
                    printf("1. Ingresar 1er operando (A = %d)\n", x);
                    printf("2. Ingresar 2do operando (B = %d)\n", y);
                    printf("3. Calcular todas las operaciones\n");
                    printf("   a) Calcular la suma (A+B)\n");
                    printf("   b) Calcular la resta (A-B)\n");
                    printf("   c) Calcular la division (A/B)\n");
                    printf("   d) Calcular la multiplicacion (A*B)\n");
                    printf("   e) Calcular el factorial (A!)\n");
                    printf("4. Informar resultados\n");
                    printf("   a) Resultado de (A+B): %d\n", suma(x, y));
                    printf("   b) Resultado de (A-B): %d\n", resta(x, y));
                    printf("   c) Division de (A/B): %f\n", resultadoDivision);
                    printf("   d) Multiplicacion de (A*B): %lld\n", multiplicacion(x, y));
                    printf("   e) Factorial (A!): %lld\n", factorial(x));
                    printf("5. Salir\n\n");
                }
                else
                {
                    system("cls");
                    printf("******Menu de opciones******\n");
                    printf("1. Ingresar 1er operando (A = %d)\n", x);
                    printf("2. Ingresar 2do operando (B = %d)\n", y);
                    printf("3. Calcular todas las operaciones\n");
                    printf("   a) Calcular la suma (A+B)\n");
                    printf("   b) Calcular la resta (A-B)\n");
                    printf("   c) Calcular la division (A/B)\n");
                    printf("   d) Calcular la multiplicacion (A*B)\n");
                    printf("   e) Calcular el factorial (A!)\n");
                    printf("4. Informar resultados\n");
                    printf("   a) Resultado de (A+B): %d\n", suma(x, y));
                    printf("   b) Resultado de (A-B): %d\n", resta(x, y));
                    printf("   c) Division de (A/B): No se puede dividir por cero.\n");
                    printf("   d) Multiplicacion de (A*B): %lld\n", multiplicacion(x, y));
                    printf("   e) Factorial (A!): %lld\n", factorial(x));
                    printf("5. Salir\n\n");
                }
                break;
            }
            case 5:
                //Salir
                printf("Saliendo...\n");
                system("pause");
                break;
            }
        }
        while(opcion != 5);
    }

    /*do
    {
        printf("Ingrese opcion\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            opc1 = 1;
            x = obtNum();
            system("cls");
            printf("******Menu de opciones******\n");
            printf("1. Ingresar 1er operando (A = %d)\n", x);
            printf("2. Ingresar 2do operando (B = y)\n");
            printf("3. Calcular todas las operaciones\n");
            printf("   a) Calcular la suma (A+B)\n");
            printf("   b) Calcular la resta (A-B)\n");
            printf("   c) Calcular la division (A/B)\n");
            printf("   d) Calcular la multiplicacion (A*B)\n");
            printf("   e) Calcular el factorial (A!)\n");
            printf("4. Informar resultados\n");
            printf("5. Salir\n\n");
            break;
        case 2:
            if(opc1)
            {
                opc2 = 1;
                y = obtNum();
                system("cls");
                printf("******Menu de opciones******\n");
                printf("1. Ingresar 1er operando (A = %d)\n", x);
                printf("2. Ingresar 2do operando (B = %d)\n", y);
                printf("3. Calcular todas las operaciones\n");
                printf("   a) Calcular la suma (A+B)\n");
                printf("   b) Calcular la resta (A-B)\n");
                printf("   c) Calcular la division (A/B)\n");
                printf("   d) Calcular la multiplicacion (A*B)\n");
                printf("   e) Calcular el factorial (A!)\n");
                printf("4. Informar resultados\n");
                printf("5. Salir\n\n");
            }
            else
            {
                printf("\nPrimero deberias ingresar el primer operando.\n");
            }
            break;
        case 3:
            if(opc2)
            {
                opc3 = 1;
                printf("\nCalculando...\n");
            }
            else
            {
                printf("No has ingresado todos los operandos.\n");
            }
            break;
        case 4:
            if(opc3)
            {
                system("cls");
                printf("******Menu de opciones******\n");
                printf("1. Ingresar 1er operando (A = %d)\n", x);
                printf("2. Ingresar 2do operando (B = %d)\n", y);
                printf("3. Calcular todas las operaciones\n");
                printf("   a) Calcular la suma (A+B)\n");
                printf("   b) Calcular la resta (A-B)\n");
                printf("   c) Calcular la division (A/B)\n");
                printf("   d) Calcular la multiplicacion (A*B)\n");
                printf("   e) Calcular el factorial (A!)\n");
                printf("4. Informar resultados\n");
                printf("   a) Resultado de (A+B): %d\n", suma(x, y));
                printf("   b) Resultado de (A-B): %d\n", resta(x, y));
                //printf("   c) Division de (A/B): %f\n", division(x, y));
                printf("   d) Multiplicacion de (A*B): %d\n", multiplicacion(x, y));
                printf("   e) Factorial (A!): %lld\n", factorial(x));
                printf("5. Salir\n\n");
            }
            else
            {
                printf("No has hecho los calculos.\n");
            }
            break;
        case 5:
            printf("Saliendo...\n");
            seguir = 'n';
            break;
        default:
            printf("\nOpcion invalida\n");
        }
        //(system("pause");
    }
    while( seguir == 's');

    //printf("\nUsted ingreso opcion: %d\n", menu());
    */

    return 0;
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
    if(b == 0 || b == 0)
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


int getOption(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int retorno = -1;
    int opcion;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &opcion);
            if(opcion >= minimo && opcion <= maximo)
            {
                *pResultado = opcion;
                return 0;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(!retorno);
    }
    return retorno;
}


