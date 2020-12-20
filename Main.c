#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "PourLePendu.h"

int start()
{
    char nomDuDictionnaire[] = "Dictionnaire",lettreEntree,c=0;
    int Victoire=0,EssaiesRestants=EssaiesMax,i=0,TailleDuTableau,myMemory[26];
    char *motTrouve,*motSecret;
    FILE* FichierDuDictionnaire=NULL;
    while(i<26)
    {
       myMemory[i]=1;
       i++;
    }
    FichierDuDictionnaire=fopen(nomDuDictionnaire,"r");
    if (FichierDuDictionnaire==NULL)
    {
        exit(0);
    }
    TailleDuTableau=ChoixDuMotSecret(FichierDuDictionnaire,&motSecret);
    fclose(FichierDuDictionnaire);
    motTrouve=CreationDuTableau(TailleDuTableau);
    RemplirEtoiles (motTrouve,TailleDuTableau);
    while ((Victoire<TailleDuTableau)&&(EssaiesRestants!=0))
    {
        Victoire=0;
        printf("    Bienvenue dans le Pendu !");
        printf("\n\n    Il vous reste %d coups a jouer",EssaiesRestants);
        printf("\n  Quel est le mot secret ? %s",motTrouve);
        /*printf("\n  les lettres restantes sont :");
        for(i=0;i<26;i++)
        {
            if(myMemory[i])
                {printf(" %c",(i+97));}
        }*/
        printf("\n  Proposez une lettre : ");
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
        if ((96<lettreEntree)&&(lettreEntree<123))
        {myMemory[lettreEntree-97]=0;}
        system("cls");
    }
    if (EssaiesRestants!=0)
        printf("\n\n    Felicitation ! vous avez gagne !\n    Le mot est %s\n    Il vous restait %d essaies",motTrouve,EssaiesRestants);
    else
        printf("\n\n    GAME OVER\n Le mot que vous cherchez etait %s",&motSecret);
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
