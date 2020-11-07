#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validations.h"
#include "Menu.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int status = -1;
    FILE *pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    ll_clear(pArrayListEmployee);

    status = parser_EmployeeFromText(pFile, pArrayListEmployee);

    fclose(pFile);

    return status;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int status = -1;
    FILE *pFile = fopen(path, "rb");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    ll_clear(pArrayListEmployee);

    status = parser_EmployeeFromBinary(pFile, pArrayListEmployee);

    fclose(pFile);

    return status;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    /*Cuando se añade un empleado, se crea con id 1. En el archivo ya hay 1000 empleados,
    por lo que, si cargamos un empleado antes de cargar la lista de 1000, daría como resultado dos
    empleados con el mismo id. Por eso validamos que primero se carguen los datos.*/
    if(ll_isEmpty(pArrayListEmployee) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar un empleado a la lista.\n");
        return -1;
    }

    Employee* newEmployee = NULL;

    do
    {
        int newId;
        char newIdAsChar[50], nombre[50], sueldo[50], horas[50];

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("\nIngrese horas trabajadas: ");
        fflush(stdin);
        gets(horas);

        printf("\nIngrese sueldo: ");
        fflush(stdin);
        gets(sueldo);

        // Queremos que nuestros IDs sean incrementales, por lo tanto buscaremos el último ID existente
        Node* currentNode = pArrayListEmployee->pFirstNode;

        // Recorremos la Linked List hasta llegar al último Nodo
        while (currentNode->pNextNode != NULL)
        {
            currentNode = currentNode->pNextNode;
        }

        // Al terminar el while, currentNode será el último Nodo en nuestra Linked List
        Employee* lastEmployee = (Employee*)currentNode->pElement;

        // Luego de encontrar el último Employee en la Linked List, utilizamos su Id y le agregamos 1.
        // De esta manera, siempre tendremos IDs unicos.
        newId = lastEmployee->id + 1;
        itoa(newId, newIdAsChar, 10);

        newEmployee = employee_newParametros(newIdAsChar, nombre, horas, sueldo);

        if(newEmployee != NULL)
        {
            ll_add(pArrayListEmployee, newEmployee);
            printf("\nEl empleado ha sido creado. Cantidad total de Empleados: %d\n", ll_len(pArrayListEmployee));
        }
        else
        {
            printf("\nEl empleado no fue creado, intente nuevamente...\n");
        }

    }
    while(newEmployee == NULL);

    return 0;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char employeeIdToModifieAsChar[50];
    char nombre[50];

    int employeeIdToModifie;
    int isValidId;
    int currentNodeIndex;
    int linkedListSize;
    int option;
    int reply;
    int horas;
    int sueldo;
    int rstScanf;

    Employee* currentEmployee;
    Node* currentNode;

    if(ll_isEmpty(pArrayListEmployee) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar un empleado a la lista.\n");
        return -1;
    }
    //Obtenemos el ID, esto repite hasta recibir un ID valido
    do
    {
        printf("\nIngrese el Id del Empleado a modificar: ");
        fflush(stdin);
        gets(employeeIdToModifieAsChar);

        isValidId = validations_isValidNumber(employeeIdToModifieAsChar);

        if (!isValidId)
        {
            printf("\nEl Id ingresado es un numero invalido, intente nuevamente.\n");
        }

    }
    while(!isValidId);
    //Convertimos el ID recibido como string a entero
    employeeIdToModifie = atoi(employeeIdToModifieAsChar);

    // busca y muestra el empleado
    currentNodeIndex = 0;
    linkedListSize = ll_len(pArrayListEmployee);
    currentNode = pArrayListEmployee->pFirstNode;

    // Recorremos la Linked List con un índice (un número)
    while (currentNodeIndex < linkedListSize)
    {
        // Uso requerido de función ll_get según especificaciones dadas
        currentEmployee = (Employee*)ll_get(pArrayListEmployee, currentNodeIndex);

        if (currentEmployee->id == employeeIdToModifie)
        {
            // mostrar datos empleado
            menu_encabezadoEmpleado();
            menu_imprimirEmpleado(currentEmployee);
            // pedir que dato quiere cambiar
            menu_menuModificaciones();
            reply = validations_getOption(&option,"\nOpcion invalida, intente nuevamente\n", 1,4);
            if(!reply)
            {
                switch(option)
                {
                case 1:
                    printf("\nIngrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    employee_setNombre(currentEmployee,nombre);
                    printf("\nNombre modificado con exito!\n");
                    break;
                case 2:
                    printf("\nIngrese cantidad de horas: ");
                    fflush(stdin);
                    rstScanf = scanf("%d",&horas);
                    while(!rstScanf)
                    {
                        printf("\nInvalido. Ingrese cantidad de horas: ");
                        fflush(stdin);
                        rstScanf = scanf("%d",&horas);
                    }
                    employee_setHorasTrabajadas(currentEmployee,horas);
                    printf("\nHoas trabajadas modificadas con exito!\n");
                    break;
                case 3:
                    printf("\nIngrese nuevo sueldo: ");
                    fflush(stdin);
                    rstScanf = scanf("%d",&sueldo);
                    while(!rstScanf)
                    {
                        printf("\nInvalido. Ingrese nuevo sueldo: ");
                        fflush(stdin);
                        rstScanf = scanf("%d",&sueldo);
                    }
                    employee_setSueldo(currentEmployee,sueldo);
                    printf("\nSueldo modificado con exito!\n");
                    break;
                case 4:
                    printf("\nVolviendo atras...\n");
                    break;
                }
            }

            return 0;
        }

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    printf("\nNo se encontro un empleado con ese id\n");

    return -1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("\nNo existen empleados en el sistema. Intente cargar uno para poder eliminar un empleado.\n");
        return -1;
    }

    int isValidId;
    char employeeIdToRemoveAsChar[50];

    do
    {
        printf("\nIngrese el Id del Empleado a remover: ");
        fflush(stdin);
        gets(employeeIdToRemoveAsChar);

        isValidId = validations_isValidNumber(employeeIdToRemoveAsChar);

        if (!isValidId)
        {
            printf("\nEl Id ingresado es un numero invalido, intente nuevamente.\n");
        }

    }
    while(!isValidId);

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pArrayListEmployee);
    int employeeIdToRemove = atoi(employeeIdToRemoveAsChar);

    Employee* currentEmployee;
    Node* currentNode = pArrayListEmployee->pFirstNode;

    // Recorremos la Linked List con un índice (un número)
    // Aunque también podríamos recorrer la lista hasta llegar al final verificando si el pNextNode del Nodo actual no sea NULL
    while (currentNodeIndex < linkedListSize)
    {
        currentEmployee = (Employee*)ll_get(pArrayListEmployee, currentNodeIndex);

        if (currentEmployee->id == employeeIdToRemove)
        {
            ll_remove(pArrayListEmployee, currentNodeIndex);
            printf("\nEl Empleado con Id %d ha sido eliminado del sistema.\n", employeeIdToRemove);
            return 0;
        }

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    printf("\nNo se ha encontrado un Empleado con el Id %d. Por favor vuelva a intentarlo.\n", employeeIdToRemove);

    return -1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("\nNo existen empleados en el sistema. Intente cargar uno para listar los empleados.\n");
        return 0;
    }

    menu_imprimirEmpleados(pArrayListEmployee);

    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("\nNo existen empleados en el sistema. Intente cargar uno para listar los empleados.\n");
        return 0;
    }

    int optionSort = 0;
    int selectSort = 0;

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
                printf("Ordenando por Nombre ...");
                ll_sort(pArrayListEmployee, employee_SortByName, 1);
                printf("\nEmpleados ordenados por nombre exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                printf("Ordenando por Id ...");
                ll_sort(pArrayListEmployee, employee_SortById, 1);
                printf("\nEmpleados ordenados por ID exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                printf("Ordenando por Horas Trabajadas ...");
                ll_sort(pArrayListEmployee, employee_SortByWorkHours, 1);
                printf("\nEmpleados ordenados por horas trabajadas exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                printf("Ordenando por Sueldo ...");
                ll_sort(pArrayListEmployee, employee_SortBySalary, 1);
                printf("\nEmpleados ordenados por sueldo exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 5:
                printf("volviendo al menu principal...\n");
                break;
            }
            system("pause");
        }
    }
    while(optionSort != 5);

    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;

    pFile = fopen(path, "w");

    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pArrayListEmployee);

    Employee* currentEmployee;
    Node* currentNode = pArrayListEmployee->pFirstNode;

    // Escribimos los headers del CSV
    fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

    // Recorremos la Linked List con un índice (un número)
    // Aunque también podríamos recorrer la lista hasta llegar al final verificando si el pNextNode del Nodo actual no sea NULL
    while (currentNodeIndex < linkedListSize)
    {
        currentEmployee = (Employee*)ll_get(pArrayListEmployee, currentNodeIndex);

        fprintf(pFile, "%d,%s,%d,%d\n",
                currentEmployee->id,
                currentEmployee ->nombre,
                currentEmployee->horasTrabajadas,
                currentEmployee->sueldo);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    printf("\nLos cambios han sido guardados correctamente.\n");

    return 0;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile= fopen(path, "wb");

    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pArrayListEmployee);

    Employee* currentEmployee;
    Node* currentNode = pArrayListEmployee->pFirstNode;

    while (currentNodeIndex < linkedListSize)
    {
        currentEmployee = (Employee*)ll_get(pArrayListEmployee, currentNodeIndex);

        fwrite(currentEmployee, sizeof(Employee), 1, pFile);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    return 0;
}

int controller_freeResources(LinkedList* pArrayListEmployee)
{
    Node* currentNode = pArrayListEmployee->pFirstNode;
    Node* temporaryNode;

    while (currentNode != NULL)
    {
        temporaryNode = currentNode;
        currentNode = currentNode->pNextNode;
        free(temporaryNode);
    }

    ll_deleteLinkedList(pArrayListEmployee);

    return 1;
}

