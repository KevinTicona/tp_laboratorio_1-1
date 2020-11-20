#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Parser.h"
#include "../inc/LinkedList.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"

int parser_MascotaFromText(FILE* pFile, LinkedList* pLinkedListMascotas)
{
    int amountOfDataRead;
    char id[50], nombre[50], tipo[50], sexo[50], edad[50], ID_duenio[50];

    if (pFile == NULL || pLinkedListMascotas == NULL)
    {
        return -1;
    }

    // Forzamos lectura de la primer linea del archivo ya que esta contiene los encabezados
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,sexo,edad,ID_duenio);

    do
    {
        amountOfDataRead = fscanf(
                                  pFile,
                                  "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                  id,
                                  nombre,
                                  tipo,
                                  sexo,
                                  edad,
                                  ID_duenio
                              );

        if (amountOfDataRead == 6)
        {
            Mascota* newMascota = mascota_newParams(id,nombre,tipo,sexo,edad,ID_duenio);

            if (newMascota != NULL)
            {
                ll_add(pLinkedListMascotas, newMascota);
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

int parser_duenoFromText(FILE* pFile, LinkedList* pLinkedListDuenos)
{
    int amountOfDataRead;
    char id[50], nombre[50], telefono[50];

    if (pFile == NULL || pLinkedListDuenos == NULL)
    {
        return -1;
    }

    fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,telefono);

    do
    {
        amountOfDataRead = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,telefono);

        if (amountOfDataRead == 3)
        {
            Dueno* newDueno = dueno_newParams(id,nombre,telefono);

            if (newDueno != NULL)
            {
                ll_add(pLinkedListDuenos, newDueno);
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
