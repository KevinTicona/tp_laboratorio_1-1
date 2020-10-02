#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"
#define TAM 1000
#define INIT_ID 2000


int main()
{
    Employee list[TAM];
    int actualID = INIT_ID;
    int addEmp;
    int option;
    int rst;
    // case 2
    int modifie;
    // case 3
    int removes;
    // subMenu case 4
    int opt4;
    int rst4;
    int rst41;
    int order;
    //sum, avg & number of employees exceeding average salary
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
                addEmp = addEmployee(list, TAM, actualID);
                if(addEmp < 0)
                {
                    printf("Ha ocurrido un problema. Intente nuevamente\n");
                }
                else
                {
                    printf("Operacion exitosa.\n");
                    employeesExist = 1;
                    actualID++;
                }
                break;
            case 2:
                if(!employeesExist)
                {
                    printf("Primero debes agregar un empleado.\n");
                    break;
                }
                modifie = modifieEmployee(list, TAM);
                if(!modifie)
                {
                    printf("Modificacion exitosa.\n");
                }
                else
                {
                    printf("Problemas al realizar la modificacion. Intente nuevamente\n");
                }
                break;
            case 3:
                if(!employeesExist)
                {
                    printf("Primero debes agregar un empleado.\n");
                    break;
                }
                removes = removeEmployee(list, TAM);
                if(!removes)
                {
                    printf("Baja exitosa.\n");
                }
                else if(removes == 1)
                {
                    printf("Baja cancelada por usuario.\n");
                }
                else
                {
                    printf("Problemas al realizar la baja. Intente nuevamente\n");
                }
                break;
            case 4:
                if(!employeesExist)
                {
                    printf("Primero debes agregar un empleado.\n");
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
                        system("cls");
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



