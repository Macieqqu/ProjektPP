#include "file_util.h"

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "ui.h"

void saveFile(char *fileName, List *list) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Nie udalo sie zapisac listy do pliku");
        return;
    }

    Node *curr = list->head;
    while (curr != NULL) {
        fprintf(file, "%ld;%s;%s;%i;%s;%s\n",
                curr->value.id,
                curr->value.nazwa,
                curr->value.swiat,
                curr->value.poziomChaosu,
                enumToString(curr->value.stabilnosc),
                curr->value.opis);
        curr = curr->next;
    }
    fclose(file);
}

void loadFile(char *fileName, List *list) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Nie udalo sie odtworzyc listy z pliku");
        return;
    }
    Przedmiot p;
    char stabilnosc[20];
    long maxId = 0;

    while (fscanf(file, " %ld;%[^;];%[^;];%i;%[^;];%[^\n]", &p.id, p.nazwa, p.swiat, &p.poziomChaosu, stabilnosc, p.opis) == 6) {
        p.stabilnosc = stringToEnum(stabilnosc);

        Node *n = calloc(1, sizeof(Node));

        if (n == NULL) {
            fclose(file);
            return;
        }

        n->value = p;
        n->next = NULL;
        n->prev = list->tail;

        if (list->head == NULL) list->head = n;
        else list->tail->next = n;
        list->tail = n;

        if (p.id > maxId) maxId = p.id;
    }
    list->nextId = maxId + 1;
    fclose(file);
}