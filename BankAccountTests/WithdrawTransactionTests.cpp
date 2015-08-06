#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "WithdrawTransaction.h"
#include <BankAccount.h>

TEST(WithdrawTransactionTests, GivenNoRules_WhenIExecuteAWithdrawTransaction_TheAccountShouldBeDebited)
{
    // Given
    auto initialBalance = 1000;
    std::shared_ptr<BankAccount> account(new BankAccount(CurrentAccount));
    account->SetBalance(initialBalance);

    // When
    std::unique_ptr<WithdrawTransaction> withdrawFromAccount(new WithdrawTransaction(account));
    withdrawFromAccount->Execute(600);

    // Then
    ASSERT_LT(account->GetBalance(), initialBalance);
}