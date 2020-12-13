#ifndef Lependu
#define Lependu
#define EssaiesMax 13
char* CreationDuTableau(int Taille);
void RemplirEtoiles (char tableau[],int Taille);
int NombreDeMotsAuDictionnaire (FILE* leFichier);
int ChoixDuMotSecret(FILE* leFichier,char* motSecret);
void RemplissageDuMotSecret(int Ndemot, char motSecret[],FILE* Lefichier);
char fonctionDeLectrure(char tab[],int i);
#endif // Lependu
