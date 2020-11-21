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
    printf("7. Ordenar mascotas.\n");
    printf("8. Guardar los datos de las mascotas en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de las mascotas en el archivo data.bin (modo binario)..\n");
    printf("10. Salir.\n");
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

    // Recorremos la Linked List con un índice (un número)
    // Aunque también podríamos recorrer la lista hasta llegar al final verificando si el pNextNode del Nodo actual no sea NULL

    system("cls");
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

