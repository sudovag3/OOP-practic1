#include <iostream>
#include "polynomial.h"


int main(){
    // Создаём два массива под коэффициенты
    int degree1, degree2;
    double coefficients1[20], coefficients2[20];
    // Задаём порядок полиномов и их коэффициенты
    
    std::cout << "Enter degree of first polynomial: ";
    std::cin >> degree1;
    std::cout << "Enter coefficients of first polynomial: ";
    for (int i = 0; i <= degree1; ++i) {
        std::cin >> coefficients1[i];
    }
    Polynomial p1(degree1, coefficients1);

    std::cout << "Enter degree of second polynomial: ";
    std::cin >> degree2;
    std::cout << "Enter coefficients of second polynomial: ";
    for (int i = 0; i <= degree2; ++i) {
        std::cin >> coefficients2[i];
    }
    Polynomial p2(degree2, coefficients2);

    int choice = 0;
    while (choice != 5) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Evaluate\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        double x;
        switch (choice) {
        case 1:
            std::cout << "(" << p1 << ")" << " + " << "(" << p2 << ")" << " = " << p1 + p2 << '\n';
            break;
        case 2:
            std::cout << "(" << p1 << ")" << " - " << "(" << p1 << ")" << " = " << p1 - p2 << '\n';
            break;
        case 3:
            std::cout << "(" << p1 << ")" << " * " << "(" << p1 << ")" << " = " << p1 * p2 << '\n';
            break;
        case 4:
            std::cout << "Enter value of x: ";
            std::cin >> x;
            std::cout << p1 << "First polynom evaluated at " << x << " = " << p1.evaluate(x) << '\n';
            std::cout << p1 << "Second polynom evaluated at " << x << " = " << p2.evaluate(x) << '\n';
            break;
        case 5:
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
}
    
    
    return 0;
}
