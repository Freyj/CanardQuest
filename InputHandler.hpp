#ifndef INPUTHANDLER_HPP	
#define INPUTHANDLER_HPP

#include "Canard.hpp"

class InputHandler
{
	protected:
		Canard* canard;

	public:
		InputHandler(Canard* can);
		~InputHandler();

		void userInput();
		bool terminate();

		Canard* getCanard();




};

#endif