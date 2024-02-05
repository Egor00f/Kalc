#ifndef __UI_H__
#define __UI_H__

#include <KolibriLib.hpp>

#include <vector>
#include <string>

#include "globals.hpp"


// отступы от края окна в px
#define MARGIN 10


//Кнопки калькулятора
namespace CalcButtons
{
    const char AC           = 'A';
    const char BACKSPACE    = 'B';
    const char SIN	        = 'S';
    const char COS			= 'C';
    const char TG			= 'T';
    const char ANSWER       = 'a';
	const char ROOT			= 'R';

	const unsigned button_cols	= 8;
	const unsigned button_rows	= 4;

	unsigned ButtonsHeight = 20;
	unsigned ButtonsWidth = 1 / button_cols - MARGIN;

	

	void DefineButtons()
	{
		KolibriLib::point size = globals::window.GetSize();

		for(unsigned i = 0; i < button_cols * button_rows; i++)
		{
			globals::window.CreateButton({}, {ButtonsWidth, ButtonsHeight}, std::string());
		}
	}

}



#endif // __UI_H__
