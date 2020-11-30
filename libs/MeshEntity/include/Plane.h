//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_PLANE_H
#define CURRENTLINES3D_PLANE_H

#include <Node.h>
#include <PlaneType.h>
#include <vector>
#include "PlaneIntersections.h"
#include "GeneralFormOfPlane.h"

class Plane {
private:
    PlaneType planeType;
    std::vector<Node*> nodes;
    GeneralFormOfPlane* generalFormOfPlane;

    void setPlaneType();
    void mainNodesSort();
    void sortLEFT_RIGHT();
    void sortTOP_BOTTOM();
    void sortFRONT_BACK();


    // Метод для определения имеет ли ячейка 4 уникальных узла или же они попарно совпадают
    bool checkIsCorrectPlane();

    // Методы для нахождения максимальной дистанции относиттельно одной координаты для точек плоскости
    [[nodiscard]] double foundDeltaX() const;
    [[nodiscard]] double foundDeltaY() const;
    [[nodiscard]] double foundDeltaZ() const;

    [[nodiscard]] double foundMaxOfThree(double a, double b, double c) const;
    [[nodiscard]] double foundMinOfThree(double a, double b, double c) const;

public:
    Plane(Node& n1,
          Node& n2,
          Node& n3,
          Node& n4);
    ~Plane();

    PlaneType getType();

    // Метод который позволяет определить могут ли две плоскости явзятся гранями одной ячейки
    bool areSuitsPlane(const Plane& plane);

    /*! TODO: Не работает для криволинейной сетки!
     * Метод, который позваляет определить точки пересечения сканирующих линий из point c с ребрами ячейки
     * @param point - точка на плоскости
     * @return если переданная точка находится в заданной области простасти, то позвращается true, PlaneIntersections
     *          иначе false, PlaneIntersections()
     */
    std::pair<bool, PlaneIntersections*> getPlaneIntersections(const Point& point);


    bool operator==(const Plane& plane) const;

    [[nodiscard]] Node* V1() const {
        return this->nodes[0];
    }

    [[nodiscard]] Node* V2() const {
        return this->nodes[1];
    }

    [[nodiscard]] Node* V3() const {
        return this->nodes[2];
    }

    [[nodiscard]] Node* V4() const {
        return this->nodes[3];
    }

    //! Метод, который подставляет точку в стандартное уравнение плоскости
    double getPositionOfPoint(const Point& point);
};


#endif //CURRENTLINES3D_PLANE_H
