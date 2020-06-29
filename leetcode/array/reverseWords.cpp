#include<string>
#include<iostream>
using std::string, std::size_t;
/**
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 */
string reverseWords(const string& str) {
    size_t end = str.size()-1;
    int begin = end;
    while (begin >= 0 and str[begin] == ' ')
            --begin;
    end = begin;
    string ans{};

    while (begin >= 0)
    {
        while (begin >= 0 and str[begin] != ' ')
            --begin;
        ans.append(str.substr(begin + 1, end-begin));
        ans.push_back(' ');

        // std::cout << ans << std::endl;

        while (begin >= 0 and str[begin] == ' ')
            --begin;

        end = begin;
    }
    ans.pop_back();

    return ans;
}

int main() {
    std::cout << reverseWords("  sky  is blue  ") << "/end" << std::endl;
}
