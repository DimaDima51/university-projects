// Atm.java
import java.util.List;
import java.util.Scanner;

public class Atm {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Bank bank = Bank.createBank(10, 10000.0, 6.0);

        for (int i = 0; i < 10; i++) {
            Account acc = bank.getAccountById(i);
            acc.setName("Клиент №" + i);
        }

        System.out.println("Добро пожаловать в банкомат!");

        boolean isProgramRunning = true;

        while (isProgramRunning) {
            Account current = null;
            do {
                System.out.print("Введите ID счета: ");
                int id = scanner.nextInt();
                current = bank.getAccountById(id);
                if (current == null) {
                    System.out.println("Некорректный ID. Повторите.");
                }
            } while (current == null);

            boolean exitToIdMenu = false;
            scanner.nextLine();

            while (!exitToIdMenu) {
                System.out.println("\n--- Основное меню ---");
                for (MenuOption option : MenuOption.values()) {
                    System.out.println(String.format("%s: %s"
                    , option.getCode()
                    , option.getDescription()));
                }
                System.out.print("Выберите пункт: ");
                String choice = scanner.nextLine().trim();

                MenuOption selected = MenuOption.fromCode(choice);
                if (selected == null) {
                    System.out.println("Неверный выбор. Попробуйте снова.");
                    continue;
                }

                switch (selected) {
                    case CHECK_BALANCE:
                        System.out.printf("Баланс: %.2f%n", current.getBalance());
                        break;

                    case WITHDRAW:
                        System.out.print("Сумма для снятия: ");
                        double withdrawAmount = readDouble(scanner);
                        boolean okWithdraw = current.withdraw(withdrawAmount);
                        if (okWithdraw) {
                            System.out.println("Снятие успешно");
                        } else {
                            System.out.println("Ошибка: недостаточно средств или некорректная сумма");
                        }
                        break;

                    case DEPOSIT:
                        System.out.print("Сумма для внесения: ");
                        double depositAmount = readDouble(scanner);
                        boolean okDeposit = current.deposit(depositAmount);
                        if (okDeposit) {
                            System.out.println("Внесение успешно");
                        } else {
                            System.out.println("Ошибка: некорректная сумма");
                        }
                        break;

                    case MONTHLY_INTEREST:
                        System.out.printf("Ежемесячные проценты: %.2f%n", current.getMonthlyInterest());
                        break;

                    case SHOW_ALL_TRANSACTIONS:
                        printTransactions(current.getAllTransactions());
                        break;

                    case SHOW_SUCCESS_TRANSACTIONS:
                        printTransactions(current.getSuccessfulTransactions());
                        break;

                    case SHOW_FAILED_TRANSACTIONS:
                        printTransactions(current.getFailedTransactions());
                        break;

                    case SWITCH_ACCOUNT:
                        exitToIdMenu = true;
                        break;

                    case EXIT:
                        isProgramRunning = false;
                        exitToIdMenu = true;
                        System.out.println("До свидания!");
                        break;
                }
            }
        }
    }

    // Корректный ввод дробного числа
    private static double readDouble(Scanner scanner) {
        double value = 0;
        boolean correctWrite = true;
        while (correctWrite) {
            try {
                String line = scanner.nextLine().trim();
                value = Double.parseDouble(line);
                correctWrite = false;
            } catch (NumberFormatException ex) {
                System.out.print("Некорректный ввод. Введите число: ");
            }
        }
        return value;
    }

    // Печать списка транзакций
    private static void printTransactions(List<Transaction> list) {
        if (list == null || list.isEmpty()) {
            System.out.println("Транзакций нет.");
        } else {
            for (Transaction t : list) {
                System.out.println(t);
            }
        }
    }
}
