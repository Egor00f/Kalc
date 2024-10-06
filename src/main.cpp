#include <vector>

#include <KolibriLib.hpp>

#include <tinyexpr.h>

const std::string ProgrammName = "Kalc";

struct buttonCharacter
{
	buttonCharacter() = default;
	buttonCharacter(const std::string &c) : front(c), back(c){}
	buttonCharacter(const std::string &c, const std::string &t) : front(c), back(t){}

	std::string front;
	std::string back;
};

const std::string BACKSPACE = "BACKSPACE";

std::vector<std::vector<buttonCharacter>> buttonsChar = {
	{buttonCharacter("sin", "sin("), buttonCharacter("cos", "cos("), buttonCharacter("tan", "tan("), buttonCharacter("|", "abs("), buttonCharacter("<-", BACKSPACE)},
	{buttonCharacter("1"), buttonCharacter("2"), buttonCharacter("3"), buttonCharacter("+"), buttonCharacter("-"), buttonCharacter("("), buttonCharacter(")")},
	{buttonCharacter("4"), buttonCharacter("5"), buttonCharacter("6"), buttonCharacter("/"), buttonCharacter("*"), buttonCharacter("^"), buttonCharacter("s", "sqrt(")},
	{buttonCharacter("7"), buttonCharacter("8"), buttonCharacter("9"), buttonCharacter("."), buttonCharacter("%"), buttonCharacter("!"), buttonCharacter("=")}};

KolibriLib::TextLabel *display;

// то что ввёл пользователь
std::string Input;

/*
	Окно программы
	т.к. программа небольшая и больше одного потока тут не планируется этот объект можно объявить глобально
*/
KolibriLib::Window wnd(ProgrammName);

void onInput(const std::string &inputedChar)
{
	static bool calculated = false;

	if(calculated)
	{
		Input = "";
		calculated = false;
	}

	if (inputedChar == "=")
	{
		int error;

		char buff[32];

		std::sprintf(buff, "%f", te_interp(Input.c_str(), &error));

		if(error)
		{
			Input = buff;
		}
		else
		{

		}

		calculated = true;
		
	}
	else if(inputedChar == BACKSPACE && Input.size() > 0)
	{
		Input.pop_back();
	}
	else
	{
		Input += inputedChar;
	}

	display->SetText(Input);

	wnd.Render();
}

int main()
{
	KolibriLib::keyboard::SetInputMode(KolibriLib::keyboard::InputMode::SCANCODES);

	// Окошко в котором будет всё выводиться
	display = wnd.AddElement(
		KolibriLib::TextLabel(
			KolibriLib::UDim(0.1f, 0.086f),
			KolibriLib::UDim(0.8f, 0.3f), "0"));
	display->SetAling(KolibriLib::TextLabel::Align::Right);

	// Облать для конопок
	KolibriLib::UIElement *frameArea = wnd.AddElement(
		KolibriLib::UIElement(
			KolibriLib::UDim(0.05f, 0.3f),
			KolibriLib::UDim(1.0f, 0.6f),
			KolibriLib::Globals::SystemColors.work_area));

	std::vector<KolibriLib::TextButton *> buttons;

	

	for (std::size_t i = 0; i < buttonsChar.size(); i++)
	{
		buttons.reserve(buttons.size() + buttonsChar[i].size());

		for (std::size_t j = 0; j < buttonsChar[i].size(); j++)
		{

			KolibriLib::UDim butttonSize (
				1.0f / static_cast<float>(buttonsChar[i].size()), 
				1.0f / static_cast<float>(buttonsChar.size()) );

			KolibriLib::TextButton button = KolibriLib::TextButton (
				buttonsChar[i][j].front,
				KolibriLib::UDim(butttonSize.X.Scale * static_cast<float>(j), butttonSize.Y.Scale * static_cast<float>(i)),
				butttonSize);
			
			button.SetId();
			button.SetParent(frameArea);

			buttons.push_back(wnd.AddElement(button));
		}
	}

	wnd.Render();

	KolibriLib::PrintDebug(display);
	

	bool Exit = false;
	while (!Exit)
	{
		switch (wnd.Handler())
		{
		case KolibriLib::Event::Exit:
			Exit = true;
			break;

		case KolibriLib::Event::Button:

			for (auto i : buttons)
			{
				if (wnd.GetPressedButton() == i->GetId())
				{
					for (std::size_t j = 0; j < buttonsChar.size(); j++)
					{
						for (std::size_t k = 0; j < buttonsChar[k].size(); k++)
						{
							if(i->GetText() == buttonsChar[j][k].front)
							{
								onInput(buttonsChar[j][k].back);
							}
							break;
						}
					}
					break;
				}
			}
			break;

		case KolibriLib::Event::Key:

			KolibriLib::Scancode inputChar = KolibriLib::CheckKeyboard().scancode;

			KolibriLib::PrintDebug("\nInput Scancode:");
			KolibriLib::PrintDebug(inputChar);
			KolibriLib::PrintDebug(" ( char: ");
			KolibriLib::PrintDebug(inputChar.operator char());
			KolibriLib::PrintDebug(")\n");

			if(inputChar == KolibriLib::Scancode(KolibriLib::keyboard::Scancodes::BACKSPACE))
			{
				KolibriLib::PrintDebug("delete");
			 	onInput(BACKSPACE);
			 	break;
			}

			for(std::size_t i = 0; i < buttonsChar.size(); i++)
			{
				for(std::size_t j = 0; j < buttonsChar[i].size(); i++)
				{
					std::string input(1, static_cast<char>(inputChar));
					if (input == buttonsChar[i][j].front)
					{
						KolibriLib::PrintDebug("\nFound");
						onInput(buttonsChar[i][j].back);
						break;
					}
				}
			}

			break;
		};
	}

	return 0;
}
