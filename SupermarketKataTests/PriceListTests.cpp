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
	CPPUNIT_ASSERT_EQUAL(40, price);
}

void PriceListTests::PriceOfTinOfSoupIs90p()
{
	// Arrange
	PriceList priceList;

	// Act
	auto price = priceList["TinOfSoup"];

	// Assert
	CPPUNIT_ASSERT_EQUAL(90, price);
}

void PriceListTests::PriceOfTinOfPeachesIs55p()
{
	// Arrange
	PriceList priceList;

	// Act
	auto price = priceList["TinOfPeaches"];

	// Assert
	CPPUNIT_ASSERT_EQUAL(55, price);
}


CPPUNIT_TEST_SUITE_REGISTRATION(PriceListTests);
