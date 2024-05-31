#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/* using namespace testing; */
extern "C" {
#include "quadraticEquations.h"
}

// Тестирование функции quadraticEquations с положительным дискриминантом
TEST(quadraticEquations_test, positiveDiscriminant) {
    // Вызов функции с коэффициентами, дающими положительный дискриминант
    Roots roots = quadraticEquations(1, -3, 2);
    // Проверка, что функция возвращает два корня
    ASSERT_EQ(roots.numRoots, 0);
    // Проверка точности вычисленных корней
    ASSERT_DOUBLE_EQ(roots.root1, 2);
    ASSERT_DOUBLE_EQ(roots.root2, 1);
}

// Тестирование функции quadraticEquations с нулевым дискриминантом
TEST(quadraticEquations_test, zeroDiscriminant) {
    // Вызов функции с коэффициентами, дающими нулевой дискриминант
    Roots roots = quadraticEquations(1, -2, 1);
    // Проверка, что функция возвращает один корень
    ASSERT_EQ(roots.numRoots, 1);
    // Проверка точности вычисленного корня
    ASSERT_DOUBLE_EQ(roots.root1, 1);
    ASSERT_DOUBLE_EQ(roots.root2, 1);
}

// Тестирование функции quadraticEquations с отрицательным дискриминантом
TEST(quadraticEquations_test, negativeDiscriminant) {
    // Вызов функции с коэффициентами, дающими отрицательный дискриминант
    Roots roots = quadraticEquations(1, 2, 5);
    // Проверка, что функция не возвращает корней
    ASSERT_EQ(roots.numRoots, 2);
}

// Тест для проверки корректности вычисления дискриминанта
TEST(quadraticEquations_test, discriminantCalculation) {
    // Вызов функции с известными коэффициентами
    Roots roots = quadraticEquations(1, -3, 2);
    // Проверка точности вычисленного дискриминанта
    ASSERT_DOUBLE_EQ(roots.discriminant, 1);
}

// Тесты для проверки функции с маленькими коэффициентами
TEST(quadraticEquations_test, smallCoefficients) {
    // Вызов функции с очень маленькими коэффициентами
    Roots roots = quadraticEquations(1e-308, -3e-308, 2e-308);
    // Проверка, что функция корректно обрабатывает маленькие числа
    ASSERT_EQ(roots.numRoots, 2);
}

// Тесты для проверки точности вычислений функции
TEST(quadraticEquations_test, calculationAccuracy) {
    // Вызов функции с коэффициентами, близкими к целым числам
    Roots roots = quadraticEquations(1, -3.0000001, 2.0000001);
    // Проверка, что функция возвращает корни, близкие к ожидаемым значениям
    ASSERT_NEAR(roots.root1, 2, 1e-6);
    ASSERT_NEAR(roots.root2, 1, 1e-6);
}

// Тест для проверки поведения функции при нулевом коэффициенте 'a'
TEST(quadraticEquations_test, zeroACoefficient) {
    // Вызов функции с нулевым коэффициентом 'a'
    Roots roots = quadraticEquations(0, -3, 2);
    // Проверка, что функция не возвращает корней
    ASSERT_EQ(roots.numRoots, 0);
}

// Тест для проверки поведения функции при всех нулевых коэффициентах
TEST(quadraticEquations_test, allZeroCoefficients) {
    // Вызов функции со всеми нулевыми коэффициентами
    Roots roots = quadraticEquations(0, 0, 0);
    // Проверка, что функция не возвращает корней
    ASSERT_EQ(roots.numRoots, 0);
}

