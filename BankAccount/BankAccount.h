#pragma once

#include "AccountType.h"

class BankAccount
{
    AccountType m_Type;
    int m_Balance;
public:
    explicit BankAccount(enum AccountType);
    explicit BankAccount(enum AccountType, int initialBalanceInCents);

    AccountType GetType() const;
    int GetBalance() const;
    void SetBalance(int cents);
    void Deposit(int cents);
    void Withdraw(int cents);

    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;
};

