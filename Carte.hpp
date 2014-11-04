#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>
/**
Classe qui gère la carte du jeu représentée par un tableau 
d'entiers pour le moment (un entier représente un type de terrain)
(deux tableaux d'entiers ? un pour les terrains, un pour l'occupation
avec genre 0 rien, 1 : prédateur, 2 : brindilles, 3 : nourriture
4 : predateur et brindilles, 5 predateur et nourriture 
jamais brindilles et nourriture.) 
structure définie juste pour ça, qui ne sert QUE dans cette classe
*/
class Carte
{
	private:
		/** Structure de deux entiers permettant de définir une case comme un type de terrain et une occupation (possibilité d'ajouterd'autres infos plus tard) */
		struct Case
		{
		/** représente le type de terrain */
		int type;
		/** représente l'occupation du terrain */
		int occupation;
		};
		/** Pointeur vers un tableau de Terraint représentant la carte */
		Case* tabl_;
	public:
		Carte();
		~Carte();
		/** Méthode qui va créer la carte à partir d'un fichier*/
		void creerCarte();
		/**	Méthode qui renvoit un string pour savoir quoi afficher ? */
		std::string sendAff();
		/** Méthode renvoyant la case demandée*/
		int getType(int i);
		/**	Méthode permettant de mettre un entier donné (b)sur la case voulue(a) */
		void setType(int i, int a);
		/** Méthode changeant le type d'une case i en a.*/
		void setTab(int a, int b);
		/** Méthode renvoyant l'entier d'une casede la carte */
		int getTab(int i);
		/**	Fonction qui renvoit les cases que le canard voit (+1/-1) */
		int* getVue(int* vue, int i);
		/** Méthode permettant de changer l'occupation d'une case */
		void setOccupation(int a, int b);
		/** Méthode renvoyant un entier représentant l'occupation d'une case */
		int getOccupation(int a);
		/** Méthode renvoyant un booléen pour déterminer si on peut passer sur la case ou pas*/
		bool getObstacle(int a);
};
#endif