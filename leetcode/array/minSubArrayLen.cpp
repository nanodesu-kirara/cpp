#include<vector>
#include<iostream>

using std::vector;

int minSubArrayLen(int, vector<int>&);

int minSubArrayLen(int s, vector<int>& nums)
{
    const int len = nums.size();
    int i = 0, j = -1, sum = 0;
    int min = 0;

    while (j < len - 1)
    {
        if (sum < s)
            sum += nums[++j];
        else
            sum -= nums[i++];
        
        if (sum >= s)
            min = min != 0 ? std::min(min, j-i+1) : j-i+1;

        printf("i: %d, j: %d, min: %d, sum: %d\n", i, j, min, sum);
    }

    while (sum >= s)
        sum -= nums[i++];
    
    min = std::min(min, j-i+2);

    return min;
}

int main()
{
    vector<int> nums{1,4,4};
    const int s = 10;
    std::cout << minSubArrayLen(s, nums) << std::endl;

}
