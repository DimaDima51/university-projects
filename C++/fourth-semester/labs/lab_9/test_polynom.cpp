#include <QTest>

#include "polynom.h"

class Test_Polynom: public QObject {
    Q_OBJECT

private slots:

    void testEvaluate_data() {
        // Аргумент x и ожидаемое значение p(x)
        QTest::addColumn < double > ("x");
        QTest::addColumn < double > ("expected");

        QTest::newRow("При x=0 возвращается свободный член") << 0.0 << 3.0; // p(0)=3
        QTest::newRow("При x=1 суммируются все коэффициенты") << 1.0 << 7.0; // 3+2+1=7 - Специально не верно
        QTest::newRow("При x=2 учитываются старшие степени") << 2.0 << 11.0; // 3+4+4=11
    }

    void testEvaluate() {
        QFETCH(double, x);
        QFETCH(double, expected);

        // Полином p(x) = 3 + 2x + 1x^2
        double coeffs[] = {
            3.0,
            2.0,
            1.0
        };
        Polynom p(2, coeffs);

        // Сравниваем фактический результат с ожидаемым
        QCOMPARE(p.evaluate(x), expected);
    }

    // Проверка операции сложения двух полиномов
    void testAdd() {
        // p1(x) = 1 + 2x
        double a1[] = {
            1,
            2
        };
        // p2(x) = 3 - x + 4x^2
        double a2[] = {
            3,
            -1,
            4
        };

        Polynom p1(1, a1), p2(2, a2);
        Polynom sum = p1.add(p2);

        // Ожидаем новый полином: (1+3) + (2-1)x + 4x^2 => 4 + 1x + 4x^2
        QCOMPARE(sum.deg(), 2);
        QCOMPARE(sum.coeff(0), 4.0); // свободный член
        QCOMPARE(sum.coeff(1), 1.0); // коэффициент при x
        QCOMPARE(sum.coeff(2), 4.0); // при x^2
    }

    // Проверка операции вычитания p1 - p2
    void testSub() {
        // p1(x) = 5 + 0x + 2x^2
        double a1[] = {
            5,
            0,
            2
        };
        // p2(x) = 1 + x
        double a2[] = {
            1,
            1
        };

        Polynom p1(2, a1), p2(1, a2);
        Polynom diff = p1.sub(p2);

        // Ожидаем: (5-1) + (0-1)x + 2x^2 => 4 - 1x + 2x^2
        QCOMPARE(diff.deg(), 2);
        QCOMPARE(diff.coeff(0), 4.0); // свободный член
        QCOMPARE(diff.coeff(1), -1.0); // коэффициент при x
        QCOMPARE(diff.coeff(2), 2.0); // при x^2
    }

    // Проверка операции умножения p1 * p2
    void testMult() {
        // p1(x) = 1 + x
        double a1[] = {
            1,
            1
        };
        // p2(x) = 1 + 2x
        double a2[] = {
            1,
            2
        };

        Polynom p1(1, a1), p2(1, a2);
        Polynom prod = p1.mult(p2);

        // (1+x)*(1+2x) = 1 + 3x + 2x^2
        QCOMPARE(prod.deg(), 2);
        QCOMPARE(prod.coeff(0), 1.0); // свободный член
        QCOMPARE(prod.coeff(1), 3.0); // коэффициент при x
        QCOMPARE(prod.coeff(2), 2.0); // при x^2
    }
};

QTEST_MAIN(Test_Polynom)
#include "test_polynom.moc"
