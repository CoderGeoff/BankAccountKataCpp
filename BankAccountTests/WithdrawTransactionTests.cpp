#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "WithdrawTransaction.h"
#include <BankAccount.h>

TEST(WithdrawTransactionTests, GivenAnAccountWith$10AndNoRules_WhenIWithdraw$6_ThenBalanceShouldBe$4)
{
    // Given
    std::shared_ptr<BankAccount> account(new BankAccount(CurrentAccount));
    account->SetBalance(1000);

    // When
    std::unique_ptr<WithdrawTransaction> withdrawFromAccount(new WithdrawTransaction(account));
    withdrawFromAccount->Execute(600);

    // Then
    ASSERT_EQ(400, account->GetBalance());
}