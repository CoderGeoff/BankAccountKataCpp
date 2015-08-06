#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "DepositTransaction.h"
#include <BankAccount.h>

TEST(DepositTransactionTests, GivenAnAccountWith$1AndNoRules_WhenIDeposit$1_ThenBalanceShouldBe$2)
{
    // Given
    std::shared_ptr<BankAccount> account(new BankAccount(CurrentAccount));
    account->SetBalance(100);

    // When
    std::unique_ptr<DepositTransaction> depositInAccount(new DepositTransaction(account));
    depositInAccount->Execute(100);

    // Then
    ASSERT_EQ(200, account->GetBalance());
}