//
// Created by Виктория Губанова on 01.09.2020.
//

#ifndef CURRENTLINES3D_NODE_H
#define CURRENTLINES3D_NODE_H

#include <Field.h>
#include <iostream>

class Node {

private:
    unsigned int id;
    Point* point;
    Field* field;

public:
    Node();
    Node(const Node& node);
    explicit Node(const Point& point);
    Node(double x, double y, double z = 0);
    Node(unsigned int id, const Point& point);
    Node(unsigned int id, double x, double y, double z = 0);

    ~Node();

    void setPoint(double newX, double newY, double newZ = 0);
    void setField(double newX, double newY, double newZ = 0);
    void setPoint(const Point& newPoint);
    Point& getPoint();
    Field& getField();
    unsigned int getId();
    void setId(unsigned int newId);

    bool operator==(const Node& node) const;
    friend std::ostream& operator<<(std::ostream &out, const Node &node);
};


#endif //CURRENTLINES3D_NODE_H
