//
// Created by Виктория Губанова on 01.09.2020.
//

#ifndef CURRENTLINES3D_FIELD_H
#define CURRENTLINES3D_FIELD_H

#include <Point.hpp>

class Field: public Point {
public:
    Field();
    explicit Field(const Point& point);
    Field(double newX, double newY, double newZ = 0);

    ~Field();

    double getSizeOfVectorField();
    Point& getVectorField();
    Point& getNormalizeVectorField();

    bool operator==(const Field& field);
};


#endif //CURRENTLINES3D_FIELD_H
