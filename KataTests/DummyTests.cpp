#include "stdafx.h"

#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../Kata/BankAccount.h"

TEST_FIXTURE(BankAccountTests, GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10);

void BankAccountTests::GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10()
{
    BankAccount account;
    account.Deposit(1000);
    CPPUNIT_ASSERT_EQUAL(1000, account.GetBalance());
}