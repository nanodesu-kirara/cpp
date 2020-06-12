/**
 * 实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/
#include<cstdio>
#include<utility>

int mySqrt(std::size_t x) {
    int a = 1;
    int b = x;
    int mid = (a+b)/2;
    while (mid != a && mid != b)
    {
        if (mid*mid < x)
            a = mid;
        else if (mid*mid > x)
            b = mid;
        else 
            return mid;
        mid = (a+b)/2;
    }
    return mid;
}

int main() {
    int x = 2147395599;
    printf("sqrt(%d) = %d\n", x, mySqrt(x));
}
