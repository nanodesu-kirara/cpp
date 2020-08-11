/**
 * 4.1 有序数组的查找
 * 二分查找
 */

#include<vector>
#include<iostream>

using std::vector;

/**
 * 要求实现了 > = < 运算符
 * return 目标元素下标，没找到返回-1
 */
template<typename Comparable>
int BinarySearch(const vector<Comparable>&, const Comparable&);

int main()
{
    vector<int> vec{ 0, 1, 2, 3, 6, 8, 9 };
    std::cout << BinarySearch(vec, 2) << std::endl;
    return 0;
}

template<typename Comparable>
int BinarySearch(const vector<Comparable>& vec, const Comparable& target)
{
    const int NOT_EXIST = -1;
    const int len = vec.size();
    if (!len) return NOT_EXIST;
    int lhs = 0; 
    int rhs = len - 1;
    int mid;

    while (lhs <= rhs)
    {
        mid = (lhs + rhs) / 2;

        if (vec[mid] < target)
            lhs = mid + 1;
        else if (vec[mid] > target)
            rhs = mid - 1;
        else
            return mid;
    }

    return NOT_EXIST;
}

