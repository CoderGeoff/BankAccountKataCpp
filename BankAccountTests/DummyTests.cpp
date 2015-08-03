#include "stdafx.h"

#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "BankAccount.h"

TEST_FIXTURE(BankAccountTests, 
    GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10,
    GivenABankAccountWith$10_WhenIWithdraw$6_BalanceShouldBe$4);

void BankAccountTests::GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10()
{
    BankAccount account;
    account.Deposit(1000);
    CPPUNIT_ASSERT_EQUAL(1000, account.GetBalance());
}

void BankAccountTests::GivenABankAccountWith$10_WhenIWithdraw$6_BalanceShouldBe$4()
{
    // Given
    BankAccount account;
    account.Deposit(1000);

    // When
    account.Withdraw(600);

    // Then
    CPPUNIT_ASSERT_EQUAL(400, account.GetBalance());
}
