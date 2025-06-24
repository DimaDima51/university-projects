public class Teacher extends Spw {
    private int methodologicalWorks;    // число методических работ

    public Teacher() {
        super();
        this.methodologicalWorks = 0;
    }

    public Teacher(int id, String lastName, String firstName,
        int priorExperience, String degree, String title,
        int methodologicalWorks) {
        super(id, lastName, firstName, priorExperience, degree, title);
        this.methodologicalWorks = methodologicalWorks;
    }

    public int getMethodologicalWorks() {
        return methodologicalWorks;
    }
    public void setMethodologicalWorks(int methodologicalWorks) {
        this.methodologicalWorks = methodologicalWorks;
    }

    @Override
    public String toString() {
        return String.format("%s, Число работ: %d"
        , super.toString()
        , methodologicalWorks);
    }
}
