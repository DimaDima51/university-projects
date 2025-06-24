public enum MenuOption {
    ADD_WORKER("1", "Добавить нового сотрудника"),
    SHOW_WORKERS("2", "Показать всех сотрудников"),
    FIND_WORKER("3", "Найти сотрудника по табельному номеру"),
    EXIT("4", "Выход");

    private final String code;
    private final String description;

    MenuOption(String code, String description) {
        this.code = code;
        this.description = description;
    }

    public String getCode() {
        return code;
    }

    public String getDescription() {
        return description;
    }

    public static MenuOption fromCode(String code) {
        for (MenuOption option : values()) {
            if (option.getCode().equals(code)) {
                return option;
            }
        }
        return null;
    }
}
