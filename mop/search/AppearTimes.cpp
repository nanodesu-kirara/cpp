/**
 * 4.3 查找出现次数超过一半的数
 * "不同相消"
 */
#include<vector>
#include<iostream>
#include<exception>

using std::vector;

// 返回出现超过半数的元素
int widget(const vector<int>&);

int main()
{
    vector<int> vec{ 1, 0, 9, 3, 6, 9, 3, 2, 8, 1, 3, 3, 3, 3, 3, 3 };
    std::cout << widget(vec) << std::endl;
}

int widget(const vector<int>& vec)
{
    int candidate;
    int times = 0;

    for (auto x : vec)
    {
        if (!times)
        {
            candidate = x;
            times = 1;
        }
        else if (x != candidate)
            --times;
        else if (x == candidate)
            ++times;
    }

    if (times)
        return candidate;
    
    // 看清题目中是不是假定出现了
    throw std::exception{};
}
