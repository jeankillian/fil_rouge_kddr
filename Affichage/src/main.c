#include<stdio.h>
#include<unistd.h>
#include<ncurses.h>
#include"main.h"

#define WINDOW stdscr

/*
 *Récupère et modifie l'affichage de la position du jeton en fonction des boutons déplacements
 *En modifie la couleur selon le joueur (1 ou 2)
 */
void affichage_grille(int pos_jeton, int player, char action_fun) {
	static int grille_jeton[] = { 0, 0, 0, 0, 0, 0, 0 };
	char grille = ' ';
	char jetonp1 = 'O';
	char jetonp2 = 'X';
	char jeton = ' ';
//-----------------------------
	if (player == 1) {
		jeton = jetonp1;
	} else if (player == 2) {
		jeton = jetonp2;
	}
//-----------------------------
	printf("-");
	for (int y = 0; y < 7; y++) {
		if (y == pos_jeton) {
			printf("%c-", jeton);
		} else {
			printf("%c-", grille);
		}
	}
	printf("\n");
//-----------------------------
	for (int i = 0; i < 6; i++) {
		printf("|");
		for (int y = 0; y < 7; y++) {
			if (action_fun == 'v' && i == (5 - grille_jeton[pos_jeton])
					&& y == pos_jeton) {
				printf("%c|", jeton);
				grille_jeton[pos_jeton]++;
				grille_matrice[i][y] = jeton;
			} else {
				printf("%c|", grille);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("+++++++++++++++\n");
	for (int i = 0; i < 6; i++) {
		printf("|");
		for (int y = 0; y < 7; y++) {
			printf("%c|", grille_matrice[i][y]);
		}
		printf("\n");
	}
	printf("+++++++++++++++\n");

}

int main(void) {
	int init_jeton = 3;
	int joueur = 2;
	char action = ' ';

	initscr(); /* init de ncurses */
	clear();
	noecho(); /* pour masquer l'affichage du buffer stdin dans la console */
	cbreak(); /* Line buffering disabled. pass on everything */

	printf("Bienvenue dans le jeu du puissance 4 !!");
	refresh();

	scrollok(WINDOW, TRUE);
	nodelay(WINDOW, TRUE);
	while (1) {
		sleep(1);
		fflush(stdin);
		affichage_grille(init_jeton, joueur, action);
		//printf("q(gauche), d(droite), v(valider): \n");
		//scanf("%c", &action);
		action = wgetch(WINDOW);
		if (action == 'q') {
			if (init_jeton == 0) {
				init_jeton = 6;
			} else {
				init_jeton--;
			}
		}
		if (action == 'd') {
			if (init_jeton == 6) {
				init_jeton = 0;
			} else {
				init_jeton++;
			}
		}
	}
	clrtoeol();
	refresh();
	endwin();
	return 0;
}
