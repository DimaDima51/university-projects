import java.util.Date;
import java.util.List;

public class Account {
    private int id;
    private String name;
    private double balance;
    private double annualInterestRate;
    private final Date dateCreated = new Date();

    
    private final Transactions transactions = new Transactions();

    public Account(String name, int id, double balance, double annualInterestRate) {
        this.name = name;
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
    }

    public Account() { }

    public String getName() {
        return name;
    }

    public Account setName(String name) {
        this.name = name;
        return this;
    }

    public int getId() {
        return id;
    }

    public Account setId(int id) {
        this.id = id;
        return this;
    }

    public double getBalance() {
        return balance;
    }

    public Account setBalance(double balance) {
        this.balance = balance;
        return this;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public Account setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
        return this;
    }
    
    public Date getDateCreated() {
        return dateCreated;
    }

    private double getMonthlyInterestRate() {
        return (annualInterestRate / 100.0) / 12.0;
    }

    public double getMonthlyInterest() {
        return balance * getMonthlyInterestRate();
    }

    private void addTransaction(char type, double amount, String description, boolean success) {
        double balAfter = success ? balance : this.balance;
        transactions.add(type, amount, balAfter, description);
    }

    // Снятие наличных
    public boolean withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            addTransaction('-', amount, "снятие (НЕУД)", false);
            return false;
        }
        balance -= amount;
        addTransaction('-', amount, "снятие", true);
        return true;
    }

    // Внесение наличных
    public boolean deposit(double amount) {
        if (amount <= 0) {
            addTransaction('+', amount, "депозит (НЕУД)", false);
            return false;
        }
        balance += amount;
        addTransaction('+', amount, "депозит", true);
        return true;
    }

    public List<Transaction> getAllTransactions() {
        return transactions.getAll();
    }

    public List<Transaction> getSuccessfulTransactions() {
        return transactions.getSuccessful();
    }

    public List<Transaction> getFailedTransactions() {
        return transactions.getFailed();
    }
}
