#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validations.h"
#include "Menu.h"

void employee_buscarId(LinkedList* listaEmpleados, int id);

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
                break;
            case 2:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 3:
            {
                controller_addEmployee(listaEmpleados);
                break;
            }
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            {
                // TODO: meter toda la logica de aca abajo en la funcion controller_sortEmployee

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
            }
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                printf("\nOpcion en mantenimiento.\n");
                break;
            case 10:
                controller_freeResources(listaEmpleados);
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(option != 10);

    return 0;
}

//revisar -> No compila \240 no autocompleta pElement->id
/*
void employee_buscarId(LinkedList* listaEmpleados, int id)
{
    Node* current = listaEmpleados->pFirstNode;
    // recorrer hasta encontrar el ultimo nodo
     while (current->pNextNode != NULL)
    {
         if (current->pElement->id == id)
        {
            // actualizar current->pElement
            printf("\nHola\n");
            break;
        }
                current = current->pNextNode;
           
    }
}
*/
