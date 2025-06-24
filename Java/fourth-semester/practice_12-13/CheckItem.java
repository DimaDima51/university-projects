public class CheckItem {
    private final Dish dish;
    private final int quantity;

    public CheckItem(Dish dish, int quantity) {
        this.dish = dish;
        this.quantity = quantity;
    }

    public double getTotalPrice() {
        return dish.getPrice() * quantity;
    }

    @Override
    public String toString() {
        return String.format("%s x %d = %.2f руб."
            , dish.getName()
            , quantity
            , getTotalPrice());
    }
}
