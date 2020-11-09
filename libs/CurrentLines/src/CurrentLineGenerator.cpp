//
// Created by Виктория Губанова on 17.08.2020.
//

#include <CurrentLineGenerator.h>

CurrentLineGenerator::CurrentLineGenerator(Mesh &pmesh, Point &basePoint) {
    currentLine = new CurrentLine(*new Node(basePoint));
    mesh = &pmesh;

    // Запускаем локализация базовой точки для определения текущей ячейки
    this->localization();
}

int CurrentLineGenerator::localization() {
    for (int i = 0; i < this->mesh->numberOfCells(); ++i) {
        if (this->mesh->cells[i].containsPoint(this->currentLine->getNode().getPoint())) {
            return i;
        }
    }

    return -1;
}
