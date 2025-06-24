import java.util.Random;

// Компьютерный игрок
public class ComputerPlayer extends Player {
    private final Random rand = new Random();

    public ComputerPlayer(char symbol) {
        super(symbol);
    }

    // Выбирает случайную пустую клетку
    public int[] makeMove(Board board) {
        int size = board.getSize();
        char[][] field = board.getField();
        int row, col;
        do {
            row = rand.nextInt(size);
            col = rand.nextInt(size);
        } while (field[row][col] != '.');
        return new int[]{row, col};
    }
}
