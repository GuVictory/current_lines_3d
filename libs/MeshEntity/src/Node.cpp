//
// Created by Виктория Губанова on 01.09.2020.
//

#include "Node.h"


Node::Node() : id(0) {
    this->point = new Point();
    this->field = new Field();
}

Node::Node(const Node &node) {
    this->point = new Point(*node.point);
    this->field = new Field(*node.point);
    this->id = node.id;
}

Node::Node(const Point &point) : id(0) {
    this->point = new Point(point);
    this->field = new Field(point);
}

Node::Node(double x, double y, double z) : id(0) {
    this->point = new Point(x, y, z);
    this->field = new Field(x, y, z);
}

Node::Node(unsigned int id, const Point &point) : id(id) {
    this->point = new Point(point);
    this->field = new Field(point);
}

Node::Node(unsigned int id, double x, double y, double z) : id(id) {
    this->point = new Point(x, y, z);
    this->field = new Field(x, y, z);
}


Node::~Node() {
    delete this->point;
    delete this->field;
}

void Node::setPoint(double newX, double newY, double newZ) {
    this->point->setCoords(newX, newY, newZ);
}

void Node::setPoint(const Point &newPoint) {
    this->point->setCoords(newPoint);
}

bool Node::operator==(const Node &node) const {
    return
        *(this->point) == *(node.point) &&
        *(this->field) == *(node.field) &&
        this->id == node.id;
}

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << "[NODE]:\n\tid: " << node.id << std::endl
        << "\tx: " << node.point->getX()
        << "\n\ty: " << node.point->getY() << "\n\tz: "
        << node.point->getZ() << "" << std::endl
        << "\tfield_x: " << node.field->getX()
        << "\n\tfield_y: " << node.field->getY()
        << "\n\tfield_z: " << node.field->getZ() << "" << std::endl;
    return out;
}

Point &Node::getPoint() {
    return *this->point;
}

Field &Node::getField() {
    return *this->field;
}

unsigned int Node::getId() {
    return this->id;
}



