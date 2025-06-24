import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        boolean isRunning = true;

        while (isRunning) {
            System.out.println("Выберите операцию:");
            for (Operation op : Operation.values()) {
                System.out.printf("%s. %s%n", op.getCode(), op.getDescription());
            }
            System.out.print("Ваш выбор (код операции): ");

            String code = scanner.nextLine().trim();
            Operation operation = Operation.fromCode(code);

            if (operation == null) {
                System.out.println("Неверный код операции. Попробуйте снова.\n");
                continue;
            }

            if (operation == Operation.EXIT) {
                System.out.println("Выход из программы.");
                isRunning = false;
            }

            try {
                // Запрашиваем две дроби
                System.out.println("\nВведите первую дробь:");
                Fraction f1 = createFraction(scanner);
                System.out.println();

                System.out.println("Введите вторую дробь:");
                Fraction f2 = createFraction(scanner);
                System.out.println();

                // Выполняем выбранную операцию
                switch (operation) {
                    case ADD:
                        f1.print();
                        System.out.print(" + ");
                        f2.print();
                        System.out.print(" = ");
                        f1.add(f2).print();
                        System.out.println();
                        break;
                    case SUBTRACT:
                        f1.print();
                        System.out.print(" - ");
                        f2.print();
                        System.out.print(" = ");
                        f1.subtract(f2).print();
                        System.out.println();
                        break;
                    case MULTIPLY:
                        f1.print();
                        System.out.print(" * ");
                        f2.print();
                        System.out.print(" = ");
                        f1.multiply(f2).print();
                        System.out.println();
                        break;
                    case DIVIDE:
                        f1.print();
                        System.out.print(" / ");
                        f2.print();
                        System.out.print(" = ");
                        f1.divide(f2).print();
                        System.out.println();
                        break;
                    case EQUAL:
                        f1.print();
                        System.out.print(" == ");
                        f2.print();
                        System.out.println(" = " + f1.equals(f2));
                        break;
                    case NOT_EQUAL:
                        f1.print();
                        System.out.print(" != ");
                        f2.print();
                        System.out.println(" = " + f1.notEquals(f2));
                        break;
                    case GREATER:
                        f1.print();
                        System.out.print(" > ");
                        f2.print();
                        System.out.println(" = " + f1.greaterThan(f2));
                        break;
                    case LESSER:
                        f1.print();
                        System.out.print(" < ");
                        f2.print();
                        System.out.println(" = " + f1.lesserThan(f2));
                        break;
                    case GREATER_OR_EQUAL:
                        f1.print();
                        System.out.print(" >= ");
                        f2.print();
                        System.out.println(" = " + f1.greaterOrEqual(f2));
                        break;
                    case LESSER_OR_EQUAL:
                        f1.print();
                        System.out.print(" <= ");
                        f2.print();
                        System.out.println(" = " + f1.lesserOrEqual(f2));
                        break;
                    default:
                        // ничего не делать
                        break;
                }

                System.out.println(); // пустая строка перед новым циклом
            }
            catch (NullDenominatorException e) {
                System.err.println("Ошибка: " + e.getMessage());
                System.err.println("Попробуйте снова.\n");
            }
            catch (Exception e) {
                System.err.println("Ошибка ввода. Попробуйте снова.\n");
                scanner.nextLine();
            }
        }

        scanner.close();
    }

    private static Fraction createFraction(Scanner scanner) throws NullDenominatorException {
        System.out.println("Выберите тип ввода:");
        System.out.println("1. Обыкновенная дробь (a/b)");
        System.out.println("2. Целое число");
        System.out.println("3. Десятичная дробь");
        System.out.print("Ваш выбор: ");

        String type = scanner.nextLine().trim();
        switch (type) {
            case "1":
                System.out.print("Введите числитель: ");
                int numerator = Integer.parseInt(scanner.nextLine().trim());
                System.out.print("Введите знаменатель: ");
                int denominator = Integer.parseInt(scanner.nextLine().trim());
                return new Fraction(numerator, denominator);
            case "2":
                System.out.print("Введите целое число: ");
                int wholeNumber = Integer.parseInt(scanner.nextLine().trim());
                return new Fraction(wholeNumber);
            case "3":
                System.out.print("Введите десятичную дробь (например, 2.5): ");
                double decimal = Double.parseDouble(scanner.nextLine().trim());
                return new Fraction(decimal);
            default:
                System.out.println("Неверный выбор. Создаётся дробь 1/1 по умолчанию.");
                return new Fraction();
        }
    }
}
