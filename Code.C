#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure de la variable "contact"

typedef struct{
      char nom[100];
      int numero;
      char email[50];
  }contact;

//Fonction pour supprimer un contact

void supprimerContact(contact p[100], int *cont){
     if(*cont==0){
        printf("Aucun contact n'a ete ajouter\n");
        return;
    }

    char name[50];
    printf("Entrer le nom du contact a supprimer\n");
    scanf("%s", name);

    for(int i=0; i<*cont; i++){
         if(strcmp(p[i].nom, name)==0){
            for(int j=i; j<*cont-1; j++){

                p[j]=p[j+1];
                
            }
            (*cont)--;
            printf("Contact supprimer avec suces\n");
            return;
         } 
    }
    printf("Contact non trouvee\n");
    
}

//Fonction pour sauvegarder un contact

void sauvegardeContact(contact p[100], int cont){
    FILE *fichier = fopen("contact.bin","wb");

    if(fichier==NULL){
        printf("Impossible de sauvegarder le contact\n");
    }

    fwrite(&cont,sizeof(int),1,fichier);
    fwrite(p,sizeof(contact),cont,fichier);
    fclose(fichier);
    printf("Sauvegarde effectue\n");
}

//Fonction pour charger les contactes depuis un fichier binaire

void chargerContact(contact p[100], int *cont){
    FILE *fichier=fopen("C:\\Users\\Tiptop\\Documents\\contact.txt","rb");

    if(fichier==NULL){
        printf("Impossible de charger le contact\n");
    }

    fread(&cont,sizeof(int),1,fichier);
    fread(p,sizeof(contact),*cont,fichier);
    fclose(fichier);
    printf("Chargement effectue\n");
}
