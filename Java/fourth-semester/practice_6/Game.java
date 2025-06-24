import java.util.Scanner;

public class Game {
    private final Board board;
    private final Player humanPlayer;
    private final ComputerPlayer computerPlayer;
    private boolean isHumanTurn;

    public Game(int size, char humanSymbol) {
        board = new Board(size);
        humanPlayer = new Player(humanSymbol);
        // Компьютер получает противоположный символ
        char computerSymbol = (humanSymbol == 'X') ? 'O' : 'X';
        computerPlayer = new ComputerPlayer(computerSymbol);
        // Крестик всегда ходит первым
        isHumanTurn = (humanSymbol == 'X');
    }

    public void play() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            board.display();

            if (isHumanTurn) {
                // Ход человека
                System.out.print("Ваш ход (строка и столбец): ");
                int row = scanner.nextInt() - 1;
                int col = scanner.nextInt() - 1;
                
                if (!board.isValidMove(row, col)) {
                    System.out.println("Недопустимый ход. Повторите.");
                    continue;
                }
                
                board.makeMove(row, col, humanPlayer.getSymbol());
            } else {
                // Ход компьютера
                int[] move = computerPlayer.makeMove(board);
                System.out.println(String.format("%s %d %d"
                , "Компьютер сходил:"
                , (move[0] + 1)
                , (move[1] + 1)));
                board.makeMove(move[0], move[1], computerPlayer.getSymbol());
            }

            // Проверяем победу
            char current = isHumanTurn ? humanPlayer.getSymbol() : computerPlayer.getSymbol();
            if (board.checkWin(current)) {
                board.display();
                System.out.println(isHumanTurn ? "Вы выиграли!" : "Компьютер выиграл!");
                break;
            }
            // Проверяем ничью
            if (board.isFull()) {
                board.display();
                System.out.println("Ничья.");
                break;
            }
            // Меняем очередь хода
            isHumanTurn = !isHumanTurn;
        }
        scanner.close();
    }
}
