/**
 * 5.4 交替字符串
 * 交替s1 和 s2 组成 s3
 * 不改变原本的相对顺序
 */

#include<vector>
#include<string>
#include<iostream>

using std::vector;
using std::string;

bool widget(const string&, const string&, const string&);

int main()
{
    string s1{"aabcc"};
    string s2{"dbbca"};
    // string s3{"aadbbcbcac"};
    string s3{"accabdbbca"};

    if (widget(s1, s2, s3))
        std::cout << "true" << std::endl;
    else
        std::cout << "flase" << std::endl;

}

bool widget(const string& s1, const string& s2, const string& s3)
{
    const int l1 = s1.size();
    const int l2 = s2.size();

    if (l1 + l2 != s3.size())
        return false;

    // 状态dp[i][j]为 s1[0...i) 和 s2[0...j) 交替组成字符串 与 s3[0...(i+j-1)] 的比较
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));

    dp[0][0] = true; // 三者皆空

    for (int i = 0; i <= l1; ++i)
    {
        for (int j = 0; j <= l2; ++j)
        {
            if (dp[i][j])
                dp[i][j] = true; // 针对dp[0][0]

            else if (i > 0 && dp[i-1][j] && s3[i+j-1] == s1[i-1])
                dp[i][j] = true;

            else if (j > 0 && dp[i][j-1] && s3[i+j-1] == s2[j-1])
                dp[i][j] = true;
            
            else
                dp[i][j] = false;
            
        }
    }

    return dp[l1][l2];
}
