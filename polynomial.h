#ifndef POLYNOMIAL_H
#define POLINOMIAL_H

#include <iostream>
#include <cmath>

class Polynomial {
public:
    Polynomial(int degree, double coefficients[]);
    double evaluate(double x);
    Polynomial operator+(const Polynomial& other);
    Polynomial operator-(const Polynomial& other);
    Polynomial operator*(const Polynomial& other);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);

private:
    int degree;
    double *coefficients;
};

#endif