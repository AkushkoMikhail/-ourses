#pragma once
#include "Animals.h"
#include "Emotions.h"
#include "Feel.h"

class  Livestock : private Emotions, public  Animals
{
public:
	Livestock(const std::string animalsView,
		const double animalsFood, const std::string joysound,
		const Food::FoodType foodType);

	void Eat(Food* food) override;

private:
	Feel _feel;
};
