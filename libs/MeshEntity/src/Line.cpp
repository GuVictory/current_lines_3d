//
// Created by Виктория Губанова on 03.09.2020.
//

#include <Line.h>
#include <cmath>
#include <vector>
#include "GaussSolve.h"

Line::Line() {
    this->firstNode = new Node();
    this->secondNode = new Node();
    this->generalFormOfLine = new GeneralFormOfLine(0, 0, 0, 0, 0, 0);
}

Line::Line(const Node &n1, const Node &n2) {
    this->firstNode = new Node(n1);
    this->secondNode = new Node(n2);
    this->generalFormOfLine = new GeneralFormOfLine(this->firstNode->getPoint(),
                                                    this->secondNode->getPoint());
}

Line::Line(const Point &p1, const Point &p2) {
    this->firstNode = new Node(p1.getX(), p1.getY(), p1.getZ());
    this->secondNode = new Node(p2.getX(), p2.getY(), p2.getZ());
    this->generalFormOfLine = new GeneralFormOfLine(this->firstNode->getPoint(),
                                                    this->secondNode->getPoint());
}

Line::Line(double x1, double y1, double z1, double x2, double y2, double z2) {
    this->firstNode = new Node(x1, y1, z1);
    this->secondNode = new Node(x2, y2, z2);
    this->generalFormOfLine = new GeneralFormOfLine(this->firstNode->getPoint(),
                                                    this->secondNode->getPoint());
}

Line::~Line() {
    delete this->firstNode;
    delete this->secondNode;
    delete this->generalFormOfLine;
}

double Line::len() {
    double x = pow(this->secondNode->getPoint().getX() - this->firstNode->getPoint().getX(), 2);
    double y = pow(this->secondNode->getPoint().getY() - this->firstNode->getPoint().getY(), 2);
    double z = pow(this->secondNode->getPoint().getZ() - this->firstNode->getPoint().getZ(), 2);
    return sqrt(x + y + z);
}

/*!
 *
 * (point.getX() - x0)   (point.getX() - x0)   (point.getX() - x0)
 * ------------------- = ------------------- = ------------------- ,
 *           q                    w                     e
 * @return
 * true - равенства выполняются => точка пренадлежит прямой
 * false - равенства не выполняются => точка не пренадлежит прямой
 */
bool Line::containsPoint(const Point &point) {
    try {
        double firstElement = this->generalFormOfLine->q == 0 ? 0
                                : (point.getX() - this->generalFormOfLine->x0) / this->generalFormOfLine->q;

        double secondElement = this->generalFormOfLine->w == 0 ? 0
                                : (point.getY() - this->generalFormOfLine->y0) / this->generalFormOfLine->w;

        double thirdElement = this->generalFormOfLine->e == 0 ? 0
                                : (point.getZ() - this->generalFormOfLine->z0) / this->generalFormOfLine->e;

        if(point.getZ() == 0 && this->generalFormOfLine->z0 == 0 && this->generalFormOfLine->e == 0) {
            return firstElement == secondElement;
        }

        return firstElement == secondElement && secondElement == thirdElement;

    } catch (const std::exception& e) {
        //TODO: Добавить нормальную обработку для 2D случая
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }
}

bool Line::operator==(const Line &line) const {
    return *this->firstNode == *line.firstNode && *this->secondNode == *line.secondNode;
}

std::ostream &operator<<(std::ostream &out, const Line &line) {
    out << "[LINE]:"
        << "\n\tx1: " << line.firstNode->getPoint().getX()
        << "\tx2: " << line.secondNode->getPoint().getX()
        << "\n\ty1: " << line.firstNode->getPoint().getY()
        << "\ty2: " << line.secondNode->getPoint().getY()
        << "\n\tz1: " << line.firstNode->getPoint().getZ()
        << "\tz2: " << line.secondNode->getPoint().getZ() << std::endl;
    return out;
}


bool Line::areNotInterbreeding(const Line &line) {
    //! Вычислим смешанное произведение направляющих векторов каждой линии и линии, соеденяющей эти вектора
    double MM1x = line.secondNode->getPoint().getX() - this->firstNode->getPoint().getX();
    double MM1y = line.secondNode->getPoint().getY() - this->firstNode->getPoint().getY();
    double MM1z = line.secondNode->getPoint().getZ() - this->firstNode->getPoint().getZ();

    /*!
     * Формула для проверки компланарности трех веткоров:
     * |  q1  q2  MM1x  |
     * |  w1  w2  MM1y  | = q1 * (w2 * MM1z - e2 * MM1y)
     * |  e1  e2  MM1z  |       - q2 * (w1 * MM1z - e1 * MM1y)
     *                          + MM1x * (w1 * e2 - w2 * e1)
     */
    double firstElement = this->generalFormOfLine->q
                            * (line.generalFormOfLine->w * MM1z - line.generalFormOfLine->e * MM1y);

    double secondElement = line.generalFormOfLine->q
                            * (this->generalFormOfLine->w * MM1z - this->generalFormOfLine->e * MM1y);

    double  thirdElement = MM1x * (this->generalFormOfLine->w * line.generalFormOfLine->e
                                    - line.generalFormOfLine->w * this->generalFormOfLine->e);

    return (firstElement - secondElement + thirdElement) == 0;
}

bool Line::areParallel(const Line &line) {
    double lambdaQ = 0, lambdaW = 0, lambdaE = 0;

    if (line.generalFormOfLine->q == 0 && this->generalFormOfLine->q == 0) {
        lambdaQ = 1;
    } else {
        lambdaQ = line.generalFormOfLine->q == 0 ? 0 : this->generalFormOfLine->q / line.generalFormOfLine->q;
    }

    if (line.generalFormOfLine->w == 0 && this->generalFormOfLine->w == 0) {
        lambdaW = 1;
    } else {
        lambdaW = line.generalFormOfLine->w == 0 ? 0 : this->generalFormOfLine->w / line.generalFormOfLine->w;
    }

    if (line.generalFormOfLine->e == 0 && this->generalFormOfLine->e == 0) {
        lambdaE = 1;
    } else {
        lambdaE = line.generalFormOfLine->e == 0 ? 0 : this->generalFormOfLine->e / line.generalFormOfLine->e;
    }

    if( this->generalFormOfLine->x0 == 0
        && line.generalFormOfLine->x0 == 0
        && this->generalFormOfLine->q == 0
        && line.generalFormOfLine->q == 0) {
        return lambdaW == lambdaE;
    }

    if( this->generalFormOfLine->y0 == 0
        && line.generalFormOfLine->y0 == 0
        && this->generalFormOfLine->w == 0
        && line.generalFormOfLine->w == 0) {
        return lambdaQ == lambdaW;
    }

    if( this->generalFormOfLine->z0 == 0
        && line.generalFormOfLine->z0 == 0
        && this->generalFormOfLine->e == 0
        && line.generalFormOfLine->e == 0) {
        return lambdaQ == lambdaW;
    }

    return lambdaQ == lambdaW && lambdaW == lambdaE;
}

std::pair<bool, Point> Line::foundIntersectionPoint(const Line &line) {

    // Проверим являются ли прямые скрещивающимися
    if(!this->areNotInterbreeding(line)) {
        return std::make_pair(false, *new Point(0, 0, 0));
    }

    // Проверим являются ли прямые параллельными
    if(this->areParallel(line)) {
        return std::make_pair(false, *new Point(0, 0, 0));
    }


    // Для нахождения точки пересечения будем использовать параметрический вид прямых
    // Составляем систему

    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(2);
    std::vector<double> B = std::vector<double>(2);

    A[0] = std::vector<double>(2);
    A[1] = std::vector<double>(2);

    if (this->generalFormOfLine->e == 0 && line.generalFormOfLine->e == 0) {
        A[0][0] = this->generalFormOfLine->q;
        A[0][1] = - line.generalFormOfLine->q;
        A[1][0] = this->generalFormOfLine->w;
        A[1][1] = - line.generalFormOfLine->w;

        B[0] = -this->generalFormOfLine->x0 + line.generalFormOfLine->x0;
        B[1] = -this->generalFormOfLine->y0 + line.generalFormOfLine->y0;

    } else if (this->generalFormOfLine->w == 0 && line.generalFormOfLine->w == 0) {
        A[0][0] = this->generalFormOfLine->q;
        A[0][1] = - line.generalFormOfLine->q;
        A[1][0] = this->generalFormOfLine->e;
        A[1][1] = - line.generalFormOfLine->e;

        B[0] = -this->generalFormOfLine->x0 + line.generalFormOfLine->x0;
        B[1] = -this->generalFormOfLine->z0 + line.generalFormOfLine->z0;
    } else {
        A[0][0] = this->generalFormOfLine->w;
        A[0][1] = - line.generalFormOfLine->w;
        A[1][0] = this->generalFormOfLine->e;
        A[1][1] = - line.generalFormOfLine->e;

        B[0] = -this->generalFormOfLine->y0 + line.generalFormOfLine->y0;
        B[1] = -this->generalFormOfLine->z0 + line.generalFormOfLine->z0;
    }

    auto parameterValues = gauss(A, B, 2);

    // После нахожденя параметров находим координаты точки пересечения
    double x0 = this->generalFormOfLine->q * parameterValues.second[0] + this->generalFormOfLine->x0;
    double y0 = this->generalFormOfLine->w * parameterValues.second[0] + this->generalFormOfLine->y0;
    double z0 = this->generalFormOfLine->e * parameterValues.second[0] + this->generalFormOfLine->z0;

    return std::make_pair(true, *new Point(x0, y0, z0));
}

Line &Line::getScanLineOX(const Point &point) {
    Line* scanLine = new Line(point, *new Point(point.getX() + 0.1, point.getY(), point.getZ()));
    return *scanLine;
}

Line &Line::getScanLineOY(const Point &point) {
    Line* scanLine = new Line(point, *new Point(point.getX(), point.getY() - 0.1, point.getZ()));
    return *scanLine;
}

Line &Line::getScanLineOZ(const Point &point) {
    Line* scanLine = new Line(point, *new Point(point.getX(), point.getY(), point.getZ() + 0.1));
    return *scanLine;
}
