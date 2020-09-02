/**
 * 17 打印从1到最大的n位数(十进制)
 * 
 * 像这种看起来很简单地问题都有明显的'陷阱'在里面
 * 这道题需要处理大数问题,一般采用数组或字符串
 */

#include<string>
#include<iostream>
using std::string, std::size_t;

void core(size_t k, size_t n, string& number);

void PrintOneToN(size_t n)
{
    if (!n) return;

    string number(n, 0);

    // n个位置上数字0~9的全排列,从小到大输出
    core(0, n, number);

}

// 前面的0不打印
void PrintNumber(const string& str)
{
    size_t i = 0;
    while (i < str.size() && str[i] == '0')
        ++i;

    if (i >= str.size())
        return;
    std::cout << str.substr(i) << std::endl;
}

// 固定首位 + 余下位全排列
void core(size_t k, size_t n, string& number)
{
    if (k > n-1)
        // std::cout << number << std::endl;
        PrintNumber(number);
    else
    {
        for (int i = 0; i <= 9; ++i)
        {
            number[k] = i + '0';
            // 这里不能用++k, 每次循环不能改变k的值
            core(k+1, n, number);
        }
    }
}

int main()
{
    PrintOneToN(2);
}
