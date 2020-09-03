//
// Created by Виктория Губанова on 03.09.2020.
//

#include <Line.hpp>
#include <cmath>

Line::Line() {
    this->firstNode = new Node();
    this->secondNode = new Node();
}

Line::Line(const Node &n1, const Node &n2) {
    this->firstNode = new Node(n1);
    this->secondNode = new Node(n2);
}

Line::Line(double x1, double y1, double z1, double x2, double y2, double z2) {
    this->firstNode = new Node(x1, y1, z1);
    this->secondNode = new Node(x2, y2, z2);
}

Line::~Line() {
    delete this->firstNode;
    delete this->secondNode;
}

double Line::len() {
    double x = pow(this->secondNode->getPoint().getX() - this->firstNode->getPoint().getX(), 2);
    double y = pow(this->secondNode->getPoint().getY() - this->firstNode->getPoint().getY(), 2);
    double z = pow(this->secondNode->getPoint().getZ() - this->firstNode->getPoint().getZ(), 2);
    return sqrt(x + y + z);
}

bool Line::operator==(const Line &line) const {
    return *this->firstNode == *line.firstNode && *this->secondNode == *line.secondNode;
}

std::ostream &operator<<(std::ostream &out, const Line &line) {
    out << "[LINE]:"
        << "\n\tx1: " << line.firstNode->getPoint().getX()
        << "\tx2: " << line.secondNode->getPoint().getX()
        << "\n\ty1: " << line.firstNode->getPoint().getY()
        << "\ty2: " << line.secondNode->getPoint().getY()
        << "\n\tz1: " << line.firstNode->getPoint().getZ()
        << "\tz2: " << line.secondNode->getPoint().getZ() << std::endl;
    return out;
}
