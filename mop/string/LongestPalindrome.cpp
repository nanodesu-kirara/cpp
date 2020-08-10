#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;

int LongestPalindrome(const string& str)
{
    const int len = str.size();
    if (!len) return 0;

    int max = 0;
    int l;
    for (int i = 0; i < len; ++i)
    {
        // 奇数长度回文
        // str[i]是中心
        for (l = 1; i - l >= 0 && i + l < len; ++l)
            if (str[i-l] != str[i+l])
                break;

        max = std::max(max, 2*l-1);

        // 偶数长度回文
        // str[i]是中心左邻字母
        for (l = 0; i - l >= 0 && i + l + 1 < len; ++l)
            if (str[i-l] != str[i+l+1])
                break;

        max = std::max(max, 2*l);
    }

    return max;
}

// manacher算法
int manacher(const string& str)
{
    if (!str.size()) return 0;
    // 预处理 插入间隔字符（不一定是未出现的）
    const char desperate = '#';
    string copy(2*str.size()+1, desperate);
    for (int i = 0; i < str.size(); ++i)
        copy[2*i+1] = str[i];

    std::cout << copy << std::endl;

    // 遍历比较
    vector<int> P(copy.size());
    int id = 0;
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < copy.size(); ++i)
    {
        // 设好P[i]最小值，避免重复比较
        if (mx > i)
            P[i] = std::min(P[2*id-i], mx - i);
        else
            P[i] = 1;

        // 从P[i]开始比较
        while (i-P[i] >= 0 && i + P[i] < copy.size())
        {
            if (copy[i+P[i]] == copy[i-P[i]])
                ++P[i];
            else
                break;
        }

        if (i + P[i] > mx)
        {
            mx = i + P[i];
            id = i;
        }
        
        ans = std::max(ans, (P[i] - 1));
        // std::cout << "i: " << i << "; " << "P[i]: " << P[i] << "; " << "mx: " << mx << "; " << "id: " << id << "; " << std::endl;
    }

    return ans;
}

int main()
{
    const int len = manacher(string{"12212321"});
    printf("%d\n", len);
}
