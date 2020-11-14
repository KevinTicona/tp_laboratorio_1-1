#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int ID;
    char nombre[100];
    char tipo[50];
    char sexo;
    int edad;
    int ID_Duenio;
}Mascota;

#endif // MASCOTAS_H_INCLUDED
