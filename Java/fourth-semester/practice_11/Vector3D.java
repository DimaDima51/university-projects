public class Vector3D {
    private final Point3D vectorStart;
    private final Point3D vectorEnd;

    public Vector3D(Point3D vectorStart, Point3D vectorEnd) {
        this.vectorStart = vectorStart; // начальная точка вектора
        this.vectorEnd = vectorEnd;     // конечная точка вектора
    }

    public Point3D getVectorStart() {
        return vectorStart;
    }

    public Point3D getVectorEnd() {
        return vectorEnd;
    }

    // Компоненты в трёх плоскостях
    // (разность координат начала и конца)

    public double getDx() {
        return vectorEnd.getX() - vectorStart.getX();
    }

    public double getDy() {
        return vectorEnd.getY() - vectorStart.getY();
    }

    public double getDz() {
        return vectorEnd.getZ() - vectorStart.getZ();
    }

    // Длина вектора
    // Корень сумм квадратов
    public double length() {
        double dx = getDx();
        double dy = getDy();
        double dz = getDz();
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Скалярное произведение
    public double dot(Vector3D other) {
        return this.getDx() * other.getDx() + this.getDy() * other.getDy() + this.getDz() * other.getDz();
    }

    // Векторное произведение
    public Point3D cross(Vector3D other) {

        // Компоненты первого вектора
        double x1 = this.getDx();
        double y1 = this.getDy();
        double z1 = this.getDz();
        
        // Компоненты второго вектора
        double x2 = other.getDx();
        double y2 = other.getDy();
        double z2 = other.getDz();

        // Вычисление компонент результирующего вектора
        double cx = y1 * z2 - z1 * y2;
        double cy = z1 * x2 - x1 * z2;
        double cz = x1 * y2 - y1 * x2;

        return new Point3D(cx, cy, cz);
    }

    // Сложение векторов
    public Point3D add(Vector3D other) {

        // Сумма компонентов по каждой оси
        double rx = this.getDx() + other.getDx();
        double ry = this.getDy() + other.getDy();
        double rz = this.getDz() + other.getDz();
        return new Point3D(rx, ry, rz);
    }

    // Вычитание векторов
    public Point3D subtract(Vector3D other) {

        // Вычитание компонентов по каждой оси
        double rx = this.getDx() - other.getDx();
        double ry = this.getDy() - other.getDy();
        double rz = this.getDz() - other.getDz();
        return new Point3D(rx, ry, rz);
    }

    // Угол между векторами
    public double angle(Vector3D other) {
        double dot = this.dot(other);   // скалярное произведение
        double len1 = this.length();    // длина первого вектора
        double len2 = other.length();   // длина второго вектора
        
        // Косинус угла = скалярное произведение / (произведение векторов)
        double cosTheta = dot / (len1 * len2);

        // Могут быть неточности
        // Косинус в пределах [-1; 1]
        cosTheta = Math.max(-1.0, Math.min(1.0, cosTheta));

        double thetaRad = Math.acos(cosTheta);
        return Math.toDegrees(thetaRad);
    }

    @Override
    public String toString() {
        String vectorStartStr = vectorStart.toString();
        String vectorEndStr  = vectorEnd.toString();
        return String.format("Начало: %s  Конец: %s", vectorStartStr, vectorEndStr);
    }
}
