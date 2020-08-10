/**
 * 2.6 奇偶数排序
 */

#include<vector>
#include<iostream>
#include"utils.hpp"

using std::vector;


void OddEvenSort(vector<int>&);

void OddEvenSortV2(vector<int>&);

int main()
{
    vector<int> nums{ 4, 1, 0, 9, 3, 6, 2, 8, 9 };

    M::printVector(nums);
    // OddEvenSort(nums);
    OddEvenSortV2(nums);
    M::printVector(nums);
}

// 双指针，头尾向中间扫描
void OddEvenSort(vector<int>& nums)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        if ((nums[i] & 1) == 1) // i指向奇数
            ++i;
        else if ((nums[j] & 1) != 1) // j指向偶数
            --j;
        else
            std::swap(nums[i], nums[j]);
    }

}

// 双指针，从头到尾以不同速率扫描
void OddEvenSortV2(vector<int>& nums)
{
    int i = -1; // 指向奇数放置位置，也就是前半部分
    int j = 0; // 指向偶数...，排序后的后半部分

    while (j < nums.size())
    {
        if ((nums[j] & 1) == 1) // j指向奇数
            std::swap(nums[++i], nums[j]);

        ++j;
    }

    // 这里不要忘了重置主元
    std::swap(*std::prev(nums.end()), nums[++i]);

}
