import java.util.Scanner;

public class MatrixProgram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Введите размеры матрицы A (от 1 до 5):");
        System.out.print("Количество строк A: ");
        int rowsA = sc.nextInt();
        System.out.print("Количество столбцов A: ");
        int colsA = sc.nextInt();

        System.out.println("Введите размеры матрицы B (от 1 до 5):");
        System.out.print("Количество строк B: ");
        int rowsB = sc.nextInt();
        System.out.print("Количество столбцов B: ");
        int colsB = sc.nextInt();

        if (rowsA < 1 || rowsA > 5 || colsA < 1 || colsA > 5 ||
                rowsB < 1 || rowsB > 5 || colsB < 1 || colsB > 5) {
            System.out.println("Ошибка: размеры матриц должны быть от 1 до 5.");
            sc.close();
            return;
        }

        Matrix A = new Matrix(rowsA, colsA);
        Matrix B = new Matrix(rowsB, colsB);

        System.out.println("Выберите способ задания элементов матрицы:");
        System.out.println("1 - Случайным образом");
        System.out.println("2 - С клавиатуры");
        int fillChoice = sc.nextInt();

        if (fillChoice == 1) {
            A.fillRandom();
            B.fillRandom();
        } else if (fillChoice == 2) {
            System.out.println("Для матрицы A:");
            MatrixFunc.fillManual(A, sc);
            System.out.println("Для матрицы B:");
            MatrixFunc.fillManual(B, sc);
        } else {
            System.out.println("Неверный выбор.");
            sc.close();
            return;
        }

        System.out.println("Матрица A:");
        A.printMatrix();
        System.out.println("Матрица B:");
        B.printMatrix();

        for (;;) {
            System.out.println("\nВыберите операцию:");
            System.out.println("0 - Выйти из программы");
            System.out.println("1 - Сложение матриц");
            System.out.println("2 - Вычитание матриц");
            System.out.println("3 - Умножение матрицы на число");
            System.out.println("4 - Перемножение матриц");
            System.out.println("5 - Транспонирование матрицы");
            System.out.println("6 - Вывести матрицы A и B повторно");
            int opChoice = sc.nextInt();

            if (opChoice == 0) {
                System.out.println("Завершение программы...");
                break;
            }

            Matrix result = null;

            switch (opChoice) {
                case 1:
                    // Сложение матриц
                    if (!A.isSameSize(B)) {
                        System.out.println("Операция сложения невозможна: размеры матриц не совпадают.");
                    } else {
                        result = A.add(B);
                        System.out.println("Результат сложения матриц:");
                        result.printMatrix();
                    }
                    break;
                case 2:
                    // Вычитание матриц
                    if (!A.isSameSize(B)) {
                        System.out.println("Операция вычитания невозможна: размеры матриц не совпадают.");
                    } else {
                        result = A.subtract(B);
                        System.out.println("Результат вычитания матриц (A - B):");
                        result.printMatrix();
                    }
                    break;
                case 3:
                    // Умножение на число
                    System.out.println("Выберите матрицу для умножения на число (A или B):");
                    char matrixChoice = sc.next().charAt(0);
                    System.out.print("Введите число: ");
                    int scalar = sc.nextInt();
                    if (matrixChoice == 'A' || matrixChoice == 'a') {
                        result = A.multiply(scalar);
                        System.out.println(String.format("%s %d:"
                        , "Результат умножения матрицы A на"
                        , scalar));
                        result.printMatrix();
                    } else if (matrixChoice == 'B' || matrixChoice == 'b') {
                        result = B.multiply(scalar);
                        System.out.println(String.format("%s %d:"
                        , "Результат умножения матрицы B на"
                        , scalar));
                        result.printMatrix();
                    } else {
                        System.out.println("Неверный выбор матрицы.");
                    }
                    break;
                case 4:
                    // Перемножение матриц
                    if (!A.isMultiplyable(B)) {
                        System.out.println("Операция перемножения невозможна: число столбцов A не равно числу строк B.");
                    } else {
                        result = A.multiply(B);
                        System.out.println("Результат перемножения матриц (A * B):");
                        result.printMatrix();
                    }
                    break;
                case 5:
                    // Транспонирование
                    System.out.println("Выберите матрицу для транспонирования (A или B):");
                    matrixChoice = sc.next().charAt(0);
                    if (matrixChoice == 'A' || matrixChoice == 'a') {
                        result = A.transpose();
                        System.out.println("Транспонированная матрица A:");
                        result.printMatrix();
                    } else if (matrixChoice == 'B' || matrixChoice == 'b') {
                        result = B.transpose();
                        System.out.println("Транспонированная матрица B:");
                        result.printMatrix();
                    } else {
                        System.out.println("Неверный выбор матрицы.");
                    }
                    break;
                case 6:
                    // Повторный вывод матриц
                    System.out.println("Матрица A:");
                    A.printMatrix();
                    System.out.println("Матрица B:");
                    B.printMatrix();
                    break;
                default:
                    System.out.println("Неверный выбор операции.");
                    break;
            }
        }
        sc.close();
    }
}