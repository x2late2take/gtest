#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/* using namespace testing; */
extern "C" {
#include "tribonacchi.h"
}

TEST(tribonacchiTest, num0) {
    ASSERT_EQ(tribonacchi(0), 0);
    ASSERT_EQ(tribonacchi(1), 1);
    ASSERT_EQ(tribonacchi(2), 1);
}

TEST(tribonacchiTest, negativeInput) {
    ASSERT_EQ(tribonacchi(-5), 0);
}

TEST(tribonacchiTest, largeValue) {
    ASSERT_EQ(tribonacchi(50), 5742568741225);
}
