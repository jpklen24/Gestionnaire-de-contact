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

//Fonction pour modifier un contact

void modifierContact(contact p[100],int cont){
    if(cont==0){
        printf("Aucun contact n'a ete ajouter\n");
        return;
    }
    char name[50];
    printf("Quelles contacts voulez vous modifier?\n");
    scanf("%s",name);

    for(int i=0; i< cont; i++){
        if(strcmp(p[i].nom, name)==0){
            printf("Entrer votre nom\n");
            scanf("%s",p[i].nom);
            printf("Entrer votre numero \n");
            scanf("%d",&p[i].numero);
            printf("Entrer votre email\n");
            scanf("%s",p[i].email);
        }
    }
    printf("Modification reussi\n");

}

int main(){
    contact p[100];
  int nbrecontact=0;
  int choix;

//Menu

  printf("--------------------BIENVENUE DANS LE GESTIONNAIRE DE CONTACTS---------------------\n\n");
  do{
    printf("||1-Ajouter un contact || 2-Modifier un contact || 3-Afficher un contact || 4-Rechercher un contact ||\n\n|| 5-Supprimer un contact || 6-Sauvegarder un contact || 7-Charger un contact || 8-Quitter || \n\n");
    printf("Entrer votre choix\n");
    scanf("%d",&choix);

    switch(choix){
        case 1:
            ajouterContact(p,&nbrecontact);
            break;

        case 2:
            modifierContact(p,nbrecontact);
            break;

        case 3:
            afficherContact(p,nbrecontact);
                   break;

        case 4:
            rechercheContact(p,nbrecontact);
            break;

        case 5:
            supprimerContact(p,&nbrecontact);
            break;

        case 6:
           sauvegardeContact(p,nbrecontact);
           break;
        
        case 7:
            chargerContact(p,&nbrecontact);
            break;

        case 8:
            printf("Fin \n");
            break;

           default:
            printf("Error. Veillez entrer un numero correct\n");
    }

  }while(choix!=8);
  return 0;
 }

            

           
