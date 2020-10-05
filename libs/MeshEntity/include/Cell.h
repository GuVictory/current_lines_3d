//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENTLINES3D_CELL_H
#define CURRENTLINES3D_CELL_H

#include <Plane.h>
#include <EdgeValues.h>
#include <CellFaces.h>

#include <vector>

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
     *
     * @param point - точка, принадлежность которой проверяется
     * @return
     * true - если точка принадлежит яцейке
     * false - если точка не принадлежит яцейке
     */
    bool containsPoint(const Point& point);

    bool operator==(const Cell& cell);
};


#endif //CURRENTLINES3D_CELL_H
