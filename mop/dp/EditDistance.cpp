/**
 * 5.2 字符串（最短）编辑距离
 */

#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using std::vector;
using std::string;

int EditDistance(const string&, const string&);

int EditDistance(const string& src, const string& tar)
{
    const int l_s = src.size();
    const int l_t = tar.size();

    // dp[i][j] 代表 src[0...i) 到 tar[0...j) 的编辑距离
    // 注意这里dp[0][j]是 空白 到 tar[0...j), 不是src[0] 到 ... 
    vector<vector<int>> dp(l_s + 1, vector<int>(l_t + 1));

    // 设置初始边界
    for (int i = 1; i <= l_s; ++i)
        dp[i][0] = i;

    // 设置初始边界
    for (int j = 1; j <= l_t; ++j)
        dp[0][j] = j;

    // 深度优先搜索
    for (int i = 1; i <= l_s; ++i)
    {
        for (int j = 1; j <= l_t; ++j)
            // dp[i][j] = dp[i-1][j] + 1;  删除src[i-1]

            // dp[i][j] = dp[i][j-1] + 1;  插入src[i-1]

            // dp[i][j] = ( src[i-1] == tar[j-1] ? 0 : 1 ) + dp[i-1][j-1];  修改s[i-1] 或者不操作

            dp[i][j] = (src[i-1] == tar[j-1]) ? dp[i-1][j-1] : (std::min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + 1);
    }

    return dp[l_s][l_t];

}
