#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<conio.h>
#include<string.h>



// declaration initiale de la fonction
void Color(int couleurDuTexte, int couleurDeFond);

int main(int argc, char *argv[]){
	printf("L'utilisateur vas jouer contre un ami Il faut réfléchit le mot passe qui peut être un mot ou un chiffre   Le player 2 vas entre le mot passe et le palyer1 vas réfléchir ");
printf(" dans ce programme  vas afficher le verte (un nombre vrai et en même position) le bleue (un nombre vrai mais n'est pas dans le position vrai) Rouge (nombre fausse)");
	char mot_passe[100], player[100];	
	int i=0, c=0, j=0;
	int green=0,red=0,bleu=0;
	// Demande au joueur 1 de saisir le mot de passe
	
	printf("\nLe joueur 1 saisit le mot de passe : ");
		
	scanf("%s", mot_passe);
	printf("\n \n \n \n \n \n \n \n \n  \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n maintent c'est tour de joueur 2 ");
	int langeur_motpasse = strlen(mot_passe);
	printf("\n le mot de passe ayant %d cararctere \n",langeur_motpasse);

	printf("Vous avez 8 essais.\n");
	
	while(i <8){
		
		
	
		Color(15, 0);
		
		printf("Saisissez le mot de passe \n : ");
		scanf("%s", player);
		
		
		
		printf("Reste : %d\n", 8 - i);
		
		for(j = 0; j < langeur_motpasse ; j++){
			
				if(mot_passe[j] == player[j]){
					// vrai caractère/chiffre à la bonne position (vert)
					Color(2, 0);
					printf("*");
					
					
					green++;
				}else {
				
				for(c = 0; c < langeur_motpasse ; c++){
				if(mot_passe[j] == player[c] && j!=c ){
					// vrai caractère/chiffre à la mauvaise position (bleu)
					Color(1, 0);
					printf("*");
					bleu++;
				}
				}
			}
			}
			
				
		for(red=0;red<langeur_motpasse-green-bleu;red++){
					// Mauvais caractère (rouge)
					Color(4, 0);
					printf("*");
					}
				
		
		i++;
		if(i==8){
			Color(15, 0);
			printf(" \n voua avez epuise vos essais \n le mot de passe est %s \n",mot_passe);
		}
		if(green==langeur_motpasse){
			// Le joueur a réussi
			i=8;// pour arrete la boucle while
			Color(15, 0);
			printf("\nVous avez réussi !");
		 }
		 green=0;//intialisation les variable 
		 bleu=0;
		}
		
			return 0;
	}
	




void Color(int couleurDuTexte, int couleurDeFond) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
