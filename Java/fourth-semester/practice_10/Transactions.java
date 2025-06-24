import java.util.ArrayList;
import java.util.List;

public class Transactions {
    private final List<Transaction> list = new ArrayList<>();

    public void add(char type, double amount, double balanceAfter, String description) {
        list.add(new Transaction(type, amount, balanceAfter, description));
    }

    public List<Transaction> getAll() {
        return new ArrayList<>(list);
    }

    public List<Transaction> getSuccessful() {
        List<Transaction> successTr = new ArrayList<>();
        for (Transaction tr : list) {
            // Удачные транзакции
            if (!tr.getDescription().contains("(НЕУД)")) {
                successTr.add(tr);
            }
        }
        return successTr;
    }

    public List<Transaction> getFailed() {
        List<Transaction> failedTr = new ArrayList<>();
        for (Transaction tr : list) {
            // Неудачные транзакции
            if (tr.getDescription().contains("(НЕУД)")) {
                failedTr.add(tr);
            }
        }
        return failedTr;
    }
}
