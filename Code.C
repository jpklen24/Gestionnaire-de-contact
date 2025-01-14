#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure de la variable "contact"

typedef struct{
      char nom[100];
      int numero;
      char email[50];
  }contact;

//Fonction pour afficher les contacts

void afficherContact(contact p[100], int cont){
     if(cont==0){
        printf("Aucun contact n'a ete ajouter\n");
        return;
    }

    printf("-------Liste de contact-------\n");

    for(int i=0; i<cont;i++){
       printf("Contact #%d\n",i+1);
       printf("Nom: %s \n",p[i].nom);
       printf("Numero: %d \n",p[i].numero);
       printf("Email: %s \n",p[i].email);
       printf("-------------------------------\n");

    }

}

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
