/*
	Калькулятор
*/
#include <KolibriLib.hpp>

#include <sstream>
#include <string>

#include "globals.hpp"
#include "UI.hpp"

int main() {
	
	KolibriLib::init();

	KolibriLib::UI::Size WindowSize = globals::window.GetSize();

	// Основная форм
	unsigned output = globals::window.CreateForm(
		KolibriLib::UI::Form(
			{KolibriLib::UI::DefaultMargin, KolibriLib::UI::DefaultMargin},
			{WindowSize.x - (KolibriLib::UI::DefaultMargin * 2), WindowSize.y / 4},
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
		
		}
	}

	return 0;
}
