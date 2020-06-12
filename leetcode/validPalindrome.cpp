#include<string>
#include<cstdio>
/**
 * 
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True

示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。

注意:字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/
using namespace std;

class Solution {
    static const int MODIFY = 1;

public:
    bool validPalindrome(const string& s) {
        return validPalindrome(s, 0, s.size()-1);
    }

private:
    int modify = 0;
    bool validPalindrome(const string& s, std::size_t head, std::size_t tail) {
        if (head >= tail) return true;

        // 每个去掉首尾的子串递归一次，递归层数过多
        // if (s[head] == s[tail]) return validPalindrome(s, head+1, tail-1);
        while (s[head] == s[tail]) {
            ++head;
            --tail;
            if (head >= tail)
                return true;
        } 

        if (modify >= MODIFY)
            return false;
    
        ++modify;
        return validPalindrome(s, head+1, tail) or validPalindrome(s, head, tail-1); 
        
    }

};

int main() {
    Solution s{};
    string str {"abca"};
    if (s.validPalindrome(str))
        printf("true\n");
    else
        printf("flase\n");
}
