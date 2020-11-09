//
// Created by Виктория Губанова on 17.08.2020.
//

#ifndef CURRENTLINES_CURRENTLINEGENERATOR_HPP
#define CURRENTLINES_CURRENTLINEGENERATOR_HPP

#include "CurrentLine.h"
#include "Mesh.h"

class CurrentLineGenerator {
    CurrentLine* currentLine;
    Mesh* mesh;
public:
    CurrentLineGenerator(Mesh& pmesh, Point& basePoint);

    //! Метод для локализации текущей базовой точки
    //! \return id ячейки, в которой находится базовая точка
    //! \return -1, если такая ячейка не найдена
    int localization();
};


#endif //CURRENTLINES_CURRENTLINEGENERATOR_HPP
