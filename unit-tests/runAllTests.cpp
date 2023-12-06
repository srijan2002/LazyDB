// test_sum.cpp
#include <gtest/gtest.h>
#include "io.h"
#include "io.cpp"

// Test case for the input_prompt() function
TEST(IOFunctions, InputPrompt){
    EXPECT_EQ(input_test(), "lazydb > ");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
