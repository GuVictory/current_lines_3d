//
// Created by Виктория Губанова on 24.10.2020.
//

#ifndef CURRENTLINES3D_PLANEINTERSECTIONS_H
#define CURRENTLINES3D_PLANEINTERSECTIONS_H

#include "Point.h"

struct PlaneIntersections {
    Point minX, maxX, minY, maxY, minZ, maxZ;

    PlaneIntersections(const Point& minXp, const Point& maxXp, const Point& minYp, const Point& maxYp, const Point& minZp, const Point& maxZp)
    : minX(minXp), maxX(maxXp), minY(minYp), maxY(maxYp), minZ(minZp), maxZ(maxZp) {}

    PlaneIntersections() :
        minX(*new Point(0.0, 0.0, 0.0)),
        maxX(*new Point(0.0, 0.0, 0.0)),
        minY(*new Point(0.0, 0.0, 0.0)),
        maxY(*new Point(0.0, 0.0, 0.0)),
        minZ(*new Point(0.0, 0.0, 0.0)),
        maxZ(*new Point(0.0, 0.0, 0.0)) {}

    ~PlaneIntersections() {
        delete &minX;
        delete &maxX;
        delete &minY;
        delete &maxY;
        delete &minZ;
        delete &maxZ;
    }

    bool operator==(const PlaneIntersections& planeIntersections) const {
        return  minX == planeIntersections.minX &&
                maxX == planeIntersections.maxX &&
                minY == planeIntersections.minY &&
                maxY == planeIntersections.maxY &&
                minZ == planeIntersections.minZ &&
                maxZ == planeIntersections.maxZ;
    }
};

#endif //CURRENTLINES3D_PLANEINTERSECTIONS_H
