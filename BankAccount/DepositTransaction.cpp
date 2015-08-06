#include "stdafx.h"
#include <memory>
#include "DepositTransaction.h"
#include "BankAccount.h"

DepositTransaction::DepositTransaction(std::shared_ptr<BankAccount> account)
{
    m_Account = account;
}

bool DepositTransaction::Execute(int cents)
{
    m_Account->SetBalance(m_Account->GetBalance() + cents);
    return true;
}
