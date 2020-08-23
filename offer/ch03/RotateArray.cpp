/**
 * search 旋转数组中的最小数字
 * 非递减数组 经过 翻转 得到的数组 称为 旋转数组
 * 123456 -> 345612
 */

#include<vector>
#include<exception>
#include<algorithm>
#include<iostream>
using std::vector, std::size_t;

// 二分法
int SearchRotate(const vector<int>& nums)
{
    const size_t len = nums.size();
    if (! len) throw std::exception{};

    size_t lhs = 0;
    size_t rhs = len - 1;

    size_t mid = lhs;

    while (nums[lhs] >= nums[rhs])
    {
    
        if (rhs - lhs == 1)
            return nums[rhs];

        mid = (lhs + rhs) / 2;

        // 在第一段序列的尾部
        if (nums[mid] > nums[lhs])
            lhs = mid;
        // 在第二段序列的头部
        else if (nums[mid] < nums[rhs])
            rhs = mid;
        // 无法判断, 改为遍历查找，或者在两段里面查找 较小者
        else if (nums[lhs] == nums[mid] && nums[mid] == nums[rhs])
            return *std::min_element(nums.cbegin() + lhs, nums.cbegin() + rhs + 1);

    }
    
    return nums[mid];

}

int main()
{
    vector<int> nums{ 2, 3, 4, 1, 2 };
    std::cout << SearchRotate(nums) << std::endl;
}
