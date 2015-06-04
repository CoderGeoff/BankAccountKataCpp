#pragma once
#include <string>
#include <map>
#include "Exports.h"

class LIBRARY_API PriceList
{
public:
	PriceList();
	~PriceList() {};
	int operator [](const std::string& item);

private:
	std::map<std::string, int> m_Prices;
};

