import java.time.LocalDate;
import java.time.Period;

public class Spw extends Employee {
    private String degree;  // учёная степень
    private String title;   // учёное звание

    public Spw() {
        super();
        this.degree = "не имеет";
        this.title = "не имеет";
    }

    public Spw(int id, String lastName, String firstName,
        int priorExperience, String degree, String title) {
        super(id, lastName, firstName, priorExperience);
        this.degree = degree;
        this.title = title;
    }

    public String getDegree() {
        return degree;
    }

    public void setDegree(String degree) {
        this.degree = degree;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    // Полное кол-во лет научно-педагогического стажа работы в организации
    public int getAcademicExperience() {
        return Period.between(getHireDate(), LocalDate.now()).getYears();
    }

    @Override
    public String toString() {
        return String.format("%s, %s, %s"
        , super.toString()
        , degree
        , title);
    }   
}
