/**
 * 19 正则表达式匹配
 * 假定只有'.' 和 '*' 两种模式匹配符
 */

#include<string>
#include<iostream>
using std::string;

bool ReMatch(const string& s, const string& pattern);
bool ReMatch(const string& s, const string& pattern, int i, int j);

bool ReMatch(const string& s, const string& pattern)
{
    return ReMatch(s, pattern, 0, 0);
}

bool ReMatch(const string& s, const string& pattern, int i, int j)
{
    // 模式字符串已经结束 并且 被匹配字符串已完成匹配 
    if (i >= s.size() && j >= pattern.size())
        return true;
    
    // 模式字符串已经结束 但是 被匹配字符串未完成匹配 
    if (i < s.size() && j >= pattern.size())
        return false;

    // 模式字符串还未结束 而 被匹配字符串 已完成 / 未完成 匹配
    // 如果未完成，那么需要是'*'
    if (pattern[j+1] == '*') 
    {
        // 当前位匹配
        if (pattern[j] == s[i] || (pattern[j] == '.' && s[i] != '\0'))
            return ReMatch(s, pattern, i+1, j)
                || ReMatch(s, pattern, i, j+2);
        else
            return ReMatch(s, pattern, i, j+2);

    }

    if (pattern[j] == s[i] || (pattern[j] == '.' && s[i] != '\0'))
        return ReMatch(s, pattern, i+1, j+1);
    
    return false;
}

int main()
{
    string s{"aaa"};
    string p{"ab*ac*a"};
    if (ReMatch(s, p))
        std::cout << "match" << std::endl;
    else
        std::cout << "not match" << std::endl;

    return 0;
}

