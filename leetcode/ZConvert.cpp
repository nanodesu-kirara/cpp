/**
 * 6. Z 字形变换
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
通过次数136,660提交次数284,365
*/

/**
 * 思路：
 * 有很明显的规律...
 * L.C.O.D     R
 * E   . E   I I
 * E .   I H   N
 * T     S     G
 * 
 * L     D     R
 * E C O E   I I
 * E .   I H   N
 * T     S     G
 * 
 * L     D     R
 * E   . E   I I
 * E C O I H   N
 * T     S     G
 * 
 * row 1: 
 * L和D的距离可以看成一个直角三角形的底和高之和
 * 3 + 3 = 6
 * 
 * row 2: 
 * E和O的距离同理: 2 + 2 = 4
 * O和E: 1 + 1 = 2
 * 
 * row 3: 
 * E和C: 1 + 1 = 2
 * C和I: 2 + 2 = 4
 * 
 * row 4: T
 * 0 + 0 = 0
 * 
 * 这样好像复杂化了
 * 
 * 直接考虑对numRows的余数
 * 
 * row1: (4-1)*2n = 6n +/_ 0
 * 
 * row2: (4-1)*2n +/_ 1 = 6n +/_ 1
 * 
 * ...
 */
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::size_t;

string convert(string s, int numRows){
    /**
     * 单行模为零
     * 不能对零取模
     */
    if (numRows == 1)
        return s;
    vector<string> rows(numRows);
    const int mod = (numRows - 1) * 2;
    int remainder;
    for (size_t i = 0; i < s.length(); ++i) {
        remainder = i % mod;
        rows[std::min(remainder, mod - remainder)].push_back(s[i]);
    }
    string ans {};
    for (const auto& r : rows)
    {
        ans = ans.append(r);
    }
    return ans;
}

