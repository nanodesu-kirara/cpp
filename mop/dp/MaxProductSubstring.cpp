/**
 * 5.1 最大连续乘积子数组
 */

#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;

double MaxProductSubstring(const vector<double>&);

int main()
{
    vector<double> nums{ -2.5, 4, 0, 3, 0.5, 8, -1 };
    std::cout << MaxProductSubstring(nums) << std::endl;
}

double MaxProductSubstring(const vector<double>& nums)
{
    vector<double> maxP(nums.size());
    vector<double> minP(nums.size());

    maxP[0] = minP[0] = nums[0];

    double a, b;
    double ans = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        a = maxP[i-1] * nums[i];
        b = minP[i-1] * nums[i];
        maxP[i] = std::max({ a, b, nums[i] }); // 注意这里还有nums[i]
        minP[i] = std::min({ a, b, nums[i] }); // 注意这里: T max( std::initializer_list<T> ilist)

        if (maxP[i] > ans)
            ans = maxP[i];
    }

    return ans;
}

