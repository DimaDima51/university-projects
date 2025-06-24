import java.util.Scanner;

public class PR3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); 

        // задание 1
        System.out.print("Введите слово: ");
        String word = scanner.nextLine();
        Stack stack = new Stack();

        // слова в стек
        for (int i = 0; i < word.length(); i++) {
            stack.push(word.charAt(i));
        }

        System.out.print("Слово наоборот: ");
        stack.display();

        // задание 2
        System.out.print("\nВведите число: ");
        String number = scanner.nextLine();
        Queue queue = new Queue();
        
        for (int i = 0; i < number.length(); i++) {
            char digit = number.charAt(i);
            if (Character.isLetter(digit)) {
                System.out.println("Ошибка! В числе есть что-то кроме цифр!");
                System.exit(0);
            }

            if (Character.isDigit(digit) && (digit - '0') % 2 != 0) {
                // добавление в очередь
                queue.push(digit);
            }
        }

        System.out.print("Нечётные цифры: ");
        queue.display();
        scanner.close();
    }
}
