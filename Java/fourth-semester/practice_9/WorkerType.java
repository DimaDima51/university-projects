public enum WorkerType {
    TEACHER("1", "Преподаватель"),
    RESEARCHER("2", "Научный сотрудник");

    private final String code;
    private final String description;

    WorkerType(String code, String description) {
        this.code = code;
        this.description = description;
    }

    public String getCode() {
        return code;
    }

    public String getDescription() {
        return description;
    }

    public static WorkerType fromCode(String code) {
        for (WorkerType type : values()) {
            if (type.getCode().equals(code)) {
                return type;
            }
        }
        return null;
    }
}
