//
// Created by Виктория Губанова on 23.10.2020.
//

// TODO: Разобраться почему этот файл не линкуется в тесты...

/*
#include <gtest/gtest.h>
#include "GaussSolve.h"

TEST(GaussTest, simpleGaussTestSize2)
{
    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(2);
    std::vector<double> B = std::vector<double>(2);

    A[0] = std::vector<double>(2);
    A[1] = std::vector<double>(2);

    A[0][0] = 1;
    A[0][1] = -1;
    A[1][0] = 2;
    A[1][1] = 1;

    B[0] = -5;
    B[1] = -7;

    std::vector<double> expected = std::vector<double>(2);

    expected[0] = -4;
    expected[1] = 1;

    EXPECT_TRUE(gauss(A, B, 2).first);
    EXPECT_EQ(expected, gauss(A, B, 2).second) << "Gauss with size 2 not working!";
}

TEST(GaussTest, simpleGaussTestSize3)
{
    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(3);
    std::vector<double> B = std::vector<double>(3);

    A[0] = std::vector<double>(3);
    A[1] = std::vector<double>(3);
    A[2] = std::vector<double>(3);

    A[0][0] = 4;
    A[0][1] = 2;
    A[0][2] = -1;
    A[1][0] = 5;
    A[1][1] = 3;
    A[1][2] = -2;
    A[2][0] = 3;
    A[2][1] = 2;
    A[2][2] = -3;

    B[0] = 1;
    B[1] = 2;
    B[2] = 0;

    std::vector<double> expected = std::vector<double>(3);

    expected[0] = -1;
    expected[1] = 3;
    expected[2] = 1;

    auto result = gauss(A, B, 3);

    EXPECT_TRUE(result.first);

    // Для теста снизим точность решения до 2х знаков после запятой
    for (int i = 0; i < 3; i++) {
        result.second[i] = round(result.second[i] *100)/100;
    }

    EXPECT_EQ(expected, result.second) << "Gauss with size 3 not working!";
}

TEST(GaussTest, simpleGaussTestSize2_2)
{
    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(2);
    std::vector<double> B = std::vector<double>(2);

    A[0] = std::vector<double>(2);
    A[1] = std::vector<double>(2);

    A[0][0] = 1;
    A[0][1] = 3;
    A[1][0] = 1;
    A[1][1] = 4;

    B[0] = 4;
    B[1] = 7;

    std::vector<double> expected = std::vector<double>(2);

    expected[0] = -5;
    expected[1] = 3;

    EXPECT_TRUE(gauss(A, B, 2).first);
    EXPECT_EQ(expected, gauss(A, B, 2).second) << "Gauss with size 2 not working!";
}
 */