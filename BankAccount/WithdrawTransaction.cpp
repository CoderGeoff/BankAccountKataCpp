#include "stdafx.h"
#include <memory>
#include "WithdrawTransaction.h"
#include "BankAccount.h"

WithdrawTransaction::WithdrawTransaction(std::shared_ptr<BankAccount> account)
{
    m_Account = account;
}

void WithdrawTransaction::Execute(int cents)
{
    m_Account->Withdraw(cents);
}

