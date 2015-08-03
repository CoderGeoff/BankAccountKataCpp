#pragma once
class BankAccount
{
    int m_Balance;
public:
    BankAccount();
    explicit BankAccount(int initialBalanceInCents);
    int GetBalance() const;
    void Deposit(int cents);
    void Withdraw(int cents);
};

