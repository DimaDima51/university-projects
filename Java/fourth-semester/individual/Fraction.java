import java.math.BigDecimal;

public class Fraction {
    private int numerator;
    private int denominator;

    // Конструктор по умолчанию - создаёт дробь 1/1
    public Fraction() throws NullDenominatorException {
        this(1, 1);
    }

    // Основной конструктор: принимает числитель и знаменатель
    public Fraction(int numerator, int denominator) throws NullDenominatorException {
        if (denominator == 0) {
            throw new NullDenominatorException("Знаменатель не может быть равен 0");
        }
        this.numerator = numerator;
        this.denominator = denominator;
        simplify();
    }

    // Конструктор из целого числа: value -> value/1
    public Fraction(int value) throws NullDenominatorException {
        this(value, 1);
    }

    // Конструктор из вещественного: например, 0.75 -> 75/100 -> 3/4
    public Fraction(double realValue) throws NullDenominatorException {
        BigDecimal bd = BigDecimal.valueOf(realValue);
        int scale = bd.scale();
        this.numerator = bd.unscaledValue().intValue();
        this.denominator = BigDecimal.TEN.pow(scale).intValue();
        simplify();
    }

    // Геттеры
    public int getNumerator() {
        return numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    // Сложение
    // a/b + c/d = (a * d + c * d)/(b * d)
    public Fraction add(Fraction other) throws NullDenominatorException {
        int newNum = this.numerator * other.denominator + other.numerator * this.denominator;
        int newDen = this.denominator * other.denominator;
        return new Fraction(newNum, newDen);
    }

    public Fraction add(int value) throws NullDenominatorException {
        return add(new Fraction(value));
    }

    public Fraction add(double realValue) throws NullDenominatorException {
        return add(new Fraction(realValue));
    }

    // Вычитание
    public Fraction subtract(Fraction other) throws NullDenominatorException {
        int newNum = this.numerator * other.denominator - other.numerator * this.denominator;
        int newDen = this.denominator * other.denominator;
        return new Fraction(newNum, newDen);
    }

    public Fraction subtract(int value) throws NullDenominatorException {
        return subtract(new Fraction(value));
    }

    public Fraction subtract(double realValue) throws NullDenominatorException {
        return subtract(new Fraction(realValue));
    }

    // Умножение
    public Fraction multiply(Fraction other) throws NullDenominatorException {
        int newNum = this.numerator * other.numerator;
        int newDen = this.denominator * other.denominator;
        return new Fraction(newNum, newDen);
    }

    public Fraction multiply(int value) throws NullDenominatorException {
        return multiply(new Fraction(value));
    }

    public Fraction multiply(double realValue) throws NullDenominatorException {
        return multiply(new Fraction(realValue));
    }

    // Деление
    public Fraction divide(Fraction other) throws NullDenominatorException {
        if (other.numerator == 0) {
            throw new NullDenominatorException("Деление на дробь с нулевым числителем");
        }
        int newNum = this.numerator * other.denominator;
        int newDen = this.denominator * other.numerator;
        return new Fraction(newNum, newDen);
    }

    public Fraction divide(int value) throws NullDenominatorException {
        return divide(new Fraction(value));
    }

    public Fraction divide(double realValue) throws NullDenominatorException {
        return divide(new Fraction(realValue));
    }

    // Сравнение: равно
    public boolean equals(Fraction other) {
        return this.numerator * other.denominator == other.numerator * this.denominator;
    }

    public boolean equals(int value) throws NullDenominatorException {
        return equals(new Fraction(value));
    }

    public boolean equals(double realValue) throws NullDenominatorException {
        return equals(new Fraction(realValue));
    }

    // Не равно
    public boolean notEquals(Fraction other) {
        return !equals(other);
    }

    public boolean notEquals(int value) throws NullDenominatorException {
        return notEquals(new Fraction(value));
    }

    public boolean notEquals(double realValue) throws NullDenominatorException {
        return notEquals(new Fraction(realValue));
    }

    // Больше: a/b > c/d <-> a*d > c*b
    public boolean greaterThan(Fraction other) {
        return this.numerator * other.denominator > other.numerator * this.denominator;
    }

    public boolean greaterThan(int value) throws NullDenominatorException {
        return greaterThan(new Fraction(value));
    }

    public boolean greaterThan(double realValue) throws NullDenominatorException {
        return greaterThan(new Fraction(realValue));
    }

    // Меньше: a/b < c/d <-> a*d < c*b
    public boolean lesserThan(Fraction other) {
        return this.numerator * other.denominator < other.numerator * this.denominator;
    }

    public boolean lesserThan(int value) throws NullDenominatorException {
        return lesserThan(new Fraction(value));
    }

    public boolean lesserThan(double realValue) throws NullDenominatorException {
        return lesserThan(new Fraction(realValue));
    }

    // Больше или равно
    public boolean greaterOrEqual(Fraction other) {
        return greaterThan(other) || equals(other);
    }

    public boolean greaterOrEqual(int value) throws NullDenominatorException {
        return greaterOrEqual(new Fraction(value));
    }

    public boolean greaterOrEqual(double realValue) throws NullDenominatorException {
        return greaterOrEqual(new Fraction(realValue));
    }

    // Меньше или равно
    public boolean lesserOrEqual(Fraction other) {
        return lesserThan(other) || equals(other);
    }

    public boolean lesserOrEqual(int value) throws NullDenominatorException {
        return lesserOrEqual(new Fraction(value));
    }

    public boolean lesserOrEqual(double realValue) throws NullDenominatorException {
        return lesserOrEqual(new Fraction(realValue));
    }

    // Сокращение дроби (алгоритм Евклида)
    private void simplify() {
        int g = gcd(Math.abs(numerator), Math.abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Общий делитель
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Печать дроби в виде "числитель/знаменатель"
    public void print() {
        System.out.print(numerator + "/" + denominator);
    }
}
