#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PourLePendu.h"
char* CreationDuTableau(int Taille)
{
    char* PointeurSurTableau=NULL;
    PointeurSurTableau=(char*)malloc((Taille+1)*sizeof(char));
    if (PointeurSurTableau == NULL)
    {
        printf("ECHEC");
        exit(0);
    }
    return PointeurSurTableau;
}
void RemplirEtoiles (char tableau[],int Taille)
{
    int i=0;
    do
    {
        tableau[i]='*';
        i++;
    }while (i<Taille);
    tableau[i]='\0';
}
int NombreDeMotsAuDictionnaire (FILE* leFichier)
{
    int i=0;
    char c='a';
    rewind(leFichier);
    while (c!=EOF)
    {
        c=fgetc(leFichier);
        if (c=='\n')
            i++;
    }
    return i;
}
int ChoixDuMotSecret(FILE* leFichier,char* motSecret)
{
    int Ndemot=0;
    srand(time(NULL));
    Ndemot=NombreDeMotsAuDictionnaire(leFichier);//printf("%dmots\n",Ndemot);
    Ndemot = (rand() % Ndemot) + 1;//printf("on prends le %d eme\n",Ndemot);
    rewind(leFichier);
    while (Ndemot!=1)
    {
        if (fgetc(leFichier)=='\n')
            Ndemot--;
    }
    while(fgetc(leFichier)!='\n')
        Ndemot++;
    Ndemot++;
    fseek(leFichier, -Ndemot, SEEK_CUR);Ndemot=Ndemot-2;
    //printf("le mot cherche contient %d lettres\n",Ndemot);
    *motSecret=CreationDuTableau(Ndemot);
    RemplissageDuMotSecret(Ndemot,motSecret,leFichier);
    return Ndemot;
}
void RemplissageDuMotSecret(int Ndemot, char motSecret[],FILE* leFichier)
{
    int i;
    for(i=0;i<Ndemot;i++)
    {
        motSecret[i]=fgetc(leFichier);
    }
    motSecret[i]='\0';
    //printf("%s\n",motSecret);
}
char fonctionDeLectrure(char tab[],int i)
{
    char c;
    c=tab[i];
    return c;
}
