/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

*/
#include<list>
#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>

using std::size_t, std::string, std::vector;

string longestPalindrome(const string& s) {
    size_t head = 0;
    size_t tail = 0;
    size_t ssize = s.size();
    vector<vector<bool>> m((ssize), vector<bool>(ssize));
    for (size_t len = 0; len < ssize; ++len) {

        for (int i = 0; i < ssize ; --i) {
            if (s[i] != s[j])
                m[i][j] = false;
            else if (i+1 >= j)
                m[i][j] = true;
            else if (m[i+1][j-1] == true)
                m[i][j] = true;
            else
                m[i][j] = false;

            
            // printf("m[%d][%d] = %d, s[i]: %c, s[j]: %c, head: %d, tail: %d\n", i, j, static_cast<int>(m[i][j]), s[i], s[j], head, tail);
            
            if (m[i][j] == true and j - i > tail - head) {
                head = i;
                tail = j;
            }
        }
    }
    return s.substr(head, tail - head + 1);
}

int main(){
    string s{"babad"};
    std::cout << longestPalindrome(s) << std::endl;
}

