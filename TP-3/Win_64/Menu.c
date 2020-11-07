#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"

void menu_main()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                             Trabajo Practico nro. 3          \n");
    printf("__________________________________________________________________________________\n");
    printf("                                       ABM                    \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)..\n");
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
    printf("4. Ordenar empleados por sueldo.\n");
    printf("5. Volver al menu principal.\n");
}

void menu_imprimirEmpleado(Employee* currentEmployee)
{
    printf("\n%4d  %20s                    %4d            %4d\n",
           currentEmployee->id,
           currentEmployee->nombre,
           currentEmployee->horasTrabajadas,
           currentEmployee->sueldo);
}

int menu_imprimirEmpleados(LinkedList* pArrayListEmployee)
{
    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pArrayListEmployee);

    Employee* currentEmployee;
    Node* currentNode = pArrayListEmployee->pFirstNode;

    // Recorremos la Linked List con un índice (un número)
    // Aunque también podríamos recorrer la lista hasta llegar al final verificando si el pNextNode del Nodo actual no sea NULL

    system("cls");
    printf("______________________________________________________________________\n");
    printf("                          NOMINA DE EMPLEADOS \n");
    printf("______________________________________________________________________\n");
    printf("  ID                Nombre               Horas Trabajadas    Salario \n");
    printf("______________________________________________________________________\n");

    while (currentNodeIndex < linkedListSize)
    {
        // Uso requerido de función ll_get según especificaciones dadas
        currentEmployee = (Employee*)ll_get(pArrayListEmployee, currentNodeIndex);

        menu_imprimirEmpleado(currentEmployee);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    return 0;
}

void menu_menuModificaciones()
{
    printf("\n\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar horas trabajadas\n");
    printf("3. Modificar sueldo\n");
    printf("4. Volver atras\n");
}

void menu_encabezadoEmpleado()
{
    system("cls");
    printf("______________________________________________________________________\n");
    printf("  ID                Nombre               Horas Trabajadas    Salario \n");
    printf("______________________________________________________________________\n");
}
