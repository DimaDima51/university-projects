import java.util.Scanner;

public class VectorCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        // Чтение первого вектора
        System.out.println("Первый вектор:");
        System.out.println("Начало вектора: ");
        Point3D vectorStart1 = readPoint(scanner);
        System.out.println("Конец вектора: ");
        Point3D vectorEnd1  = readPoint(scanner);
        Vector3D vector1 = new Vector3D(vectorStart1, vectorEnd1);

        // Чтение второго вектора
        System.out.println("\nВторой вектор:");
        System.out.println("Начало вектора: ");
        Point3D vectorStart2 = readPoint(scanner);
        System.out.println("Конец вектора: ");
        Point3D vectorEnd2  = readPoint(scanner);
        Vector3D vector2 = new Vector3D(vectorStart2, vectorEnd2);

        // Вывод информации о введённых векторах
        System.out.println("\n--- Заданные векторы ---");
        System.out.println("Вектор 1: " + vector1);
        System.out.println("Вектор 2: " + vector2);

        boolean running = true;
        while (running) {
            System.out.println("\n--- Меню операций ---");
            for (Operation op : Operation.values()) {
                System.out.printf("%s. %s%n", op.getCode(), op.getDescription());
            }
            System.out.print("Выберите код операции: ");
            String choice = scanner.nextLine().trim();
            Operation selected = Operation.fromCode(choice);
            if (selected == null) {
                System.out.println("Некорректный код операции. Попробуйте снова.");
                continue;
            }

            switch (selected) {
                case LENGTH:
                    System.out.print("Для какого вектора (1 или 2)? ");
                    String num = scanner.nextLine().trim();
                    if (num.equals("1")) {
                        double vectorLen1 = vector1.length();
                        System.out.printf("Длина вектора 1 = %.3f%n", vectorLen1);
                    } else if (num.equals("2")) {
                        double vectorLen2 = vector2.length();
                        System.out.printf("Длина вектора 2 = %.3f%n", vectorLen2);
                    } else {
                        System.out.println("Неверный номер вектора.");
                    }
                    break;

                case SUM:
                    Point3D sum = vector1.add(vector2);
                    System.out.println("Операция: Сумма векторов 1 + 2");
                    System.out.println("Результат: " + sum);
                    break;

                case DIFFERENCE:
                    Point3D diff = vector1.subtract(vector2);
                    System.out.println("Операция: Разность векторов 1 - 2");
                    System.out.println("Результат: " + diff);
                    break;

                case ANGLE:
                    try {
                        double angle = vector1.angle(vector2);
                        System.out.printf("Угол между векторами = %.3f°%n", angle);
                    } catch (IllegalArgumentException e) {
                        System.out.println("Ошибка: " + e.getMessage());
                    }
                    break;

                case DOT_PRODUCT:
                    double dot = vector1.dot(vector2);
                    System.out.printf("Скалярное произведение векторов = %.3f%n", dot);
                    break;

                case CROSS_PRODUCT:
                    Point3D cross = vector1.cross(vector2);
                    System.out.println("Векторное произведение:");
                    System.out.println(cross);
                    break;

                case EXIT:
                    running = false;
                    System.out.println("Выход из программы.");
                    break;
            }
        }

        scanner.close();
    }

    private static Point3D readPoint(Scanner scanner) {
        System.out.printf("Введите координату X: ");
        double x = readDouble(scanner);
        System.out.printf("Введите координату Y: ");
        double y = readDouble(scanner);
        System.out.printf("Введите координату Z: ");
        double z = readDouble(scanner);
        return new Point3D(x, y, z);
    }

    private static double readDouble(Scanner scanner) {
        while (true) {
            try {
                return Double.parseDouble(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.print("Некорректный ввод. Введите, пожалуйста, число: ");
            }
        }
    }
}
