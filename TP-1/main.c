#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

/*
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/

int obtNum();
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
long long int factorial(int a);
float division(int a, int b);


int main()
{
    char seguir = 's';
    int opcion;
    int x;
    int y;
    int opc1 = 0;
    int opc2 = 0;
    int opc3 = 0;

    printf("******Menu de opciones******\n");
    printf("1. Ingresar 1er operando (A=x)\n");
    printf("2. Ingresar 2do operando (B=y)\n");
    printf("3. Calcular todas las operaciones: \n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");


    do
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
                printf("   c) Division de (A/B): %f\n", division(x, y));
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
        system("pause");
    }
    while( seguir == 's');

    //printf("\nUsted ingreso opcion: %d\n", menu());

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

int multiplicacion(int a, int b)
{
    int resultado = a * b;
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

float division(int a, int b)
{
    float resultado;
    char error = 'n';
    if(b == 0)
    {
        return error;
    }
    else
    {
        resultado = (float) a / b;
        return resultado;
    }
}


