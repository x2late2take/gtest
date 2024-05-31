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
