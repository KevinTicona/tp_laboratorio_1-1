#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int numberOfReadValues;
    char id[50], nombre[50], horasTrabajadas[50], sueldo[50];

    // skip first line from CSV file with headers TODO: hay una mejor forma?
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    do
    {
        numberOfReadValues = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        if (numberOfReadValues == 4)
        {
            Employee* newEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            if (newEmployee != NULL)
            {
                ll_add(pArrayListEmployee, newEmployee);
            }
        }

    }
    while (!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
