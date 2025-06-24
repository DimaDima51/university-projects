public abstract class Validator {
    protected Validator() {}

    public boolean validate(String str) {
        return false;
    }

    public static Validator createEmailValidator() {
        return new EmailValidator();
    }

    public static Validator createPhoneValidator() {
        return new PhoneValidator();
    }

    public static Validator createBirthDateValidator() {
        return new BirthDateValidator();
    }
}

class EmailValidator extends Validator {
    private static final String REGEX = "^[A-Za-z0-9]+(?:[._-][A-Za-z0-9]+)*@(?:[A-Za-z]+(?:\\.[A-Za-z]+)*)\\.(?:ru|org|com)$";

    @Override
    public boolean validate(String email) {
        return email.matches(REGEX);
    }
}

class PhoneValidator extends Validator {
    private static final String REGEX = "^\\+7(?:9\\d{2}|7\\d{2})\\d{7}$";

    @Override
    public boolean validate(String phone) {
        return phone.matches(REGEX);
    }
}

class BirthDateValidator extends Validator {
    private static final String REGEX = "^(0[1-9]|1[0-2])\\.(19[6-9]\\d|200[0-5])$";

    @Override
    public boolean validate(String date) {
        return date.matches(REGEX);
    }
}
