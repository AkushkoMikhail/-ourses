#pragma once


/**
 * \����� ��������
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
