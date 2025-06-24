import java.time.LocalDate;
import java.time.Period;

public class Employee {
    private static int count = 0;       // число принятых сотрудников
    private int stuffNumber;            // табельный номер (5 цифр)
    private String lastName, firstName; // фамилия и имя
    private LocalDate hireDate;         // дата приёма
    private int priorExperience;        // стаж на момент приёма

    public Employee() {
        this(0, "", "", 0);
    }

    public Employee(int stuffNumber, String lastName, String firstName, int priorExperience) {
        this.stuffNumber = stuffNumber;
        this.lastName = lastName;
        this.firstName = firstName;
        this.hireDate = LocalDate.now();
        this.priorExperience = priorExperience;
        count++;
    }

    public static int getCount() {
        return count;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }
    
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public int getStuffNumber() {
        return stuffNumber;
    }

    public LocalDate getHireDate() {
        return hireDate;
    }

    // Стаж работы на момент приема на работу
    public int getPriorExperience() {
        return priorExperience;
    }

    // Общий стаж
    public int getTotalExperience() {
        return priorExperience + Period.between(hireDate, LocalDate.now()).getYears();
    }

    @Override
    public String toString() {
        return String.format("%s %s, нанят: %s"
        , lastName
        , firstName
        , hireDate);
    }
}
