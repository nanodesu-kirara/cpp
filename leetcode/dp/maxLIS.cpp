#include<vector>
#include<algorithm>
#include<iostream>
using std::vector;

int maxLIS(const vector<int>&);
int binarySearch(const vector<int>&, int);
int better(const vector<int>&);
template<typename T>
void printVector(const vector<T>&);

int main(){
    vector<int> nums{ 10, 9, 2, 5, 3, 7, 101, 18 };
    printf("maxLIS: %d\n", better(nums));
    return 0;
}

int maxLIS(const vector<int>& nums)
{
    const int len = nums.size();
    if (!len) return 0;
    vector<int> dp(len, 1);

    for (int j = 0; j < len; ++j)
        for (int i = 0; i < j; ++i)
            if (nums[i] < nums[j])
                dp[j] = std::max(dp[j], dp[i]+1);

    return *max_element(dp.begin(), dp.end());
}

int better(const vector<int>& nums)
{
    const int len = nums.size();
    if (!len) return 0;
    vector<int> dp{};
    dp.push_back(nums[0]);
    // 定义状态dp[i]为长度为i+1的上升序列的最小末位数字
    // dp是递增的, 因为每一个更长的上升序列都是由前一个上升序列得到的，可以用反证法证明
    // j每走一步都会更新dp中的一项
    // 该项是比nums[j]小的最后一项
    int index = 0;
    for (int j = 1; j < len; ++j)
    {
        index = binarySearch(dp, nums[j]);
        if (nums[j] < dp[index])
            dp[index] = nums[j];
        else if (nums[j] > dp[index])
            dp.push_back(nums[j]);
    }
    printVector(dp);
    return dp.size();
}

int binarySearch(const vector<int>& dp, int target)
{
    int i = 0, j = dp.size()-1;
    int mid = (i + j) / 2;
    while (i != mid)
    {
        if (dp[mid] < target)
            i = mid;
        else if (dp[mid] > target)
            j = mid;
        else return mid;
        mid = (i + j) / 2;
    }
    return j;
}

template<typename T>
void printVector(const vector<T>& v)
{
    for (auto x : v)
        std::cout << x << " ";    
    std::cout << std::endl;
}

