//
// Created by Виктория Губанова on 06.10.2020.
//

#ifndef CURRENTLINES3D_GENERALFORMOFLINE_H
#define CURRENTLINES3D_GENERALFORMOFLINE_H

#include <Point.h>

/*!
 * Структура описывающая стандартный вид записи прямой
 * (x - x0)   (y - y0)   (z - z0)
 * -------- = -------- = -------- ,
 *    q           w          e
 * где x0, y0, z0 - точка, через которую проходит прямая,
 * q, w, e - координаты направляющего вектора
 */

struct GeneralFormOfLine {
    double x0, y0, z0;
    double q, w, e;

    GeneralFormOfLine(const Point& point1, const Point& point2) {
        this->x0 = point1.getX();
        this->y0 = point1.getY();
        this->z0 = point1.getZ();

        this->q = point2.getX() - point1.getX();
        this->w = point2.getY() - point1.getY();
        this->e = point2.getZ() - point1.getZ();
    }

    GeneralFormOfLine(double x1, double y1, double z1, double x2, double y2, double z2) {
        this->x0 = x1;
        this->y0 = y1;
        this->z0 = z1;

        this->q = x2 - x1;
        this->w = y2 - y1;
        this->e = z2 - z1;
    }
};

#endif //CURRENTLINES3D_GENERALFORMOFLINE_H
