public enum Operation {
    ADD("1", "Сложение"),
    SUBTRACT("2", "Вычитание"),
    MULTIPLY("3", "Умножение"),
    DIVIDE("4", "Деление"),
    EQUAL("5", "Равно"),
    NOT_EQUAL("6", "Не равно"),
    GREATER("7", "Больше"),
    LESSER("8", "Меньше"),
    GREATER_OR_EQUAL("9", "Больше или равно"),
    LESSER_OR_EQUAL("10", "Меньше или равно"),
    EXIT("0", "Выход");

    private final String code;
    private final String description;

    Operation(String code, String description) {
        this.code = code;
        this.description = description;
    }

    public String getCode() {
        return code;
    }

    public String getDescription() {
        return description;
    }

    public static Operation fromCode(String code) {
        for (Operation op : Operation.values()) {
            if (op.getCode().equals(code)) {
                return op;
            }
        }
        return null;
    }
}
