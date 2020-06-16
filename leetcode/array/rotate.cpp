/*给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

/**
 * 思路：
 * 顺时针旋转90度
 * 等价于，按右对角线翻折
 * 再按纵轴对称翻折
 */
#include<vector>
#include<algorithm>
using std::vector;
using std::size_t;

void rotate(vector<vector<int>>& matrix) {
    const size_t size = matrix.size();
    if (size < 2)
        return;
    // 按x + y = 0翻转
    for (size_t r = 1; r < size; ++r)
        for (size_t c = 0; c < r; ++c)
            std::swap(matrix[r][c], matrix[c][r]);
    // 按y轴翻转
    for (auto& row : matrix)
        for (size_t i = 0; i < size/2; ++i)
            std::swap(row[i], row[size-i-1]);
}
