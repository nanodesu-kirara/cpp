/**
 * 2.3 寻找任意多个数，和为给定值
 */

#include<vector>
#include<iostream>
using std::vector;

/**
 * t: 已经装入背包的数字之和
 * k: 第k个元素
 * r: 未装入的元素之和
 * M: 目标和
 * X: 解向量，各个元素选取情况
 * flag: 标志是否找到解
 */
void SumOfKNumber(int t, int k, int r, int& M, bool& flag, vector<bool>& X);

void SumOfKNumber(int t, int k, int r, int& M, bool& flag, vector<bool>& X)
{
    X[k] = true;
    if (t + k == M)
    {
        flag = true;
        
        // output:
        for (int i = 1; i <= k; ++i)
            if (X[i])
                std::cout << i << " ";

        std::cout << std::endl;
    }
    else
    {
        // 选取了第k个元素，并且后续不会无解(> M), 否则剪枝
        if (t + k + (k+1) <= M)
        {
            SumOfKNumber(t+k, k+1, r-k, M, flag, X);
        }

        // 没有选取第k个元素，也就是前一种情况无解（剪枝），或者是已经返回了
        // 转而对第k+1个元素进行判定
        if (t + k + 1 <= M && t + r - k >= M)
        {
            X[k] = false;
            SumOfKNumber(t, k+1, r-k, M, flag, X);
        }

    }
}

/**
 * N: 数列 1 2 3 ... N
 * M: 目标和
 */
void search(int& N, int& M)
{
    // 初始化解向量
    vector<bool> X(N-1, false);

    int total = N * ( N + 1 ) / 2;
    // 简单地排除几个无解情况
    if (total < M || M < 1)
    {
        std::cout << "No solution." << std::endl;
        return;
    }
    bool flag = false;
    SumOfKNumber(0, 1, total, M, flag, X);
    if (!flag)
        std::cout << "No solution." << std::endl;
}
