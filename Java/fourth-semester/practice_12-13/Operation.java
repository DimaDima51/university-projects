public enum Operation {
    SHOW_MENU("1", "Показать меню"),
    ADD_DISH("2", "Добавить блюдо в меню"),
    REMOVE_DISH("3", "Удалить блюдо из меню"),
    CREATE_CHECK("4", "Сделать заказ"),
    EXIT("0", "Выход");

    private final String code;
    private final String description;

    Operation(String code, String description) {
        this.code = code;
        this.description = description;
    }

    public String getCode() { return code; }
    public String getDescription() { return description; }

    public static Operation fromCode(String code) {
        for (Operation op : Operation.values()) {
            if (op.code.equals(code)) {
                return op;
            }
        }
        return null;
    }
}
