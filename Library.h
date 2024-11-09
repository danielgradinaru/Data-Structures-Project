#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Jucator
{
    char nume[50];
    char prenume[50];
    int puncte;
} Jucator;


typedef struct lista_jucatori
{
    Jucator jucator;
    struct lista_jucatori *next;

}lista_jucatori;
typedef struct Echipa
{
    char numeEchipa[50];
    float puncte_echipa;
    lista_jucatori *jucatori;

} Echipa;
typedef struct lista_echipe
{
    Echipa nod;
    struct lista_echipe *next;
}lista_echipe;

typedef struct coada{
    lista_echipe *front, *rear;
}coada;

typedef struct stack{
    lista_echipe* top;
}stack;

Echipa* creareNod(char numeEchipa[50], float puncte_nod, lista_jucatori **head);
void adaugareLista(lista_echipe **head, Echipa *nod);
Jucator* creareJucator(char nume[50], char prenume[50], int puncte);
void adaugareJucatori(lista_jucatori** head,Jucator* jucatorr);
void afisareLista(lista_echipe* head, FILE* filename);
void freejucatori(lista_jucatori* head);
void eliberareLista(lista_echipe* head);
int putere2(int num);
void deleteteam(lista_echipe** head, int numToKeep, int numarEchipe);
coada* creare_coada();
void encoada(coada** q, Echipa* v);
int isEmpty(coada* q);
Echipa* eliminare_din_coada(coada** q);
void eliberare_coada(coada* q);
stack* creareStack();
void push(stack** s, Echipa* x);
Echipa* pop(stack** s);
void freeStack(stack** s);
void creare_meciuri(lista_echipe* head, coada** coada_meciuri);
void afisare_meciuri(coada* coada_meciuri, FILE* fisier);
void jucare_meciuri(coada** coada_jocuri, stack** castigatori, stack** pierzatori);
void afisare_castigatori(coada* coada_castigatori, FILE* fisier);
void copiere_echipe(coada* coadaw, lista_echipe** lista);
void eliberare_castigatori(lista_echipe* head);

