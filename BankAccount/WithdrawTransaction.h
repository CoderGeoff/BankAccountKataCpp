#pragma once
#include <memory>
class BankAccount;

class WithdrawTransaction
{
public:
    explicit WithdrawTransaction(std::shared_ptr<BankAccount> account);
    bool Execute(int cents);
private:
    std::shared_ptr<BankAccount> m_Account;
};

