#pragma once
#include <string>
#include "Food.h"

struct Animals
{
public:
	Animals(const std::string animalsView,
		const double animalsFood, const Food::FoodType foodType)
		:_animalsView(animalsView),
		_animalsFood(animalsFood),
		_foodType(foodType) {};

	virtual ~Animals() = default;

	virtual void Eat(Food* feedCount) = 0;

	const	std::string& GetAnimalsView() const
	{
		return _animalsView;
	}
	const Food::FoodType& GetFoodType() 
	{
		return _foodType;
	}
protected:
	std::string _animalsView;
	double _animalsFood;
	Food::FoodType _foodType;
};
