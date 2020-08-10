/**
 * 2.1 寻找最小的k个数
 */
#include<vector>
#include<iostream>
#include<algorithm>
#include"utils.hpp"

using std::vector;

vector<int> partSort(vector<int>&, int);

void QuickSelect(vector<int>& , int , int, int );

// 插入排序，未实现
void InsertSort();

int main() {
    vector<int> v{ 1, 0, 9, 3, 6, 9, 3, 2, 8, 1 };
    M::printVector(partSort(v, 6));
    return 0;
}

// 如果全排复杂度为nlogn
// 部分排序则减少至nlogk (n >> k)
vector<int> partSort(vector<int>& vec, int k)
{
    // 如果使用二叉堆，复杂度会从nk降至nlogk
    vector<int> ans = vector<int>{ vec.cbegin(), vec.cbegin() + k };
    for (int i = k; k < vec.size(); ++k)
    {
        auto maxInAns = std::max_element(ans.cbegin(), ans.cend());
        if (*maxInAns > vec[k])
            ans[maxInAns - ans.cbegin()] = vec[k];
    }
    return ans;
}

template<typename T>
T median3(vector<T>& vec, int left, int right)
{
    int median = (left + right)/2;
    if (vec[left] > vec[median])
        std::swap(vec[left], vec[median]);
    if (vec[median] > vec[right])
        std::swap(vec[median], vec[right]);
    if (vec[left] > vec[right])
        std::swap(vec[left], vec[right]);
    
    // 藏pivot
    std::swap(vec[median], vec[right-1]);
    return vec[right-1];

}

// 把第k小的元素放在k-1的位置上
void QuickSelect(vector<int>& vec, int k, int left, int right)
{
    int i, j;
    if (left <= right)
    {
        int median = median3(vec, left, right);
        i = left;
        j = right - 1;
        while(true)
        {
            while(vec[++i] < median) {}
            while(vec[--j] > median) {}
            if (i < j)
                std::swap(vec[i], vec[j]);
            else
                break;
        }

        // 重置主元，结合line55来看
        std::swap(vec[i], vec[right-1]);

        if (k <= i)
            QuickSelect(vec, k, left, i-1);
        else if (k > i + 1)
            QuickSelect(vec, k - i - 1, i+1, right);
        // else k = i+1
        // 则vec[i]为第i+1小元素，即第k小元素
    }
    else
    {
        // 对于left > right的情况下快速排序不好用
        // 使用插入排序
        InsertSort();
    }
    
}

void InsertSort()
{
    // 未实现
}
