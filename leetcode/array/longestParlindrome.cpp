#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using std::string;
using std::vector;
using std::unordered_map;
using std::cout, std::endl;

/**
 * 思路：
 * 如何得到最长回文子串？
 * 两种方式取较大者
 * 1. 前n-1个字母的最长回文子串
 * 2. 以str[n-1]结尾的回文串, 首尾加上str[n]
 * 
 * 熟悉的两个递推式:
 * 当前n-1个字母的最长回文子串，开头的前一个字母 不等于 str[n] 时
 * 以str[n-1]结尾的回文子串，开头前一个字母 等于 str[n] 时
 * 二者取较大者
 * 
 * 需要的信息有：（只记录开头和结尾位置）
 * 前一个最长回文子串
 * 以及以str[n-1]结尾的回文子串(在当中找一个，开头前一个字母 等于 str[n]的 最长的)
 * 
 * 重新定义状态：
 * dp[i] 为 以str[i]结尾的回文子串开头的索引的集合
 * 状态转移方程：
 * dp[n] = { x-1 | x ∈ dp[n-1], str[x-1] = str[n] } ∪ { n }
 * 
 * 
 * 考虑压缩状态
 * 是否需要维护全部的索引
 * 很不幸，是的
 * 
 * 每次都需要遍历一次dp[n-1]
 * 将str[x-1]等于str[n]的索引-1加入dp[n]
 * 
 * 考虑用unordered_map, 以str[x-1]建立索引
 * 每次查找等于str[n]的，只需要O(1)
 * 构建这样一个unordered_map需要插入dp[n-1][str[n]]次
 * 
 */

string longestParlindrome(string& str) {
    const int len = str.size();
    if (!len)
        return string{};
    vector<unordered_map<char, vector<int> > > dp(len);
    char c = str[0];
    dp[0][c].push_back(0);
    int begin = 0, max_len = 1;
    for (size_t i = 1; i < len; ++i)
    {
            c = str[i];

            for (const auto& x : dp[i-1][c])
            {
                if (x > 0)
                    dp[i][str[x-1]].push_back(x-1);

                if (i - x + 1 > max_len)
                {
                    begin = x;
                    max_len = static_cast<int>(i) - x + 1;
                }
                    
            }
            // printf("begin: %d, len: %d\n", begin, max_len);
            dp[i][c].push_back(i); // 把自己加进去, "aa"的情况
            dp[i][str[i-1]].push_back(i-1); // 把前一项加进去, "xax"的情况
    }
    return str.substr(begin, max_len);
}

/**
 * 再思考：
 * 
 * 在这种字符串问题中
 * 状态转移的过程
 * 一定就是从 前n-1项 -> 前n项 吗?
 * 
 * 也就是说这个一定是线性的吗？
 * 一定是单个方向的吗?
 * 
 * 这个问题是区间DP
 * 应该考虑向两端延伸
 * 即[i, j] -> [i-1, j+1]
 * 
 * 如果只是考虑[0, i] -> [0, i+1]
 * 不能定义出更优的状态
 * 
 * 不同的问题要结合其性质来
 * 
 * 计算顺序:
 * 一个更长的回文子串一定是由一个更短的回文子串得到的
 * 
 * 定义了状态之后, 我们也可以用递归的视角来看
 * 
 * 子问题: P[i+1, j-1] 又依赖子问题的解 P[i+2, j-1] ... 直到基准情形: P[i+k, j-k] , i+k = j-k 或 i+k+1 = j-k
 * 
 * 上述过程倒转过来就是我们求解子问题的顺序P[0,0],P[1,1]...P[n,n] -> P[0,1],P[1,2]...P[n-1,n] -> ...
 * 
 * 按照子串长度，就可以确保，子问题已经得到求解
 * 
 */

string betterLongestParlindrome(string& str)
{
    const size_t len = str.size();
    if (!len)
        return string{};
    vector<vector<bool>> dp(len, vector<bool>(len));
    // P(i, j) = P(i+1, j-1) and (str[i] == str[j])
    // 计算顺序，外层循环是长度
    size_t begin = 0, max_len = 1;
    for (size_t l = 0; l < len; ++l) 
    {
        for (size_t i = 0; i + l < len; ++i)
        {
            if (l == 0)
                dp[i][i+l] = true;
            else if (l == 1)
                dp[i][i+l] = str[i] == str[i+l];
            else
                dp[i][i+l] = dp[i+1][i+l-1] && (str[i] == str[i+l]);
            
            if (dp[i][i+l] && l + 1 > max_len)
            {
                begin = i;
                max_len = l + 1;
            }
        }
    }

    return str.substr(begin, max_len);

}

int main() {
    string str{"a"};
    cout << longestParlindrome(str) << endl;
}
