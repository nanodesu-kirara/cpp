/* 498
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]
*/

#include<vector>
#include<iostream>
using std::vector;
using std::size_t;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    size_t rowNums = matrix.size();
    if (rowNums < 1)
        return vector<int>{};
    size_t columnNums = matrix[0].size();
    printf("rowNums: %d, columnNums: %d\n", rowNums, columnNums);
    bool moveUp = true;
    size_t i = 0;
    size_t j = 0;
    vector<int> ans{};
    while (i < rowNums && j < columnNums)
    {
        ans.push_back(matrix[i][j]);
        printf("push in: %d\n", matrix[i][j]);

        /**
         * 几种情况可以合并一下
         * A ∩ (B ∪ C) 
         * 就是这种感觉..
         * 有空再细看吧
         * 这道题没什么通用性的感觉
         */

        if (i == 0 && j != columnNums - 1 && moveUp)
        {
            ++j;
            moveUp = !moveUp;
        }
        else if (j == 0 && i != rowNums - 1 && !moveUp)
        {
            ++i;
            moveUp = !moveUp;
        }
        else if (i == rowNums - 1 && !moveUp)
        {
            ++j;
            moveUp = !moveUp;
        }
        else if (j == columnNums - 1 && moveUp)
        {
            ++i;
            moveUp = !moveUp;
        }
        else
        {
            if (moveUp)
            {
                --i;
                ++j;
            }
            else
            {
                ++i;
                --j;
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix{};
    matrix.push_back(vector<int>{1,2,3});
    matrix.push_back(vector<int>{4,5,6});
    matrix.push_back(vector<int>{7,8,9});

    findDiagonalOrder(matrix);
}
