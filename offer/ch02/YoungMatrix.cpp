/**
 * 4. 杨氏矩阵查找
 */
#include<vector>
using std::vector;

/**
 * 需要注意的是如果题目以int*的形式给出
 * 二维数组在内存中的存储可以用首地址（数组名）+ 偏移量的方式计算得出
 * base + (x*column_size) + y
 */

bool Search(const vector<vector<int>>& matrix, int target)
{
    const int rows = matrix.size();
    if (! rows) return false;

    const int columns = matrix[0].size();
    if (! columns) return false;

    for (auto row : matrix)
        if (row.size() != columns)
            return false;

    int x = 0; // 行下标
    int y = columns - 1; // 列下标

    while (x < rows && y >= 0)
    {
        if (matrix[x][y] < target)
            ++x;
        else if (matrix[x][y] > target)
            --y;
        else
            return true;
    }

    return false;
}

