public final class Board {
    private char[][] field; // игровое поле
    private int size; // размер поля

    public Board(int size) {
        this.size = size;
        field = new char[size][size];
        // Инициализируем точками пустое поле
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                field[i][j] = '.';
            }
        }
    }

    // Вывод текущего состояния поля
    public void display() {
        System.out.println("Текущее поле:");
        for (char[] row : field) {
            for (char cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }

    // Проверка на действительность хода
    public boolean isValidMove(int row, int col) {
        return row >= 0 && row < size && col >= 0 && col < size && field[row][col] == '.';
        // Есть ли в Java гарантия на порядок выполнения предикатов/логических выражений в составном логическом выражении
        // Может ли оптимизатор в Java прекратить вычисление логического выражения досрочно
    }

    // Ставит символ в указанную клетку
    public void makeMove(int row, int col, char symbol) {
        field[row][col] = symbol;
    }

    // Проверяет, заполнено ли поле целиком
    public boolean isFull() {
        for (char[] row : field) {
            for (char cell : row) {
                if (cell == '.')
                    return false;
            }
        }
        return true;
    }

    // Проверяет, есть ли выигрышная линия символа
    public boolean checkWin(char symbol) {
        // Проверка всех строк и столбцов
        for (int i = 0; i < size; i++) {
            if (checkRow(i, symbol) || checkCol(i, symbol))
                return true;
        }
        // Проверка диагоналей
        return checkMainDiagonal(symbol) || checkSecondaryDiagonal(symbol);
    }

    // Проверка строки
    private boolean checkRow(int row, char symbol) {
        for (int j = 0; j < size; j++) {
            if (field[row][j] != symbol)
                return false;
        }
        return true;
    }

    // Проверка столбца
    private boolean checkCol(int col, char symbol) {
        for (int i = 0; i < size; i++) {
            if (field[i][col] != symbol)
                return false;
        }
        return true;
    }

    // Главная диагональ
    private boolean checkMainDiagonal(char symbol) {
        for (int i = 0; i < size; i++) {
            if (field[i][i] != symbol)
                return false;
        }
        return true;
    }

    // Побочная диагональ
    private boolean checkSecondaryDiagonal(char symbol) {
        for (int i = 0; i < size; i++) {
            if (field[i][size - 1 - i] != symbol)
                return false;
        }
        return true;
    }

    public char[][] getField() {
        return field;
    }

    public int getSize() {
        return size; 
    }
}
