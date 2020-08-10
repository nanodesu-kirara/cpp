/**
 * 将字符串前若干个字符移至尾部
 */
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

// 编写一个一次移动一个字母的函数
void LeftShiftOne(string& s, int n)
{
    char p = s[0];
    for (int i = 0; i < n-1; ++i)
        s[i] = s[i+1];
    s[n - 1] = p;
}

// 调用需要移动字符串长度的次数
void LeftRotateString(string&s, int n, int m)
{
    while (m--)
        LeftShiftOne(s, n);
}

/** 
 * 三步翻转
 * 1. 分为需要移动的部分和不需要移动的部分
 * 2. 二者分别翻转
 * 3. 整体翻转
 * 
 * 原理： 分别翻转确保了内部顺序和原来一致，外部翻转移动了前后的位置
 */
void ReverseString(string& s, int from, int to)
{
    while(from < to)
        std::swap(s[from++], s[to--]);
}

void LeftRotateStringReverse(string&s, int n, int m)
{
    ReverseString(s, 0, m-1);
    ReverseString(s, m, n-1);
    ReverseString(s, 0, n-1);
}

// exercise: 翻转一个英文句子
// I am a student. -> student. a am I
// 未考虑首尾空格情形
void RotateSentence(string&s)
{
    int i = 0, j = 0;
    const int l = s.size();
    while (j < l)
    {
        if (s[j++] == ' ' || j == l)
        {
            ReverseString(s, i, j-2);
            i = j;
        }
    }
    ReverseString(s, 0, l-1);
}

int main()
{
    string s{"I am a student."};
    RotateSentence(s);
    cout << s << endl;
    return 0;
}
