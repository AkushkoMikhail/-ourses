#include "Feel.h"

#include <cmath>

bool Feel::IsHunger(const double& feedCount, const double& animalsFood)
{
	hunger = feedCount - animalsFood;
	return  hunger > 0;
}

const double& Feel::GetHunger()
{
	return abs(hunger);
}

