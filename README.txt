---------------------------------------------------------------
Echipa* creareNod(char numeEchipa[50], float puncte_nod, lista_jucatori **head);
functia s a folosit pentru a creea echipele

---------------------------------------------------------------
void adaugareLista(lista_echipe **head, Echipa *nod);
functia s a folosit pentru a adauga echipe in lista

---------------------------------------------------------------
Jucator* creareJucator(char nume[50], char prenume[50], int puncte);
functia s a folosit pentru a creea un jucator

---------------------------------------------------------------
void adaugareJucatori(lista_jucatori** head,Jucator* jucatorr);
functia s a folosit pentru a adauga jucatorii in lista

---------------------------------------------------------------
void afisareLista(lista_echipe* head, FILE* filename);
este o functie de afisare a listei de echipe in fisierul extern

---------------------------------------------------------------
void freejucatori(lista_jucatori* head);
s a folosit pentru eliberarea spatiului ocupat de jucatori

---------------------------------------------------------------
void eliberareLista(lista_echipe* head);
s a folosit pentru eliberarea listei

---------------------------------------------------------------
int putere2(int num);
s a folosit pentru determinarea celei mai mari puteri a lui 2 mai mica decat numarul de echipe

---------------------------------------------------------------
void deleteteam(lista_echipe** head, int numToKeep, int numarEchipe);
aceasta functie foloseste la stergerea unei echipe din lista

---------------------------------------------------------------
coada* creare_coada();
s a folosit pentru creerea cozilor

---------------------------------------------------------------
void encoada(coada** q, Echipa* v);
s a folosit pentru adaugarea in coada a unei echipe

---------------------------------------------------------------
int isEmpty(coada* q);
verifica daca coada este goala
nu a fost ceruta functia 

---------------------------------------------------------------
Echipa* eliminare_din_coada(coada** q);
s a folosit pentru scoaterea din coada

---------------------------------------------------------------
void eliberare_coada(coada* q);
aceasta functie s a folosit pentru golirea unei cozi

---------------------------------------------------------------
stack* creareStack();
functie folosita pentru creerea unei stive

---------------------------------------------------------------
void push(stack** s, Echipa* x);
functie de push pentru a adauga in stiva

---------------------------------------------------------------
Echipa* pop(stack** s);
pentru a scoate din stiva

---------------------------------------------------------------
void freeStack(stack** s);
pentru eliberarea stivei

---------------------------------------------------------------
void creare_meciuri(lista_echipe* head, coada** coada_meciuri);
folosita pentru generarea meciurilor

---------------------------------------------------------------
void afisare_meciuri(coada* coada_meciuri, FILE* fisier);
functie folosita pentru afisarea meciurilor

---------------------------------------------------------------
void jucare_meciuri(coada** coada_jocuri, stack** castigatori, stack** pierzatori);
pentru a juca meciurile

---------------------------------------------------------------
void afisare_castigatori(coada* coada_castigatori, FILE* fisier);
pentru afisarea castigatorilor

---------------------------------------------------------------
void copiere_echipe(coada* coadaw, lista_echipe** lista);
am creeat o copie pentru a retine ultimele 8 echipe

---------------------------------------------------------------
void eliberare_castigatori(lista_echipe* head);
pentru eliberarea memoriei ocupata de castigatori

