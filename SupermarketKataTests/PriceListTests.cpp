#include "stdafx.h"
#include "PriceListTests.h"
#include "..\SupermarketKata\PriceList.h"

void PriceListTests::PriceOfTinOfBeansIs40p()
{
	// Arrange
	PriceList priceList;

	// Act
	auto price = priceList["TinOfBeans"];

	// Assert
	CPPUNIT_ASSERT(price == 40);
}

void PriceListTests::PriceOfTinOfSoupIs90p()
{
	// Arrange
	PriceList priceList;

	// Act
	auto price = priceList["TinOfSoup"];

	// Assert
	CPPUNIT_ASSERT(price == 90);
}

CPPUNIT_TEST_SUITE_REGISTRATION(PriceListTests);
