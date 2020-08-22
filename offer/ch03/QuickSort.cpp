/**
 * 快速排序
 */

// 这里给出基于中位数的快速排序算法

#include<vector>
#include<iostream>

using std::vector, std::size_t, std::swap;

int median(vector<int>& nums, size_t begin, size_t end)
{
    int mid = (begin + end) / 2;

    if (nums[begin] > nums[end])
        swap(nums[begin], nums[end]);
    
    if (nums[mid] > nums[end])
        swap(nums[mid], nums[end]);

    else if (nums[mid] < nums[begin])    
        swap(nums[mid], nums[begin]);

    // 藏一下
    std::swap(nums[mid], nums[end-1]);

    return nums[end-1];
}

// 一趟排序
size_t Partition(vector<int>& nums, size_t begin, size_t end)
{
    int pivot = median(nums, begin, end);

    size_t left = begin;
    size_t right = end-1;

    while (true)
    {
        while (nums[++left] < pivot)
            ;
    
        while (nums[--right] > pivot)
            ;

        if (left < right)
            swap(nums[left], nums[right]);
        else
            break; 
    }

    // 重置主元 nums[left] > pivot
    swap(nums[left], nums[end-1]);

    return left;
}

void QuickSort(vector<int>& nums, size_t begin, size_t end)
{
    if (begin >= end)
        return;
    // 因为是基于中位数标准，所以至少3个数
    else if (end - begin < 2)
    {
        if (nums[begin] > nums[end])
            swap(nums[begin], nums[end]);
        
        return;
    }

    size_t pivot = Partition(nums, begin, end);

    QuickSort(nums, begin, pivot-1);
    QuickSort(nums, pivot+1, end);
}

void QuickSort(vector<int>& nums)
{
    if (nums.size() < 2) return;
    QuickSort(nums, 0, nums.size()-1);
}

int main()
{
    // vector<int> nums{ 1, 0, 9, 3, 5, 6, 6, 2, 6 , 9 };
    vector<int> nums{ 1, 0, 3, 3, 6, 9, 3, 2, 8 , 1 };
    QuickSort(nums);
    for (const auto& x : nums)
        std::cout << x << " ";
    std::cout << std::endl;
}
