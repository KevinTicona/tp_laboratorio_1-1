#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validations.h"
#include "Menu.h"

#define PATH_TXT "data.csv"
#define PATH_BIN "data.bin"

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
                if (controller_loadFromText(PATH_TXT, listaEmpleados) == 0)
                {
                    printf("\nSe han cargado %d empleados desde el archivo %s\n", listaEmpleados->size, PATH_TXT);
                }
                else
                {
                    printf("\nHa ocurrido un problema al cargar empleados desde el archivo %s. Compruebe la ruta y el formato del archivo.\n", PATH_TXT);
                }
                break;
            case 2:
                if (controller_loadFromBinary(PATH_BIN, listaEmpleados) == 0)
                {
                    printf("\nSe han cargado %d empleados desde el archivo %s\n", listaEmpleados->size, PATH_BIN);
                }
                else
                {
                    printf("\nHa ocurrido un problema al cargar empleados desde el archivo %s. Compruebe la ruta y el formato del archivo.\n", PATH_BIN);
                }
                break;
            case 3:
                if (controller_addEmployee(listaEmpleados) != 0)
                {
                    printf("\nHa ocurrido un problema al intentar crear un empleado.\n");
                }
                break;
            case 4:
                if (controller_editEmployee(listaEmpleados) != 0)
                {
                    printf("\nHa ocurrido un problema al intentar modificar un empleado.\n");
                }
                break;
            case 5:
                if (controller_removeEmployee(listaEmpleados) != 0)
                {
                    printf("\nHa ocurrido un problema al intentar eliminar un empleado.\n");
                }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if (controller_saveAsText(PATH_TXT, listaEmpleados) == 0)
                {
                    printf("\nSe han guardado %d empleados en el archivo %s.\n", listaEmpleados->size, PATH_TXT);
                }
                else
                {
                    printf("\nHa ocurrido un problema al guardar empleados en el archivo %s. Compruebe la ruta del archivo.\n", PATH_TXT);
                }
                break;
            case 9:
                if (controller_saveAsBinary(PATH_BIN, listaEmpleados) == 0)
                {
                    printf("\nSe han guardado %d empleados en el archivo %s.\n", listaEmpleados->size, PATH_BIN);
                }
                else
                {
                    printf("\nHa ocurrido un problema al guardar empleados en el archivo %s. Compruebe la ruta del archivo.\n", PATH_BIN);
                }
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
