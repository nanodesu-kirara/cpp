#include<string>
#include<iostream>
using std::string;

int StrToInt(const string& s)
{
    // 判断为空
    if (!s.size())
        return 0;
    
    // 判断符号
    int sign = 1;
    if (s[0] == '-')
        sign = -1;
    
    // 计算同时判断是否溢出
    int ans = 0;
    // TODO: 还没有对非数字的处理（包括空格）
    if (sign == 1)
        for (auto x : s)
            if (static_cast<int>((INT32_MAX - x) / 10) >= ans)
                ans = ans*10 + (x - '0');
            else
                return INT32_MAX;
    else
        for (int i = 1; i < s.size() && isdigit(s[i]); ++i)
            if (static_cast<int>((INT32_MIN + s[i]) / 10) <= ans)
                ans = ans*10 - (s[i] - '0');
            else
                return INT32_MIN;

    return ans;
}

int main() {
    string str{"12345"};
    std::cout << StrToInt(str) - 4 << std::endl;
}
