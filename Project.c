#include "Library.h"

int main(int argc, char* argv[])
{
    //FILE* fisier_cerinte=fopen("c.in","r");
    FILE* fisier_cerinte=fopen(argv[1],"r");
    if (fisier_cerinte == NULL)
    {
        printf("Nu s-a putut deschide fisierul c.in\n");
        return 1;
    }
    int c[6],i;
    for(i=1;i<=5;i++)
        fscanf(fisier_cerinte,"%d",&c[i]);

    //FILE* fisier = fopen("d.in", "r");
    FILE* fisier = fopen(argv[2],"r");
    if (fisier == NULL)
    {
        printf("Nu s-a putut deschide fisierul d.in\n");
        return 1;
    }
    //FILE* fisier_out = fopen("r.out", "w");
    FILE* fisier_out = fopen(argv[3],"w");
    if (fisier_out == NULL)
    {
        printf("Nu s-a putut deschide fisierul r.out\n");
        return 1;
    }

    lista_echipe* head_nod=NULL;
    int numarEchipe;
    fscanf(fisier, "%d", &numarEchipe);

    if(c[1]==1)
    {
        for (i = 0; i < numarEchipe; i++) {
            char numeEchipa[50];
            int numarJucatori;

            fscanf(fisier, "%d %[^\n]", &numarJucatori, numeEchipa);
            if (numeEchipa[strlen(numeEchipa) - 1] == ' ')
                numeEchipa[strlen(numeEchipa) - 1] = '\0';
            lista_jucatori *head_jucator = NULL;
            float sum = 0;
            int j;
            for (j = 0; j < numarJucatori; j++) {
                char nume[50];
                char prenume[50];
                int puncte;
                fscanf(fisier, "%s %s %d", nume, prenume, &puncte);
                Jucator *jucator_data;
                jucator_data = creareJucator(nume, prenume, puncte);
                adaugareJucatori(&head_jucator, jucator_data);
                sum += puncte;
            }
            sum = (float) sum / numarJucatori;
            Echipa *nod_data = creareNod(numeEchipa, sum, &head_jucator);

            adaugareLista(&head_nod, nod_data);

        }
        if (c[2] == 1) {
            int numToKeep = putere2(numarEchipe);
            deleteteam(&head_nod, numToKeep, numarEchipe);
            numarEchipe = numToKeep;
        }
        afisareLista(head_nod, fisier_out);
        if(c[3]==1)
        {
            fprintf(fisier_out,"\n");
            coada* meciuri=creare_coada();
            stack* castigatori=creareStack();
            stack* pierzatori=creareStack();
            lista_echipe* optimi=NULL;
            creare_meciuri(head_nod,&meciuri);
            int runda=0;
            while(numarEchipe>1)
            {
                runda++;
                fprintf(fisier_out,"--- ROUND NO:%d\n",runda);
                afisare_meciuri(meciuri,fisier_out);
                jucare_meciuri(&meciuri,&castigatori,&pierzatori);
                fprintf(fisier_out,"WINNERS OF ROUND NO:%d\n",runda);
                afisare_castigatori(meciuri,fisier_out);
                numarEchipe/=2;
                if(numarEchipe>1)
                    fprintf(fisier_out,"\n");
                if(numarEchipe==8)
                    copiere_echipe(meciuri,&optimi);
            }
            eliberare_coada(meciuri);
            freeStack(&castigatori);
            free(castigatori);
            free(pierzatori);
            eliberare_castigatori(optimi);
        }
        eliberareLista(head_nod);
    }

    fclose(fisier);
    fclose(fisier_out);

    return 0;
}
