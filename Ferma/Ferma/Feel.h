#pragma once


/**
 * \класс ощущений
 */
class Feel
{
public:
	Feel() = default;
	bool IsHunger(const double& feedCount, const double& animalsFood);
	const double& GetHunger();

private:
	double hunger;
};
