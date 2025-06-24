import java.util.ArrayList;
import java.util.List;

public class Menu {
    private final List<Dish> dishes = new ArrayList<>();

    public void addDish(Dish dish) {
        dishes.add(dish);
    }

    public boolean removeDish(int index) {
        if (index >= 0 && index < dishes.size()) {
            dishes.remove(index);
            return true;
        }
        return false;
    }

    public List<Dish> getDishes() {
        return dishes;
    }

    public void printMenu() {
        if (dishes.isEmpty()) {
            System.out.println("Меню пустое.");
            return;
        }
        System.out.println("Текущие блюда в меню:");
        for (int i = 0; i < dishes.size(); i++) {
            System.out.printf("%d) %s%n"
            , i + 1
            , dishes.get(i));
        }
    }
}
