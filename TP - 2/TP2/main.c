#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"
#define TAM 1000

void menu();
int getOption(int* pResult, char* errorMsj, int min, int max);


int main()
{
    Employee list[TAM];
    int ID = 20000;
    int addEmp;
    int option;
    int rst;
    //subMenu case 4
    int opt4;
    int rst4;
    int rst41;
    int order;
    //suma, promedio y cantidad de empleados que superan el promedio
    float sum;
    float average;
    int supWageEmp;
    //flags
    int employeesExist = 0;

    initEmployees(list, TAM);
    do
    {
        menu();
        rst = getOption(&option, "\n Opcion invalida\n", 1, 5);
        if(!rst)
        {
            switch(option)
            {
            case 1:
                addEmp = addEmployee(list, TAM, ID);
                if(addEmp < 0)
                {
                    printf("Ha ocurrido un problema. Intente nuevamente\n");
                }
                else
                {
                    printf("Operación exitosa.\n");
                    employeesExist = 1;
                }
                break;
            case 2:
                if(!employeesExist)
                {
                    printf("Primero Debes añadir un empleado.\n");
                    break;
                }
                printf("Opcion en matenimiento\n");
                break;
            case 3:
                if(!employeesExist)
                {
                    printf("Primero Debes añadir un empleado.\n");
                    break;
                }
                printf("Opcion en matenimiento\n");
                break;
            case 4:
                if(!employeesExist)
                {
                    printf("Primero Debes añadir un empleado.\n");
                    break;
                }
                printf("4. MOSTRAR:\n");
                printf("1. Lista de empleados\n");
                printf("2. Total y promedio de Salarios.\n");
                rst4 = getOption(&opt4, "Opcion invalida. Intente nuevamente\n", 1, 2);
                if(!rst4)
                {
                    switch(opt4)
                    {
                    case 1:
                        printf("4. MOSTRAR:\n");
                        printf("1. EN FORMA CRECIENTE: Ingrese 1\n");
                        printf("2. EN FORMA DECRECIENTE: Ingrese 0\n");
                        rst41 = getOption(&order, "Opcion invalida. Intente nuevamente\n", 0, 1);
                        if(!rst41)
                        {
                            if(order)
                            {
                                sortEmployees(list, TAM, 1);
                            }
                            else if(!order)
                            {
                                sortEmployees(list, TAM, 0);
                            }
                        }
                        printEmployees(list, TAM);
                        break;
                    case 2:
                        acumWages(list, TAM, &sum);
                        averageWages(list, TAM, &average);
                        getSuperiorWages(list, TAM, &supWageEmp);
                        printf("4. MOSTRAR\n");
                        printf("1. TOTAL SALARIOS: %.2f\n", sum);
                        printf("2. PROMEDIO SALARIOS: %.2f\n", average);
                        printf("3. EMPLEADOS QUE COBRAN MÁS QUE EL SALARIO PROMEDIO: %d\n", supWageEmp);
                        break;
                    }
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(option != 5);
    return 0;
}

int getOption(int* pResult, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            scanf("%d", &opcion);
            int validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) || !validate)
            {
                *pResult = opcion;
                error = 0;
            }
            else
            {
                printf("%s\n", errorMsj);
                system("pause");
            }
        }
        while(error != 0);
    }
    return error;
}

void menu()
{
    system("cls");
    printf("**********************************************\n");
    printf("           Trabajo Practico nro. 2          \n");
    printf("**********************************************\n");
    printf("                    ABM                    \n");
    printf("**********************************************\n");
    printf("1. ALTA: Ingrese un empleado.\n");
    printf("2. MODIFICACION: Modifique un empleado por ID.\n");
    printf("3. BAJA: Elimine un empleado por ID.\n");
    printf("4. MOSTRAR:\n");
    printf("4.1. Lista de empleados\n");
    printf("4.2. Total y promedio de Salarios.\n");
    printf("5. SALIR\n");
}

