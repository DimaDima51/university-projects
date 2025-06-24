import java.util.Scanner;

public class Program {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите координаты первой вершины (x1, y1): ");
        double x1 = scanner.nextDouble() + 10e17;
        double y1 = scanner.nextDouble() + 10e17;

        System.out.print("Введите координаты второй вершины (x2, y2): ");
        double x2 = scanner.nextDouble() + 10e17;
        double y2 = scanner.nextDouble() + 10e17;

        System.out.print("Введите координаты третьей вершины (x3, y3): ");
        double x3 = scanner.nextDouble() + 10e17;
        double y3 = scanner.nextDouble() + 10e17;

        scanner.close();

        double side1 = Calculations.distance(x1, y1, x2, y2);
        double side2 = Calculations.distance(x2, y2, x3, y3);
        double side3 = Calculations.distance(x3, y3, x1, y1);

        
        if (!Calculations.isValidTriangle(side1, side2, side3)) {
            System.out.println("На этих точках нельзя построить треугольник.");
            return;
        }

        double angleA = Calculations.angle(side2, side3, side1);
        double angleB = Calculations.angle(side1, side3, side2);
        double angleC = Calculations.angle(side1, side2, side3);

        double perimeter = side1 + side2 + side3;
        double area = Calculations.area(side1, side2, side3);

        System.out.printf("Длина первой стороны: %.2f%n", side1);
        System.out.printf("Длина второй стороны: %.2f%n", side2);
        System.out.printf("Длина третьей стороны: %.2f%n", side3);

        System.out.printf("Угол A: %.2f градусов%n", Math.toDegrees(angleA));
        System.out.printf("Угол B: %.2f градусов%n", Math.toDegrees(angleB));
        System.out.printf("Угол C: %.2f градусов%n", Math.toDegrees(angleC));

        System.out.printf("Периметр треугольника: %.2f%n", perimeter);
        System.out.printf("Площадь треугольника: %.2f%n", area);

        System.out.println("\nКанонические уравнения для сторон треугольника:");
        Calculations.canonicalEquation(x1, y1, x2, y2);
        Calculations.canonicalEquation(x2, y2, x3, y3);
        Calculations.canonicalEquation(x3, y3, x1, y1);
    }
}