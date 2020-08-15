/**
 * 5.实现一个函数
 * 将字符串中的空格替换成"%20"
 * 要求：修改原字符串
 * 长度会变化，思路是需要减少移动次数
 */
#include<string>
#include<iostream>

void ReplaceSpace(std::string& str)
{
    const int len = str.size();
    if (! len) return;
    int spaceCount = 0;

    for (auto x : str)
        if (x == ' ')
            ++spaceCount;

    // 根据空格数量重新分配字符串容量和大小
    str.reserve(str.capacity() + 2 * spaceCount);
    str.resize(len + 2 * spaceCount);

    // 从尾到头移动字符串，末尾的'\0'也算进去了
    int j = len + 2 * spaceCount;
    int i = len;

    while (i >= 0)
    {
        if (str[i] != ' ')
            str[j--] = str[i--];
        else
        {
            str[j] = '0';
            str[j-1] = '2';
            str[j-2] = '%';
            j -= 3;
            --i;
        }
    }
}

int main()
{
    std::string str{"We are happy."};
    ReplaceSpace(str);
    std::cout << str << std::endl;
    return 0;
}
