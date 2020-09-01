//
// Created by Виктория Губанова on 31.08.2020.
//

#ifndef CURRENTLINES3D_POINT_H
#define CURRENTLINES3D_POINT_H


#include <iostream>

class Point {

private:
    double x, y, z;

public:
    Point();
    Point(const Point& point);
    Point(double newX, double newY, double newZ = 0);

    ~Point();

    void setCoords(double newX, double newY, double newZ = 0);
    void setCoords(const Point& point);

    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;
    [[nodiscard]] double getZ() const;

    bool operator==(const Point& point) const;
    friend std::ostream& operator<<(std::ostream &out, const Point &point);
};


#endif //CURRENTLINES3D_POINT_H
