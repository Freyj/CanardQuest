#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>
#include <vector>
/**
Classe qui gère la carte du jeu représentée par un tableau
d'entiers pour le moment (un entier représente un type de terrain)
(deux tableaux d'entiers ? un pour les terrains, un pour l'occupation
avec genre 0 rien, 1 : nourriture , 2 : brindilles, 3 : prédateur
4 : predateur et brindilles, 5 predateur et nourriture
jamais brindilles et nourriture.)
structure définie juste pour ça, qui ne sert QUE dans cette classe
Types de terrain :
eau ~  1
arbre ! 2
herbe . 3
sable - 4
rocher # 5
nid * 6
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
		/** Pointeur vers un tableau de Terrain représentant la carte */
		Case* tabl_;
		/** Vecteur des cases aquatiques */
		std::vector<int> caseEau;
		/** Vecteur des cases terrestres */
		std::vector<int> caseSol;
	public:
		/** \brief Constructeur.
			Initialise le tableau de 256 pointeurs vers des Cases, et utiliser creerCarte() et triParType() pour générer l'ensemble.
		*/
		Carte();
		/** Destructeur */
		~Carte();
		/** \brief Création de carte par fichier.
		Méthode qui va créer la carte à partir d'un fichier*/
		void creerCarte();
		/** \brief Création de carte aléatoire.
			Méthode qui crée une carte aléatoire [possibilité d'être coincé, car pas de contrôles d'aléatoire]*/
		void creerCarteAlea();
		/** \brief Getter du type de la case.
		    Méthode renvoyant la case demandée
			\param i un entier pour la case demandée
			\return un entier pour le type
		*/
		int getType(int i);
		/** \brief Setter du type de la case.
			Méthode changeant le type d'une case i en a.
			\param i : la case en position
			\param a : le type a changé
		*/
		void setType(int i, int a);

		/** \brief Getter du type de la case. 
			Méthode donnant le type d'une case i.
			\param i : la case
		*/
		int getTab(int i);

		/**	\brief Vue du canard.
			Fonction qui renvoit les cases que le canard voit (+1/-1) 
			\param vue : un pointeur vers un tableau d'entiers
			\param i : la position du canard
			\return : un pointeur vers un tableau d'entiers pour l'affichage
		*/
		int* getVue(int* vue, int i);

		/** \brief Setter du type de la case.
			Méthode permettant de changer l'occupation d'une case
			\param a : la case en position
			\param b : l'occupation à mettre.
		*/
		void setOccupation(int a, int b);

		/** \brief Getter de l'occupation de la case. 
			Méthode donnant le t'occupation d'une case a.
			\param a : la case
		*/
		int getOccupation(int a);

		/** \brief Renvoie l'obstacle terrestre.
			Méthode renvoyant vrai s'il y a un obstacle sur la case a. trois type d'obstacle possible en fonction de l'etat du canard
			\param a un int la case
			\return un booléen (vrai si obstacle)
		*/
		bool getObstacleSol(int a);
		/** \brief Renvoie l'obstacle aérien.
			Méthode renvoyant faux, y a pas d'obstacle en vol
			\return un booléen  faux
		*/
		bool getObstacleVol();
		/** \brief Renvoie l'obstacle aquatique.
			Méthode renvoyant vrai s'il y a un obstacle sur la case a. trois type d'obstacle possible en fonction de l'etat du canard
			\param a un int la case
			\return un booléen (vrai si obstacle)
		*/
		bool getObstacleEau(int a);
		/** \brief Remplit la carte.
			Méthode qui remplit la carte de nourriture et de brindilles 
		*/
		void remplirCarte();
		/** \brief tri des types
		Méthode qui met dans leur tableaux respectifs les types de chaques états */
		void triParType();
		/** \brief renvoie les cases eau.
			Renvoie un vecteur de cases aquatiques	
			\return un vecteur d'int 
		*/
		std::vector<int> getCaseEau();
		/** \brief renvoie les cases terrestres.
			Renvoie un vecteur de cases terrestres	
			\return un vecteur d'int 
		*/
		std::vector<int> getCaseSol();
};
#endif
