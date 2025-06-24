#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>

#include <cmath>

class Polynom {
    public: Polynom(int degree,
                const double * coeff);
        ~Polynom();

        double evaluate(double x) const;
        Polynom add(const Polynom & other) const;
        Polynom sub(const Polynom & other) const;
        Polynom mult(const Polynom & other) const;
        void print() const;

        // для тестов: получить коэффициент i
        double coeff(int i) const {
            return coef[i];
        }
        int deg() const {
            return degree;
        }

    private: int degree;
        double * coef;
};

#endif // POLYNOM_H
