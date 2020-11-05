#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validations.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void menu();

int main()
{
    int option = 0;
    int select = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        menu();
        select = validations_getOption(
                     &option,
                     "\nOpcion invalida. Intente nuevamente.\n",
                     1,
                     10
                 );

        if(!select)
        {
            switch(option)
            {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 3:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 4:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 5:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 6:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 7:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 8:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 9:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 10:
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(option != 10);

    return 0;
}


void menu()
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
