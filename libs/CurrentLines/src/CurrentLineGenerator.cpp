//
// Created by Виктория Губанова on 17.08.2020.
//

#include <CurrentLineGenerator.h>
#include "Line.h"
#include "Interpolator.h"

CurrentLineGenerator::CurrentLineGenerator(Mesh &pmesh, Point &basePoint) {
    currentLine = new CurrentLine(*new Node(basePoint));
    mesh = &pmesh;

    // Запускаем локализация базовой точки для определения текущей ячейки
    this->currentCellId = this->localization();

    if (this->currentCellId == -1) {
        std::cout << "Базовая точка не входит в область сетки" << std::endl;
    } else {
        generateCurrentLine();
    }
}

int CurrentLineGenerator::localization() {
    for (int i = 0; i < this->mesh->numberOfCells(); ++i) {
        if (this->mesh->cells[i].containsPoint(this->currentLine->getNode().getPoint())) {
            return i;
        }
    }

    return -1;
}

void CurrentLineGenerator::generateCurrentLine() {

    while (this->currentCellId != -1) {
        // Найдем точки на ребрах, на уровне базовой точки
        Node* D = new Node(this->mesh->cells[this->currentCellId].V1()->getPoint().getX(),
                           this->mesh->cells[this->currentCellId].V1()->getPoint().getY(),
                           this->currentLine->getNode().getPoint().getZ());

        Node* E = new Node(this->mesh->cells[this->currentCellId].V5()->getPoint().getX(),
                           this->mesh->cells[this->currentCellId].V5()->getPoint().getY(),
                           this->currentLine->getNode().getPoint().getZ());

        Node* F = new Node(this->mesh->cells[this->currentCellId].V2()->getPoint().getX(),
                           this->mesh->cells[this->currentCellId].V2()->getPoint().getY(),
                           this->currentLine->getNode().getPoint().getZ());

        Node* G = new Node(this->mesh->cells[this->currentCellId].V6()->getPoint().getX(),
                           this->mesh->cells[this->currentCellId].V6()->getPoint().getY(),
                           this->currentLine->getNode().getPoint().getZ());

        // Проведем сканирующую линию по OX через базовую точку
        auto scanLine = Line::getScanLineOX(this->currentLine->getNode().getPoint());

        // Находим пересечение сканирующей линии и линий на ребрах для нахождения точек пересечения на гранях
        std::pair<bool, Point> BPoint = scanLine.foundIntersectionPoint(*new Line(*D, *E));
        std::pair<bool, Point> CPoint = scanLine.foundIntersectionPoint(*new Line(*F, *G));


        // Вытащим высоту, ширину и грубину ячейки, чтобы посчитать параметры для интеполяции
        double height = this->mesh->cells[this->currentCellId].getHeight();
        double width = this->mesh->cells[this->currentCellId].getWidth();
        double depth = this->mesh->cells[this->currentCellId].getDepth();

        // Получим линию соединяющую верхнюю грань ячейки и базовую точку
        Line* topA = new Line(this->currentLine->getNode(),
                              *new Node(this->currentLine->getNode().getPoint().getX(),
                                        this->currentLine->getNode().getPoint().getY(),
                                        this->mesh->cells[this->currentCellId].V1()->getPoint().getZ()));

        // Получим линию соединяющую переднюю грань ячейки и базовую точку
        Line* frontA = new Line(this->currentLine->getNode(),
                                *new Node(this->currentLine->getNode().getPoint().getX(),
                                          this->mesh->cells[this->currentCellId].V1()->getPoint().getY(),
                                          this->currentLine->getNode().getPoint().getZ()));

        // Получим линию соединяющую левую грань ячейки и базовую точку
        Line* leftA = new Line(this->currentLine->getNode(),
                               *new Node(this->mesh->cells[this->currentCellId].V1()->getPoint().getX(),
                                         this->currentLine->getNode().getPoint().getY(),
                                         this->currentLine->getNode().getPoint().getZ()));

        // Находим значения параметров интерполяции
        double tau = topA->len() / height;
        double omega = frontA->len() / depth;
        double gamma = leftA->len() / width;

        // Создаем объект для расчета интерполяции
        auto* interpolator = new Interpolator(tau, omega, gamma);

        if (BPoint.first && CPoint.first) {
            Node* B = new Node(BPoint.second);
            Node* C = new Node(CPoint.second);

            // Выполняем первую интерполяцию
            FirstInterpolationData resultOfFirstInterpolation = interpolator->firstInterpolation(*this->mesh->cells[this->currentCellId].V1(),
                                                                                                 *this->mesh->cells[this->currentCellId].V2(),
                                                                                                 *this->mesh->cells[this->currentCellId].V3(),
                                                                                                 *this->mesh->cells[this->currentCellId].V4(),
                                                                                                 *this->mesh->cells[this->currentCellId].V5(),
                                                                                                 *this->mesh->cells[this->currentCellId].V6(),
                                                                                                 *this->mesh->cells[this->currentCellId].V7(),
                                                                                                 *this->mesh->cells[this->currentCellId].V8());

            // Записываем значения векторного поля в точки на ребрах
            D->setField(resultOfFirstInterpolation.uD,
                        resultOfFirstInterpolation.vD,
                        resultOfFirstInterpolation.wD);

            E->setField(resultOfFirstInterpolation.uE,
                        resultOfFirstInterpolation.vE,
                        resultOfFirstInterpolation.wE);

            F->setField(resultOfFirstInterpolation.uF,
                        resultOfFirstInterpolation.vF,
                        resultOfFirstInterpolation.wF);

            G->setField(resultOfFirstInterpolation.uG,
                        resultOfFirstInterpolation.vG,
                        resultOfFirstInterpolation.wG);

            // Выполняем вторую интерполяцию
            SecondInterpolationData resultOfSecondInterpolation = interpolator->secondInterpolation(*D, *E, *F, *G);

            // Записываем значение векторного поля в точках на гранях
            B->setField(resultOfSecondInterpolation.uB,
                        resultOfSecondInterpolation.vB,
                        resultOfSecondInterpolation.wB);

            C->setField(resultOfSecondInterpolation.uC,
                        resultOfSecondInterpolation.vC,
                        resultOfSecondInterpolation.wC);


            // Выполняем третью интерполяцию
            ThirdInterpolationData resultOfThirdInterpolation = interpolator->thirdInterpolation(*B, *C);

            // Записываем значение векторного поля в текущую базовую точку
            this->currentLine->setFieldOfNewNode(resultOfThirdInterpolation.uA,
                                                 resultOfThirdInterpolation.vA,
                                                 resultOfThirdInterpolation.wA);

            // Создаем новый узел в линии тока
            this->currentLine->addNode();


            // Снова запускаем локализация базовой точки для определения текущей ячейки
            this->currentCellId = this->localization();

        } else {
            std::cout << "Error while trying to found B an C for base point" << std::endl;
            return;
        }
    }

    std::cout << "Построение лини тока закончилось, базовая точка вышла за пределы сетки" << std::endl;
}


