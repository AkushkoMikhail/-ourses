#include <iostream>
#include <vector>

#include "CalculatorUtils.h"

void DisplayTutorialByMode(int mode)
{
	std::string simpleTutorial = "example (2+2+2)  \noperators (/ , + , - , * , ^) \nStart!!!";
	std::string EngineerModeTutorial = "\n 0=x2 ; 1= 1/x; 2=sqrt; 3=10^x; 4=Log; 5=In; 6=|x|; 7=!n \n Select button";
	std::string tutorial = mode == 1 ? simpleTutorial : EngineerModeTutorial;
	std::cout << tutorial << "\n";
}

int main()
{
	int selectMode = 0;
	int selectButton = 0;
	std::string input = "";
	std::cout << "Select mode" << "\n";
	std::cout << "0 Exit \n" << "1 (arithmetic operations) \n" << "2 (engineer operations) \n\n";

	std::cin >> selectMode;


	if (selectMode <= 0 || selectMode > 2)
		std::cout << "Exit" << "\n";
	else
	{
		if (selectMode == 2)
			std::cin >> selectButton;

		DisplayTutorialByMode(selectMode);
		std::cout << "Enter value" << "\n";
		std::cin >> input;
		std::cout << "Result = " << GetResult(input, selectMode, selectButton) << "\n";
	}

	return 0;
}
