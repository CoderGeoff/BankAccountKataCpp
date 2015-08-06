#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount(AccountType type) : 
m_Type(type),
m_Balance(0) {}

AccountType BankAccount::GetType() const
{
    return m_Type;
}

int BankAccount::GetBalance() const { return m_Balance; }

void BankAccount::SetBalance(int cents)
{
    m_Balance = cents;
}

void BankAccount::Deposit(int cents)
{
    m_Balance += cents;
}

