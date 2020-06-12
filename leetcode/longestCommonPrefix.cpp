/**
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        string back{strs.back()};
        strs.pop_back();
        return commonPrefix(back, longestCommonPrefix(strs));
    }

private:
    string commonPrefix(const string& s1, const string& s2) {
        std::size_t index = 0;
        std::size_t len = s1.size() < s2.size() ? s1.size() : s2.size();
        while (index < len)
            if (s1[index] == s2[index]) ++index; else break;
        return s1.substr(0, index);
    }
    
};

int main() {
    Solution slt{};
    vector<string> vec{"floor", "flood", "floot", "fly"};
    slt.longestCommonPrefix(vec);
}
