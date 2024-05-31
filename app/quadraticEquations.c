#include <math.h>
#include <quadraticEquations.h>

// Структура для хранения корней и дискриминанта
struct Roots {
    double root1, root2; // Корни уравнения, если они есть
    double discriminant; // Дискриминант квадратного уравнения
    int numRoots;        // Количество действительных корней
};

// Функция для вычисления корней квадратного уравнения
Roots quadraticEquations(double a, double b, double c) {
    Roots roots;
    // Вычисление дискриминанта
    double discriminant = b * b - 4 * a * c;
    roots.discriminant = discriminant;

    // Проверка значения дискриминанта для определения количества корней
    if (discriminant > 0) {
        // Два различных действительных корня
        roots.root1 = (-b + sqrt(discriminant)) / (2 * a);
        roots.root2 = (-b - sqrt(discriminant)) / (2 * a);
        roots.numRoots = 2;
    } else if (discriminant == 0) {
        // Один действительный корень (кратность 2)
        roots.root1 = roots.root2 = -b / (2 * a);
        roots.numRoots = 1;
    } else {
        // Нет действительных корней
        roots.numRoots = 0;
    }

    return roots; // Возвращение структуры с корнями и дискриминантом
}
