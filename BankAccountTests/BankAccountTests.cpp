#include "stdafx.h"

#include <gtest/gtest.h>
#include "BankAccount.h"
#include <memory>
#include <AccountType.h>

TEST(BankAccountTests, GivenANewBankAccount_BalanceShouldBe$0)
{
    BankAccount account(CurrentAccount);
    ASSERT_EQ(0, account.GetBalance());
}

TEST(BankAccountTests, WhenISetTheBalanceTo$1_ThenBalanceShouldBe$1)
{
    BankAccount account(CurrentAccount);
    account.SetBalance(100);
    ASSERT_EQ(100, account.GetBalance());
}

TEST(BankAccountTests, WhenISetTheBalanceTo$Minus1_ThenBalanceShouldBe$Minus1)
{
    BankAccount account(CurrentAccount);
    account.SetBalance(-100);
    ASSERT_EQ(-100, account.GetBalance());
}

TEST(BankAccountTests, WhenISetTheBalanceTo$0_ThenBalanceShouldBe$0)
{
    BankAccount account(CurrentAccount);
    account.SetBalance(0);
    ASSERT_EQ(0, account.GetBalance());
}

TEST(BankAccountTests, GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10)
{
    BankAccount account(CurrentAccount);
    account.Deposit(1000);
    ASSERT_EQ(1000, account.GetBalance());
}

TEST(BankAccountTests, GivenASavingBankAccount_ItsTypeShouldBeSavings)
{
    // Given
    BankAccount account(SavingsAccount);

    // Then
    ASSERT_EQ(SavingsAccount, account.GetType());
}
