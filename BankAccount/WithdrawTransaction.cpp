#include "stdafx.h"
#include <memory>
#include "WithdrawTransaction.h"
#include "BankAccount.h"

WithdrawTransaction::WithdrawTransaction(std::shared_ptr<BankAccount> account)
{
    m_Account = account;
}

bool WithdrawTransaction::Execute(int cents)
{
    m_Account->SetBalance(m_Account->GetBalance() - cents);
    return true;
}

