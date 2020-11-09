//
// Created by Виктория Губанова on 31.08.2020.
//

#ifndef CURRENTLINES3D_MESHLOADER_H
#define CURRENTLINES3D_MESHLOADER_H

#include <string>
#include "Mesh.h"

class MeshLoader {

private:
    Mesh* mesh;
    std::string nodesFilename;
    std::string cellsFilename;

    // Метод, который получает на вход строку, разделитель и вектор результатов
    template<class T>
    void tokenize(std::string &str, char delim, std::vector<T> &out);
public:
    MeshLoader(std::string nodesFilename_p, std::string cellsFilename_p);
    ~MeshLoader();

    std::vector<Node> loadNodes();
    std::vector<std::tuple<long, long, long, long, long, long, long, long, long>> loadCells();
};


#endif //CURRENTLINES3D_MESHLOADER_H
