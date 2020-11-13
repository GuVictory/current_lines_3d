//
// Created by Виктория Губанова on 13.11.2020.
//

#include "MeshUnloading.h"
#include <fstream>

void MeshUnloading::setFileToUnload(std::string currentLineFilename_p) {
    this->currentLineFilename = std::move(currentLineFilename_p);
}

void MeshUnloading::unloadCurrentLine(std::vector<Node *> currentLine) {

    std::ofstream out;
    out.open(this->currentLineFilename, std::ios::trunc);

    if(!out) {
        std::cout << "Ошибка при создании файла для выкрузки результатов!" << std::endl;
        return;
    }

    out << currentLine.size() << std::endl;

    for(int i = 0; i < currentLine.size(); ++i) {
        out << i << " " << currentLine[i]->getPoint().getX()
                 << " " << currentLine[i]->getPoint().getY()
                 << " " << currentLine[i]->getPoint().getZ()
                 << " " << currentLine[i]->getField().getX()
                 << " " << currentLine[i]->getField().getY()
                 << " " << currentLine[i]->getField().getZ() << std::endl;
    }

    out.close();

}
