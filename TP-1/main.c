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

int main()
{
    char seguir = 's';
    int opcion;
    int x;
    int y;
    int opc1 = 0;
    int opc2 = 0;

    printf("******Menu de opciones******\n");
    printf("1. Ingresar 1er operando (A=x)\n");
    printf("2. Ingresar 2do operando (B=y)\n");
    printf("3. Calcular todas las operaciones\n");
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
            printf("4. Informar resultados\n");
            printf("5. Salir\n\n");
            break;
        case 2:
            if(!opc1)
            {
                printf("Primero deberías ingresar el primer operando.\n");
            }
            else
            {
                opc2 = 1;
                y = obtNum();
                system("cls");
                printf("******Menu de opciones******\n");
                printf("1. Ingresar 1er operando (A = %d)\n", x);
                printf("2. Ingresar 2do operando (B = %d)\n", y);
                printf("3. Calcular todas las operaciones\n");
                printf("4. Informar resultados\n");
                printf("5. Salir\n\n");
            }
            break;
        case 3:
            if(!opc2)
            {
                printf("No has ingresado todos los operandos.\n");
            }
            else
            {
                printf("Calculando...\n");
            }
            break;
        case 4:
            break;
        case 5:
            printf("Realmente desea salir? s para si, n para no\n");
            fflush(stdin);
            scanf("%c", &seguir);
            seguir = tolower(seguir);
            if(seguir == 's')
            {
                printf("\nSaliendo...\n");
                seguir = 'n';
            }
            else if (seguir == 'n')
            {
                printf("Bueno, segui...\n");
                seguir = 's';
            }
            else
            {
                printf("Opcion invalida\n");
                seguir = 's';
            }
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


