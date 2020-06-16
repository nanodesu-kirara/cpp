/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

示例 1：
输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

示例 2：
输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

/**
 * 思路：
 * 本来想一遍遍历解决问题
 * 但是，处于后面遍历的行如果有0会影响前面的列
 * 所以还是改成了两遍遍历
 * 
 * 注意：
 * 第二次遍历就没必要遍历整个矩阵了
 * 数组是随机访问的, 只需要访问记录的位置即可
 */

#include<vector>
#include<unordered_set>
using std::size_t;
using std::vector;
using std::unordered_set;

void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> zeroRows{};
    unordered_set<int> zeroColumns{};

    size_t rowNums = matrix.size();
    if (rowNums == 0)
        return;

    size_t columnNums = matrix[0].size();
    if (columnNums == 0)
        return;

    for (size_t r = 0; r < rowNums; ++r)
        for (size_t c = 0; c < columnNums; ++c)
            if (matrix[r][c] == 0) {
                zeroRows.insert(r);
                zeroColumns.insert(c);
            }

    for (const auto& r : zeroRows)
        matrix[r] = vector<int>(columnNums, 0);

    for (const auto& c : zeroColumns)
        for (auto& r : matrix)
            r[c] = 0;

    /**
     * 第二遍就没必要遍历矩阵了
     * 数组是随机访问的
     *
    for (size_t r = 0; r < rowNums; ++r) {
        if (zeroRows.count(r)) {
            matrix[r] = vector<int>(columnNums, 0);
            continue;
        }

        for (size_t c = 0; c < columnNums; ++c) {
            if (zeroColumns.count(c))
                matrix[r][c] = 0;
        }

    }
    */

}