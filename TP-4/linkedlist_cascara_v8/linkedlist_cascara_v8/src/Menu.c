#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Menu.h"

void menu_main()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                             Trabajo Practico nro. 4          \n");
    printf("__________________________________________________________________________________\n");
    printf("                                    MASCOTAS                   \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Cargar los datos de las mascotas desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de las mascotas desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de mascota.\n");
    printf("4. Modificar datos de mascota.\n");
    printf("5. Baja de mascota.\n");
    printf("6. Listar mascotas.\n");
    printf("7. Listar duenos.\n");
    printf("8. Ordenar mascotas.\n");
    printf("9. Filtrar mascotas por tipo.\n");
    printf("10. Clonar mascotas.\n");
    printf("11. Revisar si una mascota o una lista esta contenida en la lista de mascotas.\n");
    printf("12. Generar sublista de mascotas.\n");
    printf("13. Setear una mascota nueva en un indice de la lista de mascotas.\n");
    printf("14. Hacer un push de una mascota nueva en un indice de la lista de mascotas.\n");
    printf("15. Guardar los datos de las mascotas en el archivo data.csv (modo texto).\n");
    printf("16. Guardar los datos de las mascotas en el archivo data.bin (modo binario)..\n");
    printf("17. Salir.\n");
}

void menu_imprimirMascota(LinkedList* duenos,Mascota* currentMascota)
{
    Dueno* auxDueno = duenos_searchByID(duenos,currentMascota->ID_Duenio);

    printf("\n%4d  %15s   %15s            %2s     %4d        %20s\n",
           currentMascota->ID,
           currentMascota->nombre,
           currentMascota->tipo,
           currentMascota->sexo,
           currentMascota->edad,
           auxDueno->nombre);
}

int menu_imprimirMascotas(LinkedList* pLLMascotas,LinkedList* duenos)
{
    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLLMascotas);

    Mascota* currentMascota;
    Node* currentNode = pLLMascotas->pFirstNode;

    // Recorremos la Linked List con un �ndice (un n�mero)
    // Aunque tambi�n podr�amos recorrer la lista hasta llegar al final verificando si el pNextNode del Nodo actual no sea NULL

    printf("_____________________________________________________________________________________________\n");
    printf("                                            MASCOTAS \n");
    printf("_____________________________________________________________________________________________\n");
    printf("  ID           Nombre               Tipo          Sexo     Edad                 Dueno\n");
    printf("_____________________________________________________________________________________________\n");

    while (currentNodeIndex < linkedListSize)
    {
        currentMascota = (Mascota*)ll_get(pLLMascotas, currentNodeIndex);

        menu_imprimirMascota(duenos,currentMascota);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    return 0;
}

void menu_imprimirDueno(Dueno* currentDueno)
{
    printf("\n%4d  %20s           %15s\n",
           currentDueno->ID,
           currentDueno->nombre,
           currentDueno->telefono);
}

int menu_imprimirDuenos(LinkedList* this)
{
    int currentNodeIndex = 0;
    int linkedListSize = ll_len(this);
    Dueno* currentDueno;
    Node* currentNode = this->pFirstNode;

    printf("____________________________________________________\n");
    printf("                    DUENOS \n");
    printf("____________________________________________________\n");
    printf("  ID           Nombre                    Telefono   \n");
    printf("____________________________________________________\n");

    while (currentNodeIndex < linkedListSize)
    {
        currentDueno = (Dueno*)ll_get(this, currentNodeIndex);

        menu_imprimirDueno(currentDueno);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    return 0;
}

void menu_encabezadoMascota()
{
    system("cls");
    printf("_____________________________________________________________________________________________\n");
    printf("                                            MASCOTAS \n");
    printf("_____________________________________________________________________________________________\n");
    printf("  ID           Nombre               Tipo          Sexo     Edad                 Dueno\n");
    printf("_____________________________________________________________________________________________\n");
}

void menu_modificaciones()
{
    printf("\n\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar tipo.\n");
    printf("3. Modificar edad.\n");
    printf("4. Volver atras.\n");
    printf("\n\n");
}

void menu_submenu_order()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                                    MASCOTAS          \n");
    printf("__________________________________________________________________________________\n");
    printf("                            SUBMENU DE ORDENAMIENTOS                    \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Ordenar mascotas por nombre.\n");
    printf("2. Ordenar mascotas por ID.\n");
    printf("3. Ordenar mascotas por tipo.\n");
    printf("4. Volver al menu principal.\n");
}

void menu_submenu_filter()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                                    MASCOTAS          \n");
    printf("__________________________________________________________________________________\n");
    printf("                            FILTRAR MASCOTAS POR TIPO                    \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Filtrar perros.\n");
    printf("2. Filtrar gatos.\n");
    printf("3. Filtrar reptiles.\n");
    printf("4. Filtrar roedores.\n");
    printf("5. Volver al menu principal.\n");
}

void menu_submenu_contains()
{
    system("cls");
    printf("__________________________________________________________________________________\n");
    printf("                                    MASCOTAS          \n");
    printf("__________________________________________________________________________________\n");
    printf("1. Revisar si la lista de mascotas esta contenida en la lista de mascotas principal.\n");
    printf("2. Revisar si la lista de duenos esta contenida en la lista de mascotas.\n");
    printf("3. Volver al menu principal.\n");
}
