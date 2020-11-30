//
// Created by GuVictory on 30.11.2020.
//

#ifndef CURRENTLINES3D_GENERALFORMOFPLANE_H
#define CURRENTLINES3D_GENERALFORMOFPLANE_H

#include "Point.h"

/*!
 * Структура описывающая стандартный вид записи плоскости
 * Ax + By + Cz + D = 0
 */

struct GeneralFormOfPlane {
    double A, B, C, D;

    GeneralFormOfPlane(const Point& point1, const Point& point2, const Point& point3, const Point &point4) {

        double  v1 = point3.getX() - point1.getX(),
                v2 = point3.getY() - point1.getY(),
                v3 = point3.getZ() - point1.getZ();

        double  w1 = point4.getX() - point2.getX(),
                w2 = point4.getY() - point2.getY(),
                w3 = point4.getZ() - point2.getZ();


        /*!
        * Формула для нахождения коэф-ов проскости:
         * |  x-x0  v1  w1  |
         * |  y-y0  v2  w2  | = 0
         * |  z-z0  v3  w3  |
         *
         * (x-x0) * (v2 * w3 - w2 * v3) - (y-y0) * (v1 * w3 - w1 * v3) + (z-z0) * (v1 * w2 - v2 * w1) = 0
         * (v2 * w3 - w2 * v3) * x - (v1 * w3 - w1 * v3) * y + (v1 * w2 - v2 * w1) * z + D = 0
         *
         * A = (v2 * w3 - w2 * v3)
         * B = - (v1 * w3 - w1 * v3)
         * C = (v1 * w2 - v2 * w1)
         * D = - (v2 * w3 - w2 * v3) * x0 + (v1 * w3 - w1 * v3) * y0 - (v1 * w2 - v2 * w1) * z0
        */

        this->A = v2 * w3 - w2 * v3;
        this->B = - (v1 * w3 - w1 * v3);
        this->C = v1 * w2 - v2 * w1;
        this->D = - (v2 * w3 - w2 * v3) * point1.getX()
                  + (v1 * w3 - w1 * v3) * point1.getY()
                  - (v1 * w2 - v2 * w1) * point1.getZ();
    }
};

#endif //CURRENTLINES3D_GENERALFORMOFPLANE_H
