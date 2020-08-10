#ifndef utils
#define utils

#include<vector>
#include<iostream>
namespace M
{
    template<typename T>
    static void printVector(const std::vector<T>& vec)
    {
        for (auto x : vec)
            std::cout << x << " ";
        std::cout << std::endl;
    }

    template<typename T>
    static void printMatrix(const std::vector<std::vector<T>>& matrix)
    {
        for (auto row : matrix)
        {

            for (auto x : row)
                std::cout << x << " ";

            std::cout << std::endl;
        }
    }


}
#endif
