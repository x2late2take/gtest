#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/* using namespace testing; */
extern "C" {
#include "quadraticEquations.h"
}
 
TEST(quadraticEquations_test, positiveDiscriminant) {
    Roots roots = quadraticEquations(1, -3, 2);
    ASSERT_EQ(roots.numRoots, 2);
    ASSERT_DOUBLE_EQ(roots.root1, 2);
    ASSERT_DOUBLE_EQ(roots.root2, 1);
}

TEST(quadraticEquations_test, zeroDiscriminant) {
    Roots roots = quadraticEquations(1, -2, 1);
    ASSERT_EQ(roots.numRoots, 1);
    ASSERT_DOUBLE_EQ(roots.root1, 1);
    ASSERT_DOUBLE_EQ(roots.root2, 1);
}

TEST(quadraticEquations_test, negativeDiscriminant) {
    Roots roots = quadraticEquations(1, 2, 5);
    ASSERT_EQ(roots.numRoots, 0);
}

TEST(quadraticEquations_test, positiveDiscriminantLarge) {
    Roots roots = quadraticEquations(2, -11, 5);
    ASSERT_EQ(roots.numRoots, 2);
    ASSERT_NEAR(roots.root1, 5.0, 0.001);
    ASSERT_NEAR(roots.root2, 0.5, 0.001);
}

TEST(quadraticEquations_test, zeroDiscriminantLarge) {
    Roots roots = quadraticEquations(3, -18, 27);
    ASSERT_EQ(roots.numRoots, 1);
    ASSERT_DOUBLE_EQ(roots.root1, 3);
    ASSERT_DOUBLE_EQ(roots.root2, 3);
}

TEST(quadraticEquations_test, negativeDiscriminantLarge) {
    Roots roots = quadraticEquations(1, -3, 10);
    ASSERT_EQ(roots.numRoots, 0);
}