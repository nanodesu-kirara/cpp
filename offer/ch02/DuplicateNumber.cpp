/**
 * 3. 找出数组中重复的数字
 * 长为n的数组nums中，nums[i] 属于 [0, n-1]
 * 可能有一个或多个数字重复，可能重复任意多次
 * 返回任意一个重复的数字
 */

#include<vector>
#include<iostream>

int DuplicateNumber(std::vector<int>& nums)
{
    const int ERROR = -1;
    const int len = nums.size();
    if (!len) return ERROR;

    // 已知 nums[i] < n, 但我们不能完全信任传进来的参数
    for (const auto& x : nums)
        if (x < 0 || x > len-1)
            return ERROR;


    int i = 0;
    // 充分利用已知条件的排序
    while (i < len)
    {

        /** for (auto x : nums)
                std::cout<< x <<' ';
            std::cout << std::endl;
        */

        // 如果下标为i的位置存放的数字不等于i
        if (i != nums[i])
            // 如果位置上已经有相同元素
            if (nums[i] == nums[nums[i]]) // 已知 nums[i] < n
                // 返回重复元素
                return nums[i];
            else
                // 将其与nums[i]位置上的值交换
                std::swap(nums[i], nums[nums[i]]);
        else
            // 否则后移一位
            ++i;
    }

    return ERROR;
}

int countRange(const std::vector<int>& nums, int min, int max)
{
    if (! nums.size())
        return 0;

    int count = 0;
    for (const auto& x : nums)
        if (min <= x && max >= x)
            ++count;
    
    return count;
}

// 要求不修改数组的情况下找出重复元素
int DuplicateNumber(const std::vector<int>& nums)
{
    const int ERROR = -1;
    const int len = nums.size();
    if (!len) return ERROR;

    // 已知 nums[i] < n, 但我们不能完全信任传进来的参数
    for (const auto& x : nums)
        if (x < 1 || x > len-1)
            return ERROR;

    int l = 1;
    int r = nums.size()-1;
    int m;

    // 划分的是1~n这个范围
    while (l < r)
    {
        m = l + ((r-l) >> 1);

        printf("l: %d, r: %d, m: %d.\n", l, r, m);

        if (countRange(nums, l, m) > m - l + 1)
            r = m;
        else if (countRange(nums, m+1, r) > r - m)
            l = m+1;
        else
            return -1; 
    }

    // l = m = r
    if (l == r)
        if (countRange(nums, l, l+((r-l)>>1)) > 1)
                return l;

    return -1;

}

void test()
{
    // std::vector<int> nums{ 1, 0, 9, 3, 6, 9, 3, 2, 8, 1 }; // 有重复
    const std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 3 }; // 无重复
    // std::vector<int> nums{ -1, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 无效输入
    // std::vector<int> nums{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 10 }; 无效输入
    std::cout << DuplicateNumber(nums) << std::endl;
}

int main()
{
    test();
    return 0;
}
