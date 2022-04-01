#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "sample.cpp"

class SampleTest : public ::testing::Test {
 protected:
    void SetUp() override { s = Sample(); }

    // void TearDown() override {}
    Sample s;
};

TEST_F(SampleTest, inputZero) {
    int input = 0;
    int expect = 1;

     EXPECT_EQ(expect, s.increase(input));
}
