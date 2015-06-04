#include "stdafx.h"
#include "PriceListTests.h"
#include "..\SupermarketKata\PriceList.h"

void PriceListTests::PriceOfTinOfBeansIs40p()
{
	// Arrange
	PriceList priceList;

	// Act
	auto priceOfTinOfBeans = priceList["TinOfBeans"];

	// Assert
	CPPUNIT_ASSERT(priceOfTinOfBeans == 40);
}
CPPUNIT_TEST_SUITE_REGISTRATION(PriceListTests);
