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
    return error;
}

int mascotas_getId(Mascota* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->ID;
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

int mascotas_getNombre(Mascota* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
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

int mascotas_getTipo(Mascota* this,char* tipo)
{
    int error = -1;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        error = 0;
    }
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

    return error;
}

int mascotas_getSexo(Mascota* this,char* sexo)
{
    int error = -1;

    if(this != NULL && sexo != NULL)
    {
        strcpy(sexo, this->sexo);
        error = 0;
    }
    return error;
}

int mascotas_setIdDuenio(Mascota* this,int ID_Duenio)
{
    int error = -1;
    char IDToChar[50];
    itoa(ID_Duenio,IDToChar,10);

    if(this != NULL && validations_isValid_IDDueno(IDToChar))
    {
        this->ID_Duenio = ID_Duenio;
        error = 0;
    }
    return error;
}

int mascotas_getIdDuenio(Mascota* this,int* ID_Duenio)
{
    int error = -1;

    if(this != NULL && ID_Duenio != NULL)
    {
        *ID_Duenio = this->ID_Duenio;
        error = 0;
    }
    return error;
}

int mascotas_setEdad(Mascota* this,int edad)
{
    int error = -1;
    char edadToChar[50];
    itoa(edad,edadToChar,10);

    if(this != NULL && validations_isValidEdad(edadToChar))
    {
        this->edad = edad;
        error = 0;
    }
    return error;
}

int mascotas_getEdad(Mascota* this,int* edad)
{
    int error = -1;

    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        error = 0;
    }
    return error;
}

void mascotas_enterName(char* nombreValidado)
{
    char nombre[100];
    int nombreValido;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(nombre);
    nombreValido = validations_isValidName(nombre);
    while(nombreValido != 1)
    {
        printf("\nDato invalido. Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        nombreValido = validations_isValidName(nombre);
    }
    strcpy(nombreValidado,nombre);
}

void mascotas_enterType(char* tipoValidado)
{
    char tipo[100];
    int tipoValido;

    printf("\nIngrese tipo: ");
    fflush(stdin);
    gets(tipo);
    tipoValido = validations_isValidType(tipo);
    while(tipoValido != 1)
    {
        printf("\nDato invalido. Ingrese tipo: ");
        fflush(stdin);
        gets(tipo);
        tipoValido = validations_isValidType(tipo);
    }
    strcpy(tipoValidado,tipo);
}

void mascotas_enterSex(char* sexoValidado)
{
    char sexo[100];
    int sexoValido;

    printf("\nIngrese sexo: ");
    fflush(stdin);
    gets(sexo);
    sexoValido = validations_isValidSex(sexo);
    while(sexoValido != 1)
    {
        printf("\nDato invalido. Ingrese sexo: ");
        fflush(stdin);
        gets(sexo);
        sexoValido = validations_isValidSex(sexo);
    }
    strcpy(sexoValidado,sexo);
}

void mascotas_enterAge(char* edadValidada)
{
    char edad[50];
    int edadValida;

    printf("\nIngrese edad: ");
    fflush(stdin);
    gets(edad);
    edadValida = validations_isValidEdad(edad);
    while(edadValida != 1)
    {
        printf("\nDato invalido. Ingrese edad: ");
        fflush(stdin);
        gets(edad);
        edadValida = validations_isValidEdad(edad);
    }
    strcpy(edadValidada,edad);
}

void mascotas_enterIdDueno(char* idDuenoValidado, LinkedList* pLLduenos)
{
    char idDueno[50];
    int idDuenoValido;

    system("cls");
    menu_imprimirDuenos(pLLduenos);

    printf("\n\nIngrese ID Dueno: ");
    fflush(stdin);
    gets(idDueno);
    idDuenoValido = validations_isValid_IDDueno(idDueno);
    while(idDuenoValido != 1)
    {
        printf("\nDato invalido. Ingrese ID Dueno: ");
        fflush(stdin);
        gets(idDueno);
        idDuenoValido = validations_isValid_IDDueno(idDueno);
    }
    strcpy(idDuenoValidado,idDueno);
}
