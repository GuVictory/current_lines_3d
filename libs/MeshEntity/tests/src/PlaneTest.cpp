//
// Created by Виктория Губанова on 04.09.2020.
//

#include <gtest/gtest.h>
#include <Plane.h>

#include <iostream>

TEST(PlaneTest, foundPlaneTypeYZ)
{
    auto* n1 = new Node(0.0, 1.2, 2);
    auto* n2 = new Node(0.0, 2, 1);
    auto* n3 = new Node(0.0, 2, 2);
    auto* n4 = new Node(0.0, 1.2, 1);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::YZ) << "PlaneType YZ isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeXY)
{
    auto* n1 = new Node(2.0, 2, 0);
    auto* n2 = new Node(1.0, 2, 0);
    auto* n3 = new Node(1.0, 1.2, 0);
    auto* n4 = new Node(2.0, 1.2, 0);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::XY) << "PlaneType XY isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeXZ)
{
    auto* n1 = new Node(1.2, 2, 2);
    auto* n2 = new Node(2.0, 2, 1);
    auto* n3 = new Node(2.0, 2, 2);
    auto* n4 = new Node(1.2, 2, 1);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::XZ) << "PlaneType XZ isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeERR)
{
    auto* n1 = new Node(1.2, 2, 2);
    auto* n2 = new Node(2.0, 2.2, 1);
    auto* n3 = new Node(2.0, 2, 1);
    auto* n4 = new Node(1.2, 12.9, 2);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::ERR) << "PlaneType ERR isn\'t correct";
}

TEST(PlaneTest, foundPlaneTypeSAME_POINTS)
{
    auto* n1 = new Node(1.2, 2, 2);
    auto* n2 = new Node(1.2, 2, 2);
    auto* n3 = new Node(2.0, 2, 1);
    auto* n4 = new Node(1.2, 2, 1);

    auto* p = new Plane(*n1, *n2, *n3, *n4);
    EXPECT_EQ(p->getType(), PlaneType::SAME_POINTS) << "PlaneType SAME_POINTS isn\'t correct";
}