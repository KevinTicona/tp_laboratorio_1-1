#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"

int initEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        return 0;
    }

    return -1;
}

int addEmployee(Employee* list, int len, int ID)
{
    Employee newEmp;
    int validName;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                //Ahora este espacio esta lleno
                newEmp.isEmpty = 0;
                //id
                newEmp.id = ID;
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
                //Pedir Apellido y validar
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
                //Pedir salario
                printf("\nIngrese salario: ");
                scanf("%f", &newEmp.salary);
                //Pedir sector
                printf("\nIngrese sector: ");
                scanf("%d", &newEmp.sector);

                list[i] = newEmp;
                return 0;
            }
        }

    }

    return -1;
}


int findEmployeeById(Employee* list, int len,int id)
{
    int indiceId = -1;
    if(list != NULL && len > 0 && len <= 1000)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                indiceId = i;
                break;
            }
        }
    }
    return indiceId;
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
    if(list != NULL && len > 0 && len <= 1000)
    {
        printEmployees(list, len);
        printf("\nIngrese ID del empleado a modificar: ");
        scanf("%d", &id);
        index = findEmployeeById(list, len, id);
        system("cls");
        if(index == -1)
        {
            printf("No hay personas con ese ID\n");
        }
        else
        {
            printf("****************************************************************************\n");
            printf("  ID                Nombre             Apellido          Salario     Sector \n");
            printf("****************************************************************************\n");
            showEmployee(list[index]);
            printf("4. MODIFICAR:\n");
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Salario\n");
            printf("4. Sector\n");
            rst = getOption(&mOption, "\nOpcion invalida\n", 1, 4);
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
                    //Pedir apellido y validar apellido
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
    }

    return error;
}

int removeEmployee(Employee* list, int len)
{
    int error = -1;
    int id;
    int index;
    char confirmation;
    //La función podría devolver 3 enteros (0 - ok, -1 error, 1 ok pero no borró a nadie
    if(list != NULL && len > 0 && len <= 1000)
    {
        printEmployees(list, len);
        printf("\nIngrese ID del empleado a eliminar: ");
        scanf("%d", &id);
        index = findEmployeeById(list, len, id);
        if(index == -1)
        {
            printf("No hay personas con ese ID\n");
        }
        else
        {
            printf("****************************************************************************\n");
            printf("  ID                Nombre             Apellido          Salario     Sector \n");
            printf("****************************************************************************\n");
            showEmployee(list[index]);
            printf("Confirmar baja? s - si; n - no\n");
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
                list[index].isEmpty = 1;
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

int sortEmployees(Employee* list, int len, int order)
{
    if(list == NULL || len < 0 || len > 1000 || order < 0 || order > 1 )
    {
        return -1;
    }

    Employee aux;
    if(order == 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(list[i].sector > list[j].sector)  // Ordenar alfabeticamente por apellido && sector
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    else if(order == 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(list[i].sector < list[j].sector)  // Ordenar en forma inversa alfabeticamente por apellido && sector
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }

    return 0;
}

int printEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0 && len <= 1000)
    {
        //system("cls");
        printf("****************************************************************************\n");
        printf("  ID                Nombre             Apellido          Salario     Sector \n");
        printf("****************************************************************************\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                showEmployee(list[i]);
            }
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showEmployee(Employee emp)
{
    orderName(emp.name);
    orderName(emp.lastName);
    printf("%5d %20s %20s          %7.2f    %4d\n",
           emp.id,
           emp.name,
           emp.lastName,
           emp.salary,
           emp.sector);

}

int acumWages(Employee* list, int len, float* pSum)
{
    int error = -1;
    float acumWage = 0;

    if(list != NULL && len > 0 && len <= 1000 && pSum != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                acumWage += list[i].salary;
            }
        }
        *pSum = acumWage;
        error = 0;
    }

    return error;
}

int averageWages(Employee* list, int len, float* pAvg)
{
    int error = -1;
    int countEmployees = 0;
    float acumWage;
    if(list != NULL && len > 0 && len <= 1000 && pAvg != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                countEmployees++;
            }
        }
        acumWages(list, len, &acumWage);
        if(acumWage != -1)
        {
            *pAvg = (float) acumWage / countEmployees;
            error = 0;
        }
    }
    return error;
}

int getSuperiorWages(Employee* list, int len, int* pSuperiorWagesEmployees)
{
    int error = -1;
    int sprWagesEmployees = 0;
    float average;
    if(list != NULL && len > 0 && len <= 1000 && pSuperiorWagesEmployees != NULL)
    {
        averageWages(list, len, &average);
        if(average != -1)
        {
            for(int i = 0; i < len; i++)
            {
                if(list[i].isEmpty == 0 && list[i].salary > average)
                {
                    sprWagesEmployees++;
                }
            }
            *pSuperiorWagesEmployees = sprWagesEmployees;
            error = 0;
        }

    }
    return error;
}

void menu()
{
    system("cls");
    printf("**************************************************************************\n");
    printf("                        Trabajo Practico nro. 2          \n");
    printf("**************************************************************************\n");
    printf("                                 ABM                    \n");
    printf("**************************************************************************\n");
    printf("1. ALTA: Ingrese un empleado.\n");
    printf("2. MODIFICACION: Modifique un empleado por ID.\n");
    printf("3. BAJA: Elimine un empleado por ID.\n");
    printf("4. MOSTRAR:\n");
    printf("4.1. Lista de empleados\n");
    printf("4.2. Total y promedio de Salarios.\n");
    printf("5. SALIR\n");
}


