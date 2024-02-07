
#include <KolibriLib.hpp>
#include <tinyexpr.h>


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

	std::vector<unsigned> a = CalcButtons::DefineButtons();

	globals::window.Render();

	while(true)
	{
		KolibriLib::OS::Event event = globals::window.Handler();

		switch (event)
		{
		case KolibriLib::OS::Events::Exit:
			
			break;
		case KolibriLib::OS::Events::Button:

			for(int i = 0; i < a.size(); i++)
			{
				if(a[i] == globals::window.GetPressedButton())
				{
					
				}
			}

			break;
		}
	}

	return 0;
}
