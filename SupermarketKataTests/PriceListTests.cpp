#include "stdafx.h"
#include "PriceListTests.h"

void PriceListTests::PriceOfTinOfBeansIs40p()
{
	int x = 5;
	CPPUNIT_ASSERT(x == 4);
}
CPPUNIT_TEST_SUITE_REGISTRATION(PriceListTests);
