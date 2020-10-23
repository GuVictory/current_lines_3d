//
// Created by Виктория Губанова on 03.09.2020.
//

#include <gtest/gtest.h>
#include <Line.h>
#include <cmath>

#include <iostream>

TEST(LineTest, simpleLineGeneration)
{
    auto* n1 = new Node();
    auto* n2 = new Node();

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line();

    EXPECT_EQ(*l1, *l2) << "Lines isn\'t the same";
}

TEST(LineTest, lineLen)
{
    auto* n1 = new Node(1.0, 3.0);
    auto* n2 = new Node(2.0, 5.0);

    auto* l = new Line(*n1, *n2);

    EXPECT_EQ(l->len(), sqrt(5)) << "Lines isn\'t the same";
}

TEST(LineTest, lineContainsPointTrue)
{
    auto* n1 = new Node(0.0, 0.0);
    auto* n2 = new Node(3.0, 4.0);

    auto* l = new Line(*n1, *n2);

    EXPECT_TRUE(l->containsPoint(*new Point(6.0, 8.0, 0.0))) << "Lines contains point not working";
}

TEST(LineTest, lineContainsPointTrue2)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 1.0, 1.0);

    auto* l = new Line(*n1, *n2);

    EXPECT_TRUE(l->containsPoint(*new Point(2.0, 2.0, 2.0))) << "Lines contains point not working";
}

TEST(LineTest, lineContainsPointFalse)
{
    auto* n1 = new Node(0.0, 0.0);
    auto* n2 = new Node(3.0, 4.0);

    auto* l = new Line(*n1, *n2);

    EXPECT_FALSE(l->containsPoint(*new Point(1.0, 8.0, 0.0))) << "Lines contains point not working";
}

TEST(LineTest, lineContainsPointFalse2)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(1.0, 1.0, 1.0);

    auto* l = new Line(*n1, *n2);

    EXPECT_FALSE(l->containsPoint(*new Point(2.0, 3.0, 2.0))) << "Lines contains point not working";
}

TEST(LineTest, linesAreNotInterbreedingTestTrue)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(3.0, 0.0, 1.0);

    auto* n3 = new Node(0.0, 0.0, 0.0);
    auto* n4 = new Node(1.0, 0.0, 3.0);

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line(*n3, *n4);

    EXPECT_TRUE(l1->areNotInterbreeding(*l2)) << "Lines AreNotInterbreeding not working";
}

TEST(LineTest, linesAreNotInterbreedingTestFalse)
{
    auto* n1 = new Node(0.0, 0.0, 0.0);
    auto* n2 = new Node(3.0, 0.0, 1.0);

    auto* n3 = new Node(0.0, 2.0, 0.0);
    auto* n4 = new Node(0.0, 0.0, 2.0);

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line(*n3, *n4);

    EXPECT_FALSE(l1->areNotInterbreeding(*l2)) << "Lines AreNotInterbreeding not working";
}

TEST(LineTest, linesAreParallelTestTrue)
{
    auto* n1 = new Node(0.0, 0.0, 3.0);
    auto* n2 = new Node(6.0, 0.0, 3.0);

    auto* n3 = new Node(0.0, 0.0, 1.0);
    auto* n4 = new Node(6.0, 0.0, 1.0);

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line(*n3, *n4);

    EXPECT_TRUE(l1->areParallel(*l2)) << "Lines AreParallel true not working";
}

TEST(LineTest, linesAreParallelTestTrue2)
{
    auto* n1 = new Node(0.0, 1.0, 0.0);
    auto* n2 = new Node(1.0, 1.0, 4.0);

    auto* n3 = new Node(0.0, 2.0, 0.0);
    auto* n4 = new Node(1.0, 2.0, 4.0);

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line(*n3, *n4);

    EXPECT_TRUE(l1->areParallel(*l2)) << "Lines AreParallel true not working";
}

TEST(LineTest, linesAreParallelTestFalse)
{
    auto* n1 = new Node(0.0, 0.0, 4.0);
    auto* n2 = new Node(0.0, 6.0, 2.0);

    auto* n3 = new Node(0.0, 0.0, 2.0);
    auto* n4 = new Node(0.0, 4.0, 4.0);

    auto* l1 = new Line(*n1, *n2);
    auto* l2 = new Line(*n3, *n4);

    EXPECT_FALSE(l1->areParallel(*l2)) << "Lines AreParallel false not working";
}