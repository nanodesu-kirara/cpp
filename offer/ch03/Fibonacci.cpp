/**
 * 斐波那契数列
 * 是不是本书都要讲一遍这个
 */

#include<utility>

int Fibonacci(unsigned int);

int Fibonacci(unsigned int n)
{
    if (! n)
        return 0;

    int pre = 0;
    int ans = 1;

    for (unsigned int i = 2; i <= n; ++i)
    {
        std::swap(pre, ans);
        ans += pre;
    }

    return ans;
}
