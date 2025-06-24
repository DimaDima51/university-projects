public class Bank {
    private final Account[] accounts;

    public Bank(final int numberOfAccounts) {
        accounts = new Account[numberOfAccounts];
     }   
    
    public static Bank createBank(int numberOfAccounts
    , double initialBalance
    , double annualInterestRate) {
        Bank tmpBank = new Bank(numberOfAccounts);
        for (int i = 0; i < numberOfAccounts; i++) {
            tmpBank.accounts[i] = new Account()
                .setId(i)
                .setBalance(initialBalance)
                .setAnnualInterestRate(annualInterestRate);
        }
        return tmpBank;
    }

    public Account getAccountById(int id) {
        if (id < 0 || id >= accounts.length) {
            return null;
        }
        return accounts[id];
    }
}
