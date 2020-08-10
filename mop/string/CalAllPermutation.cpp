/**
 * 输入一个字符串
 * 输出其中字符的全排列
 */
#include<string>
#include<iostream>
#include<algorithm>
using std::string;
using std::cout;
using std::endl;

// 递归解法： 固定第一位 + 余下位的全排列
void CalAllPermutation(string& s, int from, int to)
{
    if (from == to)
        cout << s.substr(0, to+1) << endl;
    else
    {
        for (int i = from; i <= to; ++i)
        {
            std::swap(s[i], s[from]);
            CalAllPermutation(s, from + 1, to);
            // 再下次循环之前，恢复原样
            std::swap(s[i], s[from]);
        }
    }
}

// 字典序排列
bool CalAllPermutationNext(string& s, int num)
{
    int i;
    // 倒序可以减少遍历的长度
    for (i = num - 2; i >= 0 && s[i] >= s[i+1]; --i) {}
    if (i < 0)
       return false; // 此时s已经是最大字典序 
    int k;
    // 依旧是倒序，找最后一个比s[i]大的位置，tips: i后面都是倒序
    for (k = num - 1; k > i && s[k] <= s[i]; --k) {}
    // k肯定有, s[i+1] > s[i]
    std::swap(s[i], s[k]);
    std::reverse(s.begin() + i + 1, s.begin() + num);
    return true;
}

void ex1(string&, const string&, int, int);

void ex1(string& s)
{
    std::sort(s.begin(), s.end());
    string set{ s };
    ex1(s, set, 0, s.size()-1);
}

void ex1(string& s, const string& set, int from, int to)
{
    if (from == to)
    {
        int t = s[to];
        for (int i = 0; i <= to; ++i)
        {
            s[to] = set[i];
            cout << s << endl;
            s[to] = t;
        }
    }
    else
    {
        int t = s[from];
        for (int j = 0; j <= to; ++j)
        {
            s[from] = set[j];
            ex1(s, set, from+1, to);
        }
        s[from] = t;
    }
    
}

int main()
{
    string s{"ab"};
    ex1(s);
    return 0;
}
