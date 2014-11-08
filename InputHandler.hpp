#ifndef INPUTHANDLER_HPP	
#define INPUTHANDLER_HPP

#include "Canard.hpp"
#include "Carte.hpp"

class InputHandler
{
	private:
		Canard* canard_;
		Carte* carte_;
		bool arret_;

	public:
		InputHandler(Canard* can, Carte* cart);
		~InputHandler();

		void userInput();
		bool terminate();
		void deplacement(int place, int sens);

		Canard* getCanard();
		void setCanard(Canard* can);

		bool getArret();
		void setArret(bool ar);
		void manger();



};

#endif