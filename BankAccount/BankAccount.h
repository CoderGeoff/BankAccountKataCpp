#pragma once

#include "AccountType.h"

class BankAccount
{
    AccountType m_Type;
    int m_Balance;
public:
    explicit BankAccount(enum AccountType);
    explicit BankAccount(enum AccountType, int initialBalanceInCents);

    int GetBalance() const;
    void Deposit(int cents);
    void Withdraw(int cents);

    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;
};

