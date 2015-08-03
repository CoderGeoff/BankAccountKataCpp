#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount() : m_Balance(0) {}

void BankAccount::Deposit(int cents) { m_Balance += cents; }

int BankAccount::GetBalance() const { return m_Balance; }
