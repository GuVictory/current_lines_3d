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

    if (this->currentCellId != -1) {
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

        auto scanLine = Line::getScanLineOX(this->currentLine->getNode().getPoint());

        std::pair<bool, Point> BPoint = scanLine.foundIntersectionPoint(*new Line(*D, *E));
        std::pair<bool, Point> CPoint = scanLine.foundIntersectionPoint(*new Line(*F, *G));

        if (BPoint.first && CPoint.first) {
            Node* B = new Node(BPoint.second);
            Node* C = new Node(CPoint.second);
        } else {
            std::cout << "Error while trying to found B an C for base point" << std::endl;
            return;
        }

        double height = this->mesh->cells[this->currentCellId].getHeight();
        double width = this->mesh->cells[this->currentCellId].getWidth();
        double depth = this->mesh->cells[this->currentCellId].getDepth();

        Line* topA = new Line(this->currentLine->getNode(),
                              *new Node(this->currentLine->getNode().getPoint().getX(),
                                            this->currentLine->getNode().getPoint().getY(),
                                            this->mesh->cells[this->currentCellId].V1()->getPoint().getZ()));

        Line* frontA = new Line(this->currentLine->getNode(),
                              *new Node(this->currentLine->getNode().getPoint().getX(),
                                            this->mesh->cells[this->currentCellId].V1()->getPoint().getY(),
                                            this->currentLine->getNode().getPoint().getZ()));

        Line* leftA = new Line(this->currentLine->getNode(),
                              *new Node(this->mesh->cells[this->currentCellId].V1()->getPoint().getX(),
                                            this->currentLine->getNode().getPoint().getY(),
                                            this->currentLine->getNode().getPoint().getZ()));

        double tau = topA->len() / height;
        double omega = frontA->len() / depth;
        double gamma = leftA->len() / width;

        auto* interpolator = new Interpolator(tau, omega, gamma);

        // Осталось выполнить интерполяцию значений
    }
}


