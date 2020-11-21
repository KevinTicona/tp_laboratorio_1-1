#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu_main();
void menu_imprimirMascota(LinkedList* duenos,Mascota* currentMascota);
int menu_imprimirMascotas(LinkedList* pLLMascotas,LinkedList* duenos);

void menu_imprimirDueno(Dueno* currentDueno);
int menu_imprimirDuenos(LinkedList* this);
#endif // MENU_H_INCLUDED
