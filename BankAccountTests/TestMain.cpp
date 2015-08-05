#include "stdafx.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <gmock/gmock.h>


void SetUpGoogleMockToWorkWithCppUnit(int argc, char** argv)
{
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);
}

template<typename FormatterT>
void SetOutputter(CppUnit::TextUi::TestRunner& runner)
{
    auto outputter = new FormatterT(&runner.result(), std::cerr);
    runner.setOutputter(outputter);
}

void AddRegisteredTests(CppUnit::TextUi::TestRunner& runner)
{
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    runner.addTest(suite);
}

int main(int argc, char* argv[])
{
    SetUpGoogleMockToWorkWithCppUnit(argc, argv);

    CppUnit::TextUi::TestRunner runner;
    AddRegisteredTests(runner);
    SetOutputter<CppUnit::CompilerOutputter>(runner);

	return runner.run() ? 0 : 1;
}