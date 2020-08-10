/**
 * 2.5 跳台阶问题
 */

#include<vector>
#include<iostream>

using std::vector;

int ClimbStairs(int);

int main()
{
    std::cout << ClimbStairs(5) << std::endl;
}

int ClimbStairs(int n)
{
    int ans = 1;
    int pre = 1;

    if (n < 2)
        return ans;

    for (int i = 2; i <= n; ++i)
    {
        std::swap(ans, pre);
        ans += pre;
    }

    return ans;
}

