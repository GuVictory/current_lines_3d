//
// Created by Виктория Губанова on 01.09.2020.
//

#include "Node.hpp"

Node::Node() : id(-1) {
    point = new Point();
}

Node::Node(const Point &point) : id(-1) {
    this->point = new Point(point);
}

Node::Node(double x, double y, double z) : id(-1) {
    this->point = new Point(x, y, z);
}

Node::Node(unsigned int id, const Point &point) : id(id) {
    this->point = new Point(point);
}

Node::Node(unsigned int id, double x, double y, double z) : id(id) {
    this->point = new Point(x, y, z);
}

void Node::setPoint(double newX, double newY, double newZ) {
    this->point->setCoords(newX, newY, newZ);
}

void Node::setPoint(const Point &newPoint) {
    this->point->setCoords(newPoint);
}

// TODO: Доделать сравнение векторных полей потом
bool Node::operator==(const Node &node) const {
    return
        *(this->point) == *(node.point) &&
        this->id == node.id;
}

