/**
 * 2.8 两个矩阵相乘
 * 通用算法O(n^3), 优化后可以达到O(n^2.3727)
 * 这里只写通用解法，一些专门的库有更好的实现（利用硬件并行）
 */

#include<vector>
#include"utils.hpp"

using std::vector;

vector<vector<int>> MulMatrix(const vector<vector<int>>&, const vector<vector<int>>&);

int  main()
{
    vector<vector<int>> A{vector<int>{1,2}, vector<int>{3,4}};
    vector<vector<int>> B{vector<int>{0,1}, vector<int>{0,0}};
    M::printMatrix(MulMatrix(A, B));
    return 0;
}

/**
 *  AB 不是 BA
 * tips: 
 * 记 A 为 (a1, a2)^T
 * 记 B 为 (b1, b2)
 * 
 * AB = ((a1b1, a1b2), (a2b1, a2b2))
 */

    
vector<vector<int>> MulMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B)
{
    // 初始化存放乘积的矩阵
    const int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    // A的横向量
    for (int Ax = 0; Ax < n; ++Ax)
        // B的纵向量
        for (int By = 0; By < n; ++By)
            // A的横向量的纵向分量(标量), 控制各个对应分量(标量)相乘
            for (int Ay = 0; Ay < n; ++Ay)
                result[Ax][By] += A[Ax][Ay] * B[Ay][By];

    return result;
}
