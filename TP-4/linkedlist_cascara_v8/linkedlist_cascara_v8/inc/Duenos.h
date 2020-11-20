#ifndef DUENOS_H_INCLUDED
#define DUENOS_H_INCLUDED

typedef struct
{
    int ID;
    char nombre[100];
    char telefono[35];
}Dueno;

Dueno* dueno_new();
Dueno* dueno_newParams(char* id, char* nombre, char* telefono);
void duenos_deleteOne(Dueno* this);
int duenos_setId(Dueno* this,int id);
int duenos_getId(Dueno* this,int* id);
int duenos_setNombre(Dueno* this,char* nombre);
int duenos_getNombre(Dueno* this,char* nombre);
int duenos_setTelefono(Dueno* this, char* telefono);
int duenos_getTelefono(Dueno* this, char* telefono);

#endif // DUENOS_H_INCLUDED
