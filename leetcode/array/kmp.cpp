#include<vector>
#include<string>

using namespace std;

vector<int> buildNext(const string& str);

int strStr(const string&, const string&);

int main()
{
    // string str{"aabaaabaaac"};
    string pattern {"aabaaac"};
    // printf("%d\n", strStr(str, pattern));
    vector<int> next = buildNext(pattern);
    for (auto x : next)
        printf("%d\n", x);
    return 0;
}

/**
 * 其实是个动态规划的过程
 * 
 * 定义状态dp[i]: 以str[i]结尾的子串的最长公共前后缀长度
 * 
 * 状态转移方程:
 * 
 * dp[n] = max(i + 1)  i满足str[n] = str[i], 其中：i(k) = dp[i(k-1)-1], i(1) = dp[n-1]
 * 
 * i为前一个最长公共前后缀的后一个位置下标
 * 
 * 形象的解释就是：
 * 
 * 比如 aabaaac 匹配到aab和aaa时
 * 
 * b != a
 * 
 * 但是前面的部分肯定是相同的__b和__a
 * 
 * 我们只需要在共同的部分里面找有没有 X__X 这种结构
 * 
 * 也就是只需在共同前缀当中找最长公共前后缀X
 * 
 * 然后去比较X后面一位和a
 * 
 * 如果没有就直接和第一位比
 * 
 * 可以看出dp[n]都可以由之前的状态转移得到
 * 
 * 原因是： 一个长度大于1的公共前后缀，只能由一个现有的在末尾加上一部分得到
 * 
 * 比如Xa__Xa 只能由 Xa__X得到
 * 
 */
vector<int> buildNext(const string& str)
{
    const std::size_t len = str.size();
    if (!len) return vector<int> {};
    vector<int> next(len);
    next[0] = 0; // 基础情形

    int pre = 0;
    for (int i = 1; i < len - 1; ++i)
    {
        pre = next[i-1];
        if (str[i] == str[pre])
            next[i] = pre + 1;
        else
        {
            // 回溯比较直到没有公共前后缀为止
            // 暂时先不合并吧，这里方便理解，但看着确实别扭
            while (pre > 0)
            {
                // 匹配成功
                if (str[pre] == str[i]) // 这里可以写成一个循环，如果没匹配成功，i是不会右移的
                {
                    next[i] = pre + 1;
                    break;
                }
                pre = next[pre-1];
            }
            
            // 最终未匹配成功，和第一位比较
            if (pre == 0)
                next[i] = str[i] == str[0] ? 1 : 0;
        }
    }

    return next;
}


int strStr(const string& str, const string& pattern)
{
    const std::size_t l_p = pattern.size();
    if (!l_p) return 0;
    const std::size_t l_s = str.size();
    if (!l_s) return -1;

    vector<int> next = buildNext(pattern);
    printf("next:\n");
    for (auto x : next)
        printf("%d\n", x);
    // next[0] = -1; 这样后面就不用判断j == 0了
    int i = 0;
    int len = 0;
    while (i < static_cast<int>(l_s) - static_cast<int>(l_p) + 1) // 确保str不会越界
    {
        len = 0;
        printf("i: %d ", i);
        while (len < l_p) // pattern 不会越界
        {
            if (str[i+len] != pattern[len])
            {
                if (len == 0) 
                    ++i;
                else
                    i += len - next[len-1];
                    
                break;

            } else ++len;
        }

        printf("len: %d ", len);
        printf("i: %d \n", i);
        if (len == l_p) return i; // 到达末尾才退出循环，代表匹配完成，否则继续匹配
            
    }

    return -1;
}
