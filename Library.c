#include "Library.h"

Echipa* creareNod(char numeEchipa[50], float puncte_nod, lista_jucatori **head)
{
    Echipa* nod = (Echipa*)malloc(sizeof(Echipa));
    strcpy(nod->numeEchipa, numeEchipa);
    nod->puncte_echipa = puncte_nod;
    nod->jucatori = *head;
    return nod;
}

void adaugareLista(lista_echipe **head, Echipa *nod)
{
    lista_echipe *Newnod=(lista_echipe*)malloc(sizeof(lista_echipe));
    Newnod->nod=*nod;
    Newnod->next=*head;
    *head=Newnod;
}
Jucator* creareJucator(char nume[50], char prenume[50], int puncte)
{
    Jucator* Newjucator=(Jucator*)malloc(sizeof(Jucator));
    strcpy(Newjucator->nume, nume);
    strcpy(Newjucator->prenume, prenume);
    Newjucator->puncte=puncte;
    return Newjucator;
}
void adaugareJucatori(lista_jucatori** head,Jucator* jucatorr)
{
    lista_jucatori* Newjucator=(lista_jucatori*)malloc(sizeof(lista_jucatori));
    Newjucator->jucator=*jucatorr;
    Newjucator->next=*head;
    *head=Newjucator;
}
void afisareLista(lista_echipe* head, FILE* filename)
{
    lista_echipe* cap=head;
    while (cap != NULL)
    {
        fprintf(filename, "%s\n", cap->nod.numeEchipa);

        cap = cap->next;
    }
}
void freejucatori(lista_jucatori* head)
{
    lista_jucatori* cap = head;
    while (cap != NULL)
    {
        lista_jucatori* temp = cap;
        cap = cap->next;
        free(temp);
    }
}

void eliberareLista(lista_echipe* head)
{

    lista_echipe* cap=head;
    while (cap != NULL)
    {
        lista_echipe* temporar=cap;
        cap = cap->next;
        freejucatori(temporar->nod.jucatori);
        free(temporar);
    }
}
//cerinta 2
int putere2(int num)
{
    int numToKeep = 1;
    while (num >= numToKeep)
    {
        numToKeep=2*numToKeep;
    }
    return (numToKeep/2);
}

void deleteteam(lista_echipe** head, int numToKeep, int numarEchipe)
{
    while(numToKeep!=numarEchipe)
    {
        lista_echipe* current=*head;
        lista_echipe* prev=NULL;
        lista_echipe* echipa_min=*head;
        lista_echipe* prev_min=NULL;

        while(current!=NULL)
        {
            if(current->nod.puncte_echipa < echipa_min->nod.puncte_echipa)
            {
                echipa_min=current;
                prev_min=prev;
            }
            prev=current;
            current=current->next;
        }
        if(echipa_min==*head)
            *head=(*head)->next;
        else
            prev_min->next=echipa_min->next;

        freejucatori(echipa_min->nod.jucatori);
        free(echipa_min);



        numarEchipe--;
    }


}
//cerinta 3
coada* creare_coada()
{
    coada *q;
    q=(coada*) malloc(sizeof(coada));
    if(q== NULL )
        return NULL;
    q->front=q->rear=NULL ;
    return q;
}
void encoada(coada** q, Echipa* v)
{
    lista_echipe* Newnode=(lista_echipe*)malloc(sizeof(lista_echipe));
    Newnode->nod=*v;
    Newnode->next=NULL;
    if((*q)->rear==NULL)
    {
        (*q)->front=Newnode;
        (*q)->rear=Newnode;
    }

    else
    {
        (*q)->rear->next=Newnode;
        (*q)->rear=Newnode;
    }
}
int isEmpty(coada* q)
{
    return (q->front==NULL);
}
Echipa* eliminare_din_coada(coada** q)
{
    if ((*q)->front == NULL)
        return NULL;
    lista_echipe* aux = (*q)->front;
    Echipa* d = &(aux->nod);

    (*q)->front=((*q)->front)->next;
    free(aux);
    if ((*q)->front == NULL)
        (*q)->rear = NULL;
    return d;
}

void eliberare_coada(coada* q)
{
    lista_echipe* aux;
    while (!(q->front==NULL))
    {
        aux=q->front;
        q->front=q->front->next;
        free(aux);
    }
    free(q);
}

stack* creareStack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

void push(stack** s, Echipa* x)
{
    lista_echipe* newS = (lista_echipe*)malloc(sizeof(lista_echipe));
    newS->nod = *x;
    newS->next = (*s)->top;
    (*s)->top= newS;
}
Echipa* pop(stack** s)
{
    if ((*s)->top == NULL)
        return NULL;
    lista_echipe* popedS=(*s)->top;
    Echipa* popedNod = &(popedS->nod);
    (*s)->top = popedS->next;
    free(popedS);
    return popedNod;
}

void freeStack(stack** s)
{
    while ((*s)->top != NULL)
    {
        pop(s);
    }
}

void creare_meciuri(lista_echipe* head, coada** coada_meciuri)
{
    lista_echipe* current=head;
    while(current!=NULL)
    {
        Echipa* actual=&(current->nod);
        encoada(coada_meciuri, actual);
        current=current->next;

    }
}

void afisare_meciuri(coada* coada_meciuri, FILE* fisier)
{
    coada* current_coada=coada_meciuri;
    lista_echipe* current=current_coada->front;
    while(current!=NULL)
    {
        int i;
        fprintf(fisier,"%s",current->nod.numeEchipa);
        for(i=1;i<=33-strlen(current->nod.numeEchipa);i++)
            fprintf(fisier," ");
        fprintf(fisier,"-");
        for(i=1;i<=33-strlen(current->next->nod.numeEchipa);i++)
            fprintf(fisier," ");
        fprintf(fisier,"%s\n",current->next->nod.numeEchipa);
        current=current->next->next;
    }
    fprintf(fisier,"\n");
}

void jucare_meciuri(coada** coada_jocuri, stack** castigatori, stack** pierzatori)
{
    while((*coada_jocuri)->front!=NULL)
    {
        Echipa* echipa1= eliminare_din_coada(coada_jocuri);
        Echipa* echipa2= eliminare_din_coada(coada_jocuri);
        if(echipa1->puncte_echipa>echipa2->puncte_echipa)
        {
            echipa1->puncte_echipa++;
            push(castigatori,echipa1);
            push(pierzatori,echipa2);
        }
        else
        {
            echipa2->puncte_echipa++;
            push(castigatori,echipa2);
            push(pierzatori,echipa1);
        }
    }
    freeStack(pierzatori);
    while((*castigatori)->top!=NULL)
    {
        Echipa* echipaw=pop(castigatori);
        encoada(coada_jocuri,echipaw);
    }
}

void afisare_castigatori(coada* coada_castigatori, FILE* fisier)
{
    coada* current_coada=coada_castigatori;
    lista_echipe* current=current_coada->front;
    while(current!=NULL)
    {
        int i;
        fprintf(fisier,"%s",current->nod.numeEchipa);
        for(i=1;i<=34-strlen(current->nod.numeEchipa);i++)
            fprintf(fisier," ");
        fprintf(fisier,"-");
        fprintf(fisier,"  %.2f\n",current->nod.puncte_echipa);
        current=current->next;
    }
}

void copiere_echipe(coada* coadaw, lista_echipe** lista)
{
    lista_echipe* current=coadaw->front;
    while(current!=NULL)
    {
        Echipa* e=&(current->nod);
        lista_echipe* newNode=(lista_echipe*)malloc(sizeof(lista_echipe));
        newNode->nod=*e;
        newNode->next=*lista;
        *lista=newNode;
        current=current->next;
    }
}

void eliberare_castigatori(lista_echipe* head)
{
    lista_echipe* current = head;
    while (current != NULL)
    {
        lista_echipe* temp = current;
        current = current->next;
        free(temp);
    }
}
