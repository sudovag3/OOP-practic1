#include "polynomial.h"

Polynomial::Polynomial(int degree, double coefficients[])
    : degree(degree), coefficients(new double[degree + 1]) {
    for (int i = 0; i <= degree; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

double Polynomial::evaluate(double x) {
    double result = 0;
    for (int i = degree; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) {
    int new_degree = std::max(degree, other.degree);
    // Обнуляем все коэффициенты 
    double *new_coefficients = new double[new_degree + 1];
    for (int i = 0; i <= new_degree; ++i) {
        new_coefficients[i] = 0;
    }
    // По очереди добавляаем коэффициенты с обоих полиномов 
    for (int i = 0; i <= degree; ++i) {
        new_coefficients[i] += coefficients[i];
    }
    for (int i = 0; i <= other.degree; ++i) {
        new_coefficients[i] += other.coefficients[i];
    }
    return Polynomial(new_degree, new_coefficients);
}

Polynomial Polynomial::operator-(const Polynomial& other) {
    int new_degree = std::max(degree, other.degree);
    double *new_coefficients = new double[new_degree + 1];
    // Обнуляем все коэффициенты 
    for (int i = 0; i <= new_degree; ++i) {
        new_coefficients[i] = 0;
    }
    // Добавляаем коэффициенты с полинома - уменьшаемого
    for (int i = 0; i <= degree; ++i) {
        new_coefficients[i] += coefficients[i];
    }
    // Вычитаем коэффициенты полинома - вычитаемого
    for (int i = 0; i <= other.degree; ++i) {
        new_coefficients[i] -= other.coefficients[i];
    }
    // Возвращаем разность
    return Polynomial(new_degree, new_coefficients);
}

Polynomial Polynomial::operator*(const Polynomial& other) {
    int new_degree = degree + other.degree;
    double *new_coefficients = new double[new_degree + 1];
    // Обнуляем все коэффициенты 
    for (int i = 0; i <= new_degree; ++i) {
        new_coefficients[i] = 0;
    }

    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= other.degree; ++j) {
            new_coefficients[i + j] += coefficients[i] * other.coefficients[j];
                }
            }
        return Polynomial(new_degree, new_coefficients);
    }

//Перегружаем оператор << для вывода
std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    for (int i = p.degree; i >= 0; --i) {
        out << p.coefficients[i];
        if (i > 0) {
            out << "x^" << i << " + ";
            }
        }
        return out;
    }