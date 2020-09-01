//
// Created by Виктория Губанова on 31.08.2020.
//

#include "Point.hpp"

Point::Point() : x(0), y(0), z(0) {}

Point::Point(double newX, double newY, double newZ) :  x(newX), y(newY), z(newZ) {}

Point::Point(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

Point::~Point() {}

void Point::setCoords(double newX, double newY, double newZ) {
    this->x = newX;
    this->y = newY;
    this->z = newZ;
}

void Point::setCoords(const Point &point) {
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}


bool Point::operator==(const Point &point) const {
    return
        this->x == point.x &&
        this->y == point.y &&
        this->z == point.z;
}




