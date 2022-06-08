#include <vector>
#include <random>
#include <algorithm>
#include <array>
#include <iostream>

void RandomValues(std::array<int, 100 >& values)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(-25, 25);
	for (int a = 0; a < values.size(); a = a + 1)
	{
		values[a] = (distrib(gen));
	}
}
void DisplayValues(std::vector<int>& evenNumbers,std::string header)
{
	std::cout << "-------------"<< header << "-----------------------------" << "\n";
	for (auto val : evenNumbers)
		std::cout << val<< " ";
	std::cout  << "\n";
}

void DisplayValues(std::array<int, 100 > values,std::string header)
{
	std::cout << "-------------"<< header << "-----------------------------" << "\n";
	for (auto val : values)
		std::cout << val << " ";
	std::cout << "\n";
}
void EvenNumber(std::array<int, 100 >values,std::vector<int>& eventValues)
{

	for ( int a = 0; a <values.size(); a = a + 1)
	{
		if (values[a] % 2 != 0)
			continue;
		eventValues.push_back(values[a]);
	}
}

void DivisionNumbers(std::vector<int>& evenNumbers)
{
	int lastvalue = static_cast<int>(evenNumbers.size() - 1);
	for (size_t index = 0; index < evenNumbers.size(); index++)
	{
		if (index == lastvalue || lastvalue < index)
			break;

		int firsvalue = evenNumbers[index];
		int secondvalue = evenNumbers[lastvalue];
		if (firsvalue == 0 || secondvalue == 0)
		{
			lastvalue--;
			continue;
		}

		evenNumbers[lastvalue] = secondvalue % firsvalue;
		evenNumbers[index] = firsvalue % secondvalue;
		lastvalue--;
	}
}

void RemoveValues(std::vector<int>& evenNumbers)
{

	evenNumbers.erase(std::remove_if(
		evenNumbers.begin(), evenNumbers.end(),
		[](const int& x) {
			return x % 4 == 0; // put your condition here
		}), evenNumbers.end());
}

int main()
{
	std::array<int, 100> _randomValues{};
	std::vector<int> evenNumbers;
	//----------------------
	RandomValues(_randomValues);
	DisplayValues(_randomValues,"Random Value");
	//----------------------
	EvenNumber(_randomValues, evenNumbers);
	DisplayValues(evenNumbers,"Even Numbers");
	//----------------------
	DivisionNumbers(evenNumbers);
	DisplayValues(evenNumbers,"Division Numbers");
	//----------------------
	RemoveValues(evenNumbers);
	DisplayValues(evenNumbers, "Remove Values");

	std::vector<int>::iterator min = std::min_element(std::begin(evenNumbers), std::end(evenNumbers));
	std::vector<int>::iterator max = std::max_element(std::begin(evenNumbers), std::end(evenNumbers));

	std::cout << "-------------MinMax-----------------------------" << "\n";
	std::cout << "min = " << min[0]<<"\n";
	std::cout << "max = " << max[0] << "\n";
	return 0;
}


