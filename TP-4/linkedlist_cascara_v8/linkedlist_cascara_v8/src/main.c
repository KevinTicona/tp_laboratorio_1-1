/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Duenos.h"
#include "../inc/Mascotas.h"
#include "../inc/Validations.h"
#include "../inc/Menu.h"
#define PATH_MASCOTAS_TXT "animales.csv"
#define PATH_DUENOS_TXT "duenios.csv"
#define PATH_MASCOTAS_BIN "animales.bin"
#define PATH_DUENOS_BIN "duenios.bin"

int main(void)
{
    //validations_testLL(20); //Esto corre todos los test del LinkedList

    int option;
    int selection;

    LinkedList* petList = ll_newLinkedList();
    LinkedList* ownersList = ll_newLinkedList();

    do
    {
        menu_main();
        selection = validations_getOption(
                        &option,
                        "\nOpcion invalida, vuelva a intentar.\n",
                        1,
                        11
                    );
        if(!selection)
        {
            switch(option)
            {
            case 1:
                if(!controller_loadMascotasFromText(PATH_MASCOTAS_TXT,petList) && !controller_loadDuenosFromText(PATH_DUENOS_TXT,ownersList))
                {
                    printf("\nSe han cargado %d mascotas desde el archivo %s\n", ll_len(petList), PATH_MASCOTAS_TXT);
                    printf("\nSe han cargado %d Duenios desde el archivo %s\n", ll_len(ownersList), PATH_DUENOS_TXT);
                }
                break;
            case 2:
                if(!controller_loadMascotasFromBinary(PATH_MASCOTAS_BIN,petList) && !controller_loadDuenosFromBinary(PATH_DUENOS_BIN,ownersList))
                {
                    printf("\nSe han cargado %d mascotas desde el archivo %s\n", ll_len(petList), PATH_MASCOTAS_BIN);
                    printf("\nSe han cargado %d Duenios desde el archivo %s\n", ll_len(ownersList), PATH_DUENOS_BIN);
                }
                break;
            case 3:
                if(!controller_addMascota(petList, ownersList))
                {
                    printf("\nMascota agregada con exito, total de mascotas: %d\n", ll_len(petList));
                }
                else
                {
                    printf("\nOcurrio un problema al intentar agregar la mascota, vuelva a intentarlo mas tarde.\n");
                }
                break;
            case 4:
                if(!controller_editMascota(petList,ownersList))
                {
                    printf("\nMascota modificada con exito.\n");
                }
                else
                {
                    printf("\nOcurrio un problema al intentar modificar la mascota, vuelva a intentarlo mas tarde.\n");
                }
                break;
            case 5:
                if(!controller_removeMascota(petList,ownersList))
                {
                    printf("\nMascota eliminada con exito.\n");
                }
                else
                {
                    printf("\nOcurrio un problema al intentar eliminar la mascota, vuelva a intentarlo mas tarde.\n");
                }
                break;
            case 6:
                controller_ListMascotas(petList,ownersList);
                break;
            case 7:
                controller_ListDuenos(ownersList);
                break;
            case 8:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 9:
                if(!controller_saveMascotasAsText(PATH_MASCOTAS_TXT,petList) && !controller_saveDuenosAsText(PATH_DUENOS_TXT,ownersList))
                {
                    printf("\nSe han guardado %d mascotas en el archivo %s.\n", petList->size, PATH_MASCOTAS_TXT);
                    printf("\nSe han guardado %d duenos en el archivo %s.\n", ownersList->size, PATH_DUENOS_TXT);
                }
                break;
            case 10:
                if(!controller_saveMascotasAsBinary(PATH_MASCOTAS_BIN,petList) && !controller_saveDuenosAsBinary(PATH_DUENOS_BIN,ownersList))
                {
                    printf("\nSe han guardado %d mascotas en el archivo %s.\n", petList->size, PATH_MASCOTAS_BIN);
                    printf("\nSe han guardado %d duenos en el archivo %s.\n", ownersList->size, PATH_DUENOS_BIN);
                }
                break;
            case 11:
                //controller_freeResources(petList);
                //controller_freeResources(ownersList);
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(option!=11);

    return 0;
}

































