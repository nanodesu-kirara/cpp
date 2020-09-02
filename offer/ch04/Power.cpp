/**
 * 16. 不利用库函数pow,实现数值的整数次方
 */
#include<float.h>
#include<iostream>
#include<algorithm>
#include<exception>
double compute(double base, int n)
{
    // 递归基准情形
    if (!n)
        return 1;
    if (n == 1)
        return base;

    double half = compute(base, n >> 1);
    // 奇数
    if (n & 0x1)
        return half*half*base;
    else
        return half*half;
}
double Power(double base, int n)
{
    // 需要考虑输入的多种情况

    if (DBL_EPSILON > std::abs(base - 0.0) && !n)
        throw std::exception{};
    
    double product = 1;

    if (!n)
        return product;
    else
        // for (int i = 0; i < std::abs(n); ++i)
        //     product *= base;
        product = compute(base, n);

    if (n < 0)
        product = 1.0 / product;

    return product;
}

int main()
{
    std::cout <<  Power(-2.0, 3) << std::endl;
}
