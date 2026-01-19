#ifndef LIST_H
#define LIST_H
#include "common.h"

// edycja listy
void listAdd(List *list, Przedmiot item); //TODO: tylko unikalna nazwa
void listRemove(List *list, char *name); //TODO: uniemozliwić usuwanie przedmiotów "niestabilnych"
void listRemoveBelowChaos(List *list, int chaos);
void modifyItem(Node *target); //TODO: wyświetla sie menu edytowania obiektu

// wyszukiwanie //TODO: tylko wyswietlanie
void searchByName(List *list, char *name);
void searchByChaos(List *list, int chaos);

//sortowanie //TODO: tylko wyswietlanie
void sortAlphabetically(List *list);
void sortByChaos(List *list);

void freeList(List *list);

#endif
