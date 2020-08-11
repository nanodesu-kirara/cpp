/**
 * 4.4 字符串查找
 * kmp算法再探
 * 
 * 理清了还蛮简单的
 * 状态转移方程的未知量k设出来，然后求解
 * 
 * 匹配时，先写出蛮力法框架
 * 然后利用next数组优化
 */

#include<string>
#include<vector>
#include<iostream>

using std::string;
using std::vector;

vector<int> BuildNext(const string&);

int kmp(const string&, const string&);

int main()
{
    string str{"aabaaabaaac"};
    string pattern {"aabaaac"};
    printf("%d\n", kmp(str, pattern));
    return 0;
}

vector<int> BuildNext(const string& pattern)
{
    vector<int> dp(pattern.size());

    for (int i = 1; i < pattern.size(); ++i)
    {
        int k = i;
        while (k > 0)
        {
            k = dp[k-1];
            if (pattern[i] == pattern[k])
                break;
        }

        dp[i] = k ? k + 1 : pattern[k] == pattern[i];
    }

    return dp;
}

int kmp(const string& str, const string& pattern)
{
    const int NOT_MATCH = -1;
    const int l_s = str.size();
    const int l_p = pattern.size();
    vector<int> next{ BuildNext(pattern) };

    int i = 0; int l = 0;
    while (i < l_s - l_p + 1)
    {
        l = 0;
        while (l < l_p)
        {
            if (str[i+l] != pattern[l])
                break;
            ++l;
        }

        if (l != l_p)
            i += l - next[l-1];
        else
            return i;
    }

    return NOT_MATCH;
}
