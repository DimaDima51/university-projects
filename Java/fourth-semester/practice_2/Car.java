public class Car {
    private int seats; 
    private int fuelTankVolume; 
    private int enginePower; 
    private double fuelConsumption; 
    private int trunkVolume; 
    private int mileage; 

    public Car(int seats, int fuelTankVolume, int enginePower, double fuelConsumption, int trunkVolume, int mileage) {
        this.seats = seats;
        this.fuelTankVolume = fuelTankVolume;
        this.enginePower = enginePower;
        this.fuelConsumption = fuelConsumption;
        this.trunkVolume = trunkVolume;
        this.mileage = mileage;
    }

    public int getSeats() {
        return seats;
    }

    public int getFuelTankVolume() {
        return fuelTankVolume;
    }

    public int getEnginePower() {
        return enginePower;
    }

    public double getFuelConsumption() {
        return fuelConsumption;
    }

    public int getTrunkVolume() {
        return trunkVolume;
    }

    public int getMileage() {
        return mileage;
    }

    // Количество пассажиров
    public int getPassengerCount() {
        return seats - 1;
    }

    // Дальность поездки при полном баке
    public double getRange() {
        return (fuelTankVolume / fuelConsumption) * 100.0;
    }

    // Необходимое количество топлива для поездки
    public double getFuelNeeded(double distance) {
        return (distance / 100.0) * fuelConsumption;
    }

    // Количество километров сверх 150 000 км
    public int getMileageOver150k() {
        return Math.max(mileage - 150000, 0);
    }
}