import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class RestaurantApp {
    private static Menu restaurantMenu = new Menu();
    private static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        
        restaurantMenu.addDish(new Dish("Цезарь с курицей", 250, false, 350.0));
        restaurantMenu.addDish(new Dish("Салат овощной", 200, true, 220.0));

        boolean running = true;

        while (running) {
            System.out.println("\n--- Меню операций ---");
            for (Operation op : Operation.values()) {
                System.out.printf("%s. %s%n", op.getCode(), op.getDescription());
            }

            System.out.print("Выберите код операции: ");
            String choice = scanner.nextLine().trim();
            Operation selected = Operation.fromCode(choice);

            if (selected == null) {
                System.out.println("Некорректный код операции. Попробуйте снова.");
                continue;
            }

            switch (selected) {
                case SHOW_MENU:
                    restaurantMenu.printMenu();
                    break;

                case ADD_DISH:
                    try {
                        System.out.print("Наименование: ");
                        String name = scanner.nextLine();
                        System.out.print("Вес порции (грамм): ");
                        int weight = Integer.parseInt(scanner.nextLine());
                        System.out.print("Вегетарианское (+/-): ");
                        boolean veg = scanner.nextLine().equalsIgnoreCase("+");
                        System.out.print("Стоимость порции: ");
                        double price = Double.parseDouble(scanner.nextLine());

                        restaurantMenu.addDish(new Dish(name, weight, veg, price));
                        System.out.println("Блюдо добавлено.");
                    } catch (NumberFormatException e) {
                        System.out.println("Некорректный ввод числа. Попробуйте снова.");
                    }
                    break;

                case REMOVE_DISH:
                    restaurantMenu.printMenu();
                    System.out.print("Номер блюда для удаления: ");
                    try {
                        int idx = Integer.parseInt(scanner.nextLine()) - 1;
                        if (restaurantMenu.removeDish(idx)) {
                            System.out.println("Блюдо удалено.");
                        } else {
                            System.out.println("Неверный номер.");
                        }
                    } catch (NumberFormatException e) {
                        System.out.println("Некорректный ввод.");
                    }
                    break;

                case CREATE_CHECK:
                    if (restaurantMenu.getDishes().isEmpty()) {
                        System.out.println("Меню пустое, нечего заказывать.");
                        break;
                    }

                    List<CheckItem> items = new ArrayList<>();
                    boolean isCreatingCheck = true;

                    while (isCreatingCheck) {
                        restaurantMenu.printMenu();
                        System.out.print("Номер блюда (0 - завершить): ");
                        int dishId;
                        try {
                            dishId = Integer.parseInt(scanner.nextLine());
                            
                            if (dishId == 0) {
                                isCreatingCheck = false;
                                continue;
                            }
                            
                            if (dishId < 0) {
                                System.out.println("Неверный номер.");
                                continue;
                            }
                            
                            if (dishId > restaurantMenu.getDishes().size()) {
                                System.out.println("Неверный номер.");
                                continue;
                            }
                            
                            dishId--;

                        } catch (NumberFormatException e) {
                            System.out.println("Некорректный ввод.");
                            continue;
                        }

                        System.out.print("Количество порций: ");
                        int amountDishes;
                        try {
                            amountDishes = Integer.parseInt(scanner.nextLine());
                            if (amountDishes <= 0) {
                                System.out.println("Количество должно быть положительным числом.");
                                continue;
                            }
                            System.out.println("Блюдо успешно добавлено\n");
                        } catch (NumberFormatException e) {
                            System.out.println("Неверное количество. Введите целое число.");
                            continue;
                        }

                        items.add(new CheckItem(restaurantMenu.getDishes().get(dishId), amountDishes));
                    }

                    if (!items.isEmpty()) {
                        System.out.println("\n===== ЧЕК =====");
                        double total = 0;
                        for (CheckItem ci : items) {
                            System.out.println(ci);
                            total += ci.getTotalPrice();
                        }
                        System.out.printf("ИТОГО: %.2f руб.%n", total);
                        String now = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
                        System.out.println("Дата/время: " + now);
                        System.out.println("===============\n");
                    }
                    break;

                case EXIT:
                    running = false;
                    System.out.println("Выход. Спасибо за заказ!");
                    break;
            }
        }
        scanner.close();
    }
}