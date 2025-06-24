public enum MenuOption {
    CHECK_BALANCE("1", "Проверить баланс"),
    WITHDRAW("2", "Снять со счета"),
    DEPOSIT("3", "Положить на счет"),
    MONTHLY_INTEREST("4", "Сумма ежемесячных процентов"),
    SHOW_ALL_TRANSACTIONS("5", "Показать все транзакции"),
    SHOW_SUCCESS_TRANSACTIONS("6", "Показать успешные транзакции"),
    SHOW_FAILED_TRANSACTIONS("7", "Показать отклонённые транзакции"),
    SWITCH_ACCOUNT("8", "Сменить аккаунт"),
    EXIT("9", "Выйти");

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
        for (MenuOption option : MenuOption.values()) {
            if (option.getCode().equals(code)) {
                return option;
            }
        }
        return null;
    }
}
