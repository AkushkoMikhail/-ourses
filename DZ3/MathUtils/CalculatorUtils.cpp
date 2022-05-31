#include "CalculatorUtils.h"

bool IsOperatorValue(std::string value)
{
	return value == "/" ||
		value == "*" ||
		value == "-" ||
		value == "+" || value == "=" || value == "^";

}

double GetResult(std::string value, int mode, int selectButton)
{
	if (mode == 1)
		return 	SimpleMode(ParseInput(value));

	return  EngineerMode(ParseInput(value), selectButton);
}

double SimpleMode(std::vector<std::string> value)
{
	double result = 0;
	double currentValue = 0;
	std::string Operator = "";
	for (int i = 0; i < value.size(); i++)
	{
		if (!IsOperatorValue(value[i]))
		{
			currentValue = std::stod(value[i]);
		}
		else
		{
			Operator = value[i];
			continue;
		}

		if (Operator == "/")
		{
			result /= currentValue;
		}
		else if (Operator == "*")
		{
			result *= currentValue;
		}
		else if (Operator == "-")
		{
			result -= currentValue;
		}
		else if (Operator == "+")
		{
			result += currentValue;
		}
		else if (Operator == "^")
		{
			return  pow(result, currentValue);
		}
		else if (Operator == "=")
		{
			return result;
		}
		else
		{
			result = currentValue;
		}

	}

	return result;
}

double EngineerMode(std::vector<std::string> value, int selectButton)
{
	double stod = std::stod(value[0]);
	double result = 1;
	switch (selectButton)
	{
	case 0:
		return stod * stod;//x2
	case 1:
		return  1 / stod; // 1/x
	case 2:
		return sqrt(stod); 
	case 3:
		return pow(10, stod);// 10^x
	case 4:
		return log10(stod);//Log
	case 5:
		return log(stod); // In
	case 6:
		return abs(stod); // |x|;
	case 7:
		for (int i = 1; i <= stod; i++) // !n
		{
			result *= i;
		}
		return result;
	default:
		return 0.0;
	}
}

std::vector<std::string> ParseInput(std::string value)
{
	std::vector<std::string> input;
	std::string number = "";
	std::string Operator = "";
	for (int i = 0; i < value.size(); i++)
	{
		if (isdigit(value[i]) || value[i] == '.' || value[i] == ',' || (value[i] == '-' && i ==0))
		{
			number += value[i];
			if (i == value.size() - 1)
				input.push_back(number);
		}
		else
		{
			if (!number.empty())
				input.push_back(number);
			number = "";

			Operator = value[i];

			if (!Operator.empty())
				input.push_back(Operator);

			Operator = "";
		}

	}
	return input;
}

