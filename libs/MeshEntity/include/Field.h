//
// Created by Виктория Губанова on 01.09.2020.
//

#ifndef CURRENTLINES3D_FIELD_H
#define CURRENTLINES3D_FIELD_H

#include <Point.h>

/*!
 * \brief Класс векторного поля, наследуется от Point
 *
 * Позволяет задавать значение векторного поля в точке
 * Имеет метод для расчета силы векторного поля
 * Так же позволяет получать нормированное значение векторного поля
 */
class Field: public Point {
public:
    Field();
    explicit Field(const Point& point);
    Field(double newX, double newY, double newZ = 0);

    ~Field();

    //! Метод для расчет модуля векторного поля в точке sqrt(x^2 + y^2 + z^2)
    double getSizeOfVectorField();

    //! Возвращает само значение поля
    Point& getVectorField();

    //! Возвращает значение поля нормированное относительно силы этого поля
    Point& getNormalizeVectorField();

    bool operator==(const Field& field);
};


#endif //CURRENTLINES3D_FIELD_H
