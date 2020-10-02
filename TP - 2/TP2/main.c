#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"
#define TAM 1000

void menu();
int getOption(int* pResult, char* errorMsj, int min, int max);
int modifieEmployee(Employee* list, int len);


int main()
{
    Employee list[TAM];
    int ID = 20000;
    int addEmp;
    int option;
    int rst;
    // case 2 modificar empleado
    int modifie;
    // case 3 remover empleado
    int remove;
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
                modifie = modifieEmployee(list, TAM);
                if(!modifie)
                {
                    printf("Modificacion exitosa.\n");
                }
                else if(modifie == 1)
                {
                    printf("Modificacion cancelada por usuario.\n");
                }
                else
                {
                    printf("Problemas al realizar la modificacion. Intente nuevamente\n");
                }
                break;
            case 3:
                if(!employeesExist)
                {
                    printf("Primero Debes añadir un empleado.\n");
                    break;
                }
                remove = removeEmployee(list, TAM);
                if(!remove)
                {
                    printf("Baja exitosa.\n");
                }
                else if(remove == 1)
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
    int validate;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            scanf("%d", &opcion);
            validate = isdigit(opcion);
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

int modifieEmployee(Employee* list, int len)
{
    Employee newEmp;
    int validName;
    int error = -1;
    int id;
    int index;
    int rst;
    int mOption;
    char confirmation;
    if(list != NULL && len > 0 && len <= 1000)
    {
        printEmployees(list, len);
        printf("\nIngrese ID del empleado a modificar: ");
        scanf("%d", &id);
        index = findEmployeeById(list, len, id);
        if(index == -1)
        {
            printf("No hay personas con ese ID\n");
        }
        else
        {
            printf("ID Nombre  Apellido  Salario  Sector \n");
            printf("-------------------------------------\n");
            showEmployee(list[index]);
            printf("Confirmar modificacion? s - si; n - no\n");
            fflush(stdin);
            scanf("%c", &confirmation);
            confirmation = tolower(confirmation);
            while(confirmation != 's' && confirmation != 'n')
            {
                printf("Opción invalida. s - si; n - no\n");
                fflush(stdin);
                scanf("%c", &confirmation);
                confirmation = tolower(confirmation);
            }

            if(confirmation == 's')
            {
                printf("4. MODIFICAR:\n");
                printf("1. Nombre\n");
                printf("2. Apellido\n");
                printf("3. Salario\n");
                printf("4. Sector\n");
                rst = getOption(&mOption, "\nOpcion invaida\n", 1, 4);
                if(!rst)
                {
                    switch(mOption)
                    {
                    case 1:
                        //Pedir nombre y validar nombre
                        printf("\nIngrese nombre/s: ");
                        fflush(stdin);
                        gets(newEmp.name);
                        validName = charOnly(newEmp.name);
                        while(strlen(newEmp.name) > 51 || validName < 0)
                        {
                            printf("\nDato invalido. Ingrese nombre: ");
                            fflush(stdin);
                            gets(newEmp.name);
                            validName = charOnly(newEmp.name);
                        }
                        strcpy(list[index].name, newEmp.name);
                        break;
                    case 2:
                        //Pedir nombre y validar nombre
                        printf("\nIngrese apellido/s: ");
                        fflush(stdin);
                        gets(newEmp.lastName);
                        validName = charOnly(newEmp.lastName);
                        while(strlen(newEmp.lastName) > 51 || validName < 0)
                        {
                            printf("\nDato invalido. Ingrese apellido: ");
                            fflush(stdin);
                            gets(newEmp.lastName);
                            validName = charOnly(newEmp.lastName);
                        }
                        strcpy(list[index].lastName,newEmp.lastName);
                        break;
                    case 3:
                        printf("\nIngrese nuevo salario: ");
                        scanf("%f", &list[index].salary);
                        break;
                    case 4:
                        printf("\nIngrese nuevo sector: ");
                        scanf("%d", &list[index].sector);
                        break;
                    }
                }
                error = 0;
            }
            else if(confirmation == 'n')
            {
                error = 1;
            }
        }

    }

    return error;
}
