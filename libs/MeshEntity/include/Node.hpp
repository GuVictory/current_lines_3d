//
// Created by Виктория Губанова on 01.09.2020.
//

#ifndef CURRENTLINES3D_NODE_H
#define CURRENTLINES3D_NODE_H

#include <Point.hpp>

class Node {

private:
    unsigned int id;
    Point* point;

public:
    Node();
    explicit Node(const Point& point);
    Node(double x, double y, double z = 0);
    Node(unsigned int id, const Point& point);
    Node(unsigned int id, double x, double y, double z = 0);

    void setPoint(double newX, double newY, double newZ = 0);
    void setPoint(const Point& newPoint);
    bool operator==(const Node& node) const;
};


#endif //CURRENTLINES3D_NODE_H
