/**
 * 120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/
#include<vector>
#include<iostream>
#include<algorithm>
using std::vector;
int minimumTotal(vector<vector<int>>& triangle) {
    const int row_size = triangle.size();
    vector<int> vec(row_size + 1);

    for (int row_num = row_size - 1; row_num > -1; --row_num) {
        for (int i = 0; i < row_num + 1; ++i)
            vec[i] = triangle[row_num][i] + std::min(vec[i], vec[i+1]);
    }

    return vec[0];
}
    
int main() {
    vector<vector<int>> triangle{};
    triangle.push_back(vector<int>{ 2 });
    triangle.push_back(vector<int>{ 3, 4 });
    triangle.push_back(vector<int>{ 6, 5, 7 });
    triangle.push_back(vector<int>{ 4, 1, 8, 3 });

    printf("minimum total path: %d\n", minimumTotal(triangle));

}


