#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Définition de la structure contact
typedef struct{
      char nom[100];// Nom du contact limité à 100 carractères
      int numero;// Numéro de téléphone enregistré comme entier
      char email[50];// Adresse Email
  }contact;

// Fonction pour ajouter un contact
void ajouterContact(contact p[100], int *cont) {
    printf("\n=== Ajouter un Contact ===\n");
    printf("Nom: ");
    scanf("%s", p[*cont].nom);  // Saisie du nom
    printf("Numéro: ");
    scanf("%d", &p[*cont].numero);
    printf("Email: ");
    scanf("%s", p[*cont].email);  // Saisie de l'email

    (*cont)++;  // Incrémentation du nombre de contacts
    printf("\n[+] Contact ajouté avec succès !\n");
}

//Fonction pour supprimer un contact
void supprimerContact(contact p[100], int *cont){
     if(*cont==0){
        printf("\n[!]Aucun contact n'a ete ajouter[!]\n");
        return;
    }

    char name[50];
    printf("Entrer le nom du contact a supprimer\n");
    scanf("%s", name);
    
      // Recherche du contact à supprimer
    for(int i=0; i<*cont; i++)
    {
         if(strcmp(p[i].nom, name)==0)
         {
            // Décalage des contacts pour supprimer l'entrée
            for(int j=i; j<*cont-1; j++)
            {
                p[j]=p[j+1];
            }
            (*cont)--;// Décrémentation du nombre de contacts
            printf("Contact supprimer avec suces\n");
            return;
         } 
    }
    printf("Contact non trouvee\n");
    
}

//Fonction pour sauvegarder un contact

void sauvegardeContact(contact p[100], int cont)
    {
          FILE *fichier = fopen("contact.bin","wb");
      
          if(fichier==NULL)
            {
                printf("Impossible de sauvegarder le contact\n");
            }
      
                fwrite(&cont,sizeof(int),1,fichier);
                fwrite(p,sizeof(contact),cont,fichier);
                fclose(fichier);
                printf("Sauvegarde effectue\n");
   }

//Fonction pour charger les contactes depuis un fichier binaire
void chargerContact(contact p[100], int *cont)
    {
          FILE *fichier=fopen("C:\\Users\\Tiptop\\Documents\\contact.txt","rb");
      
          if(fichier==NULL)
            {
              printf("Impossible de charger le contact\n");
            }
      
                fread(&cont,sizeof(int),1,fichier);
                fread(p,sizeof(contact),*cont,fichier);
                fclose(fichier);
                printf("Chargement effectue\n");
      }

//Fonction pour modifier un contact

void modifierContact(contact p[100],int cont)
    {
          if(cont==0)
            {
              printf("Aucun contact n'a ete ajouter\n");
              return;
            }
          char name[50];
          printf("Quelles contacts voulez vous modifier?\n");
          scanf("%s",name);

    // Recherche du contact à modifier
          for(int i=0; i< cont; i++)
             {
              if(strcmp(p[i].nom, name)==0)
                  {
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

// Fonction pour rechercher un contact par nom
void rechercheContact(contact p[100], int cont)
      {
          if(cont==0)
            {
              printf("Aucun contact n'a ete ajouter\n");
              return;
            }
      
          char name[50];
          printf("Entrer le nom du contact que vous rechercher\n");
          scanf("%s", name);
      
      // Parcours de la liste pour trouver le contact
          for(int i=0; i<cont; i++)
            {
              if(strcmp(p[i].nom, name)==0)
                  {
                        printf("Contact Trouvee\n");
                        printf("-------------------------------\n");
                        printf("Contact #%d\n",i+1);
                        printf("Nom: %s \n",p[i].nom);
                        printf("Numero: %d \n",p[i].numero);
                        printf("Email: %s \n",p[i].email);
                        printf("-------------------------------\n");
                        return;
                  }
            }
          
          printf("Contact non trouvee\n");

      }

// Fonction pour afficher tous les contacts
void afficherContact(contact p[100], int cont) {
    if (cont == 0) {
        printf("\n[!] Aucun contact n'a été ajouté.\n");
        return;
    }
    printf("\n=== Liste des Contacts ===\n");
    for (int i = 0; i < cont; i++) {
        printf("\n--- Contact #%d ---\n", i + 1);
        printf("Nom   : %s\n", p[i].nom);
        printf("Numéro: %d\n", p[i].numero);
        printf("Email : %s\n", p[i].email);
    }
}

//Fonction principale
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
            

           
