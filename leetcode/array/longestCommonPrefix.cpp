#include<string>
#include<vector>
#include<iostream>
using std::size_t, std::string, std::vector;

/**
 * 最长公共前缀
 * 
 * 多种解法，这里用的是纵向扫描
 * 还有一种专门的处理这种问题的"字典树"结构
 * 还有一个排序然后比较首尾两个字符串，不过时间复杂度较高，不过可以作为一种思路参考
 */
string longestCommonPrefix(vector<string>& strs) {
    int colNums = INT32_MAX;
    int rowNums = strs.size();
    if (!rowNums)
        return string{};
    for (const auto& s : strs)
        if (s.size() < colNums)
            colNums = s.size();
    
    char c;
    string prefix{};
    for (size_t col = 0; col < colNums; ++col)
    {
        c = strs[0][col];

        for (size_t row = 1; row < rowNums; ++row)
            if (strs[row][col] != c)
                return prefix;

        prefix.push_back(c);
    }
    return prefix;
}

int main() {
    vector<string> strs{"dog","racecar","car"};

    std::cout << longestCommonPrefix(strs) << std::endl;
}
