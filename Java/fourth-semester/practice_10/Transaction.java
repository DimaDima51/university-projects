import java.util.Date;

public class Transaction {
    private final Date date;            // дата
    private final char type;            // '-' или '+'
    private final double amount;        // кол-во
    private final double balance;       // баланс после операции
    private final String description;   // описание

    public Transaction(char type, double amount, double balance, String description) {
        this.date = new Date();
        this.type = type;
        this.amount = amount;
        this.balance = balance;
        this.description = description;
    }

    public Date getDate() {
        return date;
    }

    public char getType() {
        return type;
    }

    public double getAmount() {
        return amount;
    }

    public double getBalance() {
        return balance;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public String toString() {
        return String.format(
            "[%s] %c %.2f -> баланс: %.2f | %s"
            , date
            , type
            , amount
            , balance
            , description
        );
    }

}
