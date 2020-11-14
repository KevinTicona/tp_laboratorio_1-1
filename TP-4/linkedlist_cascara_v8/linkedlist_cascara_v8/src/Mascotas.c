#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Validations.h"

int mascotas_setId(Mascota* this,int id)
{
    int error = -1;

    if(this != NULL && id > 0)
    {
        this->ID = id;
        error = 0;
    }

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

    return error;
}

int mascotas_setSexo(Mascota* this,char sexo)
{
    int error = -1;

    if(validations_isValidSex(sexo))
    {
        this->sexo = sexo;
        error = 0;
    }

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

    return error;
}
