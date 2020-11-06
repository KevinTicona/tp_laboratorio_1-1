#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validations.h"
#include "Menu.h"

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

int main()
{
    int option = 0;
    int select = 0;
    int optionSort = 0;
    int selectSort = 0;
    int idActual = 0;

    char idConvert[30];
    char nombre[30]; //validar nombre p/ volver a intentarlo
    char sueldo[30];
    char horas[30];

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        menu_main();
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
                printf("Linked List size: %d", ll_len(listaEmpleados));
                break;
            case 2:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 3:
            {
                Employee* newEmployee = NULL;
                do
                {
                    printf("\nIngrese nombre:");
                    fflush(stdin);
                    gets(nombre);

                    printf("\nIngrese sueldo:");
                    fflush(stdin);
                    gets(sueldo);

                    printf("\nIngrese horas trabajadas:");
                    fflush(stdin);
                    gets(horas);

                    idActual = ll_len(listaEmpleados);
                    itoa(idActual, idConvert, 10);
                    newEmployee = employee_newParametros(
                                      idConvert,
                                      nombre,
                                      horas,
                                      sueldo);
                    if(newEmployee != NULL)
                    {
                        ll_add(listaEmpleados, newEmployee);
                    }
                    else
                    {
                        printf("\nLo sentimos, algo salió mal...\n");
                    }

                }
                while(newEmployee == NULL);
                printf("Tam lista: %d\n", ll_len(listaEmpleados));
                break;
            }
            case 4:
                /*
                Pedir id para modificar
                */
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 5:
                /*
                Pedir id para eliminar
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 6:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 7:
                do
                {
                    menu_submenu_order();
                    selectSort = validations_getOption(
                                     &optionSort,
                                     "\nOpcion invalida\n",
                                     1,
                                     5);
                    if(!selectSort)
                    {
                        switch(optionSort)
                        {
                        case 1:
                            printf("Opcion en mantenimiento.\n");
                            break;
                        case 2:
                            printf("Opcion en mantenimiento.\n");
                            break;
                        case 3:
                            printf("Opcion en mantenimiento.\n");
                            break;
                        case 4:
                            printf("Opcion en mantenimiento.\n");
                            break;
                        case 5:
                            printf("volviendo al menu principal...\n");
                            break;
                        }
                        system("pause");
                    }
                }
                while(optionSort != 5);

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


