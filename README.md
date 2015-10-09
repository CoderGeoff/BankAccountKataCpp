# BankAccountKataCpp
An exercise in mocking, using C++ / Visual Studio.
Based on Visual Studio 2013.

## Getting started

1. Clone the repository
2. Open Visual Studio
3. Open the solution file, BankAccountKata.sln
4. Build (Debug)
5. Run the tests, Debug/BankAccountTests.exe

## Exercise 
Implement the following business rules for WithdrawTransaction

1. No account is allowed to go overdrawn
2. The minimum withdrawal from a savings account is $20
3. Withdrawals are not permitted from a fixed term bond account

Break the exercise down into these steps

### Step 1: A WithdrawTransaction should accept a set of rules (but ignore them)

1. In the BankAccount project, create an IRule interface (i.e. an abstract class) with the pure virtual method `bool IsBlocked(int balanceBefore, int balanceAfter)`
2. Change the test in WithdrawTransactionTests to pass an empty collection of IRule objects into the WithdrawTransaction constructor
3. Modify the WithdrawTransaction constructor so that the code compiles.
4. Compile, run the tests and verify that they still pass
5. Commit.
6. Refactor step: make any approprirate improvements to the code and the tests

### Step 2: A WithdrawTransaction should run if all the rules pass
1. Create a new test in WithdrawTransactiontests for the test scenario: Given all rules pass, when I execute a withdraw transaction, the account should be debited
2. In the test, create two mock IRule objects that return false from IsBlocked()
3. Pass the collection rules into the WithdrawTransaction ctor
4. Verify the tests pass (there is no need to implement anything here)
5. Commit
6. Make any appropriate improvements to the code and tests

### Step 3: A WithdrawTransaction should fail if any single rule fails
1. Create a new test in WithdrawTransactionTests for test scenario: Given one rule fails, when I execute a withdraw transaction, the account balance should be unchanged
2. In the test, pass in a collection of three mock IRule objects, where just one of them returns true from IsBlocked
3. Write just enough code to get the test new failing for the right reason
4. Now implement code in WithdrawTransaction to process the rules so that all the tests pass
5. Commit
6. Make any appropriate improvements to the code and tests

### Step 4: Create the rules with an IRulesFactory interface
1. Create a new interface, IRulesFactory with a method, `CreateWithdrawalRulesFor(AccountType)` that returns a collection of IRules
2. In each of the tests in WithdrawTransactionTests, create a mock IRulesFactory object, set up the mock so that it returns the collection of IRules the test uses, and pass the IRulesFactory into the WithdrawTransaction constructor in place of the collection of IRules. 
3. Run the tests - some should fail.
4. Implement code in WithdrawTransaction.Execute to call the IRulesFactory and store the rules returned, such that the tests now pass.
5. Commit.
6. Make any appropriate improvements to the code and tests

### Step 5: Write a NoOverdraftRule
1. Create a new test case (in a new file) called RulesTests. (Since each rule is really small, tests for all the rules can go into a single test case)
2. Write a test for the following scenario: given a final balance of -1, when called, IsBlocked should return true
4. Write just enough of NoOverdraftRule to get the test failing.
5. Now implement enough to get the test passing. 
6. Commit
7. Continue adding tests until NoOverdraftRule is complete
8. Look for improvements to the code and tests

### Step 6: Write a NoWithdrawRule 
Follow the method in step 4 to write a NoWithdrawalRule that always returns true from IsBlocked.
The implementation of this rule is very simple, so it's probably not worth writing more than one test for it. 

### Step 7: Write a MinimumWithdrawalRule 
Follow the same method to write a MinimumWithdrawalRule. Its IsBlocked should return true if the withdrawal amount is less than a threshold passed into object's constructor. 

### Step 9: Write the first integration test
1. In a new test suite, IntegrationTests, create a test case for the scenario: given a savings account with $19.99, when I try to withdraw $20, the transaction should fail
2. Implement the test with
  * a savings account
  * a RulesFactory object (you will define RulesFactory later)
  * a WithdrawalTransaction (you pass the RulesFactory object into its constructor)
3. Implement just enough of the RuleFactory class to get the code compiling
4. Run the test and ensure it fails for the right reason
5. Implement RulesFactory.CreateWithdrawalRulesFor(AccountType) by having it return a collection containing a single MinimumWithdrawalRule

### Step 10. Complete the implementation of RulesFactory
Continuing using TDD, adding integration tests like the one before, until the SavingsAccount rules are complete. Then continue adding rules for the FixedBondAccount and the CheckingAccount. 


