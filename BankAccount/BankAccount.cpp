#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount() : m_Balance(0) {}

int BankAccount::GetBalance() const { return m_Balance; }

void BankAccount::Deposit(int cents)
{
    m_Balance += cents;
}

void BankAccount::Withdraw(int cents)
{
    m_Balance -= cents;
}