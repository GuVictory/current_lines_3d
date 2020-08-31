//
// Created by Виктория Губанова on 31.08.2020.
//

#include "Point.hpp"

Point::Point() : x(0), y(0), z(0) {}

Point::Point(double newX, double newY, double newZ) :  x(newX), y(newY), z(newZ) {}

Point::~Point() {}

void Point::setCoords(double newX, double newY, double newZ) {
    this->x = newX;
    this->y = newY;
    this->z = newZ;
}

bool Point::operator==(const Point &firstPoint, const Point &secondPoint) {
    return
        firstPoint.x == secondPoint.x &&
        firstPoint.y == secondPoint.y &&
        firstPoint.z == secondPoint.z;
}


