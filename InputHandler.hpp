#ifndef INPUTHANDLER_HPP	
#define INPUTHANDLER_HPP

#include "Canard.hpp"

class InputHandler
{
	private:
		Canard* canard;
		bool arret;

	public:
		InputHandler(Canard* can);
		~InputHandler();

		void userInput();
		bool terminate();

		Canard* getCanard();
		void setCanard(Canard* can);

		bool getArret();
		void setArret(bool ar);



};

#endif