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
                if(controller_loadFromText(PATH_MASCOTAS_TXT,PATH_DUENOS_TXT,petList,ownersList) == 0)
                {
                    printf("\nSe han cargado %d mascotas desde el archivo %s\n", ll_len(petList), PATH_MASCOTAS_TXT);
                    printf("\nSe han cargado %d Duenios desde el archivo %s\n", ll_len(ownersList), PATH_DUENOS_TXT);
                }
                break;
            case 2:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 3:
                controller_addMascota(petList, ownersList);
                //printf("\nOpcion en mantenimiento...\n");
                break;
            case 4:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 5:
                printf("\nOpcion en mantenimiento...\n");
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
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 10:
                printf("\nOpcion en mantenimiento...\n");
                break;
            case 11:
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }
    }
    while(option!=11);

    return 0;
}

































