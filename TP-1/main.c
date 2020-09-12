#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "acunaUTN.h"

int main()
{
    int opcion;
    int x;
    int y;
    int opc1 = 0;
    int opc2 = 0;
    int opc3 = 0;
    int respuesta;
    int reset;

    do
    {
        menu(opc1, opc2, opc3, x, y);
        respuesta = getOption(&opcion, "\nOpcion invalida\n", 1, 5);
        if (!respuesta)
        {
            switch(opcion)
            {
            case 1:
                x = obtNum();
                opc1 = 1;
                break;
            case 2:
                y = obtNum();
                opc2 = 1;
                break;
            case 3:
                if(!opc1 || !opc2)
                {
                    printf("Primero debes ingresar ambos operandos\n");
                }
                else
                {
                    opc3 = 1;
                    printf("Calculando...\n");
                }
                break;
            case 4:
                reset = mostarResultado(opc3, x, y);
                if(reset)
                {
                    opc1 = 0;
                    opc2 = 0;
                    opc3 = 0;
                }
                break;
            case 5:
                //Salir
                printf("Saliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(opcion != 5);

    return 0;
}








