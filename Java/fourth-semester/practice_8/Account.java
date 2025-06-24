import java.util.Date;

public class Account {
    private int id = 0;
    private double balance = 0;
    private double annualInterestRate = 0;
    private final Date dateCreated = new Date();

    public Account() { }

    public Account(int id, double balance, double annualInterestRate) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
    }

    public Account setId(int id) {
        this.id = id;
        return this;
    }

    public Account setBalance(double balance) {
        this.balance = balance;
        return this;
    }

    public Account setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
        return this;
    }

    public int getId() {
        return id;
    }

    public double getBalance() {
        return balance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
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

    public boolean withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    public boolean deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;
    }
}
