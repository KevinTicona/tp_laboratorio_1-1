#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validations.h"

int charOnly(char str[])
{

    int i = 0;
    while (str[i])
    {
        if (
            !isalpha(str[i])
            && str[i] != ' '
        )
            return -1;
        i++;
    }

    return 0;
}
