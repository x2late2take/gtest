#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/* using namespace testing; */
extern "C" {
#include "tribonacchi.h"
}
 
TEST(tribonacchi, positiveDiscriminant) {
    Roots roots = tribonacchi(1, -3, 2);
    ASSERT_EQ(roots.numRoots, 0);
    ASSERT_DOUBLE_EQ(roots.root1, 2);
    ASSERT_DOUBLE_EQ(roots.root2, 1);
}

TEST(tribonacchi, zeroDiscriminant) {
    Roots roots = tribonacchi(1, -2, 1);
    ASSERT_EQ(roots.numRoots, 1);
    ASSERT_DOUBLE_EQ(roots.root1, 1);
    ASSERT_DOUBLE_EQ(roots.root2, 1);
}

TEST(tribonacchi, negativeDiscriminant) {
    Roots roots = tribonacchi(1, 2, 5);
    ASSERT_EQ(roots.numRoots, 2);
}