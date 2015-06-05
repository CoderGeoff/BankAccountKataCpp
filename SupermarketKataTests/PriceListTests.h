#pragma once
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#define EXPAND( x ) x

#define FOR_EACH_1(what, x, ...) what(x)
#define FOR_EACH_2(what, x, ...) what(x) EXPAND(FOR_EACH_1(what, __VA_ARGS__))
#define FOR_EACH_3(what, x, ...) what(x) EXPAND(FOR_EACH_2(what, __VA_ARGS__))
#define FOR_EACH_4(what, x, ...) what(x) EXPAND(FOR_EACH_3(what, __VA_ARGS__))
#define FOR_EACH_5(what, x, ...) what(x) EXPAND(FOR_EACH_4(what, __VA_ARGS__))
#define FOR_EACH_6(what, x, ...) what(x) EXPAND(FOR_EACH_5(what, __VA_ARGS__))
#define FOR_EACH_7(what, x, ...) what(x) EXPAND(FOR_EACH_6(what, __VA_ARGS__))
#define FOR_EACH_8(what, x, ...) what(x) EXPAND(FOR_EACH_7(what, __VA_ARGS__))


#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME 
#define FOR_EACH(action,...) EXPAND(GET_MACRO(__VA_ARGS__, FOR_EACH_5,FOR_EACH_4,FOR_EACH_3,FOR_EACH_2,FOR_EACH_1)(action, __VA_ARGS__))

#define SIMPLE(name) simple(name)
#define REGISTER_TEST(name) CPPUNIT_TEST(name);
#define REGISTER_TESTS(...) FOR_EACH(REGISTER_TEST, __VA_ARGS__)
#define DECLARE_TEST(name) void name();
#define DECLARE_TESTS(...) FOR_EACH(DECLARE_TEST, __VA_ARGS__)

#define TEST_FIXTURE(name, ...)\
class name : public CppUnit::TestFixture {\
	CPPUNIT_TEST_SUITE(name);\
	REGISTER_TESTS(__VA_ARGS__);\
	CPPUNIT_TEST_SUITE_END();\
public:\
	DECLARE_TESTS(__VA_ARGS__);\
};

TEST_FIXTURE(MyTest, a, b, c, d, e);

class PriceListTests: public CppUnit::TestFixture
{

public:
	CPPUNIT_TEST_SUITE(PriceListTests);
	CPPUNIT_TEST(PriceOfTinOfBeansIs40p);
	CPPUNIT_TEST(PriceOfTinOfSoupIs90p);
	CPPUNIT_TEST(PriceOfTinOfPeachesIs55p);
	CPPUNIT_TEST(PriceOfColeslaw);
	CPPUNIT_TEST_SUITE_END();

	void PriceOfTinOfBeansIs40p();
	void PriceOfTinOfSoupIs90p();
	void PriceOfTinOfPeachesIs55p();
	void PriceOfColeslaw();
};