#include "stdafx.h"
#include "PriceList.h"


PriceList::PriceList()
{
	m_Prices[TinOfBeans()] = 40;
}


int PriceList::operator [](const std::string& item)
{
	return m_Prices[item];
}
