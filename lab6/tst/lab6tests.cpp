#include <gtest/gtest.h>
#include "Polynom.h"

TEST(PolynomTest, test1)
{
    constexpr int arr[] = {1, 2, 1};
    constexpr int m = compile_time_calc(1, arr, 3);

    ASSERT_EQ(m, 4);
}

TEST(PolynomTest, test2)
{
    constexpr int arr[] = {2, 2, 2};
    constexpr int m = compile_time_calc(1, arr, 3);

    ASSERT_EQ(m, 6);
}

TEST(PolynomTest, test3)
{
    constexpr int arr[] = {10, 12, 13};
    constexpr int m = compile_time_calc(1, arr, 3);

    ASSERT_EQ(m, 35);
}

TEST(PolynomTest, test4)
{
    constexpr int arr[] = {100, 200, 300};
    constexpr int m = compile_time_calc(1, arr, 3);

    ASSERT_EQ(m, 600);
}

TEST(PolynomTest, test5)
{
    constexpr int arr[] = {100500, 2, 1};
    constexpr int m = compile_time_calc(1, arr, 3);

    ASSERT_EQ(m, 100503);
}

