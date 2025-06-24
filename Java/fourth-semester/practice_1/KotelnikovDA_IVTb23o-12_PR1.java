import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int credit = 0;
        double years = 0;
        double percent = 0;

        System.out.print("Введите сумму кредита (кратно 5 000, минимальное значение - 5 000, максимальное значение - 1 000 000): ");
        while (true) {
            credit = in.nextInt();
            if (credit >= 5000 && credit <= 1000000 && credit % 5000 == 0) {
                break;
            } else {
                System.out.println("Ошибка: сумма кредита должна быть от 5 000 до 1 000 000 и кратна 5 000.");
            }
        }

        System.out.print("Введите срок кредита в годах (минимальное значение - 0.5 года, максимальное - 7 лет, кратно 0.5 года): ");
        while (true) {
            years = in.nextDouble();
            if (years >= 0.5 && years <= 7 && (int)(years * 10) % 5 == 0) {
                break;
            } else {
                System.out.println("Ошибка: срок должен быть от 0.5 до 7 лет и кратен 0.5.");
            }
        }

        System.out.print("Введите процентную ставку (в интервале от 2 до 25): ");
        while (true) {
            percent = in.nextDouble();
            if (percent >= 2 && percent <= 25) {
                break;
            } else {
                System.out.println("Ошибка: процентная ставка должна быть от 2 до 25.");
            }
        }

        in.close();

        // Срок кредита в месяцах
        int months = (int)(years * 12);

        System.out.println("   Расчет дифференцированного платежа:");

        // Фиксированный платёж
        double fixPay = Math.round((credit / (double)months) * 100) / 100.0;

        // Общая сумма выплаты
        double totalDiffPay = 0;

        for (int month = 1; month <= months; month++) {

            // Сколько осталось выплатить
            double remainPay = credit - (fixPay * (month - 1));

            // Платёж по процентам
            double percentPay = Math.round((remainPay * (percent / 100) / 12) * 100) / 100.0;

            // Итоговый платёж за месяц = фиксированный + по процентам
            double monthPay = Math.round((fixPay + percentPay) * 100) / 100.0;

            totalDiffPay += monthPay;

            System.out.printf("Месяц №%d: %.2f руб.\n", month, monthPay);
        }

        System.out.printf("Общая сумма выплат (дифф.) по кредиту: %.2f руб.\n", Math.round(totalDiffPay * 100) / 100.0);

        System.out.println("   Расчет аннуитетного платежа:");
        
        // Месячная процентная ставка
        double monthRate = (percent / 100) / 12;

        // Коэффициент аннуитета
        double annuityCoefficient = (monthRate * Math.pow(1 + monthRate, months)) / (Math.pow(1 + monthRate, months) - 1);

        // Платёж в месяц
        double annuityPay = Math.round((credit * annuityCoefficient) * 100) / 100.0;

        // Общая сумма выплат
        double totalAnnuityPay = Math.round((annuityPay * months) * 100) / 100.0;
        
        System.out.printf("Ежемесячный платёж: %.2f руб.\n", annuityPay);
        System.out.printf("Общая сумма выплат (анн.) по кредиту: %.2f руб.", totalAnnuityPay);
    }
}