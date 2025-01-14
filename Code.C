#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
      char nom[100];
      int numero;
      char email[50];
  }contact;


//Fonction pour charger les contactes depuis un fichier binaire

void chargerContact(contact p[100], int cont){
    FILE *fichier=fopen("C:\\Users\\Tiptop\\Documents\\contact.txt","rb");

    if(fichier==NULL){
        printf("Impossible de charger le contact\n");
    }

    fread(&cont,sizeof(int),1,fichier);
    fread(p,sizeof(contact),cont,fichier);
    fclose(fichier);
    printf("Chargement effectue\n");
}
