#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validations.h"

int validations_getOption(int* pResult, char* errorMsj, int min, int max)
{
    int error = -1;
    int opcion;
    int validate;
    if(pResult != NULL && errorMsj != NULL && min <= max)
    {
        do
        {
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            validate = isdigit(opcion);
            if((opcion >= min && opcion <= max) && !validate)
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

int validations_charOnly(char* str)
{
    int i = 0;
    while (str[i])
    {
        printf("Validating: %s\n", &str[i]);
        if (!isalpha(str[i]) && str[i] != ' ')
        {
            return -1;
        }

        printf("Valid: %s\n", &str[i]);
        i++;
    }

    return 0;
}

int validations_nombre(char* nombre)
{
    int len = strlen(nombre);
    int valid = validations_charOnly(nombre);
    if(len >= 2 && len < 129 && !valid)
    {
        return 1;
    }
    printf("Not valid: %s\n", nombre);
    return 0;
}

int validations_horasTrabajadas(int horasTrabajadas)
{
    if(horasTrabajadas < 0 || horasTrabajadas > 180)
    {
        return 0;
    }
    return 1;
}

int validations_sueldo(int sueldo)
{
    if(sueldo > 0)
    {
        return 1;
    }
    return 0;
}
