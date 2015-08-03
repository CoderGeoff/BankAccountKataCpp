#pragma once
class BankAccount
{
    int m_Balance;
public:
    BankAccount();
    void Deposit(int cents);
    int GetBalance() const;
    void Withdraw(int cents);
};

