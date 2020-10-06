//
// Created by Виктория Губанова on 03.09.2020.
//

#include <Line.h>
#include <cmath>

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

// TODO: Написать тесты для этой функции
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
    //! Если две прямые скрещивающиеся => они не могут быть параллельными
    if(!this->areNotInterbreeding(line)) {
        return false;
    }

    double lambdaQ = line.generalFormOfLine->q == 0 ? 0 : this->generalFormOfLine->q / line.generalFormOfLine->q;
    double lambdaW = line.generalFormOfLine->w == 0 ? 0 : this->generalFormOfLine->w / line.generalFormOfLine->w;
    double lambdaE = line.generalFormOfLine->e == 0 ? 0 : this->generalFormOfLine->e / line.generalFormOfLine->e;

    if( this->generalFormOfLine->z0 == 0
        && line.generalFormOfLine->z0 == 0
        && this->generalFormOfLine->e == 0
        && line.generalFormOfLine->e == 0) {
        return lambdaQ == lambdaW;
    }

    return lambdaQ == lambdaW && lambdaW == lambdaE;
}
