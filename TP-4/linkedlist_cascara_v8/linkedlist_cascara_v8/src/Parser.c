#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Parser.h"
#include "../inc/LinkedList.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"

/*
int parser_MascotaFromText(FILE* pFile, LinkedList* pLinkedListMascotas)
{
    int amountOfDataRead;
    char id[50], nombre[50], tipo[50], sexo, edad[50], ID_duenio[50];

    if (pFile == NULL || pLinkedListMascotas == NULL)
    {
        return -1;
    }

    // Forzamos lectura de la primer linea del archivo ya que esta contiene los encabezados
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,sexo,edad,ID_duenio);

    do
    {
        cantidadDatosLeidos = fscanf(
                                  pFile,
                                  "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                  id,
                                  nombre,
                                  tipo,
                                  sexo,
                                  edad,
                                  ID_duenio
                              );

        if (cantidadDatosLeidos == 6)
        {
            Employee* newEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            if (newEmployee != NULL)
            {
                ll_add(pArrayListEmployee, newEmployee);
            }
        }
        else
        {
            printf("\nHubo un problema al leer los datos de una linea del archivo. La misma sera ignorada\n");
        }

    }
    while (!feof(pFile));

    return 0;
}
*/
/*
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return -1;
    }

    Employee* empleadoTemporal;

    while (!feof(pFile))
    {
        empleadoTemporal = (Employee*)malloc(sizeof(Employee));

        if (fread(empleadoTemporal, sizeof(Employee), 1, pFile) == 1)
        {
            ll_add(pArrayListEmployee, empleadoTemporal);
        }
    }

    return 0;
}
*/
