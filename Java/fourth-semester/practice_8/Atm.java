import java.util.Scanner;

public class Atm {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Bank bank = Bank.createBank(10, 10000.0, 6.0);

        System.out.println("Добро пожаловать в банкомат!");

        do {
            Account currentAccount = null;
            boolean accountIsInvalid = true;
            do {
                System.out.print("Введите ID счета: ");
                int id = scanner.nextInt();
                currentAccount = bank.getAccountById(id);
                accountIsInvalid = currentAccount == null;
                if (accountIsInvalid) {
                    System.out.println("Некорректный ID. Повторите ввод.");
                } else {
                    // break;
                }
            } while (accountIsInvalid);

            do {
                System.out.println("\nОсновное меню");
                System.out.println("1: проверить баланс счета");
                System.out.println("2: снять со счета");
                System.out.println("3: положить на счет");
                System.out.println("4: узнать сумму ежемесячных процентов");
                System.out.println("5: сменить аккаунт");
                System.out.println("6: выйти из программы");
                System.out.print("Выберите пункт меню: ");
                int choice = scanner.nextInt();

                switch (choice) {
                    case 1:
                        System.out.printf("Баланс равен %.2f%n", currentAccount.getBalance());
                        break;
                    case 2:
                        System.out.print("Введите сумму для снятия со счета: ");
                        double w = scanner.nextDouble();
                        if (currentAccount.withdraw(w)) {
                            System.out.println("Операция снятия со счета проведена успешно");
                        } else {
                            System.out.println("Ошибка: недостаточно средств или некорректная сумма");
                        }
                        break;
                    case 3:
                        System.out.print("Введите сумму для внесения на счет: ");
                        double d = scanner.nextDouble();
                        if (currentAccount.deposit(d)) {
                            System.out.println("Операция внесения на счет проведена успешно");
                        } else {
                            System.out.println("Ошибка: некорректная сумма");
                        }
                        break;
                    case 4:
                        System.out.printf("Сумма ежемесячных процентов: %.2f%n", currentAccount.getMonthlyInterest());
                        break;
                    case 5:
                        System.out.println("Выход в меню выбора аккаунта...");
                        break;
                    case 6:
                        System.out.println("Сеанс завершен. До новых встреч!");
                        scanner.close();
                        return;
                    default:
                        System.out.println("Некорректный выбор. Повторите.");
                }
                
                if (choice == 5) {
                    break;
                }
            } while (true);
            
        } while (true);
    }
}