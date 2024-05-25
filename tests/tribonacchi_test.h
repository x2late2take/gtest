#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/* using namespace testing; */
extern "C" {
#include "tribonacchi.h"
}

TEST(tribonacchiTest, num7) {
    ASSERT_EQ(tribonacchi(5), 7);
}

TEST(tribonacchiTest, num149) {
    ASSERT_EQ(tribonacchi(10), 7);
}

TEST(tribonacchiTest, num66012) {
    ASSERT_EQ(tribonacchi(20), 66012);
}
