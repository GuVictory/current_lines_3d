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

    int currentCellId;
public:
    //! Конструктор принимает стартовую базовую точку и сетку, на которой будет строится линия тока
    CurrentLineGenerator(Mesh& pmesh, Point& basePoint);

    //! Метод для локализации текущей базовой точки
    //! \return id ячейки, в которой находится базовая точка
    //! \return -1, если такая ячейка не найдена
    int localization();

    //! Метод генерирующий линию тока, вызывает интерполяцию
    void generateCurrentLine();

    CurrentLine* getCurrentLine();
};


#endif //CURRENTLINES_CURRENTLINEGENERATOR_HPP
