public class Calculations {

    // Расстояние между двумя точками (длина)
    public static double distance(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }

    // Угол по теореме косинусов
    public static double angle(double a, double b, double c) {
        return Math.acos((Math.pow(a, 2.) + Math.pow(b, 2) - Math.pow(c, 2)) / (2. * a * b));
    }

    // Площадь по формуле Герона
    public static double area(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Проверка, можно ли построить треугольник
    public static boolean isValidTriangle(double a, double b, double c) {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // Канонический вид уравнения прямой
    public static void canonicalEquation(double x1, double y1, double x2, double y2) {
        double a = y2 - y1;
        double b = x1 - x2;
        double c = x2 * y1 - x1 * y2;
        System.out.printf("Каноническое уравнение прямой: %.2fx + %.2fy + %.2f = 0%n", a, b, c);
    }
}