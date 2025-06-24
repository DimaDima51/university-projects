import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Выбор символа игрока
        char humanSymbol;
        while (true) {
            System.out.print("Добро пожаловать в игру \"Крестики-нолики\"\nВыберете, за кого будете играть? Введите X или O: ");
            String input = scanner.next().trim().toUpperCase();
            if (input.equals("X") || input.equals("O")) {
                humanSymbol = input.charAt(0);
                break;
            }
            System.out.println("Ошибка: нужно ввести либо X, либо O.");
        }

        // Ввод размера поля
        System.out.print("Введите размер игрового поля: ");
        int size = scanner.nextInt();

        // Создаём и запускаем игру
        Game game = new Game(size, humanSymbol);
        game.play();

        scanner.close();
    }
}
