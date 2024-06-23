#include <vector>
#include <sstream>

#include <KolibriLib.hpp>
#include <tinyexpr.h>

#include "configuration.hpp"




KolibriLib::Window::ElementNumber IO_TextLabel;

void Update(KolibriLib::Window *wnd, std::string *Input, const char &newchar)
{


	KolibriLib::TextLabel tmp(*(KolibriLib::TextLabel*)wnd->GetElement(IO_TextLabel));

	if (newchar == '=')
	{
		
		int error;
		double output = te_interp(Input->c_str(), &error);
		std::ostringstream strs;
		strs << output;
		*Input = strs.str();
	}
	else
	{
		Input->push_back(newchar);
	}

	tmp.SetText(*Input);
	wnd->SetElement(IO_TextLabel, tmp);
}

int main() 
{
	KolibriLib::init();

	KolibriLib::Window wnd(ProgrammName);

	IO_TextLabel = wnd.AddElement(KolibriLib::TextLabel(KolibriLib::UDim(0.1, 0, 0.086, 0), KolibriLib::UDim(0.8, 0, 0.3, 0), "0"));

	std::vector<KolibriLib::Window::ElementNumber> buttonsId;

	const std::vector<char> buttonsChar = {
		'1', '2', '3', '+', '-', '(', ')',
		'4', '5', '6', '/', '*', '^', 's',
		'7', '8', '9', '.', '%', '!', '='
	};

	std::vector<KolibriLib::Button> buttons;

	for(auto i : buttonsChar)
	{
		KolibriLib::Button btn;

		char *b = new char[2];
		b[0] = i;
		b[1] = '\0';
		btn.SetText(std::string(b));
		delete b;

		buttonsId.push_back(wnd.AddElement(btn));
		buttons.push_back(btn);
	}

	// то что ввёл пользователь
	std::string Input;

	

	bool Exit = false;
	while(!Exit)
	{
		KolibriLib::Event event = wnd.Handler();

		switch(event)
		{
			case KolibriLib::Event::Button:
				KolibriLib::Button* btn = (KolibriLib::Button*)wnd.GetElement(wnd.GetPressedButton());

				for(auto i : buttons)
				{
					if(*btn == i)
					{
						Update(&wnd, &Input, i.GetText()[0]);	//берём нулевой символ т.к. текст в кнопках должен быть таким, один char и \0
					}
				}

				break;
			case KolibriLib::Event::Key:

				char pressed = KolibriLib::keyboard::CheckKeyboard();
				for(auto i : buttonsChar)
				{
					if(pressed == i)
					{
						Update(&wnd, &Input, pressed);
					}
				}

				break;
		};

	}

	return 0;
}
