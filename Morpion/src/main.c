#include<stdio.h>
#include"main.h"
#include<unistd.h>
/*
 *Récupère et modifie l'affichage de la position du jeton en fonction des boutons déplacements
 *En modifie la couleur selon le joueur (1 ou 2)
 */
void affichage_grille(int pos_jetonX, int pos_jetonY, int player, char action_fun){
	char grille = '#';
	char grille_vide = ' ';
	char jetonp1 = 'O';
	char jetonp2 = 'X';
	char jeton = ' ';
	int test = 0;

	if(player == 1){
		jeton = jetonp1;
	}
	else if(player == 2){
		jeton = jetonp2;
	}
	for (int i=0;i<6;i++){
		printf("|");
		for(int y=0;y<7;y++){
			if((i>1 && i<5)&&(y>1 && y<5)){
				if(i==pos_jetonY && y==pos_jetonX){
					printf("%c|", jeton);
					if(action_fun == 'v'){
						if(grille_matrice[i][y]==' '){
							grille_matrice[i][y] = jeton;
						}
						else{
							test=1;
						}
					}
				}
				else{
					printf("%c|", grille_vide);
				}
			}
			else{
				printf("%c|", grille);
			}
		}
		printf("\n");
	}
	if(test != 0){
		printf("Erreur Emplacement déja utilisé\n");
		test=0;
	}
}

int main(void){
	int init_jetonX = 3;
	int init_jetonY = 3;
	int joueur = 2;
	char action = ' ';

	while(1){
		sleep(0.5);
		affichage_grille(init_jetonX,init_jetonY, joueur, action);
		printf("q(gauche), d(droite), v(valider): \n");
		scanf("%c", &action);
		if(action == 'q'){
			if(init_jetonX == 2){
				init_jetonX = 4;
			}
			else{
				init_jetonX --;
			}
		}
		if(action == 'd'){
			if(init_jetonX == 4){
				init_jetonX = 2;
			}
			else{
				init_jetonX ++;
			}
		}
		if(action == 'z'){
			if(init_jetonY == 2){
				init_jetonY = 4;
			}
			else{
				init_jetonY --;
			}
		}
		if(action == 's'){
			if(init_jetonY == 4){
				init_jetonY = 2;
			}
			else{
				init_jetonY ++;
			}
		}
		if(action == 'v'){
			for (int i=0;i<6;i++){
				printf("|");
				for(int y=0;y<7;y++){
					printf("%c|", grille_matrice[i][y]);
				}
				printf("\n");
			}
		}
	}
	for (int i=0;i<6;i++){
		printf("|");
		for(int y=0;y<7;y++){
			printf("%c|", grille_matrice[i][y]);
		}
	}
	return 0;
}
