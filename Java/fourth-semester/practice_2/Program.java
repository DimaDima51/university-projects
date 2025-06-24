import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Car> cars = new ArrayList<>();
        
        System.out.println("Введите данные об автомобилях (или 'stop' для завершения ввода):");
        
        while (true) {
            System.out.print("Количество мест: ");
            String input = scanner.next();
            if (input.equalsIgnoreCase("stop")) break;
            int seats = Integer.parseInt(input);
            
            System.out.print("Объем топливного бака (л): ");
            int fuelTankVolume = scanner.nextInt();
            
            System.out.print("Мощность двигателя (л.с.): ");
            int enginePower = scanner.nextInt();
            
            System.out.print("Потребление топлива (л/100 км): ");
            double fuelConsumption = scanner.nextDouble();
            
            System.out.print("Объем багажника (л): ");
            int trunkVolume = scanner.nextInt();
            
            System.out.print("Пробег (км): ");
            int mileage = scanner.nextInt();
            
            cars.add(new Car(seats, fuelTankVolume, enginePower, fuelConsumption, trunkVolume, mileage));
            System.out.println("Автомобиль добавлен! Введите следующий или 'stop'.");
        }
        
        System.out.print("Введите расстояние для расчета топлива (км): ");
        double distance = scanner.nextDouble();
        scanner.close();
        
        System.out.println("\nИнформация об автомобилях:\n");
        for (Car car : cars) {
            CarTax.printCarInfo(car, distance);
        }
    }
}