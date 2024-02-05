/*
	Калькулятор
*/
#include <KolibriLib.hpp>

#include <sstream>
#include <string>

#include "globals.hpp"
#include "configuration.hpp"



int main() {
	
	KolibriLib::init();

	KolibriLib::UI::Size WindowSize = globals::window.GetSize();

	globals::window.CreateForm(
		KolibriLib::UI::Form(
			{KolibriLib::UI::DefaultMargin, KolibriLib::UI::DefaultMargin},
			{WindowSize.x - (KolibriLib::UI::DefaultMargin * 2), },
			"0"
		)
	);

	while(true)
	{
		KolibriLib::OS::Event event = globals::window.Handler();

		switch (event)
		{
		case KolibriLib::OS::Events::Exit:
			
			break;
		
		default:
			break;
		}
	}

	return 0;
}
