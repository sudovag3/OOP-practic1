#ifndef POLYNOMIAL_H
#define POLINOMIAL_H

#include <iostream>
#include <cmath>

class Polynomial {
public:
    Polynomial(int degree, double coefficients_[]);
    Polynomial(const Polynomial &p);
    ~Polynomial();
    void deepCopy(const Polynomial &p);
    Polynomial operator+(const Polynomial& other);
    Polynomial operator-(const Polynomial& other);
    Polynomial operator*(const Polynomial& other);
    Polynomial& operator =(const Polynomial &polynomial);
    double operator()(double x);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);

private:
    int degree;
    double *coefficients;
};

#endif