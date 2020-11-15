#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/Validations.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

void validations_testLL(int tests)
{
    for(int i = 0; i < tests; i++)
    {
        startTesting(i);
    }
}

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
        if (!isalpha(str[i]) && str[i] != ' ' && str[i] != '-'&& str[i] != '_')
        {
            return -1;
        }
        i++;
    }

    return 0;
}

int validations_isValidNumber(char* str)
{
    int retorno = 1;
    int len = strlen(str);

    for(int i = 0; i < len-1; i++)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

void formatStr(char* str)
{
    //int len;
    strlwr(str);
    str[0] = toupper(str[0]);
    //len = strlen(str);
    /*for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            i++;
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = toupper(str[i]);
            }
        }
    }*/
}

int validations_isValidName(char* nombre)
{
    int len = strlen(nombre);
    int valid = validations_charOnly(nombre);
    if(len > 0 && len < 100 && !valid)
    {
        return 1;
    }

    return 0;
}

int validations_isValidType(char* type)
{
    printf("\nTIPO!!!!! %s\n",type);
    int len = strlen(type);
    int valid = validations_charOnly(type);

    if(!valid && len < 50 && len > 0)
    {
        formatStr(type);
        if(
            strcmp(type, "Gato") == 0 ||
            strcmp(type, "Perro") == 0 ||
            strcmp(type, "Roedor") == 0 ||
            strcmp(type, "Reptil") == 0
        )
        {
            return 1;
        }
    }

    return 0;
}

int validations_isValidSex(char* sex)
{
    strlwr(sex);
    if(strcmp(sex,"m") == 0 || strcmp(sex,"f") == 0)
    {
        return 1;
    }
    return 0;
}

int validations_isValidEdad(int edad)
{
    if(edad > 0 && edad <= 15)
    {
        return 1;
    }

    return 0;
}

