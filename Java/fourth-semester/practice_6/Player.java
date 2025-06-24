// Обычный игрок
public class Player {
    private final char symbol; // 'X' или 'O'

    public Player(char symbol) {
        this.symbol = symbol;
    }

    public char getSymbol() {
        return symbol;
    }
}
