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

