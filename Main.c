#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "PourLePendu.h"

int start()
{
    char nomDuDictionnaire[] = "Dictionnaire",lettreEntree,c=0;
    int Victoire=0,EssaiesRestants=EssaiesMax,i=0,TailleDuTableau;
    char *motTrouve,*motSecret;
    FILE* FichierDuDictionnaire=NULL;
    FichierDuDictionnaire=fopen(nomDuDictionnaire,"r");
    if (FichierDuDictionnaire==NULL)
    {
        exit(0);
    }
    TailleDuTableau=ChoixDuMotSecret(FichierDuDictionnaire,&motSecret);
    fclose(FichierDuDictionnaire);
    motTrouve=CreationDuTableau(TailleDuTableau);
    RemplirEtoiles (motTrouve,TailleDuTableau);
    printf("Bienvenue dans le Pendu !");
    while ((Victoire<TailleDuTableau)&&(EssaiesRestants!=0))
    {
        Victoire=0;
        printf("\n\nIl vous reste %d coups a jouer",EssaiesRestants);
        printf("\nQuel est le mot secret ? %s",motTrouve);
        printf("\nProposez une lettre : ");
        lettreEntree=getch();
        lettreEntree=tolower(lettreEntree);
        printf("%c",lettreEntree);
        for(i=0;i<TailleDuTableau;i++)
        {
            c= fonctionDeLectrure(&motSecret,i);
            if (c==lettreEntree)
            {
                   motTrouve[i]=lettreEntree;
                   if (EssaiesRestants>0)
                    EssaiesRestants= -EssaiesRestants;
            }
            if (c==motTrouve[i])
                Victoire++;
        }
        if (EssaiesRestants<0)
            EssaiesRestants=-EssaiesRestants;
        else
            EssaiesRestants--;
    }
    if (EssaiesRestants!=0)
        printf("\n\nFelicitation ! vous avez gagne !\nLe mot est %s\nIl vous restait %d essaies",motTrouve,EssaiesRestants);
    else
        printf("\n\nGAME OVER\nLe mot que vous cherchez etait %s",&motSecret);
    free(motTrouve);
    free(motSecret);
    Sleep(4000);
}
int main(int argc, char *argv[]){
    char c='y';
    while(c=='y'){
        start();
        printf("\nplay again ?\n");
        c=getch();
        system("cls");
    }
    return 0;
}
