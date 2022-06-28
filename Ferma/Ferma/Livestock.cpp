#include "Livestock.h"
#include <iostream>


Livestock::Livestock(const std::string animalsView,
	const double animalsFood,
	const std::string joysound,
	const Food::FoodType foodType):
	Emotions(joysound), Animals(animalsView, animalsFood, foodType), _feel()
{
}

void Livestock::Eat(Food* food)
{
	if (_feel.IsHunger(food->GetFoodAmount(), _animalsFood))
	{
		std:: cout << GetAnimalsView() << " " << _animalsFood << "\n";
		 Joy();
		 food->UpdateValue(_animalsFood);
	}
	else
	{
		Sadness();
		std:: cout << GetAnimalsView() << " " << _feel.GetHunger() << "\n";
		
	}
}


