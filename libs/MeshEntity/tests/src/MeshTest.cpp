//
// Created by Виктория Губанова on 01.09.2020.
//

#include <gtest/gtest.h>
#include <Mesh.h>

#include <iostream>

TEST(MeshTest, meshNodeCountTest)
{
    auto* mesh = new Mesh();
    mesh->loadNode(*new Node(1, 4.0, 0.0, 3.0));
    mesh->loadNode(*new Node(2, 4.0, 0.0, 3.0));

    EXPECT_EQ(mesh->numberOfNodes(), 2) << "Mesh node count not working";
}

TEST(MeshTest, meshNodeCountTest2)
{
    auto* mesh = new Mesh();
    EXPECT_EQ(mesh->numberOfNodes(), 0) << "Mesh node count not working";
}


TEST(MeshTest, meshNodeCountTest3)
{
    auto* mesh = new Mesh();
    for ( int i = 0; i < 1000; ++i ) {
        mesh->loadNode(*new Node(i, 4.0, 0.0, 3.0));
    }
    EXPECT_EQ(mesh->numberOfNodes(), 1000) << "Mesh node count not working";
}

TEST(MeshTest, meshNodeFieldChangeTest)
{
    auto* mesh = new Mesh();
    mesh->loadNode(*new Node(1, 4.0, 0.0, 3.0));
    mesh->loadNode(*new Node(2, 4.0, 0.0, 3.0));

    auto* f = new Field(1.0, 2.0, 3.0);
    mesh->changeFieldOfNode(1, *f);
    auto [success, node] = mesh->getNode(1);

    EXPECT_EQ(node->getField().getVectorField(), f->getVectorField()) << "Mesh node count not working";
}