#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>
/**
Classe qui gère la carte du jeu représentée par un tableau de Cases, une structure contenant deux entiers : un pour le type des terrains, un pour l'occupation avec genre 0 rien, 1 : nourriture , 2 : brindilles,structure définie pour ça, qui ne sert QUE dans cette classe.
Types de terrain : eau ~  1 arbre ! 2  herbe . 3 sable - 4 rocher # 5 nid * 6 */
class Carte
{
	private:
		/** Structure de deux entiers permettant de définir une case comme un type de terrain et une occupation (possibilité d'ajouter d'autres infos plus tard) */
		struct Case
		{
		/** représente le type de terrain */
		int type;
		/** représente l'occupation du terrain */
		int occupation;
		};
		/** Pointeur vers un tableau de Terrain représentant la carte */
		Case* tabl_;
	public:
		Carte();
		~Carte();
		/** Méthode qui va créer la carte à partir d'un fichier*/
		void creerCarte();
		/** Méthode qui crée une carte aléatoire [possibilité d'être coincé, car pas de contrôles d'aléatoire]*/
		void creerCarteAlea();
		/** Méthode renvoyant la case demandée*/
		int getType(int i);
		/** Méthode changeant le type d'une case i en a.*/
		void setType(int i, int a);
		/**	Méthode permettant de mettre un entier donné (b)sur la case voulue(a) */
		void setTab(int a, int b);
		/** Méthode renvoyant l'entier d'une casede la carte */
		int getTab(int i);
		/**	Fonction qui renvoit les cases que le canard voit (+1/-1) */
		int* getVue(int* vue, int i);
		/** Méthode permettant de changer l'occupation d'une case */
		void setOccupation(int a, int b);
		/** Méthode renvoyant un entier représentant l'occupation d'une case */
		int getOccupation(int a);
		/** Méthode renvoyant vrai s'il y a un obstacle sur la case a pour un canard au sol */
		bool getObstacleSol(int a);
		/** Méthode renvoyant toujours faux car il n'y a pas d'obstacle quand le canard vole */
		bool getObstacleVol();
		/** Méthode renvoyant vrai s'il y a un obstacle sur la case a pour un canard dans l'eau */
		bool getObstacleEau(int a);
		/** Méthode qui remplit la carte de nourriture et de brindilles */
		void remplirCarte();
};
#endif
