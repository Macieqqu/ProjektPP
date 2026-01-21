#ifndef UI_H
#define UI_H
#include "common.h"

void showMenu();
void showEditMenu();
void printList(List *list);
void printObject(Przedmiot przedmiot);
char *enumToString(Stabilnosc stabilnosc);
Stabilnosc stringToEnum(char *string);
void clearBuffer();
Przedmiot getItemFromUser();
int getMenuChoice(int max);
void removeNewlineAndClean(char *string);

#endif