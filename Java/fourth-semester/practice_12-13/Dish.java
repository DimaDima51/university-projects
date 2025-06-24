public class Dish {
    private final String name;        // название блюда
    private final int weight;         // граммы
    private final boolean vegetarian; // вегетарианское?
    private final double price;       // стоимость порции

    public Dish(String name, int weight, boolean vegetarian, double price) {
        this.name = name;
        this.weight = weight;
        this.vegetarian = vegetarian;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public int getWeight() {
        return weight;
    }
    
    public boolean isVegetarian() {
        return vegetarian;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return String.format("%s (%d гр.)%s - %.2f руб."
            , name
            , weight
            , vegetarian ? " [Вегет.]" : ""
            , price);
    }
}
