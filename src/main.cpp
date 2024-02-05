/*
	Калькулятор
*/
#include <KolibriLib.hpp>

#include <sstream>
#include <string>

#include "globals.hpp"
#include "configuration.hpp"



int main() {
	
	LoadConfiguration();

	while(true)
	{
		unsigned Event = globals::window.Handler();

		if(KolibriLib::EXIT || globals::window._Exit)
		{
			if(KolibriLib::EXITCODE != 0)
			{
				std::string message = "Error:";

				KolibriLib::childWindow::ErrorWindow(message);
			}
		}
	}

	return 0;
}
