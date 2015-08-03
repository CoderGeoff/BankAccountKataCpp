#include "stdafx.h"
#include <memory>

#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "WithdrawTransaction.h"
#include <BankAccount.h>

TEST_FIXTURE(WithdrawTransactionTests,
    GivenABankAccountWith$10_WhenIRunATransactionToWithdraw$6_BalanceShouldBe$4);

void WithdrawTransactionTests::GivenABankAccountWith$10_WhenIRunATransactionToWithdraw$6_BalanceShouldBe$4()
{
    // Given
    std::shared_ptr<BankAccount> account(new BankAccount(1000));

    // When
    std::unique_ptr<WithdrawTransaction> withdrawFromAccount(new WithdrawTransaction(account));
    withdrawFromAccount->Execute(600);

    // Then
    CPPUNIT_ASSERT_EQUAL(400, account->GetBalance());
}