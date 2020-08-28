/**
 * 13 机器人的移动范围
 * 在m x n的方格中
 * 坐标数位之和不大于k, 出发点为(0, 0)
 * 能达到多少格子
 * 
 * 题目没有描述清楚, (0, 0)的点在顶点处, 对应数组下标
 * 
 * 回溯法是解决这类二维矩阵的路径问题的基本方法
 * 本质还是有向无环图的遍历
 */
#include<vector>
#include<iostream>
using std::vector, std::size_t;

size_t digitSum(int num);

size_t movingRange(size_t threshold, size_t m, size_t n);

size_t movingRange(size_t threshold, vector<vector<bool>>& visited, int x, int y, size_t m, size_t n);

size_t movingRange(size_t threshold, size_t m, size_t n)
{

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    return movingRange(threshold, visited, 0, 0, m, n);

}

size_t movingRange(size_t threshold, vector<vector<bool>>& visited, int x, int y, size_t m, size_t n)
{
    if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y])
        return 0;

    if (digitSum(x) + digitSum(y) > threshold)
        return 0;
    else
    {
        visited[x][y] = true;

        return 1 + movingRange(threshold, visited, x-1, y, m, n)
            + movingRange(threshold, visited, x+1, y, m, n)
            + movingRange(threshold, visited, x, y-1, m, n)
            + movingRange(threshold, visited, x, y+1, m, n);

    }
}

size_t digitSum(int num)
{
    size_t result = 0;
    while (num)
    {
        result += num % 10;
        num /= 10;
    }

    return result;
}

int main()
{
    std::cout << movingRange(4, 100, 100) << std::endl;
}
