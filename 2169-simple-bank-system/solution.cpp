class Bank {
private:
    vector<long long> balance; // stores all account balances
    int n;                     // number of accounts

public:
    // Constructor: initialize the bank with given balances
    Bank(vector<long long>& balance) {
        this->balance = balance;   // store balance array
        n = balance.size();        // store number of accounts
    }

    // Helper function: check if an account number is valid
    bool isValid(int account) {
        return account >= 1 && account <= n;
    }

    // Transfer money from account1 → account2
    bool transfer(int account1, int account2, long long money) {
        // 1️⃣ Check if both accounts exist
        if (!isValid(account1) || !isValid(account2))
            return false;

        // 2️⃣ Check if account1 has enough money to transfer
        if (balance[account1 - 1] < money)
            return false;

        // 3️⃣ Perform the transfer
        balance[account1 - 1] -= money; // subtract from sender
        balance[account2 - 1] += money; // add to receiver

        return true; // ✅ successful
    }

    // Deposit money into an account
    bool deposit(int account, long long money) {
        // 1️⃣ Check if the account exists
        if (!isValid(account))
            return false;

        // 2️⃣ Add money to the account
        balance[account - 1] += money;

        return true; // ✅ successful
    }

    // Withdraw money from an account
    bool withdraw(int account, long long money) {
        // 1️⃣ Check if the account exists
        if (!isValid(account))
            return false;

        // 2️⃣ Check if sufficient balance is available
        if (balance[account - 1] < money)
            return false;

        // 3️⃣ Subtract the amount
        balance[account - 1] -= money;

        return true; // ✅ successful
    }
};

