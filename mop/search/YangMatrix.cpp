/**
 * 4.2 行列递增矩阵查找
 * 每一行递增，每一列递增
 * 这样的矩阵也被称为 “杨氏矩阵”
 */

#include<vector>
#include<iostream>

using std::vector;
using location = std::pair<int, int>;

struct SubMatrix
{
    location lu_edp; // 左上角左标
    location rd_edp; // 右下角坐标
};


// m x n 矩阵
// 感觉写复杂了...或许还有隐藏的bug
// 总之有一股bad smell
// 如果是 n x n再考虑用这个方法吧
bool DivideSearch(const vector<vector<int>>&, int, const SubMatrix&);

bool YoungMatrix(const vector<vector<int>>&, int);

int main()
{
    vector<vector<int>> matrix{vector<int>{1,2,8,9},vector<int>{2,4,9,12}};//,vector<int>{4,7,10,13},vector<int>{6,8,11,15}};
    int target = 9;
    // bool flag = DivideSearch(matrix, target, SubMatrix{location{0,0}, location{0,3}});
    bool flag = YoungMatrix(matrix, target);
    if (flag)
        std::cout << "gacha!" << std::endl;
}

bool DivideSearch(const vector<vector<int>>& matrix, int target, const SubMatrix& bitmap)
{
    int r1 = bitmap.lu_edp.first;
    int c1 = bitmap.lu_edp.second;

    int r2 = bitmap.rd_edp.first;
    int c2 = bitmap.rd_edp.second;

    SubMatrix rest{};
    bool equal_size = false;

    if (c2 - c1 > r2 - r1)
    {
        c2 = c1 + (r2 - r1);
        rest = SubMatrix{location{r1, c2 + 1}, location{r2, bitmap.rd_edp.second}};
    }
    else if (c2 - c1 < r2 - r1)
    {
        r2 = r1 + (c2 - c1);
        rest = SubMatrix{location{r2 + 1, c1}, location{bitmap.rd_edp.first, c2}};
    }
    else
        equal_size = true;

    bool DivideA = equal_size ? false : DivideSearch(matrix, target, rest);

    /**
     * m x n 可以分为 n x n 和其余两个部分（假设m>n)
     */
    location lhs{r1, c1};
    location rhs{r2, c2};
    location mid{};
    //   std::cout << r1 << c1 <<"\n"<<r2<<c2 << std::endl;

    bool A = true;

    if (matrix[lhs.first][lhs.second] > target)
        return false;
    if (matrix[rhs.first][rhs.second] < target)
        A = false;

    bool DivideB = false;
    if (A)
    {
        while (lhs.first <= rhs.first)
        {
            mid = location{(lhs.first+rhs.first)/2, (lhs.second+rhs.second)/2};

            if (matrix[mid.first][mid.second] < target)
                lhs = location{mid.first+1, mid.second+1};
            else if (matrix[mid.first][mid.second] > target)
                rhs = location{mid.first-1, mid.second-1};
            else
                return true;
        
        }

        if (matrix[mid.first][mid.second] < target)
            mid = location{mid.first+1, mid.second+1};

        DivideB = DivideSearch(matrix, target, SubMatrix{location{mid.first, c1}, location{r2, mid.second-1}})
            || DivideSearch(matrix, target, SubMatrix{location{r1, mid.second}, location{mid.first-1, c2}});
    }

    return DivideA || DivideB;
        
}

bool YoungMatrix(const vector<vector<int>>& matrix, int target)
{
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    int x = 0;
    int y = cols - 1;

    int val;

    while (x < rows && y >= 0)
    {
        val = matrix[x][y];
        if (val < target)
            ++x;
        else if (val > target)
            --y;
        else
            return true; 
    }

    return false;
}
