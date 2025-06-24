public enum Operation {
    LENGTH("1", "Длина вектора"),
    SUM("2", "Сложение двух векторов"),
    DIFFERENCE("3", "Вычитание двух векторов"),
    ANGLE("4", "Угол между двумя векторами"),
    DOT_PRODUCT("5", "Скалярное произведение двух векторов"),
    CROSS_PRODUCT("6", "Векторное произведение двух векторов"),
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
