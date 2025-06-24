import java.util.Random;

public class Matrix {
    private int rowCount;
    private int columnCount;
    private int[][] data;

    public Matrix(int rowCount, int columnCount) {
        this.rowCount = rowCount;
        this.columnCount = columnCount;
        this.data = new int[rowCount][columnCount];
    }

    public int getRowCount() {
        return rowCount;
    }

    public int getColumnCount() {
        return columnCount;
    }

    public int getElement(int row, int col) {
        return data[row][col];
    }

    public void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    public boolean isSameSize(Matrix other) {
        return this.rowCount == other.rowCount && this.columnCount == other.columnCount;
    }

    public boolean isMultiplyable(Matrix other) {
        return this.columnCount == other.rowCount;
    }

    public void fillRandom() {
        Random rand = new Random();
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                data[i][j] = rand.nextInt(11);
            }
        }
    }

    public void printMatrix() {
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                System.out.print(data[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public Matrix add(Matrix other) {
        return MatrixFunc.add(this, other);
    }

    public Matrix subtract(Matrix other) {
        return MatrixFunc.subtract(this, other);
    }

    public Matrix multiply(Matrix other) {
        return MatrixFunc.multiply(this, other);
    }

    public Matrix multiply(int scalar) {
        return MatrixFunc.multiply(this, scalar);
    }

    public Matrix transpose() {
        return MatrixFunc.transpose(this);
    }
}