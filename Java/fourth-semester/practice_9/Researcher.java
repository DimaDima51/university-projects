public class Researcher extends Spw {
    private String researchRank;    // научное звание
    private int hIndex;             // индекс Хирша

    public Researcher() {
        super();
        this.researchRank = "не имеет";
        this.hIndex = 0;
    }

    public Researcher(int id, String lastName, String firstName,
        int priorExperience, String degree, String title,
        String researchRank, int hIndex) {
        super(id, lastName, firstName, priorExperience, degree, title);
        this.researchRank = researchRank;
        this.hIndex = hIndex;
    }

    public String getResearchRank() {
        return researchRank;
    }
    
    public void setResearchRank(String researchRank) {
        this.researchRank = researchRank;
    }

    public int getHIndex() {
        return hIndex;
    }

    public void setHIndex(int hIndex) {
        this.hIndex = hIndex;
    }

    @Override
    public String toString() {
        return String.format("%s, %s, Индекс Хирша: %d"
        , super.toString()
        , researchRank
        , hIndex);
    }
}
