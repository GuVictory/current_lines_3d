//
// Created by Виктория Губанова on 23.10.2020.
//

#ifndef CURRENTLINES3D_GAUSS_H
#define CURRENTLINES3D_GAUSS_H

#include <vector>
#include <cmath>

/*!
 * Функция для решения СЛАУ методом Гауса
 * @param A - Матрица коэф при неизвестных
 * @param B - Свободные члены
 * @return - Возвращает вектор решений СЛАУ
 */
std::pair<bool, std::vector<double>> gauss(std::vector<std::vector<double>> A, std::vector<double> B, int size) {
    std::vector<double> X = std::vector<double>(size);
    double maxElement = 0;
    int k = 0, index = 0;
    const double eps = 0.00001;  // точность

    while (k < size) {
        // Поиск строки с максимальным A[i][k]
        maxElement = abs(A[k][k]);
        index = k;

        for (int i = k + 1; i < size; i++)
        {
            if (abs(A[i][k]) > maxElement)
            {
                maxElement = abs(A[i][k]);
                index = i;
            }
        }

        // Перестановка строк
        if (maxElement < eps)
        {
            // нет ненулевых диагональных элементов
            // std::cout << "Решение получить невозможно из-за нулевого столбца ";
            // cout << index << " матрицы A" << endl;
            return std::make_pair(false, X);
        }

        for (int j = 0; j < size; j++)
        {
            double temp = A[k][j];
            A[k][j] = A[index][j];
            A[index][j] = temp;
        }
        double temp = B[k];
        B[k] = B[index];
        B[index] = temp;

        // Нормализация уравнений
        for (int i = k; i < size; i++)
        {
            double temp = A[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < size; j++)
                A[i][j] = A[i][j] / temp;
            B[i] = B[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < size; j++)
                A[i][j] = A[i][j] - A[k][j];
            B[i] = B[i] - B[k];
        }
        k++;
    }

    // обратная подстановка
    for (k = size - 1; k >= 0; k--)
    {
        X[k] = B[k];
        for (int i = 0; i < k; i++)
            B[i] = B[i] - A[i][k] * X[k];
    }

    return std::make_pair(true, X);
}


#endif //CURRENTLINES3D_GAUSS_H
