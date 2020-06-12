/**
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include<string>
#include<cstdlib>
#include<set>
#include<unordered_set>


using namespace std;
using std::size_t;

class Solution {
public:
    /**
     * 动态规划
     */
    int lengthOfLongestSubstring(const string& s) {
        std::size_t ans = 0;
        string rightFrom{};
        for (const auto& c : s) {
            std::size_t offset = rightFrom.rfind(c);
            if (offset != string::npos)
                rightFrom.erase(0, offset+1);
            rightFrom.push_back(c);
            ans = std::max(ans, rightFrom.size());
        }
        return ans;
    }

    /**
     * 滑动窗口
     */
    int slideWindow(const string& s) {
        size_t ans = 0;
        size_t h = 0; size_t t = 0; const size_t len = s.size();
        unordered_set<size_t> uset{};
        while (t < len) {
            while (uset.count(s[t])) 
                uset.erase(s[h++]);
            while (t < len and !uset.count(s[t]))
                uset.insert(s[t++]);
            ans = max(ans, uset.size());
        }
        return ans;
    }
};

int main() {
    Solution slt{};
    string str{"pwwkew"};
    printf("%d\n",slt.lengthOfLongestSubstring(str));
    printf("%d\n",slt.slideWindow(str));
}
