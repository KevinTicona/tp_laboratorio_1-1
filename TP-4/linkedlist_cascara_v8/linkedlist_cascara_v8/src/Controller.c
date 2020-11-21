#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Controller.h"
#include "../inc/LinkedList.h"
#include "../inc/Parser.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Menu.h"

int controller_loadFromText(char* path1, char* path2, LinkedList* pLListMascotas, LinkedList* pLListDuenos)
{
    int statusDuenos;
    int statusMascotas;

    FILE *pFile1 = fopen(path1, "r");

    if (pFile1 == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path1);
        return -1;
    }

    ll_clear(pLListMascotas);

    statusMascotas = parser_MascotaFromText(pFile1,pLListMascotas);

    fclose(pFile1);

    //Segundo archivo
    FILE *pFile2 = fopen(path2,"r");

    if (pFile2 == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path2);
        return -1;
    }

    ll_clear(pLListDuenos);
    statusDuenos  = parser_duenoFromText(pFile2,pLListDuenos);

    fclose(pFile2);

    if(statusMascotas == -1 || statusDuenos == -1)
    {
        return -1;
    }

    return 0;
}

int controller_addMascota(LinkedList* pLLMascotas, LinkedList* pLLDuenos)
{
    if(ll_isEmpty(pLLMascotas) != 0)
    {
        printf("\nSe deben cargar los datos antes de agregar una mascota a la lista.\n");
        return -1;
    }

    Mascota* newMascota = NULL;
    int id;
    char idAsChar[50], nombre[100], tipo[50], sexo[50], edad[50], idDueno[50];

    // Ingresar y validar datos
    mascotas_enterName(nombre);
    mascotas_enterType(tipo);
    mascotas_enterSex(sexo);
    mascotas_enterAge(edad);
    mascotas_enterIdDueno(idDueno,pLLDuenos);
    // Id autoincremental
    Node* currentNode = pLLMascotas->pFirstNode;

    while (currentNode->pNextNode != NULL)
    {
        currentNode = currentNode->pNextNode;
    }

    // Al terminar el while, currentNode será el último Nodo en nuestra Linked List
    Mascota* ultimaMascota = (Mascota*)currentNode->pElement;
    // Luego de encontrar la ultima mascota en la Linked List, utilizamos su Id y le agregamos 1.
    id = ultimaMascota->ID + 1;
    itoa(id, idAsChar, 10);

    newMascota = mascota_newParams(idAsChar,nombre,tipo,sexo,edad,idDueno);

    if(newMascota != NULL)
    {
        ll_add(pLLMascotas,newMascota);
        printf("\nMascota agregada con exito. Cantidad total %d\n",ll_len(pLLMascotas));
    } else
    {
        printf("\nLo sentimos, error al crear mascota\n");
    }

    return 0;
}

int controller_ListMascotas(LinkedList* pLLMascotas, LinkedList* duenos)
{
    if (ll_isEmpty(pLLMascotas) == 1)
    {
        printf("\nNo existen mascotas en el sistema. Intente cargarlas desde el menu para poder visualizarlas.\n");
        return 0;
    }

    menu_imprimirMascotas(pLLMascotas,duenos);

    return 1;
}

int controller_ListDuenos(LinkedList* pLLDuenos)
{
    if (ll_isEmpty(pLLDuenos) == 1)
    {
        printf("\nNo existen Duenos en el sistema. Intente cargarlos desde el menu para poder visualizarlos.\n");
        return 0;
    }

    menu_imprimirDuenos(pLLDuenos);

    return 1;
}

int controller_freeResources(LinkedList* this)
{
    Node* currentNode = this->pFirstNode;
    Node* temporaryNode;

    while (currentNode != NULL)
    {
        temporaryNode = currentNode;
        currentNode = currentNode->pNextNode;
        free(temporaryNode);
    }

    ll_deleteLinkedList(this);

    return 1;
}

