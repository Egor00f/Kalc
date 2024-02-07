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
	const std::string AC		= "A";
	const std::string BACKSPACE	= "<-";
	const std::string SIN		= "sin";
	const std::string COS		= "cos";
	const std::string TG		= "tg";
	const std::string LOG		= "log";
	const std::string Ln		= "ln";
	const std::string ANSWER	= "ans";
	const std::string ROOT		= "root";
	const std::string MODE		= "Mode";

	const unsigned button_cols	= 8;
	const unsigned button_rows	= 4;

	unsigned ButtonsHeight = 20;
	unsigned ButtonsWidth = 1 / button_cols - MARGIN;

	const std::string buttons[button_rows * button_cols] = {
		SIN, COS, "7", "8", "9", AC,     BACKSPACE,
		TG,       "4", "5", "6", "+",   "-",
		LOG, Ln,  "1", "2", "3", "*",    "/"
		"(", ")", ",", "0", "%", ANSWER, "="
	};

	std::vector<unsigned> DefineButtons()
	{
		std::vector<unsigned> r;
		KolibriLib::point size = globals::window.GetSize();

		for(int i = 0; i < button_rows; i++)
		{
			for(int j = 0; j < button_cols; i++)
			{
				r.push_back(globals::window.CreateButton(
					{(int)KolibriLib::UI::DefaultMargin*(j+1) + (int)ButtonsWidth * (j+1), (int)size.y / 4 + (int)KolibriLib::UI::DefaultMargin*(i+1) + (int)ButtonsWidth * (i+1)},
					{ButtonsWidth, ButtonsHeight},
					buttons[i]
				));
			}
		}
		return r;
	}
	
}



#endif // __UI_H__
