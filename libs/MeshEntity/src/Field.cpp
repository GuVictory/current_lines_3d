//
// Created by Виктория Губанова on 01.09.2020.
//

#include "Field.h"
#include <cmath>
#include <iostream>

Field::Field() : Point() {}

Field::Field(const Point &point) : Point(point) {}

Field::Field(double newX, double newY, double newZ) : Point(newX, newY, newZ) {}

Field::~Field() {}

double Field::getSizeOfVectorField() {
    return sqrt(this->getX() * this->getX() + this->getY() * this->getY() + this->getZ() * this->getZ());
}

Point &Field::getVectorField() {
    auto* point = new Point(this->getX(), this->getY(), this->getZ());
    return *point;
}

Point &Field::getNormalizeVectorField() {
    double len = this->getSizeOfVectorField();
    auto* point = new Point(this->getX() / len, this->getY() / len, this->getZ() / len);
    return *point;
}

bool Field::operator==(const Field& field) {
    return
        this->getX() == field.getX() &&
        this->getY() == field.getY() &&
        this->getZ() == field.getZ();
}
