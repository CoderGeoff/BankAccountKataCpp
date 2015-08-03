#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount() : BankAccount(0) {}

BankAccount::BankAccount(int initialBalanceInCents)
: m_Balance(initialBalanceInCents) {}

int BankAccount::GetBalance() const { return m_Balance; }

void BankAccount::Deposit(int cents)
{
    m_Balance += cents;
}

void BankAccount::Withdraw(int cents)
{
    m_Balance -= cents;
}