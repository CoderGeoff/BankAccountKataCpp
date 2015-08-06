#pragma once
#include <memory>
class BankAccount;

class DepositTransaction
{
public:
    explicit DepositTransaction(std::shared_ptr<BankAccount> account);
    bool Execute(int cents);
private:
    std::shared_ptr<BankAccount> m_Account;
};

