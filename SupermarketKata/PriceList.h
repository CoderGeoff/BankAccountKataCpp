#pragma once
#include <string>
#include <map>

class PriceList
{
public:
	PriceList();
	~PriceList() {};

	const std::string TinOfBeans() const { return std::string("TinOfBeans"); };

	int operator [](const std::string& item);


private:
	std::map<std::string, int> m_Prices;
};

