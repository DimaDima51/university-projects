import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите email: ");
        String email = scanner.nextLine().trim();

        System.out.print("Введите телефон (+7...): ");
        String phone = scanner.nextLine().trim();

        System.out.print("Введите дату рождения (MM.YYYY): ");
        String birthDate = scanner.nextLine().trim();

        scanner.close();
        
        Validator emailValidator = Validator.createEmailValidator();
        Validator phoneValidator = Validator.createPhoneValidator();
        Validator birthDateValidator = Validator.createBirthDateValidator();

        System.out.println("\nРезультаты проверки:");
        System.out.printf("\nEmail: %b", emailValidator.validate(email));
        System.out.printf("\nТелефон: %b", phoneValidator.validate(phone));
        System.out.printf("\nДата: %b", birthDateValidator.validate(birthDate));
    }
}