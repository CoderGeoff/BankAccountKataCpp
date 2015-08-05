#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount(AccountType type) : BankAccount(type, 0) {}

BankAccount::BankAccount(AccountType type, int initialBalanceInCents) :
m_Type(type),
m_Balance(initialBalanceInCents) {}

int BankAccount::GetBalance() const { return m_Balance; }

void BankAccount::Deposit(int cents)
{
    m_Balance += cents;
}

void BankAccount::Withdraw(int cents)
{
    m_Balance -= cents;
}