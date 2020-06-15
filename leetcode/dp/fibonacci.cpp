/**
 * 斐波那契数列的动态规划方法
 */
#include<iostream>
int fibonacci(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;

    int pre = 1;
    int ppre = 1;
    int temp = 0;

    for (int i = 3; i < n; ++i)
    {
        temp = pre + ppre;
        ppre = pre;
        pre = temp;
    }
    
    return ppre + pre;
}

int main() {
    printf("fibonacci(6) is: %d\n", fibonacci(6));
}
