#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Menu.h"

void menu_main()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                             Trabajo Practico nro. 4          \n");
    printf("__________________________________________________________________________________\n");
    printf("                                    MASCOTAS                   \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Cargar los datos de las mascotas desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de las mascotas desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de mascota.\n");
    printf("4. Modificar datos de mascota.\n");
    printf("5. Baja de mascota.\n");
    printf("6. Listar mascotas.\n");
    printf("7. Ordenar mascotas.\n");
    printf("8. Guardar los datos de las mascotas en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de las mascotas en el archivo data.bin (modo binario)..\n");
    printf("10. Salir.\n");
}
