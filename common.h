#ifndef COMMON_H
#define COMMON_H

#define MAX_NAZWA 100
#define MAX_SWIAT 100
#define MAX_CHAOS 10
#define MAX_OPIS 300

typedef enum {
    STABILNY,
    CHWIEJNY,
    NIESTABILNY,
    NIEKLASYFIKOWANY
} Stabilnosc;

typedef struct {
    char nazwa[MAX_NAZWA];
    char swiat[MAX_SWIAT];
    int poziomChaosu;
    char opis[MAX_OPIS];
    Stabilnosc stabilnosc;
} Przedmiot;

typedef struct Node {
    Przedmiot value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
} List;

#endif