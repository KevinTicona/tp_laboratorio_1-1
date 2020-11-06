#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validations.h"
#include "Menu.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;

    pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }

    parser_EmployeeFromText(pFile, pArrayListEmployee);

    printf("\nSe han cargado %d empleados desde el archivo %s\n", pArrayListEmployee->size, path);

    fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    /*Cuando se añade un empleado, se crea con id 1. En el archivo ya hay 1000 empleados,
    por lo que, si cargamos empleado antes de cargar la lista, daría como resultado dos
    empleados con el mismo id. Por eso validamos que primero se carguen los datos.*/
    if(ll_isEmpty(pArrayListEmployee) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar un empleado a la lista.\n");
        return 1;
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

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    /*Cuando se añade un empleado, se crea con id 1. En el archivo ya hay 1000 empleados,
    por lo que, si cargamos empleado antes de cargar la lista, daría como resultado dos
    empleados con el mismo id. Por eso validamos que primero se carguen los datos.*/
    if(ll_isEmpty(pArrayListEmployee) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar un empleado a la lista.\n");
        return 1;
    }

    // imprimir la lista de empleados
    // pedir el id a modificar
    // mostrar empleado
    // convertir el id a int
    // recorrer la linked list con un while (por ejemplo usando un indice, ver ejemplo de listar empleados)
    // al encontrar un Employee con el mismo id, pedir datos a cambiar (definir cómo quiero hacer esto)
    // luego de pedir los datos a cambiar, puedo llamar a los setters del Employee pasandole los datos obtenidos
    // recordar que no deberiamos poder modificar el ID
    // al terminar de actualizar, hacer un return para salir del bucle y de la funcion, ya que no hay que hacer mas nada.
    // si el while terminó y no se ejecutó un return, significa que no se encontró un Employee con el Id ingresado, mostrar un mensaje de error y fin de la funcion
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    if (ll_isEmpty(pArrayListEmployee) == 1)
    {
        printf("\nNo existen empleados en el sistema. Intente cargar uno para poder eliminar un empleado.\n");
        return 0;
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
        // Uso requerido de función ll_get según especificaciones dadas
        currentEmployee = (Employee*)ll_get(pArrayListEmployee, currentNodeIndex);

        if (currentEmployee->id == employeeIdToRemove)
        {
            ll_remove(pArrayListEmployee, currentNodeIndex);
            printf("\nEl Empleado con Id %d ha sido eliminado del sistema.\n", employeeIdToRemove);
            return 1;
        }

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    printf("\nNo se ha encontrado un Empleado con el Id %d. Por favor vuelva a intentarlo.\n", employeeIdToRemove);

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
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
                ll_sort(pArrayListEmployee,employee_SortByName,1);
                printf("\nEmpleados ordenados por nombre exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_SortById,1);
                printf("\nEmpleados ordenados por ID exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                ll_sort(pArrayListEmployee,employee_SortByWorkHours,0);
                printf("\nEmpleados ordenados por horas trabajadas exitosamente.\n");
                system("pause");
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                ll_sort(pArrayListEmployee,employee_SortBySalary,1);
                printf("\nEmpleados ordenados por salario exitosamente.\n");
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;

    pFile = fopen(path, "w");

    if (pFile == NULL)
    {
        printf("\nEl archivo no existe\n");
        exit(EXIT_FAILURE);
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
        // Uso requerido de función ll_get según especificaciones dadas
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

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Libera los espacios de memoria ocupados y borra un LinkedList
 *
 * \param LinkedList* pArrayListEmployee
 * \return 1
 *
 */
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

