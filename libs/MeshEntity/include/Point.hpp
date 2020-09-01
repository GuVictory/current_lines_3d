//
// Created by Виктория Губанова on 31.08.2020.
//

#ifndef CURRENTLINES3D_POINT_H
#define CURRENTLINES3D_POINT_H


class Point {

private:
    double x, y, z;

public:
    Point();
    explicit Point(const Point& point);
    Point(double newX, double newY, double newZ = 0);

    ~Point();

    void setCoords(double newX, double newY, double newZ = 0);
    void setCoords(const Point& point);

    bool operator==(const Point& point) const;
};


#endif //CURRENTLINES3D_POINT_H
