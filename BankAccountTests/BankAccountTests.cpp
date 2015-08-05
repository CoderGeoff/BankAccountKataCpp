#include "stdafx.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BankAccount.h"
#include <memory>
#include <AccountType.h>

using ::testing::A;
using ::testing::An;
using ::testing::AtLeast;
using ::testing::Return;


TEST(BankAccountTests, GivenANewBankAccount_BalanceShouldBe$0)
{
    BankAccount account(CurrentAccount);
    ASSERT_EQ(0, account.GetBalance());
}

TEST(BankAccountTests, GivenABankAccountWith$10_BalanceShouldBe$10)
{
    BankAccount account(CurrentAccount, 1000);
    ASSERT_EQ(1000, account.GetBalance());
}

TEST(BankAccountTests, GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10)
{
    BankAccount account(CurrentAccount);
    account.Deposit(1000);
    ASSERT_EQ(1000, account.GetBalance());
}

TEST(BankAccountTests, GivenABankAccountWith$10_WhenIWithdraw$6_BalanceShouldBe$4)
{
    // Given
    BankAccount account(CurrentAccount, 1000);

    // When
    account.Withdraw(600);

    // Then
    ASSERT_EQ(400, account.GetBalance());
}

TEST(BankAccountTests, GivenASavingBankAccount_ItsTypeShouldBeSavings)
{
    // Given
    BankAccount account(SavingsAccount);

    // Then
    ASSERT_EQ(SavingsAccount, account.GetType());
}
