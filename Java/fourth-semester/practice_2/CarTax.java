public class CarTax {
    // Расчёт транспортного налога
    public static int calculateTax(Car car) {
        int power = car.getEnginePower();

        if (power > 100 && power <= 150) {
            return 22 * power;
        }

        if (power > 150 && power <= 200) {
            return 35 * power;
        }
        
        if (power > 200 && power <= 250) {
            return 56 * power;
        }
        
        return -1;
    }

    // Расчёт стоимости аренды
    public static double calculateRentalCost(Car car) {
        return 2000 * (0.01 * car.getTrunkVolume() + 0.1 * car.getSeats());
    }

    // Вывод информации
    public static void printCarInfo(Car car, double distance) {
        System.out.println("Автомобиль:");
        System.out.println("Количество пассажиров: " + car.getPassengerCount());
        System.out.println("Дальность поездки при полном баке: " + Math.round(car.getRange() * 100.0) / 100.0 + " км");
        System.out.println("Количество топлива для поездки на " + distance + " км: " + Math.round(car.getFuelNeeded(distance) * 100.0) / 100.0 + " л");
        System.out.println("Пробег сверх 150 000 км: " + car.getMileageOver150k() + " км");
        System.out.println("Транспортный налог: " + calculateTax(car) + " руб");
        System.out.println("Стоимость аренды в сутки: " + Math.round(calculateRentalCost(car) * 100.0) / 100.0 + " руб");
        System.out.println();
    }
}
