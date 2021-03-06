//
// Created by Виктория Губанова on 03.09.2020.
//

#ifndef CURRENT_LINES_3D_LINE_H
#define CURRENT_LINES_3D_LINE_H

#include <Node.h>
#include <GeneralFormOfLine.h>
#include <iostream>

/*!
 * \brief Класс линии
 *
 * Линия создается на основе двух узлов
 */
class Line {
private:
    Node* firstNode;
    Node* secondNode;
    GeneralFormOfLine* generalFormOfLine;

public:
    Line();
    Line(const Node& n1, const Node& n2);
    Line(const Point& p1, const Point& p2);
    Line(double x1, double y1, double z1, double x2, double y2, double z2);

    ~Line();

    /*!
     * Метод для определения длины линии
     * @return длина линии = sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
     */
    double len();

    /*!
     * Метод определяет принадлежит ли точка данной прямой или нет
     * @param point - точка, принадлежность которой будет проверяться
     * @return
     * true - принадлежит
     * false - не принадлежит
     */
    bool containsPoint(const Point& point);

    /*!
     * Метод для определения факта параллельности двух прямых,
     * предполагется, что прямые лежат в одной плоскости (не являются скрещивающимися)
     * @param line - прямая, которую мы будем проверять на параллельность с нашей прямой
     * @return
     * true - прямые параллельны
     * false - прямые не параллельны
     */
    bool areParallel(const Line& line);

    /*!
     * Метод для определения не являются ли две прямые скрещивающимися или нет
     * @param line - прямая, с которой мы будем проверять факт скрещивания
     * @return
     * true - прямые не скрещивающиеся
     * false - прямые скрещивающиеся
     */
    bool areNotInterbreeding(const Line& line);

    /*!
     * Метод для нахождения точки пересечения двух прямых,
     * предполагается, что прямые не являются скрещивающимися или же параллельными
     * @param line - линия с которой ищем пересечение
     * @return - точка пересечения
     */
    std::pair<bool, Point> foundIntersectionPoint(const Line& line);

    /*!
     * Метод создающий сканирующую линию по OX из определенной точки
     * @param point - точка из которой запускается сканирующая линия
     * @return - сканирующая линия
     */
    static Line& getScanLineOX(const Point& point);

    /*!
     * Метод создающий сканирующую линию по OY из определенной точки
     * @param point - точка из которой запускается сканирующая линия
     * @return - сканирующая линия
     */
    static Line& getScanLineOY(const Point& point);

    /*!
     * Метод создающий сканирующую линию по OZ из определенной точки
     * @param point - точка из которой запускается сканирующая линия
     * @return - сканирующая линия
     */
    static Line& getScanLineOZ(const Point& point);



    bool operator==(const Line& line) const;

    friend std::ostream& operator<<(std::ostream &out, const Line &line);
};


#endif //CURRENT_LINES_3D_LINE_H
