#ifndef LIST_H
#define LIST_H
#include "common.h"

// edycja listy
void listAdd(List *list, Przedmiot item);
void listRemove(List *list, long id);
void listRemoveBelowChaos(List *list, int chaos);
void modifyItem(Node *target);

// wyszukiwanie
void searchByName(List *list, char *name);
void searchByChaos(List *list, int chaos);

//sortowanie
void sortAlphabetically(List *list);
void sortByChaos(List *list);

void freeList(List *list);

#endif
