#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"

void menu_main()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                             Trabajo Practico nro. 3          \n");
    printf("__________________________________________________________________________________\n");
    printf("                                       ABM                    \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)..\n");
    printf("10. Salir.\n");
}

void menu_submenu_order()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                             Trabajo Practico nro. 3          \n");
    printf("__________________________________________________________________________________\n");
    printf("                            SUBMENU DE ORDENAMIENTOS                    \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Ordenar empleados por nombre.\n");
    printf("2. Ordenar empleados por ID.\n");
    printf("3. Ordenar empleados por horas trabajadas.\n");
    printf("4. Ordenar empleados por salario.\n");
    printf("5. Volver al menu principal.\n");
}
