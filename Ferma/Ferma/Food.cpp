#include "Food.h"

#include <iostream>


Food::Food(const FoodType type, const double amount) :_type(type), _amount(amount)
{

}

const Food::FoodType& Food::GetFoodType()
{
	return  _type;
}

double& Food::GetFoodAmount()
{
	return _amount;
}

void Food::UpdateValue(const double& value)
{
	_amount -= value;
}

void Food::ViewFoodType()
{
	std::cout  << " FoodAmount = " << _amount << "\n";
}

