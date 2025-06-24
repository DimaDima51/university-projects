import java.util.Scanner;

public final class MatrixFunc {
    private MatrixFunc() { }

    public static Matrix add(Matrix a, Matrix b) {
        if (!a.isSameSize(b)) {
            return null;
        }
        Matrix result = new Matrix(a.getRowCount(), a.getColumnCount());
        for (int i = 0; i < a.getRowCount(); i++) {
            for (int j = 0; j < a.getColumnCount(); j++) {
                result.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
            }
        }
        return result;
    }

    public static Matrix subtract(Matrix a, Matrix b) {
        if (!a.isSameSize(b)) {
            return null;
        }
        Matrix result = new Matrix(a.getRowCount(), a.getColumnCount());
        for (int i = 0; i < a.getRowCount(); i++) {
            for (int j = 0; j < a.getColumnCount(); j++) {
                result.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
            }
        }
        return result;
    }

    public static Matrix multiply(Matrix a, Matrix b) {
        if (!a.isMultiplyable(b)) {
            return null;
        }
        Matrix result = new Matrix(a.getRowCount(), b.getColumnCount());
        for (int i = 0; i < a.getRowCount(); i++) {
            for (int j = 0; j < b.getColumnCount(); j++) {
                int sum = 0;
                for (int k = 0; k < a.getColumnCount(); k++) {
                    sum += a.getElement(i, k) * b.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    public static Matrix multiply(Matrix m, int scalar) {
        Matrix result = new Matrix(m.getRowCount(), m.getColumnCount());
        for (int i = 0; i < m.getRowCount(); i++) {
            for (int j = 0; j < m.getColumnCount(); j++) {
                result.setElement(i, j, m.getElement(i, j) * scalar);
            }
        }
        return result;
    }
    
    public static Matrix transpose(Matrix m) {
        Matrix result = new Matrix(m.getColumnCount(), m.getRowCount());
        for (int i = 0; i < m.getRowCount(); i++) {
            for (int j = 0; j < m.getColumnCount(); j++) {
                result.setElement(j, i, m.getElement(i, j));
            }
        }
        return result;
    }

    public static void fillManual(Matrix m, Scanner sc) {
        int rows = m.getRowCount();
        int cols = m.getColumnCount();
        System.out.println(String.format("Введите элементы матрицы (%d x %d) от 0 до 10:"
        , rows
        , cols));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value;
                while (true) {
                    System.out.print(String.format("Элемент [%d][%d]: "
                    , i
                    , j));
                    value = sc.nextInt();
                    if (value >= 0 && value <= 10) {
                        break;
                    } else {
                        System.out.println("Ошибка: допустимы только значения от 0 до 10. Повторите ввод.");
                    }
                }
                m.setElement(i, j, value);
            }
        }
    }
}