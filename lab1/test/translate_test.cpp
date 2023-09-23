#include <gtest/gtest.h>
#include "../src/translate_into_turkish.hpp"

TEST(TurkishNumbers, ConvertToTurkish) {
    EXPECT_EQ(TranslateIntoTurkish(0), "sıfır");
    EXPECT_EQ(TranslateIntoTurkish(10), "on");
    EXPECT_EQ(TranslateIntoTurkish(21), "yirmi bir");
    EXPECT_EQ(TranslateIntoTurkish(99), "doksan dokuz");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}