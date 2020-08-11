/**
 * 2.2 寻找和为定值的两个数
 */

#include<unordered_set>
#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;
using std::unordered_set;

void HashTable(vector<int>&, int);

bool BinarySearch(vector<int>&, int);

void TwoSum(vector<int>&, int);

void TwoSumP(vector<int>&, int);

int main()
{
    
}

// 时间复杂度O(n), 空间复杂度O(n)
// 不需要有序
void HashTable(vector<int>& nums, int sum)
{
    unordered_set<int> hash{};
    for (auto x : nums)
        hash.insert(x);
    
    for (auto x : nums)
        if (hash.count(sum - x))
        {
            printf("%d + %d = %d\n", x, sum-x, sum);
            return;
        }

    printf("not exist.");
}

// 先排序，然后利用二分查找
// 时间复杂度O(nlogn), 空间O(1)
void TwoSum(vector<int>& nums, int sum)
{
    std::sort(nums.begin(), nums.end());

    for (auto x : nums)
    {
        if (BinarySearch(nums, sum-x))
        {
            printf("%d + %d = %d\n", x, sum-x, sum);
            return;
        }
    }

    printf("not exist.");
}

// 双指针时间复杂度O(n), 空间复杂度O(1)
// 前提数组有序
void twoSumP(vector<int>& nums, int sum)
{
    if (!nums.size())
        return;
    int i, j;
    i = 0;
    j = nums.size()-1;

    while (i < j)
    {
        if (nums[i] + nums[j] > sum)
            --j;
        else if (nums[i] + nums[j] < sum)
            ++i;
        else
        {
            printf("%d + %d = %d\n", nums[i], nums[j], sum);
            return;
        }

    }

    printf("not exist.");
}


bool BinarySearch(vector<int>& nums, int target)
{
    if (!nums.size())
        return false;
    int i = 0;
    int j = nums.size() - 1;
    int m;
    
    while (i <= j)
    {

        m = (i+j)/2;

        if (nums[m] < target)
            i = m + 1;
        else if (nums[m] > target)
            j = m - 1;
        else
            return true;

    }

    return false;

}
