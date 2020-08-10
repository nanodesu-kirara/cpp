/**
 * 2.4 最大连续子数组和
 */

#include<vector>
#include<iostream>

using std::vector;

int MaxSubArray(vector<int>&);

int MaxSubArrayDP(vector<int>&);

int main()
{
    vector<int> nums{ 1, -2, 3, 10, -4, 7, 2, -5 };
    std::cout << MaxSubArrayDP(nums) << std::endl;
    return 0;
}

// 蛮力枚举法
int MaxSubArray(vector<int>& nums)
{
    const int len = nums.size();
    if (!len) return 0;
    int currSum;
    int maxSum = nums[0];
    /**蛮力枚举**/
    for (int i = 0; i < len; ++i)
    {
        for (int j = i; j < len; ++j)
        {
            currSum = 0;
            // 求和, nums[i]...nums[j]
            for (int k = i; k <= j; ++k)
                currSum += nums[k];
            
            // 更新maxSum
            if (currSum > maxSum)
                maxSum = currSum;

        }
    }

    return maxSum;
}

/* 利用动态规划求解 */
int MaxSubArrayDP(vector<int>& nums)
{
    const int len = nums.size();
    if (!len) return 0;
 
    // dp[i] = max{ dp[i-1] + nums[i], nums[i] }
    // vector<int> dp(len);
    // dp[0] = nums[0];

    // 压缩状态，每一步只会用到上一步的结论
    int dp = 0;
    int ans = nums[0];

    for (int i = 0; i < len; ++i)
    {
        if (dp >= 0)
            dp += nums[i];
        else
            dp = nums[i];

        if (dp > ans)
            ans = dp;
    }

    return ans;
}
