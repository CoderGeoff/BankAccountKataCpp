#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "WithdrawTransaction.h"
#include <BankAccount.h>

TEST(WithdrawTransactionTests,     GivenABankAccountWith$10_WhenIRunATransactionToWithdraw$6_BalanceShouldBe$4)
{
    // Given
    std::shared_ptr<BankAccount> account(new BankAccount(1000));

    // When
    std::unique_ptr<WithdrawTransaction> withdrawFromAccount(new WithdrawTransaction(account));
    withdrawFromAccount->Execute(600);

    // Then
    ASSERT_EQ(400, account->GetBalance());
}