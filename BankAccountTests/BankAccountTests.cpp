#include "stdafx.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BankAccount.h"
#include <memory>

using ::testing::A;
using ::testing::An;
using ::testing::AtLeast;
using ::testing::Return;


TEST(BankAccountTests, GivenANewBankAccount_BalanceShouldBe$0)
{
    BankAccount account;
    ASSERT_EQ(0, account.GetBalance());
}

TEST(BankAccountTests, GivenABankAccountWith$10_BalanceShouldBe$10)
{
    BankAccount account(1000);
    ASSERT_EQ(1000, account.GetBalance());
}

TEST(BankAccountTests, GivenAnEmptyBankAccount_WhenIDeposit$10_BalanceShouldBe$10)
{
    BankAccount account;
    account.Deposit(1000);
    ASSERT_EQ(1000, account.GetBalance());
}

TEST(BankAccountTests, GivenABankAccountWith$10_WhenIWithdraw$6_BalanceShouldBe$4)
{
    // Given
    BankAccount account(1000);

    // When
    account.Withdraw(600);

    // Then
    ASSERT_EQ(400, account.GetBalance());
}

class ICollaborator1 
{
public: 
    virtual ~ICollaborator1() {};
    virtual int Method1() = 0;
};

class ICollaborator2
{
public: 
    virtual ~ICollaborator2() {}; 
    virtual int Method2(int) = 0;
};

class ICollaborator3 { public: virtual ~ICollaborator3(){} int virtual Method3() = 0; };

struct MockCollaborator1X : public ICollaborator1
{
    ~MockCollaborator1X() {}
    int Method1() override { return -2; }
};

struct MockCollaborator2X : public ICollaborator2
{
    ~MockCollaborator2X() {}
    int m_ValuePassedToMethod2;
    int Method2(int value) override 
    { 
        m_ValuePassedToMethod2 = value; 
        return 0; 
    }
};

struct MockCollaborator3X : public ICollaborator3
{
    ~MockCollaborator3X() {}
    int Method3() override { return -2; }
};


class MockCollaborator1 : public ICollaborator1
{
public:
    MOCK_METHOD0(Method1, int());
};

class MockCollaborator2 : public ICollaborator2
{
public:
    MOCK_METHOD1(Method2, int(int value));
};

class MockCollaborator3 : public ICollaborator3
{
public:
    MOCK_METHOD0(Method3, int());
};
class Class
{
    int m_Value;
public: 
    int MethodIWantToTest();
    void SetValue(int value) { m_Value = value; }
    std::shared_ptr<ICollaborator1> m_Collaborator1;
    std::shared_ptr<ICollaborator2> m_Collaborator2;
    std::shared_ptr<ICollaborator3> m_Collaborator3;

    Class(std::shared_ptr<ICollaborator1>& collaborator1, std::shared_ptr<ICollaborator2>& collaborator2, std::shared_ptr<ICollaborator3>& collaborator3)
    {
        m_Collaborator1 = collaborator1;
        m_Collaborator2 = collaborator2;
        m_Collaborator3 = collaborator3;
    }
};


int Class::MethodIWantToTest()
{
    int result = m_Collaborator1->Method1();
    if (result < 0)
    {
        m_Collaborator2->Method2(m_Value);
        if (result < 0) return -1;
    }
    else if (result == 0)
    {
        result = m_Collaborator3->Method3();
    }
    return result;
}

TEST(MockTests, GivenCollaborator1ReturnsLessThan0_WhenICallTheMethodIWantToTest_ThenTheResultShouldBeMinus1)
{
    auto collaborator1 = std::make_shared<MockCollaborator1>();
    auto collaborator2 = std::make_shared<MockCollaborator2>();
    auto collaborator3 = std::make_shared<MockCollaborator3>();
    auto coll1 = std::static_pointer_cast<ICollaborator1>(collaborator1);
    auto coll2 = std::static_pointer_cast<ICollaborator2>(collaborator2);
    auto coll3 = std::static_pointer_cast<ICollaborator3>(collaborator3);


    // Given
    std::shared_ptr<Class> myObject(new Class(coll1, coll2, coll3));
    ON_CALL(*collaborator1, Method1()).WillByDefault(Return(-2));

    // When
    int result = myObject->MethodIWantToTest();

    // Then
    ASSERT_EQ(-1, result);
}

TEST(MockTests, GivenCollaborator1ReturnsLessThan0_WhenICallTheMethodIWantToTest_ThenCollaborator2ShouldReceiveValue)
{
    auto collaborator1 = std::make_shared<MockCollaborator1>();
    auto collaborator2 = std::make_shared<MockCollaborator2>();
    auto collaborator3 = std::make_shared<MockCollaborator3>();
    auto coll1 = std::static_pointer_cast<ICollaborator1>(collaborator1);
    auto coll2 = std::static_pointer_cast<ICollaborator2>(collaborator2);
    auto coll3 = std::static_pointer_cast<ICollaborator3>(collaborator3);
    const int expectedValue = 2;

    // Given
    std::shared_ptr<Class> myObject(new Class(coll1, coll2, coll3));
    myObject->SetValue(expectedValue);
    ON_CALL(*collaborator1, Method1()).WillByDefault(Return(-2));

    // Set Expectation
    EXPECT_CALL(*collaborator2, Method2(expectedValue)).Times(1);

    // When
    myObject->MethodIWantToTest();

    // Assert expectation
    testing::Mock::VerifyAndClearExpectations(collaborator2.get());
}
