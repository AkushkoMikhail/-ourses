
#include <algorithm>
#include <iostream>
#include <vector>


int SelectByMaxConst(int& maxIndexFirst, int& maxIndexSecond)
{
	int select = 0;
	std::cout << "Select Goods by max cost" << "\n";
	std::cout << "0 or 1" << "\n";
	std::cin >> select;
	return  select == 0 ? maxIndexFirst : maxIndexSecond;
}

int findIndex(const std::vector<double>& arr, double item) {

	for (auto i = 0; i < arr.size(); ++i) {
		if (arr[i] == item)
			return i;
	}

	return -1;
}


void ViewCost(const std::vector<double>& categoryPrice)
{
	double allCost = 0;
	for (size_t i = 0; i < categoryPrice.size(); i++)
	{
		allCost += categoryPrice[i];

	}
	std::cout << "cost = " << allCost << "\n";
}



void —ategorize(const std::vector<double>& _goods, std::vector<double>& categoryPrice)
{
	for (size_t i = 0; i < _goods.size(); i++)
	{
		if (_goods[i] == 0)
			continue;
		if ((i >= 0 && i < 2) || i == 9) //  ÏÛ˜Ì˚Â
		{
			categoryPrice[0] += _goods[i];
		}
		else if (i >= 2 && i < 6) // ÏÓÎÓ˜Ì˚Â ÚÓ‚‡˚
		{
			categoryPrice[1] += _goods[i];
		}
		else // ‰
		{
			categoryPrice[i] = _goods[i];
		}

	}
	categoryPrice.erase(
		std::remove(categoryPrice.begin(), categoryPrice.end(), 0),
		categoryPrice.end());
}



void Discount—alculation(const std::vector<double>& _goods, std::vector<double>& categoryPrice)
{
	int selectIndex = 0;
	double max = *std::max_element(std::begin(categoryPrice), std::end(categoryPrice));
	int maxIndexFirst = findIndex(categoryPrice, max);

	std::vector<double> categoryPrice2(categoryPrice);
	categoryPrice2.erase(categoryPrice2.begin() + maxIndexFirst);
	double max2 = *std::max_element(std::begin(categoryPrice2), std::end(categoryPrice2));
	int maxIndexSecond = findIndex(categoryPrice2, max2);


	selectIndex = maxIndexFirst;

	if(max== max2)
	{
		selectIndex=	SelectByMaxConst(maxIndexFirst, maxIndexSecond);
	}
	for (size_t i = 0; i < categoryPrice.size(); i++)
	{
		if (i == selectIndex)
		{
			categoryPrice[i] = categoryPrice[i] - categoryPrice[i] / 100 * 50;
		}
		else if (i == 0) //  ÏÛ˜Ì˚Â
		{
			categoryPrice[i] = categoryPrice[i] - categoryPrice[i] / 100 * 24;
		}
		else if (i == 1) // ÏÓÎÓ˜Ì˚Â ÚÓ‚‡˚
		{
			categoryPrice[i] = categoryPrice[i] - categoryPrice[i] / 100 * 33;
		}

	}

}



void —ost—alculation(std::vector<double>& _goods, const std::vector<double>& price)
{
	for (size_t i = 0; i < _goods.size(); i++)
	{
		_goods[i] *= price[i];
	}

}



int main()
{
	int indexGoods;


	std::vector<double> categoryPrice = { 0,0,0,0,0,0,0,0,0,0 };
	std::vector<double> _goods = { 0,0,0,0,0,0,0,0,0,0 };
	std::vector<double> price = { 0.9, 1.1, 1.3, 3.6, 1.8, 16, 3, 2.5, 2.05, 1.29 };


	std::cout << "Input goods by index:" << "\n" << "bread(0), white bread(1), milk(2), oil(3), sour cream(4), meat(5), orange(6), apple(7), sugar(8), pasta(9)" << "\n";
	std::cout << "any number -1 || number > 9  = exit" << "\n";
	while (std::cin >> indexGoods && indexGoods < price.size() && indexGoods >= 0)
	{
		_goods[indexGoods] += 1;
	}
	—ost—alculation(_goods, price);
	—ategorize(_goods, categoryPrice);
	Discount—alculation(_goods, categoryPrice);
	ViewCost(categoryPrice);
	return 0;
}
