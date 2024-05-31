#ifndef QUADRATICEQUATIONS_H
#define QUADRATICEQUATIONS_H

// Определение структуры для хранения корней квадратного уравнения
typedef struct {
    double root1;        // Первый корень уравнения
    double root2;        // Второй корень уравнения
    double discriminant; // Дискриминант квадратного уравнения
    int numRoots;        // Количество действительных корней
} Roots;

// Объявление функции для вычисления корней квадратного уравнения
Roots quadraticEquations(double a, double b, double c);

#endif // QUADRATICEQUATIONS_H
