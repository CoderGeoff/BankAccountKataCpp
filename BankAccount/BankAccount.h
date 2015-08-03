#pragma once
class BankAccount
{
    int m_Balance;
public:
    BankAccount();
    int GetBalance() const;
    void Deposit(int cents);
    void Withdraw(int cents);
};

