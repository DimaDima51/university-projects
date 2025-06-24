#include "polynom.h"

Polynom::Polynom(int deg,
                 const double * mass): degree(deg), coef(new double[deg + 1]) {
    for (int i = 0; i <= degree; ++i)
        coef[i] = mass[i];
}

Polynom::~Polynom() {
    delete[] coef;
}

double Polynom::evaluate(double x) const {
    double result = 0;
    for (int i = 0; i <= degree; ++i)
        result += coef[i] * std::pow(x, i);
    return result;
}

Polynom Polynom::add(const Polynom & p2) const {
    int rd = std::max(degree, p2.degree);
    double * c = new double[rd + 1];
    for (int i = 0; i <= rd; ++i) {
        double a = (i <= degree ? coef[i] : 0.0);
        double b = (i <= p2.degree ? p2.coef[i] : 0.0);
        c[i] = a + b;
    }
    Polynom r(rd, c);
    delete[] c;
    return r;
}

Polynom Polynom::sub(const Polynom & p2) const {
    int rd = std::max(degree, p2.degree);
    double * c = new double[rd + 1];
    for (int i = 0; i <= rd; ++i) {
        double a = (i <= degree ? coef[i] : 0.0);
        double b = (i <= p2.degree ? p2.coef[i] : 0.0);
        c[i] = a - b;
    }
    Polynom r(rd, c);
    delete[] c;
    return r;
}

Polynom Polynom::mult(const Polynom & p2) const {
    int rd = degree + p2.degree;
    double * c = new double[rd + 1]();
    for (int i = 0; i <= degree; ++i)
        for (int j = 0; j <= p2.degree; ++j)
            c[i + j] += coef[i] * p2.coef[j];
    Polynom r(rd, c);
    delete[] c;
    return r;
}

void Polynom::print() const {
    bool first = true;
    for (int i = 0; i <= degree; ++i) {
        if (coef[i] == 0) continue;
        if (!first)
            std::cout << (coef[i] > 0 ? " + " : " - ");
        first = false;
        std::cout << std::abs(coef[i]);
        if (i > 0) {
            std::cout << "x";
            if (i > 1) std::cout << "^" << i;
        }
    }
    std::cout << "\n";
}
