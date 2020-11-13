//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_CELL_H
#define CURRENTLINES3D_CELL_H

#include <Plane.h>
#include <EdgeValues.h>
#include <CellFaces.h>

#include <vector>
#include "Line.h"

/*!
 * \brief Класс Ячейки для реализации работы с сетокой
 *
 * В качестве полей содержит id и 8 узлов, которые описывают вершины ячейки.
 */

class Cell {

private:
    unsigned int id;
    std::vector<Node*> nodes;

    //! Метод, возвращающий граничные значения координаты X
    EdgeValues getXEdgeValues();

    //! Метод, возвращающий граничные значения координаты Y
    EdgeValues getYEdgeValues();

    //! Метод, возвращающий граничные значения координаты Z
    EdgeValues getZEdgeValues();

    /*!
     *
     * @param face - определяет какую грань мы хотим получить
     * @param coord - координата, от которой зависит какую точку должна пересекать плоскость
     * @return плоскость, которая подходит по двум параметрам
     */
    Plane& getSuitablePlane(CellFaces face, double coord);

public:
    Cell();

    // TODO: При создании ячейки добавить сортировку узлов
    Cell(Node& n1,
         Node& n2,
         Node& n3,
         Node& n4,
         Node& n5,
         Node& n6,
         Node& n7,
         Node& n8,
         unsigned int id = 0);
    ~Cell();

    //! Возвращает переднюю грань ячейки
    Plane& getFrontPlane();
    //! Возвращает заднюю грань ячейки
    Plane& getBackPlane();

    //! Возвращает правую грань ячейки
    Plane& getRightPlane();
    //! Возвращает левую грань ячейки
    Plane& getLeftPlane();

    //! Возвращает верхнюю грань ячейки
    Plane& getTopPlane();
    //! Возвращает нижнюю грань ячейки
    Plane& getBottomPlane();

    /*!
     * Проеверка на пренодлежность точки текущей ячейке
     * @param point - точка, принадлежность которой проверяется
     * @return
     * true - если точка принадлежит яцейке
     * false - если точка не принадлежит яцейке
     */
    bool containsPoint(const Point& point);

    /*!
     * Находит точку пересечения сканирующей линии по OX из точки point с правой гранью
     * @param point точка, из которой запускается сканирующая линия
     * @return точка пересечения
     */
    Point& getIntersectionWithRightEdge(const Point &point);

    /*!
     * Находит точку пересечения сканирующей линии по OX из точки point с левой гранью
     * @param point точка, из которой запускается сканирующая линия
     * @return точка пересечения
     */
    Point& getIntersectionWithLeftEdge(const Point &point);

    /*!
     * Находит точку пересечения сканирующей линии по OY из точки point с передней гранью
     * @param point точка, из которой запускается сканирующая линия
     * @return точка пересечения
     */
    Point& getIntersectionWithFrontEdge(const Point &point);

    /*!
     * Находит точку пересечения сканирующей линии по OY из точки point с задней гранью
     * @param point точка, из которой запускается сканирующая линия
     * @return точка пересечения
     */
    Point& getIntersectionWithBackEdge(const Point &point);

    /*!
     * Находит точку пересечения сканирующей линии по OZ из точки point с верхней гранью
     * @param point точка, из которой запускается сканирующая линия
     * @return точка пересечения
     */
    Point& getIntersectionWithTopEdge(const Point &point);

    /*!
     * Находит точку пересечения сканирующей линии по OZ из точки point с нижней гранью
     * @param point точка, из которой запускается сканирующая линия
     * @return точка пересечения
     */
    Point& getIntersectionWithBottomEdge(const Point &point);

    double getHeight();
    double getWidth();
    double getDepth();

    bool operator==(const Cell& cell) const;

    Node* V1() {
        return this->getTopPlane().V4();
    }

    Node* V2() {
        return this->getTopPlane().V3();
    }

    Node* V3() {
        return this->getBottomPlane().V3();
    }

    Node* V4() {
        return this->getBottomPlane().V4();
    }

    Node* V5() {
        return this->getTopPlane().V1();
    }

    Node* V6() {
        return this->getTopPlane().V2();
    }

    Node* V7() {
        return this->getBottomPlane().V2();
    }

    Node* V8() {
        return this->getBottomPlane().V1();
    }
};


#endif //CURRENTLINES3D_CELL_H
