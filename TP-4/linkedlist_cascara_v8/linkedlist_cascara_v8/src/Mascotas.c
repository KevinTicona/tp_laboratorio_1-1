#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Validations.h"

Mascota* mascota_new()
{
    Mascota* nueva = (Mascota*) malloc(sizeof(Mascota));

    if(nueva != NULL)
    {
        nueva->ID = 0;
        nueva->edad = 0;
        nueva->ID_Duenio = 0;
        strcpy(nueva->sexo, "");
        strcpy(nueva->nombre, "");
        strcpy(nueva->tipo, "");
    }

    return nueva;
}

Mascota* mascota_newParams(
    char* id,
    char* nombre,
    char* tipo,
    char* sexo,
    char* edad,
    char* ID_duenio
)
{
    int validIdResult = validations_isValidNumber(id);
    int validEdadResult = validations_isValidNumber(edad);
    int validIdResultDueno = validations_isValidNumber(ID_duenio);
    int validId;
    int validEdad;
    int validIdDueno;

    if(!validIdResult || !validEdadResult || !validIdResultDueno)
    {
        if(!validIdResult)
        {
            printf("\nEl Id de la nueva Mascota es invalido. Valor recibido: %s\n", id);
        }
        else if(!validEdadResult)
        {
            printf("\nLa edad de la nueva Mascota es invalida. Valor recibido: %s\n", edad);
        }
        else if(!validIdResultDueno)
        {
            printf("\nEl Id del duenio de la nueva Mascota es invalido. Valor recibido: %s\n", ID_duenio);
        }

        return NULL;
    }

    validId = atoi(id);
    validEdad = atoi(edad);
    validIdDueno = atoi(ID_duenio);

    Mascota* newMascota = mascota_new();

    if(newMascota != NULL)
    {
        if(!(!mascotas_setId(newMascota,validId) &&
                !mascotas_setNombre(newMascota,nombre) &&
                !mascotas_setTipo(newMascota,tipo) &&
                !mascotas_setSexo(newMascota,sexo) &&
                !mascotas_setEdad(newMascota,validEdad) &&
                !mascotas_setIdDuenio(newMascota,validIdDueno)
            ))
        {
            printf("\nOcurrio un problema al inicializar las propiedades de la nueva Mascota. La mismo no sera creada.\n");
            newMascota = NULL;
            free(newMascota);
        }

    }
    return newMascota;
}

void mascotas_deleteOne(Mascota* this)
{
    free(this);
}

int mascotas_setId(Mascota* this,int id)
{
    int error = -1;

    if(this != NULL && id > 0)
    {
        this->ID = id;
        error = 0;
    }
    printf("\nSetID value: %d -> error; %d\n", id, error);
    return error;
}

int mascotas_setNombre(Mascota* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL && validations_isValidName(nombre))
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }
    printf("\nSetNombre value: %s -> error; %d\n", nombre, error);
    return error;
}

int mascotas_setTipo(Mascota* this,char* tipo)
{
    int error = -1;

    if(this != NULL && tipo != NULL && validations_isValidType(tipo))
    {
        strcpy(this->tipo, tipo);
        error = 0;
    }
    printf("\nSetTipo value: %s -> error; %d\n", tipo, error);
    return error;
}

int mascotas_setSexo(Mascota* this,char* sexo)
{
    int error = -1;

    if(validations_isValidSex(sexo))
    {
        strcpy(this->sexo, sexo);
        error = 0;
    }

    printf("\nSetSexo value: %s -> error; %d\n", sexo, error);
    return error;
}

int mascotas_setIdDuenio(Mascota* this,int ID_Duenio)
{
    int error = -1;

    if(this != NULL && ID_Duenio > 0 && ID_Duenio <= 95)
    {
        this->ID_Duenio = ID_Duenio;
        error = 0;
    }
        printf("\nSetDuenio value: %d -> error; %d\n", ID_Duenio, error);
    return error;
}

int mascotas_setEdad(Mascota* this,int edad)
{
    int error = -1;

    if(this != NULL && validations_isValidEdad(edad))
    {
        this->edad = edad;
        error = 0;
    }
    printf("\nSetEdad value: %d -> error; %d\n", edad, error);
    return error;
}
