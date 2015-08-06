#pragma once

#include "AccountType.h"

class BankAccount
{
    AccountType m_Type;
    int m_Balance;
public:
    explicit BankAccount(enum AccountType);

    AccountType GetType() const;
    int GetBalance() const;
    void SetBalance(int cents);
    void Deposit(int cents);

    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;
};

