/**
 * 12 在矩阵中寻找特定路径
 * 回溯法
 * 有向无环图, 一个位置不能进入两次
 */

#include<string>
#include<vector>
#include<iostream>

using std::vector, std::string, std::size_t;
bool Path(const string&, const vector<vector<char>>&);
bool Path(const string& str, const vector<vector<char>>& matrix, vector<vector<bool>>& entry, size_t x, size_t y, size_t k);

bool Path(const string& str, const vector<vector<char>>& matrix)
{
    if (!str.size() || !matrix.size() || !matrix[0].size())
        return false;
    
    vector<vector<bool>> entry(matrix.size(), vector<bool>(matrix[0].size(), true));

    for (size_t x = 0; x < matrix.size(); ++x)
        for (size_t y = 0; y < matrix[0].size(); ++y)
            if (Path(str, matrix, entry, x, y, 0))
                return true;
            
    return false;
}

bool Path(const string& str, const vector<vector<char>>& matrix, vector<vector<bool>>& entry, size_t x, size_t y, size_t k)
{
    if (x < 0 || y < 0 || x >= matrix.size()|| y >= matrix[0].size())
        return false;

    if (!entry[x][y])
        return false;

    if (str[k] != matrix[x][y])
        return false;
    else
    {
        // std::cout << matrix[x][y] << std::endl;
        if (k == str.size() - 1)
            return true;
        else
        {
            ++k;
            entry[x][y] = false;

            bool flag = Path(str, matrix, entry, x-1, y, k)
                || Path(str, matrix, entry, x+1, y, k)
                || Path(str, matrix, entry, x, y-1, k)
                || Path(str, matrix, entry, x, y+1, k);

            if (!flag)
                entry[x][y] = true;

            return flag; 
        } 
    }
}

int main()
{
    vector<vector<char>> matrix{
        vector<char>{ 'a', 'b', 't', 'g' },
        vector<char>{ 'c', 'f', 'c', 's' },
        vector<char>{ 'j', 'd', 'e', 'h' },
    };

    string str{"abf"};
    if (Path(str, matrix))
        std::cout << str << std::endl;
    
    return 0;
}