/**
 * 12. 计算二进制中1的个数
 */
#include<iostream>
int CountOneBits(int n)
{
    int count = 0;

    while (n)
    {
        n &= (n - 1);
        ++count;
    }

    return count;
}

int main()
{
    std::cout << CountOneBits(7) << std::endl;
}