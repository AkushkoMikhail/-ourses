

#include <iostream>
#include <vector>

#include "Livestock.h"

void StartOfFeeding(std::vector<Livestock*>& _livestock, std::vector<Food*>& foods)
{
	for (auto food : foods)
	{
		for (auto animal : _livestock)
		{
			if (food->GetFoodType() == animal->GetFoodType())
			{
				std::cout << "--------------------------------------" << "\n";
				food->ViewFoodType();
				animal->Eat(food);
				food->ViewFoodType();
				std::cout << "--------------------------------------" << "\n";
			}
		}
	}
}



int main()
{
	std::vector<Livestock*> _livestock;
	std::vector<Food*> foods;

	Food Corn(Food::FoodType::Corn, 100);
	Food Hay(Food::FoodType::Hay, 100);
	Food vegetables(Food::FoodType::vegetables, 100);

	Livestock chicken("chiken", 10, "Ko-ko-ko", Food::FoodType::Corn);
	Livestock cow("cow", 35, "My-my-my", Food::FoodType::Hay);
	Livestock pig("pig", 20, "Xry-xry", Food::FoodType::vegetables);


	foods.push_back(&Corn);
	foods.push_back(&Hay);
	foods.push_back(&vegetables);
	_livestock.push_back(&chicken);
	_livestock.push_back(&cow);
	_livestock.push_back(&pig);


	std::cout << "-------------------StartOfFeeding-------------------" << "\n";
	StartOfFeeding(_livestock, foods);

	std::cout << "-------------------StartOfFeeding-------------------" << "\n";
	StartOfFeeding(_livestock, foods);

	std::cout << "-------------------StartOfFeeding-------------------" << "\n";
	StartOfFeeding(_livestock, foods);

	std::cout << "-------------------StartOfFeeding-------------------" << "\n";
	StartOfFeeding(_livestock, foods);



	return 0;
}
