#pragma once
class Food
{
public:
	enum class FoodType {
		Hay, Corn, vegetables
	};
	Food(const FoodType type, const double amount);
	const FoodType& GetFoodType();
	double& GetFoodAmount();
	void UpdateValue(const double&);
	void ViewFoodType();
private:
	FoodType _type;
	double _amount;
};
