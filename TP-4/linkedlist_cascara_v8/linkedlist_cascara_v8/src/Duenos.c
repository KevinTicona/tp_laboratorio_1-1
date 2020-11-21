#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Duenos.h"
#include "../inc/Validations.h"

Dueno* dueno_new()
{
    Dueno* newDueno = (Dueno*) malloc(sizeof(Dueno));

    if(newDueno != NULL)
    {
        newDueno->ID = 0;
        strcpy(newDueno->nombre,"");
        strcpy(newDueno->telefono,"");
    }
    return newDueno;
}

Dueno* dueno_newParams(char* id, char* nombre, char* telefono)
{
    int validIdResult = validations_isValidNumber(id);
    int validId;

    if(!validIdResult)
    {
        printf("\nEl Id del Duenio es invalido. Valor recibido: %s\n", id);
        return NULL;
    }

    validId = atoi(id);

    Dueno* newDueno = dueno_new();

    if(newDueno != NULL)
    {
        if(!(!duenos_setId(newDueno,validId) &&
                !duenos_setNombre(newDueno,nombre) &&
                !duenos_setTelefono(newDueno,telefono)
            ))
        {
            printf("\nOcurrio un problema al inicializar las propiedades del nuevo Duenio. El mismo no sera creado.\n");
            newDueno = NULL;
            free(newDueno);
        }
    }
    return newDueno;
}

void duenos_deleteOne(Dueno* this)
{
    free(this);
}

int duenos_setId(Dueno* this,int id)
{
    int error = -1;

    if(this != NULL && id > 0)
    {
        this->ID = id;
        error = 0;
    }

    return error;
}

int duenos_getId(Dueno* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->ID;
        error = 0;
    }
    return error;
}

int duenos_setNombre(Dueno* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL && validations_isValidName(nombre))
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }

    return error;
}

int duenos_getNombre(Dueno* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 0;
    }
    return error;
}

int duenos_setTelefono(Dueno* this, char* telefono)
{
    int error = -1;
    int len = strlen(telefono);

    if(this != NULL && telefono != NULL && len > 0 && len < 33)
    {
        strcpy(this->telefono,telefono);
        error = 0;
    }

    return error;
}

int duenos_getTelefono(Dueno* this, char* telefono)
{
    int error = -1;

    if(this != NULL && telefono != NULL)
    {
        strcpy(telefono, this->telefono);
        error = 0;
    }
    return error;
}

Dueno* duenos_searchByID(LinkedList* this,int id)
{
    Dueno* dueno;
    int len = ll_len(this);
    int index = 0;
    Node* currentNode = this->pFirstNode;

    if(this != NULL)
    {
        while (index < len)
        {
            dueno = (Dueno*)ll_get(this,index);

            if(dueno->ID == id)
            {
                break;
            }

            currentNode = currentNode->pNextNode;
            index++;
        }
    }
    return dueno;
}
