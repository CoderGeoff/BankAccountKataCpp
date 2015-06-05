#pragma once
#include <string>
#include <map>

class PriceList
{
public:
	PriceList();
	~PriceList() {};
	int operator [](const std::string& item);

private:
	std::map<std::string, int> m_Prices;
};

