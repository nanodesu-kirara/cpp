/**
 * 14 剪绳子
 * 乘积最大的剪法
 */
#include<vector>
#include<iostream>
int CutRope(int len)
{
    std::vector<int> dp(len+1);

    if (len < 2)
        return 0; // 剪不了
    if (len == 2)
        return 1; // 题目要求必须剪一次
    if (len == 3)
        return 2;

    // 当绳子长度大于4的时候,就需要剪了
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int product;
    // 绳子长度
    for (int l = 4; l <= len; ++l)
        // 剪的长度
        for (int i = 1; i < l/2 + 1; ++i)
        {
            product = dp[i] * dp[l-i];
            dp[l] = std::max(product, dp[l]);
        }

    // for (auto x : dp)
        // std::cout << x << std::endl;

    return dp[len];
}

int main()
{
    std::cout << CutRope(8) << std::endl;
}
